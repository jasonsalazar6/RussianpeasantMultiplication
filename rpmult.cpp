/*******************************************************************************
 * Name          : rpmult.cpp
 * Author        : Jason Salazar
 * Version       : 1.0
 * Date          : 4/25/2022
 * Description   : Performs Russian Peasant Multiplication.
 ******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

unsigned long russian_peasant_multiplication(unsigned int m, unsigned int n) {
    unsigned long russianResult = 0;
   // if m is greater than n, perform swap
    if(m>n){
    	swap(m,n);
    }
    unsigned long j=n;
    // if first number is odd then it is added to russianResult
    while (m>0){
    	if (m & 1)
    		russianResult = russianResult + j;
    	// functions n*2 and m/2
    	j = j << 1;
    	m = m >> 1;
    }
    return russianResult;
}

int main(int argc, char* const argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <integer m> <integer n>" << endl;
        return 1;
    }

    int m, n;
    istringstream iss;

    iss.str(argv[1]);
    if ( !(iss >> m) || m < 0 ) {
        cerr << "Error: The first argument is not a valid nonnegative integer."
             << endl;
        return 1;
    }

    iss.clear();
    iss.str(argv[2]);
    if ( !(iss >> n) || n < 0 ) {
        cerr << "Error: The second argument is not a valid nonnegative integer."
             << endl;
        return 1;
    }

    cout << m <<" x "<< n << " = "<< russian_peasant_multiplication(m,n) << endl;

    return 0;
}
