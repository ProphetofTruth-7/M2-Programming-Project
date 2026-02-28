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
	print(ReverseArray(originalArray, originalArraySize), originalArraySize);

    return 0;
}

int *ReverseArray(const int array[], int size) {
	int* reverseArray = new int[size];
	int counter = 0;

	cout << "The first value of Reverse Array is: " << reverseArray[0] << endl;
	cout << "The size is " << size << endl;
	cout << "The operation is " << size - counter << endl;
	cout << "The value of the given Array is: " << array[(size - counter)] << endl;

	reverseArray[0] = array[(size - counter)];
	cout << "The added value is " << reverseArray[0] << endl;

	do {
		reverseArray[counter] = array[(size-counter)];
		counter++;
	} while (counter < size);

	return reverseArray;
}

void print(const int array[], int size) { //This function prints the contents of the array given to it. It needs the array and its size. The array must be a const int, 1D array, and its size must be pre-assigned
	int counter = 0;

	do {
		cout << array[counter] << " ";
		counter++;
	} while (counter < size);
	cout << endl;
} //This function WILL cout "size" amount of elements from the given array upon its completion