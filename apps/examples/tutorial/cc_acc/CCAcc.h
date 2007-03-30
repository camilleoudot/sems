#include "AmApi.h"

/**
 * accounting class for calling card.
 * this illustrates the DI interface
 * and component modules
 */
class CCAcc : public AmDynInvoke

{
  /** returns credit for pin, -1 if pin wrong */
  int getCredit(string pin);
  /** returns remaining credit */
  int subtractCredit(string pin, int amount);
  
  map<string, unsigned int> credits;
  // as this is used from various sessions,
  // it must be protected by a mutex
  AmMutex credits_mut;

  static CCAcc* _instance;
 public:
  CCAcc();
  ~CCAcc();
  static CCAcc* instance();
  void invoke(const string& method, const AmArgArray& args, AmArgArray& ret);
};
