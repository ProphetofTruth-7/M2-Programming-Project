// This is the Reverse Array Subproject! This program will fill an array of random size, then dynamically allocate an array that is filled with all elements in reverse

#include <iostream>
using namespace std;

int* ReverseArray(const int array[], int size);
void print(const int arr[], int size);

int main()
{
	const int originalArraySize = 8; //User Choice. Change this value to alter the size of the Original Array
	const int originalArray[originalArraySize] = {4, 6, 12, 39, 40, 36, 48, 33}; //User Choice. Change these values to alter what is contained within the Original Array

	print(originalArray, originalArraySize);

    return 0;
}


void print(const int array[], int size) { //This function prints the contents of the array given to it. It needs the array and its size. The array must be a const int, 1D array, and its size must be pre-assigned
	int counter = 0;

	do {
		cout << array[counter] << " ";
		counter++;
	} while (counter < size);
	cout << endl;
	cout << "As you can tell, the size of this array is " << size << " Units" << endl;
} //This function WILL cout "size" amount of elements from the given array upon its completion