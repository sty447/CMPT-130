#include <iostream>
#include <iomanip>
using namespace std;

const int daysInYear = 365;
const int minorAgeCap = 19;
const int seniorAge = 65;

int main(){

    // heading

    cout << "song libary" << endl;
    cout << "***********" << endl << endl ;

    int songs = 0;

    cout << "Inital number of songs:               " << setw(3) << songs << endl;

    songs = 10;
    cout << "Number of songs after first purchase: " << setw(3) << songs << endl;

    songs = 654;
    cout << "Number of songs after today:          " << setw(3) << songs << endl << endl;

    /*

    answer to 1 part 9

    Q:  What is the difference between defining a variable and using a variable?
    A:  defining a variable tell the program the what the variable is and store it, while using a variable uses the store input from the when variable is defined to 
    tell the program what to do or what it is when the variable is mention in code.

    Q:  When reading a program, how can you tell where a variable is defined?
    A:  when the variable is followed by the = sign.

    Q: What happens if you try to redeclare a variable? 
    A: there will be a complier error stating that the variable cannot be redeclared

    */

   
    // age conversion

    int inputAge = 0;
    cout << "Please enter your age in years " << endl;
    cin >> inputAge;

    int daysLived = daysInYear * inputAge;
    cout << "On your last birthday you had lived " << daysLived << " days!" << endl;

    int decades = inputAge / 10;
    cout << "This is also " << decades << " decades" << endl;

    int nextDecades = inputAge % 10;
    int yearTillDecades = 10 - nextDecades;
    cout << "In " << yearTillDecades << " year, you will be one decade older" << endl;

    // i don't why it treat the double (centuries) like a int so i add a new variable that the same as the input value so it can dispay the correct number of centuries
    double inputAgeDouble = inputAge;
    double centuries = inputAgeDouble / 100;
    cout <<"you are now " << centuries << " centuries old!" << endl;

    /* answer for 2 part 8
    
    Q: What inputs would make it easy (obvious) to test the number of days calculations?
    A: 1 (year)

    */

    
    // minor ,senior
    string feeling;

    if (inputAge < minorAgeCap){
        
        cout << "You are a minor in BC" << endl << endl;

    }

    if ( inputAge >= seniorAge){

        cout << "You are a senior in BC" << endl;
        int ageOverSenior = inputAge - seniorAge;
        cout << "You have been a senior for " << ageOverSenior << " years" << endl;
        cout << "How do you feel like being senior" << endl;
        cin >> feeling;
        cout << "“One’s life has value so long as one attributes value to the life of others, by means of love, friendship, indignation and compassion.” — Simone De Beauvoir" << endl;
        cout << endl;



    }

    /*Did you use a block with curly braces { } for both your if statements? 

        answer: yes

        a. Imagine you did not for the first if statement; do you think you would always
           remember to add them when you added extra code to the then part of the if
           statement?

        answer: probaly not ;howerver, I usually make sure my if statement have {}

        b. Imagine you did not for the second if statement. What would have happened?

        answer: the then part of the if statement would have display without being restricted by the condition set by the if statement 

        Can you think of an invalid age which is still an integer? What does the program do
        when you enter this invalid age? What could you do to have your program not do
        anything if the user enters such an invalid age?

        answer: negative number for example -1, the program will work fine but display numbers in the neagtive,
        put the code in a if statement with a condition that restrict the age number to be bigger or equal to zero with an else statement output invaild output
        and when the enter the value is invailed it display invailed and doesn't run the code.
    */
    return 0;
}