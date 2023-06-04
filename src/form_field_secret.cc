#include "../includes/form_field_secret.h"
namespace kittens {
FormFieldSecret::FormFieldSecret(string label, function<bool(string)> validator,
                                 int max_len)
    : FormField(label, validator, max_len) {}

void FormFieldSecret::Render(WINDOW* window, int x, int y) const {
  string line(max_len_ - value_.length(), '_');
  string content(value_.length(), '*');
  mvwprintw(window, y, x, "%s:", label_.c_str());
  mvwprintw(window, y, x + label_.length() + 1, "%s%s", content.c_str(),
            line.c_str());
}
}  // namespace kittens