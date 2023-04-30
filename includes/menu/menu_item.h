#ifndef INCLUDES_MENU_DATA_H_
#define INCLUDES_MENU_DATA_H_

#include "../types.h"

namespace kittens {
class MenuItem {
   public:
    explicit MenuItem(string& label, function<void()>& callback);
    string_view View() const;
    void Execute() const;
    void Render(int x, int y) const;

   private:
    string label_;
    function<void()> callback_;
};

}  // namespace kittens

#endif /* INCLUDES_MENU_DATA_H_ */
