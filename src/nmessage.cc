#include "../includes/nmessage.h"

#include "../includes/string_operations.h"
#include "../includes/window_manager.h"

namespace kittens {
Message::Message(vector<string> lines, shared_ptr<Window> parent)
    : lines_(lines), parent_(parent), window_width_(-1), render_lines_() {}

Message::~Message() {}

void Message::HandleInput(int ch) {
  if (ch == '\n') {
    WindowManager::Instance()->ReturnToPreviousWindow();
    return;
  }

  if (ch == '\t') {
    WindowManager::Instance()->ReturnToPreviousWindow();
    return;
  }
}

void Message::Render(WINDOW *window) {
  int x, y;
  getmaxyx(window, y, x);
  if (x != window_width_) {
    window_width_ = x;
    SplitText(lines_);
  }

  int message_height = render_lines_.size();
  int message_width = window_width_ / 2;

  int message_x = (window_width_ - message_width) / 2;
  int message_y = (y - message_height) / 2;

  int line_num = 0;
  for (auto &line : render_lines_) {
    int line_y = message_y + line_num;
    int line_x = message_x;
    mvwprintw(window, line_y, line_x, line.c_str());
    line_num++;
  }
}

void Message::CleanUp() {}

void Message::SplitText(vector<string> lines) {
  render_lines_.clear();
  for (auto &line : lines) {
    for (auto &split_line : utils::SplitLine(line, window_width_ / 2)) {
      render_lines_.push_back(line);
    }
  }
}

}  // namespace kittens