#include "../includes/menu_item.h"

namespace kittens {
MenuItem::MenuItem(string &label, function<void()> &callback)
    : label_(label), callback_(callback) {}

string_view MenuItem::View() const { return label_; }

void MenuItem::Execute() const { callback_(); }

void MenuItem::Render(WINDOW *window, int x, int y) const {
  mvwprintw(window, y, x, " %s", label_.c_str());
}
} // namespace kittens