#ifndef INCLUDES_MENU_WINDOW_MANAGER_H_
#define INCLUDES_MENU_WINDOW_MANAGER_H_

#include "./nwindow.h"
#include "./types.h"

namespace kittens {
class WindowManager {
   public:
    WindowManager();
    void Update();
    void ChangeWindow(shared_ptr<Window> next_window);
    void ReturnToPreviousWindow();
    void CloseWindow();

   private:
    unique_ptr<Window> current_window_;
    unique_ptr<Window> previous_window_;
};
}  // namespace kittens

#endif /* INCLUDES_MENU_WINDOW_MANAGER_H_ */
