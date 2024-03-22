#pragma once

#include <type_traits>

namespace code_fun {

template<class T>
class Comparable
{
protected:
    Comparable()
    {
        // static_assert(std::is_default_constructible<T>::value, "T must be default constructible");
        // static_assert(std::is_copy_constructible<T>::value, "T must be copy constructible");
        // static_assert(std::is_copy_assignable<T>::value, "T must be copy assignable");
        // static_assert(std::is_move_constructible<T>::value, "T must be move constructible");
        // static_assert(std::is_move_assignable<T>::value, "T must be move assignable");
        
        // 检查T是否支持比较操作
        static_assert(std::is_same<decltype(std::declval<T>() == std::declval<T>()), bool>::value, "T must support operator==");
        static_assert(std::is_same<decltype(std::declval<T>() != std::declval<T>()), bool>::value, "T must support operator!=");
        static_assert(std::is_same<decltype(std::declval<T>() < std::declval<T>()), bool>::value, "T must support operator<");
        static_assert(std::is_same<decltype(std::declval<T>() <= std::declval<T>()), bool>::value, "T must support operator<=");
        static_assert(std::is_same<decltype(std::declval<T>() > std::declval<T>()), bool>::value, "T must support operator>");
        static_assert(std::is_same<decltype(std::declval<T>() >= std::declval<T>()), bool>::value, "T must support operator>=");
    }
};





}