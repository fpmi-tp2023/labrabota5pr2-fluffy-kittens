#include "../includes/nmodule_title.h"
namespace kittens {
TitleModule::TitleModule(string title) : title_(title) {}

TitleModule::~TitleModule() {}

void TitleModule::Render(WINDOW* window) {
  int x, y;
  getmaxyx(window, y, x);
  int title_x = (x - title_.length()) / 2;
  wattron(window, A_BOLD);  // enable bold font
  mvwprintw(window, 1, title_x, title_.c_str());
  wattroff(window, A_BOLD);  // disable bold font
}
}  // namespace kittens