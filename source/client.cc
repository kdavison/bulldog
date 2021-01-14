#include <steamworks/steam_api.h>

#include <cstdint>
#include "utility/latch.hpp"
#include <thread>
#include <chrono>
#include <iostream>

int32_t main(int argv, char* argc[]) {
  // if ( SteamAPI_RestartAppIfNecessary( k_uAppIdInvalid )) {
  //   return EXIT_FAILURE;
  // }
  //
  // if ( !SteamAPI_Init() ) {
  //   return EXIT_FAILURE;
  // }
  //
  // std::cout << "Hello Client!" << std::endl;
  //
  // SteamAPI_Shutdown();

  const int32_t count(15);

  ::bulldog::utility::latch done( count );

  std::cout << "START!" << std::endl;

  using namespace std::chrono_literals;

  std::thread threads[count];
  for(int32_t i(0); i < count; ++i) {
    threads[i] = std::thread([&, i, count]() {
      std::cout << '(' << (i+1) << '/' << count << ')' << "hello!" << std::endl;
      done.count_down();
      std::this_thread::sleep_for(5ms);
    });
  }

  done.wait();

  for(int32_t i(0); i < count; ++i) {
    threads[i].join();
  }

  std::cout << "DONE!" << std::endl;

  return 0;
}
