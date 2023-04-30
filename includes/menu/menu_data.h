#ifndef INCLUDES_MENU_DATA_H_
#define INCLUDES_MENU_DATA_H_

#include "../types.h"

namespace kittens {
class MenuItem {
   public:
    MenuItem(string& label, function<void()>& callback);
    string_view View() const;
    void Execute() const;

   private:
    string label_;
    function<void()> callback_;
};

class MenuData {
   public:
    MenuData();
    const vector<string_view>& ViewItems() const;
    void ExecuteItem(int index) const;

   private:
    vector<MenuItem> items_;
};
}  // namespace kittens

#endif /* INCLUDES_MENU_DATA_H_ */
