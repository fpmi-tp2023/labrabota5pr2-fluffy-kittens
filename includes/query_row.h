#ifndef INCLUDES_QUERY_ROW_H_
#define INCLUDES_QUERY_ROW_H_

#include <ncurses.h>

#include "./types.h"

namespace kittens {

class QueryRow {
 public:
  QueryRow(vector<string> columns);
  ~QueryRow();
  void Render(WINDOW *window, int x, int y, vector<int> columns_width);

 protected:
  vector<string> columns_;
};

}  // namespace kittens

#endif /* INCLUDES_QUERY_ROW_H_ */
