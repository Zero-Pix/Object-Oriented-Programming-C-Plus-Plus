#include <fstream>
#include <iostream>
#include <string> 

using namespace std; 

void FileStr(string filename, string* arr, int sample_size) {
    ofstream file(filename);
    for(int i = 0; i < sample_size; i++) {
        file << arr[i] << "\n";
    }
    file.close();
    cout << "Wrote to " << filename << endl;
}
