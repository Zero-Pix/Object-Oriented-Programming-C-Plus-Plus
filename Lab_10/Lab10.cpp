#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>  // For std::sort

using namespace std;

// Generates a sorted vector of random integers
void vecGen(int size, vector<int>& v) {
    v.clear();
    for (int i = 0; i < size; ++i) {
        v.push_back(rand() % 100000);  // Populate vector with random numbers
    }
    sort(v.begin(), v.end());  // Sort vector for binary search
}

// Performs an iterative search on the vector
int iterativeSearch(const vector<int>& v, int elem) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == elem) {
            return i;
        }
    }
    return -1;
}

// Performs a binary search on the vector
int binarySearch(const vector<int>& v, int start, int end, int elem) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (v[mid] == elem) {
            return mid;
        } else if (v[mid] < elem) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

// Writes the search times to a CSV file
void writeTimes(const string& filename, const vector<double>& times, const vector<int>& sizes) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "Size,Time(sec)\n";
        for (size_t i = 0; i < times.size(); ++i) {
            file << sizes[i] << "," << times[i] << "\n";
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

int main() {
    vector<int> sizes = {100, 1000, 10000, 100000};  // Different dataset sizes
    vector<double> it_times, bi_times;  // To store times for each search method

    for (int size : sizes) {
        vector<int> data;
        vecGen(size, data);
        int search_elem = data[data.size() / 2];  // Element to search for

        // Measure iterative search time
        clock_t start = clock();
        iterativeSearch(data, search_elem);
        clock_t end = clock();
        it_times.push_back(double(end - start) / CLOCKS_PER_SEC);

        // Measure binary search time
        start = clock();
        binarySearch(data, 0, size - 1, search_elem);
        end = clock();
        bi_times.push_back(double(end - start) / CLOCKS_PER_SEC);
    }

    writeTimes("iterative_times.csv", it_times, sizes);
    writeTimes("binary_times.csv", bi_times, sizes);

    cout << "Data written to files successfully.\n";
}
