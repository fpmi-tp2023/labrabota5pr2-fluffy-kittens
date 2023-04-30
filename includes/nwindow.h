#ifndef INCLUDES_NWINDOW_H_
#define INCLUDES_NWINDOW_H_

#include <ncurses.h>

#include "./types.h"

namespace kittens {

class Window {
   public:
    Window(){};
    virtual ~Window(){};
    virtual void HandleInput(int ch) = 0;
    virtual void Render(WINDOW* window) = 0;
};

}  // namespace kittens

#endif /* INCLUDES_NWINDOW_H_ */
