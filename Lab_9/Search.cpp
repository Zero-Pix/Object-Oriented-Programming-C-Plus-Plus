#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

void vecGen(const string& filename, vector<int>& v) {
    ifstream file(filename);
    int num;
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

int iterativeSearch(const vector<int>& v, int elem) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == elem) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& v, int start, int end, int elem) {
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

int main() {
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    double total_iterative_time = 0.0;
    double total_binary_time = 0.0;

    cout << "Iterative Search Results:" << endl;
    for (size_t i = 0; i < elem_to_find.size(); i++) {
        int elem = elem_to_find[i];
        clock_t start = clock();
        int index_if_found = iterativeSearch(v, elem);
        clock_t end = clock();
        double elapsed_time_in_sec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        total_iterative_time += elapsed_time_in_sec;
        cout << "Element: " << elem << " found at index: " << index_if_found << ", Search time: " << elapsed_time_in_sec << " seconds." << endl;
    }
    double average_iterative_time = total_iterative_time / elem_to_find.size();
    cout << "Average Iterative Search Time: " << average_iterative_time << " seconds." << endl;

    cout << "\nBinary Search Results:" << endl;
    for (size_t i = 0; i < elem_to_find.size(); i++) {
        int elem = elem_to_find[i];
        clock_t start = clock();
        int index_if_found = binarySearch(v, 0, v.size() - 1, elem);
        clock_t end = clock();
        double elapsed_time_in_sec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        total_binary_time += elapsed_time_in_sec;
        cout << "Element: " << elem << " found at index: " << index_if_found << ", Search time: " << elapsed_time_in_sec << " seconds." << endl;
    }
    double average_binary_time = total_binary_time / elem_to_find.size();
    cout << "Average Binary Search Time: " << average_binary_time << " seconds." << endl;

    return 0;
}
