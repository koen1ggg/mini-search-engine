#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void searchInFile(const string& filename, const string& keyword) {
    ifstream file(filename);
    string line;
    int lineNumber = 0;
    int matchCount = 0;

    if (!file) {
        cout << "Error opening " << filename << endl;
        return;
    }

    while (getline(file, line)) {
        lineNumber++;

        string lowerLine = toLower(line);
        string lowerKeyword = toLower(keyword);

        if (lowerLine.find(lowerKeyword) != string::npos) {
            cout << "\nFound in " << filename << " at line " << lineNumber << ":\n";
            cout << line << endl;
            matchCount++;
        }
    }

    if (matchCount == 0) {
        cout << "\nNo matches found in " << filename << endl;
    } else {
        cout << "\nTotal matches in " << filename << ": " << matchCount << endl;
    }

    file.close();
}

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;
    cin.ignore();

    vector<string> files;

    for (int i = 0; i < n; i++) {
        string filename;
        cout << "Enter file " << i + 1 << ": ";
        getline(cin, filename);
        files.push_back(filename);
    }

    string keyword;
    cout << "Enter keyword: ";
    getline(cin, keyword);

    for (const string& file : files) {
        searchInFile(file, keyword);
    }

    cout << "\nSearch completed.\n";
    return 0;
}