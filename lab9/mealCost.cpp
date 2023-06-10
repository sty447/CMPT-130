// This program determines total buffet luncheon cost when
// the number of guests and the per person cost are known.
// It contains a logic error.
// By Gaddis, modified by B Fraser.
#include <iostream>
#include <iomanip>
using namespace std; 

const int ADULT_MEAL_COST = 6.25; // Child meal cost = 75% of this

int main()
{
    // Get number of adults and children attending
	cout << "This program calculates total cost "
	    << "for a buffet luncheon.\n";

	int numAdults = 0;
    cout << "Enter the number of adult guests (age 12 and over): ";
    cin >> numAdults;

    int numChildren = 0;
    cout << "Enter the number of child guests (age 2-11): ";
    cin >> numChildren;

	// Calculate meal costs
	double adultMealTotal = numAdults * ADULT_MEAL_COST;
	double childMealTotal = numChildren * ADULT_MEAL_COST * .75;
	double totalMealCost  = adultMealTotal + childMealTotal;

	// Display total meal cost
	cout << fixed << setprecision(2);
	cout << "\nTotal buffet cost is " << totalMealCost << endl;
	return 0;
}