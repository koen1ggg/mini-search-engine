#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 🔹 Base Class (Abstraction + Polymorphism)
class Searcher {
public:
    virtual void search(const string& filename) = 0; // Pure virtual function
    virtual ~Searcher() {} // Virtual destructor
};

// 🔹 Derived Class (Implements actual logic)
class FileSearcher : public Searcher {
private:
    vector<string> files;
    string keyword;

    string toLower(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

public:
    void setFiles(int n) {
        cin.ignore();
        for (int i = 0; i < n; i++) {
            string filename;
            cout << "Enter file " << i + 1 << ": ";
            getline(cin, filename);
            files.push_back(filename);
        }
    }

    void setKeyword() {
        cout << "Enter keyword: ";
        getline(cin, keyword);
    }

    // 🔹 Override base class function (Polymorphism)
    void search(const string& filename) override {
        ifstream file(filename);
        string line;
        int lineNumber = 0;
        int matchCount = 0;

        if (!file) {
            cout << "Error opening " << filename << endl;
            return;
        }

        string lowerKeyword = toLower(keyword);

        while (getline(file, line)) {
            lineNumber++;
            string lowerLine = toLower(line);

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

    void searchAll() {
        for (const string& file : files) {
            search(file); // Polymorphic call
        }
    }
};

int main() {
    Searcher* searcher;           // Base class pointer
    FileSearcher fs;              // Derived object

    searcher = &fs;               // Polymorphism in action

    int n;
    cout << "Enter number of files: ";
    cin >> n;

    fs.setFiles(n);
    fs.setKeyword();
    fs.searchAll();

    cout << "\nSearch completed.\n";
    return 0;
}
