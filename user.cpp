#include "user.h"

#include <boost/make_shared.hpp>

namespace ns
{
User::User()
{
    pointer = boost::make_shared<A<std::string>>("abc");
}

void User::call()
{
    pointer->call();
}
}