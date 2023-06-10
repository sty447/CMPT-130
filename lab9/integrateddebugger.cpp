// Program to experiment with the integrated debugger.
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int factorial(int n) 
{
	int answer = 1;
	for (int i = 0; i < n; i++) {
		answer *= i;
	}
	return answer;
}

// Return the maximum number from a vector of integers.
// If the vector is empty, return 0.
int findMax(const vector<int> &vect)
{
	int max = 0;
	for (int val : vect) {
		if (val < max) {
			max = val;
		}
	}
	return max;
}

int main () 
{
	// Test factorial:
	const int MAX_FACTORIAL_TEST = 6;
	for (int n = 1; n <= MAX_FACTORIAL_TEST; n++) {
		cout << setw(2) << n 
				<< "! = " 
				<< setw(5) << factorial(n) << endl;
	}
	
	// Test findMax():
	cout << "a) " << findMax({1, 2, 3}) << endl;
	cout << "b) " << findMax({5, 0, 3, 4}) << endl;
	cout << "c) " << findMax({10}) << endl;
	cout << "d) " << findMax({-10}) << endl;
	cout << "e) " << findMax({}) << endl;
	cout << "f) " << findMax({100, 200, 34, -25, -2525, 3}) << endl;
	cout << "g) " << findMax({0}) << endl;
}