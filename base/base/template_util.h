#pragma once

//#include <type_traits>

namespace code_fun {

template <class T, template <class...> class TM>
struct is_specialization_of_template : std::false_type {};
template <template <class...> class TM, class... TArgs>
struct is_specialization_of_template<TM<TArgs...>, TM> : std::true_type {};


template <template <class...> class TM>
std::false_type _is_derived_from_template_impl(...) {};
template <template <class...> class TM, class... TArgs>
std::true_type _is_derived_from_template_impl(TM<TArgs...>*) {};
// 如果T*可以转化为TM<>*，则说明T继承自TM
template <class T, template <class...> class TM>
using is_derived_from_template = decltype(
    _is_derived_from_template_impl<TM>(
        std::declval<T*>()
    )
);


}