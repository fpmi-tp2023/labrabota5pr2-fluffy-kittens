#ifndef INCLUDES_MENU_BUILDER_H_
#define INCLUDES_MENU_BUILDER_H_

#include "./nmenu.h"

namespace kittens {
class MenuBuilder {
   public:
    MenuBuilder();

    MenuBuilder& AddItem(string& label, const function<void()>& callback);

    operator Menu() const { return move(menu_); };

   private:
    Menu menu_;
};

}  // namespace kittens

#endif /* INCLUDES_MENU_BUILDER_H_ */
