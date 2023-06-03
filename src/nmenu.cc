#include "../includes/nmenu.h"

namespace kittens {
Menu::Menu() : selected_(0), max_label_length_(0), items_() {}

Menu::~Menu() {}

void Menu::HandleInput(int ch) {
  switch (ch) {
    case KEY_UP:
      if (selected_ > 0) {
        selected_--;
      }
      break;

    case KEY_DOWN:
      if (selected_ < items_.size() - 1) {
        selected_++;
      }
      break;

    case '\n':
      items_[selected_].Execute();
      break;

    default:
      break;
  }
}

void Menu::AddItem(string label, function<void()> callback) {
  items_.emplace_back(label, callback);
  int label_length = static_cast<int>(label.length());
  max_label_length_ = std::max(max_label_length_, label_length);
}

void Menu::Render(WINDOW* window) {
  int x, y;
  getmaxyx(window, y, x);

  int menu_width = max_label_length_ + 4;
  int menu_height = items_.size() + 2;
  int menu_x = (x - menu_width) / 2;
  int menu_y = (y - menu_height) / 2;

  box(window, 0, 0);

  int items_num = items_.size();
  for (int i = 0; i < items_num; ++i) {
    int item_x = (menu_width - items_[i].View().length()) / 2;
    int item_y = i + 2;  // Offset for title and border
    if (i == selected_) {
      wattron(window, A_REVERSE);
    }
    items_[i].Render(window, menu_x + item_x, menu_y + item_y);
    if (i == selected_) {
      wattroff(window, A_REVERSE);
    }
  }
};

}  // namespace kittens