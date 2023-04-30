#include "../../includes/menu/menu_item.h"

#include <ncurses.h>

namespace kittens {
MenuItem::MenuItem(string& label, function<void()>& callback) : label_(label), callback_(callback) {
}

string_view MenuItem::View() const {
    return label_;
}

void MenuItem::Execute() const {
    callback_();
}

void MenuItem::Render(int x, int y) const {
    mvprintw(x, y, " %s", label_.c_str());
}
}  // namespace kittens