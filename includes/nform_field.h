#ifndef INCLUDES_NFORM_FIELD_H_
#define INCLUDES_NFORM_FIELD_H_

#include <ncurses.h>

#include "./types.h"

namespace kittens {
class FormField {
 public:
  FormField(string label, function<bool(string)> validator, int max_len = 20);
  virtual ~FormField();
  virtual void HandleInput(int ch);
  void Erase();
  virtual void Render(WINDOW *window, int x, int y) const;
  bool Validate() const;
  string_view GetValue() const;
  string_view GetLabel() const;
  int GetMaxLen() const;

 protected:
  string label_;
  function<bool(string)> validator_;
  string value_;
  int max_len_;
};
}  // namespace kittens
#endif /* INCLUDES_NFORM_FIELD_H_ */
