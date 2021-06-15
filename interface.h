#pragma once

#include <boost/shared_ptr.hpp>

namespace ns 
{
class InterfaceOfA
{
public:
    virtual void call() = 0;
};

typedef boost::shared_ptr<InterfaceOfA> APtr;
}
