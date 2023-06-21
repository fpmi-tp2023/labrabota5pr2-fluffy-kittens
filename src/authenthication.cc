#include "../includes/authenthication.h"

namespace kittens {
AuthManager::AuthManager() : is_user_admin_(false), authorized_(false) {}

int AuthManager::AuthHash(string password) {
  return accumulate(password.begin(), password.end(), 0);
}

bool AuthManager::Authorize(string login, string password) {
  // TO DO: make query for login and compare password hash with db hash
}

void AuthManager::AuthenthicateAsAdmin() { is_user_admin_ = true; }

bool AuthManager::IsUserAdmin() const { return is_user_admin_; }

bool AuthManager::IsUserAuthorized() const { return authorized_; }

}  // namespace kittens