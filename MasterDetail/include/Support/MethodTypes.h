#ifndef METHODTYPES_H
#define METHODTYPES_H

#include <type_traits>

template <class T, typename R>
using Getter = R(T::*)() const;

template <class T, typename R>
using RefSetter = void(T::*)(const R&);

template <class T, typename R>
using Setter = void(T::*)(R);

template <class O, typename R>
using ChangedSignal = void(O::*)(R);


template <typename T>
using ThisType = typename std::remove_cv<typename std::remove_pointer<T>::type>::type;

#define this_t ThisType<decltype(this)>

#endif // METHODTYPES_H
