#ifndef INCLUDES_AUTHENTHICATION_H_
#define INCLUDES_AUTHENTHICATION_H_

#include "./types.h"

namespace kittens {

class AuthManager {
 public:
  AuthManager();
  ~AuthManager();
  static int AuthHash(string password);
  bool Authorize(string login, string password);
  void AuthenthicateAsAdmin();
  bool IsUserAdmin() const;
  bool IsUserAuthorized() const;

 protected:
  bool is_user_admin_;
  bool authorized_;
};

}  // namespace kittens

#endif /* INCLUDES_AUTHENTHICATION_H_ */