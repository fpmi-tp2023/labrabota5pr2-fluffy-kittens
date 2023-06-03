#ifndef INCLUDES_FORM_FIELD_CONFIRM_H_
#define INCLUDES_FORM_FIELD_CONFIRM_H_

#include "./form_field.h"
#include "./types.h"

namespace kittens {
class FormFieldConfirm : public FormField {
   public:
    FormFieldConfirm(string label, shared_ptr<FormField> field);
    bool IsMatchingConfirm(string value) const;

   protected:
    shared_ptr<FormField> confirm_field_;
};
}  // namespace kittens

#endif /* INCLUDES_FORM_FIELD_CONFIRM_H_ */
