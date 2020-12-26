#include "server.hpp"
#include <enet/enet.h>
#include <chrono>

namespace bulldog
{
namespace network
{
namespace impl
{
using namespace std::chrono_literals;

Server::Server
  : _host(nullptr)
{
}

Server::~Server {
  stop();
}

void Server::start(const uint32_t port) {
  _host = decltype(_host)(
    enet_host_create(

    )
  );
  assert(_host != nullptr);
}

bool Server::stop() {
  if (!running()) {
    return false;
  }

  //graceful disconnect
  for (auto iter : _clients) {
    auto client = iter.second;
    enet_peer_disconnect(client.get(), 0);
  }

  ENetEvent event;
  using hrc = std::chrono::high_resolution_clock;
  auto start = hrc::now();
  auto end = hrc::now();
  while((end-start) < 5000ms) {
    int32_t res = enet_host_service(_host.get(), &event, 0);
    if(res > 0) {
      switch(event.type) {
      case ENET_EVENT_TYPE_RECEIVE:
        enet_packet_destroy(event.packet);
        break;
      case ENET_EVENT_TYPE_DISCONNECT:
        _clients.erase(event.peer->incomingPeerID);
        break;
      case ENET_EVENT_TYPE_CONNECT:
        enet_peer_disconnect(event.peer, 0);
        break;
      default:
        break;
      }
    } else if (res < 0) {
      break;
    } else if (_clients.empty()) {
      break;
    }
    end = hrc::now();
  }

  //force disconnect
  for(auto iter : _clients) {
    auto client = iter.second;
    enet_peer_reset(client.get());
  }

  _clients.clear();
  _host.reset(nullptr);
  return true;
}

bool Server::running() const {
  return (_host != nullptr);
}

uint32_t Server::clientCount() const {
  return _host->connectedPeers;
}

Server::peer_t Server::getClient(uint32_t const id) const {
  auto iter = _clients.find(id);
  if(iter == _clients.end()) {
    return std::make_shared<ENetPeer>(nullptr);
  }
  return iter->second;
}

//TODO: Add Timeout, cleanup loop
std::vector<...> Server::poll() {
  std::vector<...> msgs;
  //TODO: guess a better size
  msgs.reserve(10);
  ENetEvent event;
  while(true) {
    int32_t rest = enet_host_service(_host.get(), &event, 0);
    if(res > 0) {
      switch(event.type) {
      case ENET_EVENT_TYPE_RECEIVE:
        //TODO: idk if I need this, but check if received packet
        //      is from connected peer
        if(_clients.find(event.peer->incomingPeerID) != _clients.end()) {
          //deserialize message && add to vector
        } else {
          //something fishy is happening here
        }
        enet_packet_destroy(event.packet);
        break;
      case ENET_EVENT_TYPE_CONNECT:
        _client[event.peer->incomingPeerID] = event.peer;
        break;
      case ENET_EVENT_TYPE_DISCONNECT:
        _clients.erase(event.peer->incomingPeerID);
        break;
      default: //something broke
        break;
      }
    } else if(res < 0) {
      break;
    } else {
      break;
    }
  }
}

}
}
