#include "../includes/nmodule_note.h"

namespace kittens {
NoteModule::NoteModule(vector<string> notes) : notes_(notes) {}

NoteModule::~NoteModule() {}

void NoteModule::Render(WINDOW* window) {
  int notes_num = notes_.size();
  int x, y;
  getmaxyx(window, y, x);
  int notes_y = y - notes_num - 1;  // leave one line for padding

  // Draw the notes
  for (int i = 0; i <= notes_num; ++i) {
    mvwprintw(window, notes_y - i, 1, notes_[notes_num - i - 1].c_str());
  }
}
}  // namespace kittens