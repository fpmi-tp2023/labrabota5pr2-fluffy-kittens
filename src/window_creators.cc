#include "../includes/window_creators.h"

#include "../includes/form_field_confirm.h"
#include "../includes/window_manager.h"

namespace kittens {
shared_ptr<Form> CreateLoginForm() {
  auto loginSubmit = [] { return; };

  auto loginForm = make_shared<Form>(loginSubmit);

  auto loginField =
      make_unique<FormField>("Login", ":(", [](string s) { return true; });

  auto passwordField = make_unique<FormFieldSecret>(
      "Password", ":)", [](string s) { return true; });

  loginForm->AddField(move(loginField));
  loginForm->AddField(move(passwordField));

  auto title = make_unique<TitleModule>("Authentication");

  vector<string> notesText = {"Press Enter to authenticate",
                              "Or Tab to cancel"};
  auto notes = make_unique<NoteModule>(notesText);

  loginForm->AddModule(move(title));
  loginForm->AddModule(move(notes));

  return loginForm;
}

shared_ptr<Form> CreateSignUpForm() {
  auto signUpSubmit = [] { return; };

  auto signUp = make_shared<Form>(signUpSubmit);

  auto loginField = make_unique<FormField>(
      "Login", "Invalid login: it must contain only latin characters",
      [](string s) { return true; });

  auto passwordField =
      make_unique<FormFieldSecret>("Password",
                                   "Your password is too short, it may be "
                                   "unsafe: make it 8 characters at least",
                                   [](string s) { return true; });

  signUp->AddField(move(loginField));
  signUp->AddField(move(passwordField));

  auto title = make_unique<TitleModule>("Authorization");

  vector<string> notesText = {"Press Enter to authenticate",
                              "Or Tab to cancel"};
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

  // Debug Query

  auto debugQuery = CreateQuery();

  auto goToDebugQuery = [debugQuery] {
    WindowManager::Instance()->ChangeWindow(debugQuery);
  };

  mainMenu->AddItem("Debug Query", goToDebugQuery);

  mainMenu->AddItem("Login", goToAuthMenu);
  mainMenu->AddItem("Sign Up", goToSignUpForm);
  mainMenu->AddItem("Exit", [] { WindowManager::Instance()->CloseWindow(); });

  auto title = make_unique<TitleModule>("Fluffy Kittens");

  vector<string> notesText = {
      "Made by A.Shpakovski, L.Shymkovich, T.Petrykevich"};
  auto notes = make_unique<NoteModule>(notesText);

  mainMenu->AddModule(move(title));
  mainMenu->AddModule(move(notes));

  return mainMenu;
}

shared_ptr<Message> CreateError(vector<string> lines,
                                shared_ptr<Window> parent) {
  auto message = make_shared<Message>(lines, parent);
  auto title = make_unique<TitleModule>("Error");
  message->AddModule(move(title));
  return message;
}

shared_ptr<Query> CreateQuery() {
  vector<string> headers{"a", "b", "c"};
  vector<int> grow_factors{3, 4, 5};
  auto query = make_shared<Query>(headers, grow_factors);

  for (int i = 0; i < 20; i++) {
    vector<string> row{to_string(i), to_string(i * 2), to_string(i * 3)};
    query->AddRow(make_unique<QueryRow>(row));
  }

  return query;
};

}  // namespace kittens