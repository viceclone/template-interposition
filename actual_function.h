#pragma once
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <dlfcn.h>
#include <string>
#include <cstring>

namespace actual_function {

template <class C, class ReturnType, typename... Arguments>
using mem_func_ptr = ReturnType(*)(C*, Arguments...);

template <typename FunctionPtr>
FunctionPtr get_ptr(const std::string& symbol_name) {
    const void* symbol_address{ dlsym(RTLD_NEXT, symbol_name.c_str()) };

    FunctionPtr actual_function{};
    std::memcpy(&actual_function, &symbol_address, sizeof(symbol_address));

    return actual_function;
}

}; // namespace actual_function

namespace actual_function_const {

template <class C, class ReturnType, typename... Arguments>
using mem_func_ptr = ReturnType(*)(const C*, Arguments...);

template <typename FunctionPtr>
FunctionPtr get_ptr(const std::string& symbol_name) {
    const void* symbol_address{ dlsym(RTLD_NEXT, symbol_name.c_str()) };

    FunctionPtr actual_function{};
    std::memcpy(&actual_function, &symbol_address, sizeof(symbol_address));

    return actual_function;
}

} // namespace actual_function_const
