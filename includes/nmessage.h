#ifndef INCLUDES_NMESSAGE_H_
#define INCLUDES_NMESSAGE_H_

#include "./nwindow.h"
#include "./types.h"

namespace kittens {
class Message : public Window {
 public:
  Message(vector<string> lines, shared_ptr<Window> parent);
  ~Message();
  void HandleInput(int ch);
  void Render(WINDOW *window);
  void CleanUp();
  void SplitText(vector<string> lines);

 protected:
  vector<string> lines_;
  shared_ptr<Window> parent_;
  mutable vector<string> render_lines_;
  mutable int window_width_;
};
}  // namespace kittens

#endif /* INCLUDES_NMESSAGE_H_ */
