#include "../includes/authenthication.h"

#include "authenthication.h"

namespace kittens {

AuthManager::AuthManager() {}

AuthManager::~AuthManager() {}

bool AuthManager::is_user_admin_ = false;

int AuthManager::AuthHash(string password) {
  return accumulate(password.begin(), password.end(), 0);
}

bool AuthManager::Authorize(string login, string password) {
  auto value = AuthHash(password);

  if (login.empty()) {
    return false;
  }

  sqlite3 *db;
  int rc = sqlite3_open("MusicSalonDatabase.db", &db);
  if (rc != SQLITE_OK) {
    cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
  }

  char **results = nullptr;
  int rows, columns;
  string query = "select hash from user where login = '" + login + "'";
  rc = sqlite3_get_table(db, query.c_str(), &results, &rows, &columns, nullptr);
  if (rc != SQLITE_OK) {
    cerr << "Query execution failed: " << sqlite3_errmsg(db) << endl;
    sqlite3_free_table(results);
    sqlite3_close(db);
  }

  if (rows == 0 || columns == 0) {
    return false;
  }

  if (!results[1]) {
    sqlite3_free_table(results);
    sqlite3_close(db);
    return false;
  }

  return stoi(string(results[1])) == value;
}

void AuthManager::Authenthicate(bool asAdmin) {
  AuthManager::is_user_admin_ = asAdmin;
}

bool AuthManager::IsUserAdmin() { return is_user_admin_; }

void AuthManager::SignUp(string login, string password) {
  sqlite3 *db;
  int rc = sqlite3_open("MusicSalonDatabase.db", &db);
  if (rc != SQLITE_OK) {
    cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
  }

  auto value = AuthManager::AuthHash(password);

  char *zErrMsg = 0;
  string sql;
  sql = "INSERT INTO USER(LOGIN, HASH, ROLE_ID) VALUES ('" + login + "', " +
        to_string(value) + ", 2);";
  rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &zErrMsg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }

  sqlite3_close(db);
}
}  // namespace kittens