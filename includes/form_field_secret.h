#ifndef INCLUDES_FORM_FIELD_SECRET_H_
#define INCLUDES_FORM_FIELD_SECRET_H_

#include "./nform_field.h"

namespace kittens {
class FormFieldSecret : public FormField {
public:
  FormFieldSecret(string label, function<bool(string)> validator,
                  int max_len = 20);
  virtual void Render(WINDOW *window, int x, int y) const override;
};
} // namespace kittens

#endif /* INCLUDES_FORM_FIELD_SECRET_H_ */
