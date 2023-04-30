#ifndef INCLUDES_NWINDOW_H_
#define INCLUDES_NWINDOW_H_

#include "./types.h"

namespace kittens {

class Window {
   public:
    Window();
    virtual ~Window();
    virtual void HandleInput() = 0;
    virtual void Render() = 0;
};

}  // namespace kittens

#endif /* INCLUDES_NWINDOW_H_ */
