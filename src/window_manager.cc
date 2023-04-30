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

// nwindow_(newwin(10, 20, 0, 0), [](WINDOW* win) { delwin(win); })

void WindowManager::Update() {
    if (!current_window_) {
        return;
    }
    current_window_->Render(stdscr);
    wrefresh(stdscr);
    int ch = getch();
    current_window_->HandleInput(ch);
}

void WindowManager::ChangeWindow(unique_ptr<Window> next_window) {
    previous_window_ = std::move(current_window_);
    current_window_ = std::move(next_window);
}

void WindowManager::ReturnToPreviousWindow() {
    if (!previous_window_) {
        return;
    }
    current_window_ = std::move(previous_window_);
}

void WindowManager::CloseWindow() {
    previous_window_ = std::move(current_window_);
}

bool WindowManager::WindowActive() const {
    return (current_window_.get());
}
}  // namespace kittens