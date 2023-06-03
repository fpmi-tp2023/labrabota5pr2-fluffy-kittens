#ifndef INCLUDES_NMODULE_H_
#define INCLUDES_NMODULE_H_

#include <ncurses.h>

namespace kittens {
class Module {
 public:
  Module();
  virtual ~Module();
  virtual void Render(WINDOW* window) = 0;
};

}  // namespace kittens

#endif /* INCLUDES_NMODULE_H_ */
