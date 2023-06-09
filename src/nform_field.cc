#include "../includes/nform_field.h"

namespace kittens {
FormField::FormField(string label, string error,
                     function<bool(string)> validator, int max_len) {
  label_ = label;
  error_ = error;
  validator_ = validator;
  max_len_ = max_len;
}

FormField::~FormField() {}

void FormField::HandleInput(int ch) {
  if (value_.length() >= max_len_) {
    return;
  }
  value_ += ch;
}

void FormField::Erase() {
  if (!value_.empty()) {
    value_.pop_back();  // Remove last character
  }
}

void FormField::Clear() { value_.clear(); }

void FormField::Render(WINDOW *window, int x, int y) const {
  string line(max_len_ - value_.length(), '_');
  mvwprintw(window, y, x, "%s:", label_.c_str());
  mvwprintw(window, y, x + label_.length() + 1, "%s%s", value_.c_str(),
            line.c_str());
}

bool FormField::Validate() const { return validator_(value_); }

string FormField::GetValue() const { return value_; }

string_view FormField::GetLabel() const { return label_; }

int FormField::GetMaxLen() const { return max_len_; }

string FormField::GetError() const { return error_; }
}  // namespace kittens