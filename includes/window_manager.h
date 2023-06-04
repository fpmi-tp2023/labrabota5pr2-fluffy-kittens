#ifndef INCLUDES_MENU_WINDOW_MANAGER_H_
#define INCLUDES_MENU_WINDOW_MANAGER_H_

#include "./nwindow.h"
#include "./types.h"

namespace kittens {
class WindowManager {
 public:
  static WindowManager* Instance();
  static void CleanUp();
  void ChangeWindow(shared_ptr<Window> next_window);
  void Update();
  void ReturnToPreviousWindow();
  void CloseWindow();
  bool WindowActive() const;

 private:
  static WindowManager* instance_;
  WindowManager();
  ~WindowManager();
  shared_ptr<Window> current_window_;
  stack<shared_ptr<Window>> previous_windows_;
  int clearBuffer;
  const int clearRate = 5;
};
}  // namespace kittens

#endif /* INCLUDES_MENU_WINDOW_MANAGER_H_ */
