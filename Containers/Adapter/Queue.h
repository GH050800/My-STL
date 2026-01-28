#ifndef QUEUE_H
#define QUEUE_H

#include "Vector.h"

template <typename T>
class Queue : private Vector<T>
{
public:
	void push(const T& val)
	{
		Vector<T>::push_back(val);
	}

	const T& front() const
	{
		return Vector<T>::front();
	}

	const T& back() const
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

#endif // QUEUE_H