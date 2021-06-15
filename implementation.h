#pragma once

#include "interface.h"

#include <iostream>
#include <typeinfo>

namespace ns
{
template <class T>
class A : public InterfaceOfA
{
public:
    A(T val);
    virtual void call();

private:
    T data;
};

template <class T>
A<T>::A(T val) : data(val)
{}

template <class T>
void A<T>::call()
{
    std::cout << "TypeID = " << typeid(A<T>).name() << std::endl;
    std::cout << typeid(&A<T>::call).name() << std::endl;
    std::cout << "Here is the call(): " << data << std::endl;
}
}