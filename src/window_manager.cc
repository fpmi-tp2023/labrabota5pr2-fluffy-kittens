#include "../includes/window_manager.h"

#include <ncurses.h>

namespace kittens {

WindowManager* WindowManager::instance_ = nullptr;

WindowManager* WindowManager::Instance() {
    if (!instance_) {
        instance_ = new WindowManager();
    }
    return instance_;
}

void WindowManager::CleanUp() {
    if (!instance_) {
        return;
    }
    instance_->~WindowManager();
}

WindowManager::WindowManager() : current_window_(nullptr), previous_window_(nullptr) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

WindowManager::~WindowManager() {
    endwin();
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

void WindowManager::ChangeWindow(shared_ptr<Window> next_window) {
    previous_window_ = current_window_;
    current_window_ = next_window;
    clear();
}

void WindowManager::ReturnToPreviousWindow() {
    if (!previous_window_) {
        return;
    }
    current_window_ = previous_window_;
    clear();
}

void WindowManager::CloseWindow() {
    previous_window_ = current_window_;
    current_window_ = nullptr;
    clear();
}

bool WindowManager::WindowActive() const {
    return (current_window_.get());
}
}  // namespace kittens