#pragma once

#include "interface.h"
#include "actual_function.h"

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
    std::cout << "[PREFIX] Here is the interposed call(): " << std::endl;
    static actual_function::mem_func_ptr
            <A<T>,
            void >
        actual_function;
    if (!actual_function)
    {
        actual_function = actual_function::get_ptr<decltype(actual_function)>("_ZN2ns1AINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4callEv");
    }
    // std::cout << "TypeID = " << typeid(A<T>).name() << std::endl;
    // std::cout << typeid(&A<T>::call).name() << std::endl;
    
    actual_function(this);

    std::cout << "[SUFFIX] Here is the interposed call(): " << std::endl;
}
}
