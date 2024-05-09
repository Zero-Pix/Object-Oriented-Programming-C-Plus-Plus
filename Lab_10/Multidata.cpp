#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

// Function to generate a vector from file data, generic type
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

// Function for iterative search, generic type
template <typename T>
int iterativeSearch(const vector<T>& v, T elem) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == elem) {
            return i;
        }
    }
    return -1;
}

// Function for binary search, generic type
template <typename T>
int binarySearch(const vector<T>& v, int start, int end, T elem) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if constexpr (std::is_same<T, std::string>::value) {
        // Special handling for string comparison
        if (v[mid] == elem) {
            return mid;
        } else if (v[mid] < elem) {
            return binarySearch(v, mid + 1, end, elem);
        } else {
            return binarySearch(v, start, mid - 1, elem);
        }
    } else {
        if (v[mid] == elem) {
            return mid;
        } else if (elem < v[mid]) {
            return binarySearch(v, start, mid - 1, elem);
        } else {
            return binarySearch(v, mid + 1, end, elem);
        }
    }
}

int main() {
    // Testing with integers
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> elem_to_find = {3, 1, 4};
    for (int i = 0; i < elem_to_find.size(); i++) {
        int elem = elem_to_find[i];
        clock_t start = clock();
        int index_found = binarySearch(v, 0, v.size() - 1, elem);
        clock_t end = clock();
        double elapsed_time_in_sec = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "Index found = " << index_found << "; Time in sec = " << elapsed_time_in_sec << endl;
    }

    // Testing with doubles
    vector<double> vd = {1.1, 2.2, 3.3, 4.4, 5.5};
    vector<double> double_to_find = {3.1, 2.2, 1.3};
    for (int i = 0; i < double_to_find.size(); i++) {
        double elem = double_to_find[i];
        clock_t start = clock();
        int index_found = binarySearch(vd, 0, vd.size() - 1, elem);
        clock_t end = clock();
        double elapsed_time_in_sec = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "Index found = " << index_found << "; Time in sec = " << elapsed_time_in_sec << endl;
    }

    // Testing with strings
    vector<string> names = {"Al", "Be", "Bea", "Bob", "Cat", "Ci"};
    string target = "Bea";
    int result = binarySearch(names, 0, names.size() - 1, target);
    if (result != -1) {
        cout << "Found '" << target << "' at index " << result << endl;
    } else {
        cout << "Did not find '" << target << "' in the vector." << endl;
    }

    return 0;
}
