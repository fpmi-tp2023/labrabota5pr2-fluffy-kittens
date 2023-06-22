#include "../includes/nmodule_note.h"

namespace kittens {
NoteModule::NoteModule(vector<string> notes) : notes_(notes) {}

NoteModule::~NoteModule() {}

void NoteModule::Render(WINDOW *window) {
  int notes_num = notes_.size();
  int x, y;
  getmaxyx(window, y, x);
  int notes_width = 0;
  int notes_y = y - notes_num - 1;  // leave one line for padding

  // Calculate the width of the longest note
  for (const auto &note : notes_) {
    notes_width = std::max(notes_width, static_cast<int>(note.length()));
  }

  // Calculate the x position to center the notes
  int notes_x = (x - notes_width) / 2;

  // Draw the notes
  for (int i = 0; i < notes_num; ++i) {
    mvwprintw(window, notes_y + i, notes_x, notes_[i].c_str());
  }
}
}  // namespace kittens