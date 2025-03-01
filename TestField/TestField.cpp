// TestField.cpp : Project for testing some code

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>


// Should return each digit to the caller, not the last one
void returnAllValue(int n, std::vector<int>& arr)
{
	// if number larger or equal to 10 - call the function again with a new value
	if (n >= 10)
		returnAllValue(n / 10, arr);
		
	// get module of a new digit
	int digit = n % 10;

	arr.push_back(digit);
}


int main()
{
	int num = 12345;
	std::vector<int> arr;

	returnAllValue(num, arr);
	
	for (int i = 0; i < arr.size(); ++i)
	{
		std::cout << arr[i] << '\n';
	}

    return 0;
}

