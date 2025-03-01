/*
Multiples of 3 and 5

Originally written by Mikhail Adamenko
(mikhail.adamenko@protonmail.com) December 2017

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/


#include "stdafx.h"

int multiples(int fnum, int snum, int max);

int main()
{
	std::cout << "Sum of the vector = " << multiples(3, 5, 1000) << '\n';

	return 0;
}

int multiples(int fnum, int snum, int max)
{
	int num = 0;

	std::div_t dv_f{};
	std::div_t dv_s{};

	std::vector<int> v = {};

	for (int i = 0; i < max; ++i)
	{
		dv_f = std::div(i, fnum);
		dv_s = std::div(i, snum);

		if (dv_f.rem == 0 || dv_s.rem == 0)
		{
			v.push_back(i);
		}
	}

	for (int i = 0; i < v.size(); ++i)
	{
		num += v[i];
	}

	return num;
}