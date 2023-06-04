#include "../includes/nform.h"

#include "../includes/window_manager.h"

namespace kittens {
Form::Form(shared_ptr<Window> target_window)
    : target_window_(target_window),
      fields_(),
      max_label_length_(0),
      max_value_length_(0),
      selected_(0) {}

Form::~Form() {}

void Form::HandleInput(int ch) {
  if (isprint(ch)) {
    fields_[selected_]->HandleInput(ch);
    return;
  }

  if (ch == KEY_BACKSPACE) {
    fields_[selected_]->Erase();
    return;
  }

  if (ch == KEY_UP) {
    if (selected_ > 0) {
      selected_--;
    }
    return;
  }

  if (ch == KEY_DOWN) {
    if (selected_ < fields_.size() - 1) {
      selected_++;
    }
    return;
  }

  if (ch == KEY_ENTER) {
    Submit();
    return;
  }

  if (ch == 27) {
    WindowManager::Instance()->ReturnToPreviousWindow();
    return;
  }
}

void Form::Render(WINDOW* window) {
  box(window, 0, 0);
  RenderFields(window);
  RenderModules(window);
}

void Form::AddField(unique_ptr<FormField> field) {
  fields_.push_back(move(field));
  int label_length = static_cast<int>(fields_.back()->GetLabel().length());
  max_label_length_ = std::max(max_label_length_, label_length);
  max_value_length_ = std::max(max_value_length_, fields_.back()->GetMaxLen());
}

void Form::RenderFields(WINDOW* window) {
  int x, y;
  getmaxyx(window, y, x);
  int form_width = max_label_length_ + max_value_length_ + 4;
  int form_height = fields_.size() + 2;
  int form_x = (x - form_width) / 2;
  int form_y = (y - form_height) / 2;
  for (int i = 0; i < fields_.size(); ++i) {
    if (i == selected_) {          // Check if field is selected
      wattron(window, A_REVERSE);  // enable reverse video
    }                              /*  */
    fields_[i]->Render(window, form_x + 2, form_y + i + 1);
    if (i == selected_) {           // Check if field is selected
      wattroff(window, A_REVERSE);  // disable reverse video
    }
  }
}

void Form::Submit() {}
}  // namespace kittens