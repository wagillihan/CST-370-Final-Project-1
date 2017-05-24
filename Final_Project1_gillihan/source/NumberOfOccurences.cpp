/*
* Title: NumberOfOccurences.cpp
* Abstract: Driver program to test function that counts
* the number of occurences of an specified element
* in an array that is sorted ascending.
* Author: William Gillihan
* ID: CST370 Final Project 1
* Date: 02/24/2017
*/
/*-------------------Algorithm----------------------------
 Use binary search to get index of first occurence of number.
	if number is not found, return -1
	else store index in firstOccur.
 Use binary search to get index of last occurence of number
	store index in lastOccur.
 Return return lastOccur - firstOccur + 1

 Time complexity of two binary searches is 2 * logn 
 Thus time complexity of count() is equivelent to O(logn) 
---------------------------------------------------------*/
#include <iostream>
using namespace std;

/* if num exists in arr[] then it returns the index of the
	first occurrence of the num in arr[0..n-1], otherwise returns -1 */
int first(int arr[], int low, int high, int num, int size)
{
	// using binary search
	if (high >= low)
	{
		int mid = (low + high) / 2;  // find middle
		/* if only one item or is greater than left half and
			item is present at middle */
		if ((mid == 0 || num > arr[mid - 1]) && arr[mid] == num)
			return mid; // return index
		// if item greater, ignore left half
		else if (num > arr[mid])
			return first(arr, (mid + 1), high, num, size);
		// else ignore right half
		else
			return first(arr, low, (mid - 1), num, size);
	}
	return -1;
}

/* if num exists in arr[] then it returns the index of the 
	last occurrence of the num in arr[0..n-1], otherwise returns -1 */
int last(int arr[], int low, int high, int num, int size)
{
	// using binary search
	if (high >= low)
	{
		int mid = (low + high) / 2;  // find middle
		/* if only one item or is less than right half and
			item is present at middle */
		if ((mid == size - 1 || num < arr[mid + 1]) && arr[mid] == num)
			return mid;
		// if item less, ignore right half
		else if (num < arr[mid])
			return last(arr, low, (mid - 1), num, size);
		// else ignore left half
		else
			return last(arr, (mid + 1), high, num, size);
	}
	return -1;
}

/* if num exists in arr[] then returns the count of 
	occurrences of num, otherwise returns -1. */
int count(int arr[], int num, int size)
{
	int firstOccur; // index of first occurrence of num in arr[0..n-1]
	int lastOccur; // index of last occurrence of num in arr[0..n-1]

	// get the index of first occurrence of num
	firstOccur = first(arr, 0, size - 1, num, size);

	// if num doesn't exist in arr[] then return -1
	if (firstOccur == -1)
		return firstOccur;

	/* else get the index of last occurrence of num
		in the subarray after first occurrence */
	lastOccur = last(arr, firstOccur, size - 1, num, size);

	// return count
	return lastOccur - firstOccur + 1;
}

// driver program to test above functions
int main()
{
	int arr[] = { 1, 1, 2, 2, 5, 5, 5, 5, 5, 5, 5, 8, 8, 9, 10, 11, 11 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int num; // element to be counted in arr[]
	bool loop = true;
	while (loop)
	{
		cout << "Item to count occurences (-999 to stop): ";
		cin >> num;
		if (num == -999) loop = false;
		else
		{
			// get number of occurences
			int numCount = count(arr, num, size);
			if (numCount != -1)
			{
				cout << "The number " << num << " appears " <<
					numCount << " times in the array!" << endl;
			}
			else
				cout << "The number " << num << 
					" does not appear in the array!" << endl;
		}
	}
	system("pause");
	return 0;
}