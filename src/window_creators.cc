#include "../includes/window_creators.h"

#include "../includes/form_field_confirm.h"
#include "../includes/window_manager.h"

namespace kittens {
shared_ptr<Form> CreateLoginForm() {
  auto loginForm = make_shared<Form>(nullptr);
  return loginForm;
}

shared_ptr<Form> CreateSignUpForm() {
  auto signUp = make_shared<Form>(
      nullptr);  // Debug value: change target window and validators

  auto loginField =
      make_unique<FormField>("Login", [](string s) { return true; });

  auto passwordField =
      make_unique<FormFieldSecret>("Password", [](string s) { return true; });

  signUp->AddField(move(loginField));
  signUp->AddField(move(passwordField));

  auto title = make_unique<TitleModule>("Authorization");

  vector<string> notesText = {"Press Enter to submit"};
  auto notes = make_unique<NoteModule>(notesText);

  signUp->AddModule(move(title));
  signUp->AddModule(move(notes));

  return signUp;
}

shared_ptr<Menu> CreateAuthenthicationMenu() {
  auto authMenu = make_shared<Menu>();

  auto loginForm = CreateLoginForm();

  auto goToLoginForm = [loginForm] {
    WindowManager::Instance()->ChangeWindow(loginForm);
  };

  auto goBack = [] { WindowManager::Instance()->ReturnToPreviousWindow(); };

  authMenu->AddItem("Guest", goToLoginForm);
  authMenu->AddItem("Admin", goToLoginForm);
  authMenu->AddItem("Back", goBack);

  auto title = make_unique<TitleModule>("Authenthication");

  vector<string> notesText = {
      "Note that admin user profiles are created by database admin"};
  auto notes = make_unique<NoteModule>(notesText);

  authMenu->AddModule(move(title));
  authMenu->AddModule(move(notes));

  return authMenu;
}

shared_ptr<Menu> CreateMainMenu() {
  auto mainMenu = make_shared<Menu>();

  auto signUpForm = CreateSignUpForm();
  auto authMenu = CreateAuthenthicationMenu();

  auto goToSignUpForm = [signUpForm] {
    WindowManager::Instance()->ChangeWindow(signUpForm);
  };

  auto goToAuthMenu = [authMenu] {
    WindowManager::Instance()->ChangeWindow(authMenu);
  };

  mainMenu->AddItem("Login", goToAuthMenu);
  mainMenu->AddItem("Sign Up", goToSignUpForm);
  mainMenu->AddItem("Exit", [] { WindowManager::Instance()->CloseWindow(); });

  auto title = make_unique<TitleModule>("Fluffy Kittens");

  vector<string> notesText = {
      "Made by A.Shpakovskiy, L.Shymkovich, T.Petrykevich"};
  auto notes = make_unique<NoteModule>(notesText);

  mainMenu->AddModule(move(title));
  mainMenu->AddModule(move(notes));

  return mainMenu;
}
}  // namespace kittens