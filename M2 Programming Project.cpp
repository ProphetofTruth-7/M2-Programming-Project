// This is the Course Grade Subproject. It

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int ID;
    int* dataArray;  //Supposed pointer to an array, put I'm not sure this is correct
    double averageScore;
    char letterGrade;
};

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

    class* dataArray = new class[totalStudents];

    Student dataArray[] = {{"Jordan", 26779, 55.4, 'F'}, {"Maya", 34303, 87.2, 'B'}};
    cout << "Name: " << dataArray[0].name << " ID: " << dataArray[0].ID << endl;
    cout << "Name: " << dataArray[1].name << " ID: " << dataArray[1].ID << endl;

    delete[] dataArray;

    return 0;
}
