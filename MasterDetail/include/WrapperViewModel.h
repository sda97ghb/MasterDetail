#ifndef WRAPPERVIEWMODEL_H
#define WRAPPERVIEWMODEL_H

#include "Support/MethodTypes.h"

template <class Wrapped_t>
class WrapperViewModel {
protected:
	template <typename R>
	bool updateWrapped(Getter<Wrapped_t, R> getter, RefSetter<Wrapped_t, R> setter, const R& v) {
		return updateWrapped<Wrapped_t>(wrapped(), getter, setter, v);
	}

	template <typename R>
	bool updateWrapped(Getter<Wrapped_t, R> getter, Setter<Wrapped_t, R> setter, const R& v) {
		return updateWrapped<Wrapped_t>(wrapped(), getter, setter, v);
	}

	virtual Wrapped_t* wrapped() const = 0;

private:
	template <class T, typename R, typename Getter_t, typename Setter_t>
	bool updateWrappedImpl(T* o, Getter_t getter, Setter_t setter, const R& v) {
		R oldValue = (o->*getter)();
		(o->*setter)(v);
		return (o->*getter)() != oldValue;
	}

	template <class T, typename R>
	bool updateWrapped(T* o, Getter<T, R> getter, RefSetter<T, R> setter, const R& v) {
		return updateWrappedImpl(o, getter, setter, v);
	}

	template <class T, typename R>
	bool updateWrapped(T* o, Getter<T, R> getter, Setter<T, R> setter, const R& v) {
		return updateWrappedImpl(o, getter, setter, v);
	}
};

#endif // WRAPPERVIEWMODEL_H
