#include "../includes/nmenu.h"
#include "../includes/types.h"
#include "../includes/window_manager.h"

using namespace kittens;

int main() {
    WindowManager& win_manager = *WindowManager::Instance();
    atexit(WindowManager::CleanUp);
    Menu menu{"Main"};
    menu.AddItem("Login", [] { return; });
    menu.AddItem("Sign Up", [] { return; });
    menu.AddItem("Exit", [] { WindowManager::Instance()->CloseWindow(); });
    win_manager.ChangeWindow(make_unique<Menu>(menu));
    while (win_manager.WindowActive()) {
        win_manager.Update();
    }

    return 0;
}