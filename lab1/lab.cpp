#include <iostream>
using namespace std;

int main (){

    // display hello world

    cout << "hello world \n";

    // display text, read input value ,complement value.

    int favNum = 0;
    cout <<"What is your favourite number? ";
    cin >> favNum;
    cout << "Wow! " << favNum << " is a great choice!" << endl;

    // fav colour

    string favColour;
    cout <<"What is your favourite colour? ";
    cin >> favColour;
    cout << "Wow! " << favColour << " is a nice colour !" << " My favorite colour is purple" << endl << endl;

    // JAM quote

    cout << "********** \n ";
    cout <<" A quote by Sir John A. Macdonald: \n ";
    cout <<" Let us be French, let us be English, but most importantly let us be Canadian! \n";
    cout << "********** \n " << endl;

    //extra challege retangle

    cout << " ********** \n ";
    cout << "*        * \n ";
    cout << "********** \n " << endl;

    //extra challege text

    cout << "He'll say, " << "\"WOW! She\\he did great!\"" << endl << endl;






return 0;


}