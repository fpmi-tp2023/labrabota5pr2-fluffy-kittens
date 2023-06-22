#ifndef INCLUDES_NQUERY_H_
#define INCLUDES_NQUERY_H_

#include "./nwindow.h"
#include "./query_row.h"
#include "./types.h"

namespace kittens {
class Query : public Window {
 public:
  Query(vector<string> headers, vector<int> column_grow_factors);
  ~Query();
  void Render(WINDOW *window);
  void HandleInput(int ch);
  void CleanUp() override;
  void AddRow(unique_ptr<QueryRow> row);
  void CountColumnWidths(int width);

 protected:
  vector<string> headers_;
  vector<int> column_grow_factors_;
  mutable vector<int> column_widths_;
  mutable int rows_visible_;
  vector<unique_ptr<QueryRow>> rows_;
  int current_top_row_;
};
}  // namespace kittens

#endif /* INCLUDES_NQUERY_H_ */
