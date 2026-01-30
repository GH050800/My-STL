#ifndef VECTOR_H
#define VECTOR_H

namespace my
{
template <typename T>
class Vector
{
private:
	T* m_data;
	size_t m_size;
	size_t m_cap;

public:
	Vector() : m_data(nullptr), m_size(0), m_cap(0) {};

	Vector(size_t s) : m_size(s), m_cap(s), m_data(new T[s]) {}

	Vector(std::initializer_list<T> initList) : m_size(initList.size()), m_cap(initList.size())
	{
		m_data = new T[m_cap];

		const T* ptr = initList.begin();

		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = ptr[i];
		}
	}

	Vector(const Vector& other) : m_size(other.m_size), m_cap(other.m_cap)
	{
		m_data = new T[m_cap];

		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}
	}

	Vector& operator=(const Vector& other)
	{
		if (this != &other)
		{
			delete[] m_data;

			m_size = other.m_size;
			m_cap = other.m_cap;
			m_data = new T[m_cap];

			for (size_t i = 0; i < m_size; i++)
			{
				m_data[i] = other.m_data[i];
			}
		}
		return *this;
	}

	Vector(Vector&& other) : m_data(other.m_data), m_size(other.m_size), m_cap(other.m_cap)
	{
		other.m_data = nullptr;
		other.m_size = 0;
		other.m_cap = 0;
	}

	Vector& operator=(Vector&& other)
	{
		if (this != &other)
		{
			delete[] m_data;

			m_data = other.m_data;
			m_size = other.m_size;
			m_cap = other.m_cap;

			other.m_data = nullptr;
			other.m_size = 0;
			other.m_cap = 0;
		}
		return *this;
	}

	~Vector()
	{
		delete[] m_data;
	}

public:
	void push_back(const T& value)
	{
		if (m_size >= m_cap)
		{
			size_t newCap;

			if (m_cap == 0)
			{
				newCap = 1;
			}
			else
			{
				newCap = m_cap * 2;
			}

			T* newData = new T[newCap];

			for (size_t i = 0; i < m_size; i++)
			{
				newData[i] = std::move(m_data[i]);
			}

			delete[] m_data;
			m_data = newData;
			m_cap = newCap;
		}
		m_data[m_size] = value;
		m_size++;
	}

	void pop_back()
	{
		if (m_size > 0)
		{
			m_size--;
		}
	}

	
public:
	T& operator[](size_t index)
	{
		return m_data[index];
	}

	const T& operator[](size_t index) const
	{
		return m_data[index];
	}

	size_t size() const
	{
		return m_size;
	}

	size_t capacity() const
	{
		return m_cap;
	}

	bool empty() const
	{
		return m_size == 0;
	}

	const T& front() const
	{
		return m_data[0];
	}

	const T& back() const
	{
		return m_data[m_size - 1];
	}

	const T& at(size_t n) const
	{
		if (n >= m_size)
		{
			throw std::exception("my::Vector::at, wrong number!!!");
		}

		return m_data[n];
	}
};
}

#endif // VECTOR_H