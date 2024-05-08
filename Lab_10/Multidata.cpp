#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

// Modify vecGen to use templates and take any numeric type vector
template <typename T>
void vecGen(const string& filename, vector<T>& v) {
    ifstream file(filename);
    T num;
    v.clear();
    if (file.is_open()) {
        while (file >> num) {
            v.push_back(num);
        }
        file.close();
    } else {
        cerr << "Failed to open the file: " << filename << endl;
    }
}

// Modify iterativeSearch to be templated to handle both int and double
template <typename T>
int iterativeSearch(const vector<T>& v, T elem) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == elem) {
            return i;
        }
    }
    return -1;
}

// Modify binarySearch to be templated to handle both int and double
template <typename T>
int binarySearch(const vector<T>& v, int start, int end, T elem) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (v[mid] == elem) {
        return mid;
    } else if (elem < v[mid]) {
        return binarySearch(v, start, mid - 1, elem);
    } else {
        return binarySearch(v, mid + 1, end, elem);
    }
}

int main(){
    // Testing with integers
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    vector<int> elem_to_find = {3, 1, 4};

    for(int i = 0; i < elem_to_find.size(); i++){
        int elem = elem_to_find[i];
        clock_t start = clock();
        int index_found = binarySearch(v, 0, v.size() - 1, elem);
        clock_t end = clock();
        double elapsed_time_in_sec = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "Index found = " << index_found << "; Time in sec = " << elapsed_time_in_sec << endl;
    }
    
    // Testing with doubles
    vector<double> double_to_find = {3.1, 2.2, 1.3};
    vector<double> vd = {1.1, 2.2, 3.3, 4.4, 5.5};

    for(int i = 0; i < double_to_find.size(); i++){
        double elem = double_to_find[i];
        clock_t start = clock();
        int index_found = binarySearch(vd, 0, vd.size() - 1, elem);
        clock_t end = clock();
        double elapsed_time_in_sec = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "Index found = " << index_found << "; Time in sec = " << elapsed_time_in_sec << endl;
    }
}
