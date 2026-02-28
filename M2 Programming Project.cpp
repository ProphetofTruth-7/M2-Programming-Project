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


void print(const int array[], int size) {
	int counter = 0;

	do {
		cout << array[counter] << " ";
		cout << "As you can tell, the size of this array is " << size << " Units" << endl;
		counter++;
	} while (counter < size);
}