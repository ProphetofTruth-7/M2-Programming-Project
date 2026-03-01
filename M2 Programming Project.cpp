// This is the Course Grade Subproject. It

#include <iostream>
#include <fstream>
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
    while (getline(DATAFILE, line)) {
        cout << line << endl;
    }
    
    cout << "This is the Course Grade Subproject!" << endl;
    return 0;
}
