#include "../includes/window_creators.h"

#include "../includes/authenthication.h"
#include "../includes/form_field_confirm.h"
#include "../includes/types.h"
#include "../includes/validators.h"
#include "../includes/window_manager.h"

namespace kittens {

shared_ptr<Menu> CreateGuestMenu() {
  auto loginMenu = make_shared<Menu>();
  auto title = make_unique<TitleModule>("Getting information module");

  vector<string> notesText = {"To quit the user press Tab"};
  auto notes = make_unique<NoteModule>(notesText);

  loginMenu->AddModule(move(title));
  loginMenu->AddModule(move(notes));

  auto mostSold = CreateMostSoldQuery();
  auto goToMostSold = [mostSold] {
    WindowManager::Instance()->ChangeWindow(mostSold);
  };

  auto mostPopularPerf = CreateMostPopularPerformerQuery();
  auto goToMostPopularPerf = [mostPopularPerf] {
    WindowManager::Instance()->ChangeWindow(mostPopularPerf);
  };

  loginMenu->AddItem("Most Sold CD", goToMostSold);
  loginMenu->AddItem("Most popular performer", goToMostPopularPerf);
  return loginMenu;
}

shared_ptr<Menu> CreateAdminMenu() {
  auto loginMenu = make_shared<Menu>();
  auto title = make_unique<TitleModule>("Getting information module");

  vector<string> notesText = {"To quit the user press Tab"};
  auto notes = make_unique<NoteModule>(notesText);

  loginMenu->AddModule(move(title));
  loginMenu->AddModule(move(notes));
  auto allCD = CreateAllCdQuery();
  auto goToAllCD = [allCD] { WindowManager::Instance()->ChangeWindow(allCD); };

  auto sales = CreateSpecialCDQuery();
  auto goToSales = [sales] { WindowManager::Instance()->ChangeWindow(sales); };

  auto mostSold = CreateMostSoldQuery();
  auto goToMostSold = [mostSold] {
    WindowManager::Instance()->ChangeWindow(mostSold);
  };

  auto mostPopularPerf = CreateMostPopularPerformerQuery();
  auto goToMostPopularPerf = [mostPopularPerf] {
    WindowManager::Instance()->ChangeWindow(mostPopularPerf);
  };

  auto authorsInfo = CreateAuthorsInformationQuery();
  auto goToAuthorsInfo = [authorsInfo] {
    WindowManager::Instance()->ChangeWindow(authorsInfo);
  };

  loginMenu->AddItem("All CDs", goToAllCD);
  loginMenu->AddItem("Sales", goToSales);
  loginMenu->AddItem("Most Sold CD", goToMostSold);
  loginMenu->AddItem("Most popular performer", goToMostPopularPerf);
  loginMenu->AddItem("All authors information", goToAuthorsInfo);
  return loginMenu;
}

shared_ptr<Form> CreateLoginForm() {
  auto loginSubmit = [](vector<string> values) {
    bool authorized = AuthManager::Authorize(values[0], values[1]);
    if (authorized) {
      if (AuthManager::IsUserAdmin()) {
        WindowManager::Instance()->ChangeWindow(CreateAdminMenu());
      } else {
        WindowManager::Instance()->ChangeWindow(CreateGuestMenu());
      }

    } else {
      WindowManager::Instance()->ChangeWindow(
          CreateError({"Invalid login or password"}));
    }
    return;
  };

  auto loginForm = make_shared<Form>(loginSubmit);

  auto loginField =
      make_unique<FormField>("Login", ":(", [](string s) { return true; });

  auto passwordField =
      make_unique<FormFieldSecret>("Password", "Your password contains ",
                                   [](string s) { return IsPasswordValid(s); });

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
  auto signUpSubmit = [](vector<string> values) {
    AuthManager::SignUp(values[0], values[1]);
    return;
  };

  auto signUp = make_shared<Form>(signUpSubmit);

  auto loginField = make_unique<FormField>(
      "Login", "Invalid login: it must contain only latin characters",
      [](string s) { return true; });

  auto passwordField =
      make_unique<FormFieldSecret>("Password",
                                   "Your password is too short, it may be "
                                   "unsafe: make it 8 characters at least",
                                   [](string s) { return IsPasswordValid(s); });

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

  auto authAsGuest = [loginForm] {
    AuthManager::Authenthicate();
    WindowManager::Instance()->ChangeWindow(loginForm);
  };

  auto authAsAdmin = [loginForm] {
    AuthManager::Authenthicate(true);
    WindowManager::Instance()->ChangeWindow(loginForm);
  };

  auto goBack = [] { WindowManager::Instance()->ReturnToPreviousWindow(); };

  authMenu->AddItem("Guest", authAsGuest);
  authMenu->AddItem("Admin", authAsAdmin);
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

shared_ptr<Query> CreateQuery(string query, vector<int> growFactors,
                              string title, vector<string> notes) {
  vector<string> headers;
  sqlite3* db;
  int rc = sqlite3_open("MusicSalonDatabase.db", &db);
  if (rc != SQLITE_OK) {
    cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
  }

  char** results = nullptr;
  int rows, columns;
  rc = sqlite3_get_table(db, query.c_str(), &results, &rows, &columns, nullptr);

  if (rc != SQLITE_OK) {
    cerr << "Query execution falied: " << sqlite3_errmsg(db) << endl;
    sqlite3_free_table(results);
    sqlite3_close(db);
  }

  for (int i = 0; i < columns; i++) {
    headers.push_back(results[i]);
  }

  auto queryWindow = make_shared<Query>(headers, growFactors);

  for (int i = 1; i < rows + 1; ++i) {
    vector<string> row;
    for (int j = 0; j < columns; ++j) {
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
  const char* query =
      "SELECT cd.ID AS CompactDisc_ID, cd.Name AS CompactDisc_Name,(SELECT "
      "SUM(Amount) FROM DiscOperation WHERE CompactDisc_ID = cd.ID AND "
      "Operation_ID = 2) AS Sold, (SELECT SUM(Amount) FROM DiscOperation WHERE "
      "CompactDisc_ID = cd.ID AND Operation_ID = 1) AS Delivered, ((SELECT "
      "SUM(Amount) FROM DiscOperation WHERE CompactDisc_ID = cd.ID AND "
      "Operation_ID = 1) - (SELECT SUM(Amount) FROM DiscOperation WHERE "
      "CompactDisc_ID = cd.ID AND Operation_ID = 2)) AS LeftInStock FROM "
      "CompactDisc cd ORDER BY LeftInStock DESC;";
  return CreateQuery(query, {1, 1, 1, 1, 1}, "ALL CD");
}

shared_ptr<Query> CreateSpecialCDQuery() {
  const char* query =
      "SELECT cd.Name AS CompactDisc_Name, SUM(do.Amount) AS SoldQuantity, "
      "SUM(do.Amount * cd.Price) AS TotalPrice FROM CompactDisc cd INNER JOIN "
      "DiscOperation do ON cd.ID = do.CompactDisc_ID INNER JOIN Operation o ON "
      "do.Operation_ID = o.ID WHERE cd.ID = 1 AND do.Operation_Date BETWEEN "
      "'2023-06-11' AND '2023-06-17' AND o.Name = 'Sale' GROUP BY cd.Name;";
  return CreateQuery(query, {1, 1, 1, 1, 1}, "Sales");
}

shared_ptr<Query> CreateMostSoldQuery() {
  const char* query =
      "SELECT cd.Name AS CompactDisc_Name, cd.Manufacturer, cd.Price, "
      "cd.Production_Date, mc.Name AS MusicalComposition_Name, a.Name AS "
      "Author_Name, p.Name AS Performer_Name, do.TotalSold FROM (SELECT "
      "CompactDisc_ID, SUM(Amount) AS TotalSold FROM DiscOperation WHERE "
      "Operation_ID = (SELECT ID FROM Operation WHERE Name = 'Sale') GROUP BY "
      "CompactDisc_ID HAVING SUM(Amount) = (SELECT SUM(Amount) AS TotalSold "
      "FROM DiscOperation WHERE Operation_ID = (SELECT ID FROM Operation WHERE "
      "Name = 'Sale') GROUP BY CompactDisc_ID ORDER BY TotalSold DESC LIMIT "
      "1)) AS do INNER JOIN CompactDisc cd ON do.CompactDisc_ID = cd.ID INNER "
      "JOIN MusicalComposition mc ON cd.ID = mc.CompactDisc_ID INNER JOIN "
      "Author a ON mc.Author_ID = a.ID INNER JOIN Performer p ON "
      "mc.Performer_ID = p.ID ORDER BY do.TotalSold DESC, cd.Name ASC;";
  return CreateQuery(query, {2, 1, 1, 1, 2, 1, 1, 1}, "Most sold CD");
}

shared_ptr<Query> CreateMostPopularPerformerQuery() {
  const char* query =
      "SELECT p.Name AS Performer_Name, SUM(do.Amount) AS "
      "TotalCompactDiscsSold FROM DiscOperation do INNER JOIN CompactDisc cd "
      "ON do.CompactDisc_ID = cd.ID INNER JOIN MusicalComposition mc ON cd.ID "
      "= mc.CompactDisc_ID INNER JOIN Performer p ON mc.Performer_ID = p.ID "
      "WHERE do.Operation_ID = 2 GROUP BY p.Name ORDER BY "
      "TotalCompactDiscsSold DESC LIMIT 1;";
  return CreateQuery(query, {2, 1}, "Most Popular Performer");
}

shared_ptr<Query> CreateAuthorsInformationQuery() {
  const char* query =
      "SELECT a.Name AS Author_Name, SUM(do.Amount) AS TotalCompactDiscsSold, "
      "SUM(cd.Price * do.Amount) AS TotalRevenue FROM Author a INNER JOIN "
      "MusicalComposition mc ON a.ID = mc.Author_ID INNER JOIN CompactDisc cd "
      "ON mc.CompactDisc_ID = cd.ID INNER JOIN DiscOperation do ON cd.ID = "
      "do.CompactDisc_ID WHERE do.Operation_ID = 2 GROUP BY a.Name;";
  return CreateQuery(query, {2, 1, 1}, "All Authors");
}

}  // namespace kittens