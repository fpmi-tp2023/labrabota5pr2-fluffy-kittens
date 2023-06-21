#include "../includes/authenthication.h"

namespace kittens {
AuthManager::AuthManager() : is_user_admin_(false), authorized_(false) {}

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
    cerr<<"Cannot open database: "<<sqlite3_errmsg(db)<<endl;
  }

  char **results = nullptr;
  int rows, columns;
  string query = "select hash from user where login = '" + login + "'";
  rc = sqlite3_get_table(db, query.c_str(), &results, &rows, &columns, nullptr);
  if (rc != SQLITE_OK) {
    cerr<<"Query execution failed: "<<sqlite3_errmsg(db)<<endl;
    sqlite3_free_table(results);
    sqlite3_close(db);
  }
  

  if (!results[1]) {
    sqlite3_free_table(results);
    sqlite3_close(db);
    return false;
  }

  return stoi(results[1]) == value;
}

void AuthManager::AuthenthicateAsAdmin() { is_user_admin_ = true; }

bool AuthManager::IsUserAdmin() const { return is_user_admin_; }

bool AuthManager::IsUserAuthorized() const { return authorized_; }

}  // namespace kittens