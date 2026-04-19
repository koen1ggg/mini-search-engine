#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename, keyword, line;
    int lineNumber = 0;

    cout << "Enter file name: ";
    getline(cin, filename);

    cout << "Enter keyword: ";
    getline(cin, keyword);

    ifstream file(filename);

    if (!file) {
        cout << "Error opening file.\n";
        return 1;
    }

    while (getline(file, line)) {
        lineNumber++;
        if (line.find(keyword) != string::npos) {
            cout << "Found at line " << lineNumber << ": " << line << endl;
        }
    }

    file.close();
    return 0;
}