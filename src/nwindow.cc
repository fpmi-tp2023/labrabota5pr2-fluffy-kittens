#include "../includes/nwindow.h"
namespace kittens {
void Window::AddModule(unique_ptr<Module> module) {
  modules_.push_back(move(module));
}

void Window::RenderModules(WINDOW *window) {
  for (auto &module : modules_) {
    module->Render(window);
  }
}
} // namespace kittens