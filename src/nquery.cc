#include "../includes/nquery.h"
#include "../includes/window_manager.h"

namespace kittens {
Query::Query(vector<string> headers, vector<int> column_grow_factors)
    : headers_(headers),
      column_grow_factors_(column_grow_factors),
      current_top_row_(0),
      rows_(),
      column_widths_(column_grow_factors) {}

Query::~Query() {}

void Query::Render(WINDOW *window) {
  int x, y;
  getmaxyx(window, y, x);

  int columns_num = headers_.size();

  box(window, 0, 0);

  int height = y / 2;
  int width = x - 4;

  rows_visible_ = height - 2;

  int window_x = (x - width) / 2;
  int window_y = (y - height) / 2;

  CountColumnWidths(width - (columns_num * 3 + 1));

  int header_num = 0;
  int print_total = 0;
  for (auto &header : headers_) {
    int column_width = column_widths_[header_num];
    string print = "| " + header.substr(0, column_width) + " ";
    mvwprintw(window, window_y, window_x + print_total, "%s", print.c_str());
    print_total += 3 + column_width;
    ++header_num;
  }

  string close{"|"};
  mvwprintw(window, window_y, window_x + width - 1, "%s", close.c_str());

  string line(width, '-');

  mvwprintw(window, window_y + 1, window_x, "%s", line.c_str());

  int row_num = 0;
  int total_rows_num = rows_.size();
  int print_rows_num = min(rows_visible_, total_rows_num);

  for (int i = 0; i < print_rows_num; ++i) {
    auto &row = rows_[current_top_row_ + i];
    row->Render(window, window_x, window_y + 2 + i, column_widths_);
    ++row_num;
  }

  RenderModules(window);
}

void Query::HandleInput(int ch) {
  if (ch == KEY_UP) {
    if (current_top_row_ > 0) {
      current_top_row_--;
    }
    return;
  }

  if (ch == KEY_DOWN) {
    if (current_top_row_ < rows_.size() - rows_visible_) {
      current_top_row_++;
    }
    return;
  }

  if (ch == '\n') {
    WindowManager::Instance()->ReturnToPreviousWindow();
    return;
  }

  if (ch == '\t') {
    WindowManager::Instance()->ReturnToPreviousWindow();
    return;
  }
}

void Query::CleanUp() { current_top_row_ = 0; }

void Query::AddRow(unique_ptr<QueryRow> row) { rows_.push_back(move(row)); }

void Query::CountColumnWidths(int width) {
  float total_factor =
      accumulate(column_grow_factors_.begin(), column_grow_factors_.end(), 0);
  int column = 0;
  for (auto &column_width : column_widths_) {
    auto scale_factor = float(column_grow_factors_[column]) / total_factor;
    column_width = floor(width * scale_factor);
    ++column;
  }
}
}  // namespace kittens