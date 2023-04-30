#ifndef INCLUDES_NMENU_H_
#define INCLUDES_NMENU_H_

#include "../nwindow.h"
#include "../types.h"
#include "./menu_item.h"

namespace kittens {

class Menu : public Window {
    friend class MenuBuilder;

   public:
    Menu();
    ~Menu();
    void HandleInput() override;
    void Render() override;

   private:
    vector<MenuItem> items_;
    int selected_;
};

}  // namespace kittens

#endif /* INCLUDES_NMENU_H_ */
