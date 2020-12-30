#include <steamworks/steam_api.h>
#include <cstdint>
#include <cstdlib>

#include <iostream>

int32_t main(int argv, char* argc[]) {
  if ( SteamAPI_RestartAppIfNecessary( k_uAppIdInvalid )) {
    return EXIT_FAILURE;
  }

  if ( !SteamAPI_Init() ) {
    return EXIT_FAILURE;
  }

  std::cout << "Hello Client!" << std::endl;

  SteamAPI_Shutdown();

  return 0;
}
