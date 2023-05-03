#ifndef INCLUDES_MENU_WINDOW_MANAGER_H_
#define INCLUDES_MENU_WINDOW_MANAGER_H_

#include "./nwindow.h"
#include "./types.h"

namespace kittens {
class WindowManager {
   public:
    static WindowManager* Instance();
    static void CleanUp();
    void Update();
    void ChangeWindow(unique_ptr<Window> next_window);
    void ReturnToPreviousWindow();
    void CloseWindow();
    bool WindowActive() const;

   private:
    static WindowManager* instance_;
    WindowManager();
    ~WindowManager();
    unique_ptr<Window> current_window_;
    unique_ptr<Window> previous_window_;
};
}  // namespace kittens

#endif /* INCLUDES_MENU_WINDOW_MANAGER_H_ */
