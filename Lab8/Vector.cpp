#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief prints the elements in the vector and their memory locations
 *
 * @param vec - vector of integers
 */
void printMemVec(const vector<int>& vec) {
    cout << "Vector - Each int is worth " << sizeof(vec[0]) << " bytes\n";
    for (const auto& value : vec) {
        cout << "Value : " << value << " at memory location: " << static_cast<const void*>(&value) << "\n";
    }
}

/**
 * @brief increments all of the elements in vec by 10
 *
 * @param vec - reference to a vector of integers
 */
void incVecBy10(vector<int>& vec) {
    // Directly using a range-based for loop to increment each element by 10
    for (auto& value : vec) {
        value += 10;
    }
}

int main() {
    // Create a constant integer called SIZE that is of value 5
    const int SIZE = 5;
    // Create a vector of integers called vec that can hold up to 5 elements
    vector<int> vec(SIZE);

    // Use a for loop to populate vec with the values 100 to 104
    int value = 100;
    for (auto& element : vec) {
        element = value++;
    }

    cout << "Before Increment------------\n";
    // Call printMemVec(...) on vec
    printMemVec(vec);

    // Call incVecBy10(...) on vec
    incVecBy10(vec);

    cout << "After Increment-------------\n";
    // Call printMemVec(...) on vec again to view the changes
    printMemVec(vec);

    // Remove last element of vec
    vec.pop_back();

    cout << "After pop------------\n";
    // Call printMemVec(...) on vec again to view the changes 
    printMemVec(vec);

    // Append 101 and 102 at end of vec
    vec.push_back(101);
    vec.push_back(102);

    cout << "After Push--------\n";
    // Call printMemVec(...) on vec again to view the changes
    printMemVec(vec);
    
    return 0;
}
