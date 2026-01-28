#ifndef STACK_H
#define STACK_H

#include "Vector.h"

template <typename T>
class Stack : private Vector<T>
{
public:
	void push(const T& val)
	{
		Vector<T>::push_back(val);
	}

	void pop()
	{
		Vector<T>::pop_back();
	}

	const T& top() const
	{
		return Vector<T>::back();
	}

	size_t size() const
	{
		return Vector<T>::size();
	}

	bool empty() const
	{
		return Vector<T>::empty();
	}
};
#endif // STACK_H