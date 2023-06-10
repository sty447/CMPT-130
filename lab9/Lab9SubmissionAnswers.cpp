

// PART 1 
// **********************************************************
// For the mealcost.cpp the issue with the code is a rounding error due to the 
// intial constant being a "int" which rounds the constant value to 6 when the desired value 
// is 6.25 so the solution to this is to replace the int with a double. 
// the way I found this out is by using 1 for the adults and 0 for kids and then using 0 for adults and 1 for kids 
// **********************************************************


// PART 2 
// **********************************************************
// To set up a break point you set a starting point where you want to continue off of 
// and a 2nd point at the line in which you want to break at   

// You can set a single step by using (F8)

// To see the variables between the bounds of the break point under run in the top left corner there is a tab for variables 
// which shows both global and local variables 

// bugs that would be great to explore with a debugger are  mathmatical issues or off by 1 errors 
// for example in my assignment mayan numbers a issue I had was an off by one error with how my vector was being stored so my print mayan 
// would print an extra layer and all hell would break loose 

// using break point would be great for not having to run the entire code but seperate sections
// which is great for long lines of code 

// **********************************************************

//    PART 3 
// **********************************************************
// The first  4 initial tests work because the total value starts at 0 
// but after that the value from the first 4 are not cleared once we go through the while loop again 
// another issue is due to the fact that we are doing integer division the decimals are rounded not saved in a way 
// The value of reducing duplicate code is that if the code messes up all of it messes up which makes the code messing up more easier to spot
// **********************************************************
