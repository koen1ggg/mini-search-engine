#include <iostream> 
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void searchInFile(const string& filename, const string& keyword) {
    ifstream file(filename);
    string line;
    int lineNumber = 0;

    if (!file) {
        cout << "Error opening " << filename << endl;
        return;
    }

    while (getline(file, line)) {
        lineNumber++;
        if (line.find(keyword) != string::npos) {
            cout << "\nFound in " << filename << " at line " << lineNumber << ":\n";
            cout << line << endl;
        }
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

    return 0;
}