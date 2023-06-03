#ifndef INCLUDES_NWINDOW_NOTE_H_
#define INCLUDES_NWINDOW_NOTE_H_

#include "./nmodule.h"
#include "./nwindow.h"
#include "./types.h"

namespace kittens {

class NoteModule : Module {
   public:
    NoteModule(vector<string> notes);
    ~NoteModule();
    void Render(WINDOW* window) override;

   protected:
    vector<string> notes_;
};

}  // namespace kittens

#endif /* INCLUDES_NWINDOW_NOTE_H_ */
