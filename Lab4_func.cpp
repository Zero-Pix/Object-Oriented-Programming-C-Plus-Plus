#include <iostream>
using namespace std;

/** sumofThree
 * @brief returns the sum of x, y, and z
 *
 * @param x : (int)
 * @param y : (int)
 * @param z : (int)
 * @return int
 */
int sumofThree(int x, int y, int z) {
    return x + y + z;
}


/** division
 * @brief returns x/y
 *
 * @param x :(double)
 * @param y :(double)
 * @return double 
 */
double division(double x, double y) {
    return x / y;
}
  
/** isGreaterThan
  * @brief output the statements based on func_type
  *
  * @param x : (double)
  * @param y : (int)
  * @return true : x is great than y
  * @return false : x is less than or equal to y
*/
bool isGreaterThan(double x, double y) {
    if(x > y){
    cout << x << "is greater than" << y << "\n" << endl;
    return true;
    }else{
        cout << x << "x is less than or equal to" << y << "\n" << endl;
        return false;
    }
}

e login

string select(string func_type) {
    if (func_type == "sum") {
        return "The sum is ";
    } else if (func_type == "division") {
        return "The quotient is ";
    } else if (func_type == "comparison") {
        return "The first value being greater than the second value is ";
    } else {
        return "invalid function type\n";
    }
}


/** myPrint
* @brief Calls srlrct() to print out the output ith the correct prompt
*
* @tparam T : (int, double, or string) output of sum, division, or isGreater Than
* @param func_type : (string)
*@param output
*/
template <typename T>
void myPrint(string func_type, T output){
    cout << select(func_type) <<output <<endl;
}

int main(){
    //initialize 3 int parameters
    int x1 = 2;
    int x2 = 3;
    int x3 = 5;

    // call sumofThree
    int sum_out =sumofThree(x1, x2, x3);
    // call myPrint
    myPrint("sum", sum_out);

    //initialize 2 double parameters
    double dividend = 12345.1;
    double divisor = 2345.6;

    //call division
    double div_out = division(dividend, divisor);
    myPrint("division", div_out);

    // compare div_out and sum_out
    bool is_greater_out =isGreaterThan(div_out, sum_out);
    myPrint("comparison", is_greater_out);


    return 0;
}
