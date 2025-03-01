/*
Smallest multiple

Originally written by Mikhail Adamenko
(mikhail.adamenko@protonmail.com) January 2018

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?
*/

#include "stdafx.h"

int divNum(int limit)
// get upper limit of divided number
// return smallest div. number
{
	const int constLimit = limit;
	int num{ 0 };
	std::div_t dv_num{};

	while (true)
	{
		// increment number
		++num;

		for (int i = 0; i < limit; ++i)
		{
			dv_num = std::div(i, num);

			std::cout << "num " << num << " limit " << limit
				<< " rem " << dv_num.rem << '\n';

			if (dv_num.rem == 0)
			{
				return num;
			}
		}
	}
}

int main()
{
	// range from 1 to max
	int max = 10;

	std::cout << "Smallest pos. Number that evenly div. is: " << divNum(max) << '\n';

    return 0;
}

