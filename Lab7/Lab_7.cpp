#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(const string& filename, char data[], int size) {
    ofstream file(filename);
    if (!file) {
        cout << "Unable to open file " << filename << endl;
        return;
    }
    
    for (int i = 0; i < size; ++i) {
        file << data[i] << "\n";
    }
    cout << "Wrote to " << filename << endl;
}

void writeToFile(const string& filename, string data[], int size) {
    ofstream file(filename);
    if (!file) {
        cout << "Unable to open file " << filename << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        file << data[i] << "\n";
    }
    cout << "Wrote to " << filename << endl;
}

void writeToFile(const string& filename, int data[], int size) {
    ofstream file(filename);
    if (!file) {
        cout << "Unable to open file " << filename << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        file << data[i] << "\n";
    }
    cout << "Wrote to " << filename << endl;
}

void readFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Unable to open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
}

int main() {
    char arrChar[] = {'c', 'd'};
    string arrStr[] = {"cat", "dog"};
    int arrInt[] = {1, 0};

    string filenameChar = "output_char.txt";
    string filenameStr = "output_str.txt";
    string filenameInt = "output_int.txt";

    writeToFile(filenameChar, arrChar, 2);
    writeToFile(filenameStr, arrStr, 2);
    writeToFile(filenameInt, arrInt, 2);

    readFile(filenameChar);
    readFile(filenameStr);
    readFile(filenameInt);

    return 0;
}
