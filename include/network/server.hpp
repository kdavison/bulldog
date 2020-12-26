#pragma once

#include "network/iserver.hpp"
#include <enet/enet.h>
#include <unordered_map>
#include <memory>


namespace bulldog
{
namespace network
{
namespace impl
{
class Server final
  : public ::bulldog::network::iServer
{
public:
  std::shared_ptr<ENetPeer> client_t;
public:
  Server();
  ~Server();

  void start(uint32_t const) override;
  bool stop() override;
  bool running() const = 0;

  uint32_t clientCount() const override;

  void send(uint32_t, ::bulldog::network::DeliveryType, ...) const override;
  void broadcast(::bulldog::network::DeliveryType, ...) const override;

  std::vector<...> receive(std::chrono::milliseconds const&) override;
private:
  client_t getClient(uint32_t const) const;
  std::unordered_map<uint32_t, client_t> _clients;

  std::unique_ptr<ENetHost, [](ENetHost* p) { enet_host_destroy(p); }> _host;
};
}
}
}
