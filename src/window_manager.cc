#include "../includes/window_manager.h"

#include <ncurses.h>

namespace kittens {
WindowManager::WindowManager() : current_window_(nullptr), previous_window_(nullptr) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void WindowManager::Update() {
    if (!current_window_) {
        return;
    }
    clear();
    current_window_->Render();
    current_window_->HandleInput();
    refresh();
}

void WindowManager::ChangeWindow(unique_ptr<Window> next_window) {
    previous_window_ = move(current_window_);
    current_window_ = move(next_window);
}

void WindowManager::ReturnToPreviousWindow() {
    if (!previous_window_) {
        return;
    }
    current_window_ = move(previous_window_);
}

void WindowManager::CloseWindow() {
    previous_window_ = move(current_window_);
}
}  // namespace kittens