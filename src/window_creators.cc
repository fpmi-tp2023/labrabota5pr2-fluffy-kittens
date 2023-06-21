#include "../includes/window_creators.h"

#include "../includes/form_field_confirm.h"
#include "../includes/window_manager.h"
#include "../includes/types.h"


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

  auto debugQuery = CreateAllCdQuery();  // change this to test

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
  
  vector<string> headers = {"a" , "b"};
  vector<int> grow_factors = {1, 1};
  auto query = make_shared<Query>(headers, grow_factors);
  for (int i = 0; i < 20; i++) {
    vector<string> row{to_string(i), to_string(i * 2)};
    query->AddRow(make_unique<QueryRow>(row));
  }

  return query;
}

shared_ptr<Query> CreateQuery(string query, string title,
                              vector<string> notes) {}

shared_ptr<Query> CreateQuery(string query, vector<int> growFactors,
                              string title, vector<string> notes) {
  vector<string> headers;
  sqlite3 *db;
  int rc = sqlite3_open("MusicSalonDatabase.db", &db);
  if (rc != SQLITE_OK) {
    cerr<<"Cannot open database: "<< sqlite3_errmsg(db)<<endl;
  }

  char **results = nullptr;
  int rows, columns;
  rc = sqlite3_get_table(db, query.c_str(), &results, &rows, &columns, nullptr);

  if (rc != SQLITE_OK) {
    cerr<<"Query execution falied: " << sqlite3_errmsg(db)<<endl;
    sqlite3_free_table(results);
    sqlite3_close(db);
  }

  for(int i = 0; i < columns; i++) {
    headers.push_back(results[i]);
  }

  auto queryWindow = make_shared<Query>(headers, growFactors);

  for(int i = 1; i < rows + 1; ++i) {
    vector<string> row;
    for(int j = 0; j < columns; ++j) {
      row.push_back(results[i * columns + j]);
    }
    queryWindow->AddRow(make_unique<QueryRow>(row));
  }

  sqlite3_free_table(results);
  sqlite3_close(db);

  if (!title.empty()) {
    auto titleModule = make_unique<TitleModule>(title);
    queryWindow->AddModule(move(titleModule));
  }

  if (!notes.empty()) {
    auto noteModule = make_unique<NoteModule>(notes);
    queryWindow->AddModule(move(noteModule));
  }

  return queryWindow;
};

shared_ptr<Query> CreateAllCdQuery() {
  const char *query = "SELECT cd.ID AS CompactDisc_ID, cd.Name AS CompactDisc_Name,(SELECT SUM(Amount) FROM DiscOperation WHERE CompactDisc_ID = cd.ID AND Operation_ID = 2) AS Sold, (SELECT SUM(Amount) FROM DiscOperation WHERE CompactDisc_ID = cd.ID AND Operation_ID = 1) AS Delivered, ((SELECT SUM(Amount) FROM DiscOperation WHERE CompactDisc_ID = cd.ID AND Operation_ID = 1) - (SELECT SUM(Amount) FROM DiscOperation WHERE CompactDisc_ID = cd.ID AND Operation_ID = 2)) AS LeftInStock FROM CompactDisc cd ORDER BY LeftInStock DESC;";
  return CreateQuery(query, {1, 1, 1, 1, 1}, "ALL CD");
}

}  // namespace kittens