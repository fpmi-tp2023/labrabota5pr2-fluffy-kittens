#ifndef INCLUDES_WINDOW_CREATORS_H_
#define INCLUDES_WINDOW_CREATORS_H_

#include "./nform.h"
#include "./nmenu.h"
#include "./nmessage.h"
#include "./nmodule_note.h"
#include "./nmodule_title.h"

namespace kittens {
shared_ptr<Menu> CreateMainMenu();
shared_ptr<Form> CreateSignUpForm();
shared_ptr<Menu> CreateAuthenthicationMenu();
shared_ptr<Form> CreateLoginForm();
shared_ptr<Message> CreateError(vector<string> lines,
                                shared_ptr<Window> parent = nullptr);
}  // namespace kittens

#endif /* INCLUDES_WINDOW_CREATORS_H_ */
