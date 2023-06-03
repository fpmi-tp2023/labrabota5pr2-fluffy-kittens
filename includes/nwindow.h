#ifndef INCLUDES_NWINDOW_H_
#define INCLUDES_NWINDOW_H_

#include <ncurses.h>

#include "./nrender_module.h"
#include "./types.h"

namespace kittens {

class Window {
   public:
    Window(){};
    virtual ~Window(){};
    virtual void HandleInput(int ch) = 0;
    virtual void Render(WINDOW* window) = 0;
    void AddModule(unique_ptr<RenderModule> module);
    void RenderModules(WINDOW* window);

   protected:
    vector<unique_ptr<RenderModule>> modules_;
};

}  // namespace kittens

#endif /* INCLUDES_NWINDOW_H_ */
