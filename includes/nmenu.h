#ifndef INCLUDES_NMENU_H_
#define INCLUDES_NMENU_H_

#include "./menu_item.h"
#include "./nwindow.h"
#include "./types.h"

namespace kittens {

class Menu : public Window {
   public:
    Menu(string title);
    ~Menu();
    void HandleInput(int ch) override;
    void Render(WINDOW* window) override;
    void AddItem(string label, function<void()> callback);

   private:
    mutable int max_label_length_;
    vector<MenuItem> items_;
    string title_;
    int selected_;
};

}  // namespace kittens

#endif /* INCLUDES_NMENU_H_ */
