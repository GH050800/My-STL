#include <iostream>

#include <vector>

namespace my
{
	template <typename InputIt, typename UnaryFunc>
	UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
	{
		while (first != last)
		{
			f(*first);
			++first;
		}
		return f;
	}
}

int main()
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };

	std::cout << "Before: ";
	for (auto n : vec)
	{
		std::cout << n << " ";
	}

	my::for_each(vec.begin(), vec.end(), [](int& n) { n *= 3; });

	std::cout << "\nAfter: ";
	for (auto n : vec)
	{
		std::cout << n << " ";
	}
	
    return 0;
}