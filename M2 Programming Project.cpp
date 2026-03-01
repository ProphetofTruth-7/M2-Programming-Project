// This is the Course Grade Subproject. It

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int ID;
    //POINTER TO ARRAY
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
    int intermediary;

    DATAFILE >> intermediary;
    int constexpr totalStudents = intermediary;
    DATAFILE >> intermediary;
    int constexpr totalGrades = intermediary;

    cout << totalStudents + 5;

    Student dataArray[totalStudents] = { {"Jordan", 26779, 55.4, 'F'}, { "Maya", 34303, 87.2, 'B' } };
    cout << "Name: " << dataArray[0].name << " ID: " << dataArray[0].ID << endl;
    cout << "Name: " << dataArray[1].name << " ID: " << dataArray[1].ID << endl;



    return 0;
}
