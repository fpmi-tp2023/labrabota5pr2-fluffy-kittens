#include "../includes/nquery.h"

namespace kittens {
Query::Query(vector<string> headers, vector<int> column_grow_factors)
    : headers_(headers),
      column_grow_factors_(column_grow_factors),
      current_top_row_(0),
      rows_(),
      column_widths_(-1, headers.size()) {}

Query::~Query() {}

void Query::Render(WINDOW *window) {
  int x, y;
  getmaxyx(window, y, x);

  box(window, 0, 0);

  int height = y / 2;
  int width = x - 4;

  int window_x = (x - width) / 2;
  int window_y = (y - height) / 2;

  CountColumnWidths(width);

  int header_num = 0;
  int print_total = 0;
  for (auto &header : headers_) {
    int column_width = column_widths_[header_num];
    string print = "| " + header.substr(0, column_width) + " ";
    mvwprintw(window, window_y, window_x, "%s", header.c_str());
    print_total += 3 + column_width;
  }
  mvwprintw(window, window_y, window_x + print_total, "|");

  int row_num = 0;
  int print_rows_num = height - 1;

  for (int i = 0; i < print_rows_num; ++i) {
    auto &row = rows_[current_top_row_ + i];
    row->Render(window, window_x, window_y + 1 + i, column_widths_);
    row_num++;
  }

  RenderModules(window);
}

void Query::HandleInput(int ch) {}

void Query::AddRow(unique_ptr<QueryRow> field) {}

void Query::CountColumnWidths(int width) {
  float total_factor =
      accumulate(column_grow_factors_.begin(), column_grow_factors_.end(), 0);
  int column = 0;
  for (auto &width : column_widths_) {
    auto scale_factor = float(column_grow_factors_[column]) / total_factor;
    column_widths_[column] = floor(width * scale_factor);
  }
}
}  // namespace kittens