#ifndef INCLUDES_NRENDER_MODULE_H_
#define INCLUDES_NRENDER_MODULE_H_

#include "nwindow.h"

namespace kittens {
class RenderModule {
   public:
    virtual void Render(WINDOW* window) = 0;
};
}  // namespace kittens

#endif /* INCLUDES_NRENDER_MODULE_H_ */
