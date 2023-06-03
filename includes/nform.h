#ifndef INCLUDES_NFORM_H_
#define INCLUDES_NFORM_H_

#include <cctype>

#include "./nform_field.h"
#include "./nwindow.h"
#include "./types.h"

namespace kittens {
class Form : public Window {
 public:
  Form(shared_ptr<Window> target_window);
  ~Form();
  void HandleInput(int ch) override;
  void Render(WINDOW* window) override;
  void AddField(unique_ptr<FormField> field);
  void RenderFields(WINDOW* window);
  void Submit();

 protected:
  vector<unique_ptr<FormField>> fields_;
  shared_ptr<Window> target_window_;
  int selected_;
  int max_label_length_;
  int max_value_length_;
};
}  // namespace kittens

#endif /* INCLUDES_NFORM_H_ */
