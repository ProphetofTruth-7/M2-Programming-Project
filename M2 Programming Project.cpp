// This is the Course Grade Subproject. It

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int ID;
    int *Array;  //Dynamically allocate this
    double averageScore;
    char letterGrade;
};

Student* readFile(ifstream& STUDENTDATAFILE, int& numStudents, int& numGrades);
double calcAverage(Student ArrayofStructs[], int grades, int currentStudent);
char calcLetter(Student ArrayofStructs[], int currentStudent);
void collateReport(Student ArrayofStructs[], int numStudents);


int main()
{
    string filename = "StudentData.txt"; //File Initialization bits
    ifstream DATAFILE(filename);
    if (!DATAFILE) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    Student *ArrayOfStructs;   //Dynamically allocate this

    int totalGrades, totalStudents;

   ArrayOfStructs = readFile(DATAFILE, totalStudents, totalGrades);

    for (int currentStudent = 0; currentStudent < totalStudents; currentStudent++) {
        ArrayOfStructs[currentStudent].averageScore = calcAverage(ArrayOfStructs, totalGrades, currentStudent);
        ArrayOfStructs[currentStudent].letterGrade = calcLetter(ArrayOfStructs, currentStudent);
    }

    collateReport(ArrayOfStructs, totalStudents);

    return 0;
}


Student* readFile(ifstream& STUDENTDATAFILE, int& numStudents, int& numGrades) {
    STUDENTDATAFILE >> numStudents;
    STUDENTDATAFILE >> numGrades;

    Student* ArrayofStructs = new Student[numStudents];

    for (int i = 0; i < numStudents; i++) {
        STUDENTDATAFILE >> ArrayofStructs[i].name;
        STUDENTDATAFILE >> ArrayofStructs[i].ID;

        int* Array = new int[numGrades];
        ArrayofStructs[i].Array = Array;
        for (int d = 0; d < numGrades; d++) {
            STUDENTDATAFILE >> ArrayofStructs[i].Array[d];
        }
    }
    return ArrayofStructs;
}


double calcAverage(Student ArrayofStructs[], int grades, int currentStudent) {
    double sum = 0;

    for (int s = 0; s < grades; s++) {
        sum += ArrayofStructs[currentStudent].Array[s];
    }

   return (sum / grades);
}


char calcLetter(Student ArrayofStructs[], int currentStudent) {
    if (ArrayofStructs[currentStudent].averageScore > 89.9) {
        return 'A';
    }
    else if (ArrayofStructs[currentStudent].averageScore > 79.9) {
        return 'B';
    }
    else if (ArrayofStructs[currentStudent].averageScore > 69.9) {
        return 'C';
    }
    else if (ArrayofStructs[currentStudent].averageScore > 59.9) {
        return 'D';
    }
    else {
        return 'F';
    }
}


void collateReport(Student ArrayofStructs[], int numStudents) {  //Instead of numStudents, you'll need currentSize for dynamic
    cout << "Student Name" << setw(15) << "Student ID" << setw(15) << "Average Score" << setw(15) << "Letter Grade" << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << ArrayofStructs[i].name << setw(15) << ArrayofStructs[i].ID << setw(15) << ArrayofStructs[i].averageScore << setw(15) << ArrayofStructs[i].letterGrade << endl;
    }
}