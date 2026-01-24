#ifndef PAIR_H
#define PAIR_H

template <typename T1, typename T2>
class Pair
{
private:
	T1 first;
	T2 second;

public:
	Pair(T1 firstValue, T2 secondValue) : first(firstValue), second(secondValue) {}
	T1 getFirst() const { return first; }
	T2 getSecond() const { return second; }
};

#endif // PAIR_H