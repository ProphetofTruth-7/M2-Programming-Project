// This is the Course Grade Subproject. It

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int ID;
    int Array[5];  //Supposed pointer to an array, put I'm not sure this is correct
    double averageScore;
    char letterGrade;
};

const int NUMBER = 10;

void calcAverage(Student ArrayofStructs, int grades);


int main()
{
    string filename = "StudentData.txt"; //File Initialization bits
    ifstream DATAFILE(filename);
    if (!DATAFILE) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int totalStudents, totalGrades;

    DATAFILE >> totalStudents;
    DATAFILE >> totalGrades;

    Student ArrayOfStructs[NUMBER];

    for (int i = 0; i < totalStudents; i++) {
        DATAFILE >> ArrayOfStructs[i].name;
        DATAFILE >> ArrayOfStructs[i].ID;
        for (int d = 0; d < totalGrades; d++) {
            DATAFILE >> ArrayOfStructs[i].Array[d];
        }
    }

    calcAverage(ArrayOfStructs, totalGrades);

    return 0;
}

void calcAverage(Student array[], int grades) {

    cout << array[0].Array[0];

}