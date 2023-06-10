/* lab 9




 1 finding the bug

 Understanding 

 Q: What is the bug in the mealCost.cpp program?

 A: the constant of ADULT_MEAL_COST is interger not in double therefore it store 6 and not 6.25

 Q:How to carefully test a program is correct.

 A: By testing the the the value of 1 adult and zero children which should display 6.25 but it display 6
 
 2 Integrated Debugger

 Q:How do you set a breakpoint on a line of code?

 A: by clicking on the leftside of the number that show the line of the code,where it show a red dot

 Q:How do you step a program, one line at a time, to watch it execute?

 A: by using the step int and over function for my vscode the short cut is F10 and F11 after you use break and start debugging

 Q:How can you watch the values in a variable as it executes (without having to call
 cout all the time to print them)?

 A: by clicking on icon on the left side of the screen that look like the play with bug button and click variables and run the step into or over funnction

 Q: What kind of bug would be best explored with the debugger? A bug known to exist in
 a small function, like factorial() or a bug in a much bigger program, such as your
 most recent assignment? Why?

 A: long line of codes, because it test and check a small section of a big program with running the entire code

 3 Good test values

 Q:Explain why the initial 4 tests did not find any of the bugs
 
 A:total value started at zero so it worked

 Q:Explain how the second set of tests exercises different parts of the code than the first set

 A: the total value for the first 4 wasn't clear and was use when the while is run again, it code also does interger divison which mean 
 it cut off the decimals for the the result.

 Q:Briefly explain the value of a function for reducing duplicate code. Why can this reduce
 the number of bugs in a program

 A: the benifit of using function instead of reusing code help when there something wrong with the code,for a the function you just have to 
 change the function but when you reuse code you have look throught all of them and change all of them one by one.













*/