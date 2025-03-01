/*
Largest Palindrome Product

Originally written by Mikhail Adamenko
(mikhail.adamenko@protonmail.com) January 2018

A palindromic number reads the same both ways.The largest palindrome made
from the product of two 2 - digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3 - digit numbers.
*/

#include "stdafx.h"

void digitOfNumber(int num, std::vector<int>& arr)
// Get integer number and vector
// modified the vector with separate digits of the number
{
	if (num >= 10)
		digitOfNumber(num / 10, arr);

	int digit = num % 10;
		
	arr.push_back(digit);
}

int reversedNumber(int num)
// get number
// return reversed number
{
	int reversed{ 0 };

	while (num > 0)
	{
		reversed = reversed * 10 + (num % 10);
		num = num / 10;
	}

	return reversed;
}

bool palindrome(int num)
{
	std::vector<int> chunk{};
	std::vector<int> firstHalfCh{};
	std::vector<int> secondHalfCh{};

	// put digits in the vector 'chunk'
	digitOfNumber(num, chunk);

	// Check if 1st and last digit is the same
	if (chunk.front() == chunk.back())
	{
		// Divide size of the number by half
		int halfOfSizeNum = static_cast<int>(chunk.size() / 2);

		// push halfs digits to the vectors
		for (int i = 0; i < halfOfSizeNum; ++i)
		{
			// push first half of the number 
			// into the 1st chunk
			digitOfNumber(num, firstHalfCh);
					
			// reverse number for the second chunk
			int reversed = reversedNumber(num);
			
			// push second half of the number
			// into the 2nd chunk
			digitOfNumber(reversed, secondHalfCh);
		}

		// check if first half of the number
		// equal to the second half
		if (std::equal(firstHalfCh.begin(), firstHalfCh.begin() + halfOfSizeNum, secondHalfCh.begin()))
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

int largestPalindrome(int min, int max)
// get minimal and maximum multiplicators of two numbers
// return largest palindrome of two multiplicators
{
	int larPal{0};
	const int maximal = max;

	int constMax = max;
	int maxSum = max * max;	
	int& decrNum = maxSum;
	
	std::vector<int> palindromes{};

	// do while larPal haven't value
	while (palindromes.size() != 4)
	{
		if (palindrome(decrNum) == true) 
		{
			larPal = decrNum;

			palindromes.push_back(larPal);
		}

		if (max == min)
		{
			// reset the max
			max = maximal;

			// decrement
			--constMax;			
		}

		// decrement max value by one
		decrNum = constMax * max;
		--max;
	}

	// get max integer
	auto largest = std::max_element(std::begin(palindromes), std::end(palindromes));

	return largest[0];
}

int main()
{
	int min = 100;
	int max = 999;

	std::cout << "Largest palindrom is: " << largestPalindrome(min, max) << '\n';
    
	return 0;
}