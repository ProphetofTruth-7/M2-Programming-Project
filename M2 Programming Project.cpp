// This is the Course Grade Subproject. It

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string filename = "StudentData.txt"; //File Initialization bits
    ifstream DATAFILE(filename);
    if (!DATAFILE) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    getline(DATAFILE, line, ' ');
    cout << line << endl;
    
    cout << "This is the Course Grade Subproject!" << endl;
    return 0;
}
