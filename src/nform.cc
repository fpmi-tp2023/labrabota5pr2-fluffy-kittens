#include "../includes/nform.h"
namespace kittens {
Form::Form(shared_ptr<Window> target_window) {
    target_window_ = target_window;
}

Form::~Form() {
}

void Form::HandleInput(int ch) {
    if (isprint(ch)) {
        fields_[selected_]->HandleInput(ch);
        return;
    }
    switch (ch) {
        case '\n':
            Submit();
            break;

        case 27:  // ESCAPE
            fields_[selected_]->Erase();
            break;

        case KEY_UP:
            if (selected_ > 0) {
                selected_--;
            }
            break;

        case KEY_DOWN:
            if (selected_ < fields_.size() - 1) {
                selected_++;
            }
            break;

        default:
            break;
    }
}

void Form::Render(WINDOW* window) {
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
        fields_[i]->Render(window, form_x + 2, form_y + i + 1);
    }
}

void Form::Submit() {
}
}  // namespace kittens