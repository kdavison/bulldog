#pragma once
#include <utility/copyable.hpp>
#include <string>
#include <cstdint>

namespace bulldog
{
namespace network
{
class iClient
  : public ::bulldog::utility::copyable<false>
{
public:
  iClient() = default;
  virtual ~iClient() = default;

  virtual bool connect(std::string const&, uint32_t const) = 0;
  virtual bool disconnect() = 0;
  virtual bool connected() const = 0;

  virtual void send(..., ...) const = 0;
  virtual ... request(uint32_t const, ...) = 0;
  virtual std::vector<...> poll() = 0;

  virtual on(uint32_t const, ...) = 0;
};
}
}
