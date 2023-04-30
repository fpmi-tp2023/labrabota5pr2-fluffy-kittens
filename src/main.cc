#include "../includes/nmenu.h"
#include "../includes/types.h"
#include "../includes/window_manager.h"

using namespace kittens;

int main() {
    WindowManager win_manager;
    Menu menu{"Main"};
    menu.AddItem("Item 1", [] { return; });
    menu.AddItem("Item 2", [] { return; });
    menu.AddItem("Item 3", [] { return; });
    menu.AddItem("Item 4", [] { return; });
    win_manager.ChangeWindow(make_unique<Menu>(menu));
    while (win_manager.WindowActive()) {
        win_manager.Update();
    }

    return 0;
}