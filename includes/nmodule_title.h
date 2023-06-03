#ifndef INCLUDES_NMODULE_TITLE_H_
#define INCLUDES_NMODULE_TITLE_H_

#include "./nrender_module.h"
#include "./types.h"

namespace kittens {
class TitleModule : RenderModule {
   public:
    TitleModule(string title);
    ~TitleModule();
    void Render(WINDOW* window) override;

   protected:
    string title_;
};

}  // namespace kittens

#endif /* INCLUDES_NMODULE_TITLE_H_ */
