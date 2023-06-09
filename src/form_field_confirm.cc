#include "../includes/form_field_confirm.h"
namespace kittens {
FormFieldConfirm::FormFieldConfirm(string label, string error,
                                   shared_ptr<FormField> field)
    : FormField(label, error,
                [this](string s) { return IsMatchingConfirm(s); }) {
  confirm_field_ = field;
}

bool FormFieldConfirm::IsMatchingConfirm(string value) const {
  return confirm_field_->GetValue() == value;
}
}  // namespace kittens