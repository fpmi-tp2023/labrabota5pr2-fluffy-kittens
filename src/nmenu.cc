#include "../includes/nmenu.h"

namespace kittens {
Menu::Menu(string title) : selected_(0), title_(title) {
}

Menu::~Menu() {
}

void Menu::HandleInput(int ch) {
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

    int title_x = (x - title_.length()) / 2;
    wattron(window, A_BOLD);  // enable bold font
    mvwprintw(window, 1, title_x, title_.c_str());
    wattroff(window, A_BOLD);  // disable bold font

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