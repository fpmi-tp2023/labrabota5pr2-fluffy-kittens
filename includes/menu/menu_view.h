#ifndef INCLUDES_MENU_VIEW_H_
#define INCLUDES_MENU_VIEW_H_

#include "../types.h"

namespace kittens {

class MenuView {
   public:
    MenuView();
    void Render(int selected, vector<string_view>& items) const;
    void Render(int selected) const;

   private:
    vector<string_view>& items_cache_;
};

}  // namespace kittens

#endif /* INCLUDES_MENU_VIEW_H_ */
