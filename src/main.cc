#include "../includes/nmenu.h"
#include "../includes/types.h"
#include "../includes/window_creators.h"
#include "../includes/window_manager.h"

using namespace kittens;

int main() {
    WindowManager& win_manager = *WindowManager::Instance();
    atexit(WindowManager::CleanUp);
    win_manager.ChangeWindow(CreateMainMenu());
    while (win_manager.WindowActive()) {
        win_manager.Update();
    }
    return 0;
}