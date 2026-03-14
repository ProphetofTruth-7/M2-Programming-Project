/*
 * Course Grade Subproject
 * ------------------------------------------------------------
 * This program reads the information of a number of students from an input file. It stores the data within an array of structs that contains:
 *  - The Student's Name
 *  - The Student's ID
 *  - The Student's Grades(within a dynamically allocated Array)  
 *  
 * The program computes each student's average score and letter grade, and stores them within the above struct. It then prints a formatted table including all that data
 *
 * Input file format:
 *   #ofStudents #ofGradesPerStudent
 *   studentName studentID grade1 grade2 grade3 grade... gradeX
 *
 * Example file: StudentData.txt
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Struct Definition //
struct Student {
    string name;
    int ID;
    int *Grades;
    double averageScore;
    char letterGrade;
};

// Function Protoypes //

/*
 * readFile
 * ------------------------------------------------------------
 * Reads Student names, Students IDs, Specific Grades, number of Students, and number of Grades from an input file into the Array of Structs
 *
 * Inputs:
 *   STUDENTDATAFILE      - An open input file stream (ifstream)
 *   numStudents          - An undefined integer for total students that will eventually be filled by the header file
 *   numGrades            - An undefined integer for total grades that will eventually be filled by the header file
 * Outputs:
 *   .name       - An index within each Struct of the dynamic Array of Structs that holds the student's name
 *   .ID         - An index within each Struct of the dynamic Array of Structs that holds the student's ID
 *   .Grades     - A dynamic array within each Struct of the dynamic Array of Structs that holds all the student grades
 *   ArrayofStructs     - A pointer to the dynamic Array of Structs
 *
 * Preconditions:
 *   - inFile is open and ready for reading
 *   - File contains the appropriate headers that related to totalStudents and totalGrades
 *
 * Postconditions:
 *   - .name for each struct contains the appropriate name
 *   - .ID for each struct contains the appropriate ID
 *   - .Grades for each struct contains the appropriate grades in a dynamic array
 *   - A proper pointer is returned
 */
Student* readFile(ifstream& STUDENTDATAFILE, int& numStudents, int& numGrades);
/*
 * calcAverage
 * ------------------------------------------------------------
 * Takes the Dynamic Array, the total # of grades, and a specific loop-index and calculates the average for each students set of grades
 *
 * Inputs:
 *  - ArrayofStructs        - A dynamic array that contains structs that relate to each student
 *  - grades                - The total number of grades, given by the header file
 *  - currentStudent        - A specific loop-index that is incremented with each runthrough of calcAverage
 * Outputs:
 *  - sum / grades          - The average of the Student's grades
 *
 * Preconditions:
 *  - ArrayofStructs is properly allocated
 *  - grades is properly conveyed through header and is valid
 *  - currentStudent is a proper loop-index
 *
 * Postconditions:
 *  - The double average is directly returned
 */
double calcAverage(Student ArrayofStructs[], int grades, int currentStudent);
/*
 * calcLetter
 * ------------------------------------------------------------
 * Takes the Dynamic Array and a specific loop-index and calculates the Letter Grade for each student and inputs that grade into the dynamic array of structs
 *
 * Inputs:
 *  - ArrayofStructs        - A dynamic array that contains structs that relate to each student
 *  - currentStudent        - A specific loop-index that is incremented with each runthrough of calcLetter
 * Outputs:
 *  - "Letter Grade"        - A specific letter grade(A-F) that properly correlates to the average score stored within the dynamic Array of Structs
 *
 * Preconditions:
 *  - ArrayofStructs is properly allocated
 *  - currentStudent is a proper loop-index
 *
 * Postconditions:
 *  - The char LetterGrade is directly returned
 */
char calcLetter(Student ArrayofStructs[], int currentStudent);
/*
 * calcLetter
 * ------------------------------------------------------------
 * Takes the Dynamic Array and the total # of students collates a report of the Names, IDs, Average Scores, and Letter Grades stored within each struct of the dynamically allocated array
 *
 * Inputs:
 *  - ArrayofStructs        - A dynamic array that contains structs that relate to each student
 *  - numStudents           - The total number of students, obtained from the header file
 * Outputs:
 *  - A full report
 *
 * Preconditions:
 *  - ArrayofStructs is properly allocated
 *  - numStudents is properly conveyed through header and is valid
 *
 * Postconditions:
 *  - A report is filed
 */
void collateReport(Student ArrayofStructs[], int numStudents);


int main()
{
    string filename = "StudentData.txt"; //File Initialization bits
    ifstream DATAFILE(filename);
    if (!DATAFILE) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    Student *ArrayOfStructs;

    int totalGrades, totalStudents;

   ArrayOfStructs = readFile(DATAFILE, totalStudents, totalGrades);

    for (int currentStudent = 0; currentStudent < totalStudents; currentStudent++) {
        ArrayOfStructs[currentStudent].averageScore = calcAverage(ArrayOfStructs, totalGrades, currentStudent);
        ArrayOfStructs[currentStudent].letterGrade = calcLetter(ArrayOfStructs, currentStudent);
    }

    collateReport(ArrayOfStructs, totalStudents);

    for (int finale = 0; finale < totalStudents; finale++) {
        delete[] ArrayOfStructs[finale].Grades;
    }
    delete[] ArrayOfStructs;
    cout << "Memory Cleared" << endl;

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
        ArrayofStructs[i].Grades = Array;
        for (int d = 0; d < numGrades; d++) {
            STUDENTDATAFILE >> ArrayofStructs[i].Grades[d];
        }
    }
    return ArrayofStructs;
}


double calcAverage(Student ArrayofStructs[], int grades, int currentStudent) {
    double sum = 0;

    for (int s = 0; s < grades; s++) {
        sum += ArrayofStructs[currentStudent].Grades[s];
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
    cout << "Student Name" << right << setw(15) << "Student ID" << right << setw(15) << "Average Score" << right << setw(15) << "Letter Grade" << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << ArrayofStructs[i].name << setw(15) << ArrayofStructs[i].ID << setw(15) << ArrayofStructs[i].averageScore << setw(15) << ArrayofStructs[i].letterGrade << endl;
    }
}