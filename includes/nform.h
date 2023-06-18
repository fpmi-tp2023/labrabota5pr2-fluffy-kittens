#ifndef INCLUDES_NFORM_H_
#define INCLUDES_NFORM_H_

#include <cctype>

#include "./form_field_confirm.h"
#include "./form_field_secret.h"
#include "./nform_field.h"
#include "./nmodule_note.h"
#include "./nwindow.h"
#include "./types.h"

namespace kittens {
class Form : public Window {
 public:
  Form(function<void()> submit);
  ~Form();
  void HandleInput(int ch) override;
  void Render(WINDOW *window) override;
  void AddField(unique_ptr<FormField> field);
  void RenderFields(WINDOW *window);
  void Submit();
  void CleanUp() override;

 protected:
  function<void()> submit_;
  vector<unique_ptr<FormField>> fields_;
  shared_ptr<NoteModule> validation_output_;
  int selected_;
  int max_label_length_;
  int max_value_length_;
};
}  // namespace kittens

#endif /* INCLUDES_NFORM_H_ */
