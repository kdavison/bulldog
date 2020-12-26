#pragma once

#include <google/protobuf/message.h>

namespace bulldog
{
namespace network
{
template<bool>
struct IsLite { };

template<>
struct IsLite<true> {
  using message_t = ::google::protobuf::Message;
}

template<>
struct IsLite<false> {
  using message_t = ::google::protobuf::MessageLite;
}


}
}
