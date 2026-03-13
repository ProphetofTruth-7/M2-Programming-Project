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

void readFile(ifstream& STUDENTDATAFILE, Student ArrayofStructs[], int& numStudents, int& numGrades);
double calcAverage(Student ArrayofStructs[], int grades, int currentStudent);


int main()
{
    string filename = "StudentData.txt"; //File Initialization bits
    ifstream DATAFILE(filename);
    if (!DATAFILE) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    Student ArrayOfStructs[10];

    int totalGrades, totalStudents;

    readFile(DATAFILE, ArrayOfStructs, totalStudents, totalGrades);

    for (int currentStudent = 0; currentStudent < totalStudents; currentStudent++) {
        ArrayOfStructs[currentStudent].averageScore = calcAverage(ArrayOfStructs, totalGrades, currentStudent);
    }
    
    cout << ArrayOfStructs[0].averageScore << endl;

    return 0;
}


void readFile(ifstream& STUDENTDATAFILE, Student ArrayofStructs[], int& numStudents, int& numGrades) {
    STUDENTDATAFILE >> numStudents;
    STUDENTDATAFILE >> numGrades;

    for (int i = 0; i < numStudents; i++) {
        STUDENTDATAFILE >> ArrayofStructs[i].name;
        STUDENTDATAFILE >> ArrayofStructs[i].ID;
        for (int d = 0; d < numGrades; d++) {
            STUDENTDATAFILE >> ArrayofStructs[i].Array[d];
        }
    }
}


double calcAverage(Student ArrayofStructs[], int grades, int currentStudent) {
    double sum = 0;

    for (int s = 0; s < grades; s++) {
        sum += ArrayofStructs[currentStudent].Array[s];
    }

   return (sum / grades);
}