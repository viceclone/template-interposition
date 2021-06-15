#pragma once 

#include "implementation.h"

#include <string>

namespace ns
{
class User
{
public: 
    User();
    void call();
private:
    APtr pointer;
};
}