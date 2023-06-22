#ifndef INCLUDES_AUTHENTHICATION_H_
#define INCLUDES_AUTHENTHICATION_H_

#include "./types.h"

namespace kittens {

class AuthManager {
 public:
  AuthManager();
  ~AuthManager();
  static int AuthHash(string password);
  static bool Authorize(string login, string password);
  static void Authenthicate(bool asAdmin = false);
  static bool IsUserAdmin();
  static void SignUp(string login, string password);

 protected:
  static bool is_user_admin_;
};

}  // namespace kittens

#endif /* INCLUDES_AUTHENTHICATION_H_ */
