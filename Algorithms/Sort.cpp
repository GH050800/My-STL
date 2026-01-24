#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

void bubbleSort(std::vector<int>& v)
{
	size_t size = v.size();

	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				std::swap(v[j], v[j + 1]);
			}
		}
	}
}

void mergeSort(std::vector<int>& v, size_t start, size_t end)
{
	if (end - start < 2)	return;

	if (end - start == 2)
	{
		if (v[start] > v[start + 1])
		{
			std::swap(v[start], v[start + 1]);
		}
		return;
	}

	size_t mid = (start + end) / 2;
	mergeSort(v, start, mid);
	mergeSort(v, mid, end);

	std::vector<int> temp;
	size_t t1 = start;
	size_t t2 = mid;

	while (temp.size() < end - start)
	{
		if (t1 >= mid || (t2 < end && v[t2] <= v[t1]))
		{
			temp.push_back(v[t2]);
			t2++;
		}
		else
		{
			temp.push_back(v[t1]);
			t1++;
		}
	}

	for (size_t i = 0; i < temp.size(); i++)
	{
		v[start + i] = temp[i];
	}
}

void quickSort(std::vector<int>& v, int start, int end)
{
	if (start >= end) return;

	int mid = (start + end) / 2;
	int element = v[mid];
	
	int i = start;
	int j = end;

	while (i <= j)
	{
		while (v[i] < element) i++;
		while (v[j] > element) j--;

		if (i <= j)
		{
			std::swap(v[i], v[j]);
			i++;
			j--;
		}
	}

	quickSort(v, start, j);
	quickSort(v, i, end);
}

int main()
{
	//BUBBLE SORT TEST
	std::vector<int> vec1;	
	for (size_t i = 0; i < 15; i++)
	{
		vec1.push_back(rand() % 100);
	}
	std::cout << "Bubble Sort: ";
	bubbleSort(vec1);
	for (auto i : vec1)
	{
		std::cout << i << " ";
	}
	
	//MERGE SORT TEST
	std::vector<int> vec2;
	for (size_t i = 0; i < 15; i++)
	{
		vec2.push_back(rand() % 100);
	}
	std::cout << "\nMerge Sort: ";
	mergeSort(vec2, 0, vec2.size());
	for (auto i : vec2)
	{
		std::cout << i << " ";
	}

	//QUICK SORT TEST
	std::vector<int> vec3;
	for (size_t i = 0; i < 15; i++)
	{
		vec3.push_back(rand() % 100);
	}
	std::cout << "\nQuick Sort: ";
	quickSort(vec3, 0, vec3.size() - 1);
	for (auto i : vec3)
	{
		std::cout << i << " ";
	}
    return 0;
}
