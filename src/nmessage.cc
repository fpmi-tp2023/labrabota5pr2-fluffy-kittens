#include "../includes/nmessage.h"

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
    for (auto &split_line : SplitLine(line, window_width_ / 2)) {
      render_lines_.push_back(line);
    }
  }
}

vector<string> SplitLine(string line, int line_width) {
  vector<string> lines = SplitWords(line);
  vector<string> render_lines;
  string current_line = "";
  for (auto &word : lines) {
    if (current_line.empty()) {
      current_line = word;
    } else if (current_line.length() + word.length() + 1 <= line_width) {
      current_line += " " + word;
    } else {
      render_lines.push_back(current_line);
      current_line = word;
    }
  }
  if (!current_line.empty()) {
    render_lines.push_back(current_line);
  }
  return render_lines;
}

vector<string> SplitWords(string line) {
  vector<string> words;
  string current_word = "";
  for (char c : line) {
    if (isspace(c)) {
      if (!current_word.empty()) {
        words.push_back(current_word);
        current_word = "";
      }
    } else {
      current_word += c;
    }
  }
  if (!current_word.empty()) {
    words.push_back(current_word);
  }
  return words;
}

}  // namespace kittens