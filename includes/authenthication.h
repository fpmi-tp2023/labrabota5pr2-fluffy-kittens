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
  void AuthenthicateAsAdmin();
  bool IsUserAdmin() const;
  bool IsUserAuthorized() const;
  static void SignUp(string login, string password);

 protected:
  bool is_user_admin_;
  bool authorized_;
};

}  // namespace kittens

#endif /* INCLUDES_AUTHENTHICATION_H_ */
