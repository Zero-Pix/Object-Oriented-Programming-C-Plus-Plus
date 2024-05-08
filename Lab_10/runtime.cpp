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

void writeTimes(const string& filename, const vector<double>& times, const vector<int>& n){
    ofstream myFile(filename);
    myFile << "number of elements (n)\t Time (sec) " <<endl;
    for(int i = 0; i < times.size(); i++){
        myFile << n[i] << "\t" << times[i] << "\n";
    }
    myFile.close();
    cout << "wrote to " << filename <<endl;
 }

double average(const vector<double>& a){
    double sum = 0;
    for (double num : a) {
        sum += num;
    }
    return a.empty() ? 0 : sum / a.size();
}

int main(){
    vector<int> elements_to_find = {10, 20, 30};
    vector<string> file_sizes = {"100", "1000", "10000"};
    vector<double> avg_times;

    for(const auto& size : file_sizes){
        string fileName = "timing" + size + "_database.csv";
        vector<int> data;
        vecGen(fileName, data);
        
        vector<double> times;

        for(int elem : elements_to_find){
            clock_t start = clock();
            int index_found = binarySearch(data, 0, data.size() - 1, elem);
            clock_t end = clock();
            double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
            times.push_back(elapsed_time);
        }

        double avg_time = average(times);
        avg_times.push_back(avg_time);
    }
    
    writeTimes("average_times.csv", avg_times, vector<int>{100, 1000, 10000});
}
