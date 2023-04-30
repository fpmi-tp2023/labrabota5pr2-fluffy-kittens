#ifndef INCLUDES_NMENU_H_
#define INCLUDES_NMENU_H_

#include "../nwindow.h"
#include "../types.h"
#include "./menu_data.h"
#include "./menu_view.h"

namespace kittens {

class Menu : public Window {
    friend class MenuBuilder;

   public:
    Menu();
    ~Menu();
    void HandleInput() override;
    void Render() override;

   private:
    MenuData data_;
    int selected_;
};

}  // namespace kittens

#endif /* INCLUDES_NMENU_H_ */
