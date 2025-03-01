/*
Even Fibonacci Numbers

Originally written by Mikhail Adamenko
(mikhail.adamenko@protonmail.com) December 2017

Each new term in the Fibonacci sequence is generated by adding the previous two terms.
By starting with 1 and 2, the first 10 terms will be :
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose values do not exceed four million,
find the sum of the even - valued terms.
*/

#include "stdafx.h"

int sumOfEvenFibonacci(int max)
{
	int num = 0;

	int previous = 0;
	int current = 1;
	
	int next_term = 0;

	std::vector<int> v = {};

	next_term = previous + current;

	while (next_term <= max)
	{
		previous = current;
		current = next_term;	
		next_term = previous + current;
	
		// If even
		if (next_term % 2 == 0)
		{
			v.push_back(next_term);
		}
	}

	// Sum the even fibonacci numbers
	for (int i = 0; i < v.size(); ++i)
	{
		num += v[i];
	}

	return num;
}

int main()
{
	int max = 4000000;

	std::cout << "Sum of even fibonacci from " << max << " = " << sumOfEvenFibonacci(max) << '\n';

    return 0;
}

