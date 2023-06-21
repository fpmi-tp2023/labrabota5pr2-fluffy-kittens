#include "../includes/query_row.h"

namespace kittens {
QueryRow::QueryRow(vector<string> columns) : columns_(columns) {}

QueryRow::~QueryRow() {}

void QueryRow::Render(WINDOW *window, int x, int y, vector<int> columns_width) {
  int total_width = 0;
  int column_num = 0;
  for (auto &column : columns_) {
    int column_width = columns_width[column_num];
    string print = "| " + column.substr(0, column_width) + " ";
    mvwprintw(window, y, x + total_width, "%s", print.c_str());
    total_width += column_width + 3;
    ++column_num;
  }
  mvwprintw(window, y, x + total_width, "|");
}
}  // namespace kittens