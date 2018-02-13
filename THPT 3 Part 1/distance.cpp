/*
    Program: THPT 3 Part 1
    Author: Christian Spratt-Wilks
    Lab Section: 11
    Date: 11/5/13
    Purpose:The purpose of this program was to generate a random function from numbers between 1 and 200
    (including 1 and 200) and generating 20 other functions and seeing which of the 20 functions is the closest and the furthest
    from out first function.
*/


#include <iostream>
#include <cstdlib> //this is for srand
#include <ctime>   //this is for srand

using namespace std;

float calcCloseDistance(int, int[], int, int[]); //the function to do the math for the furthest function
float calcFarDistance(int, int[], int, int[]);  //the function to do the math for the closest function
void calcDistance(int, int[], int, int[]); //the function to output distances of 2 functions.

int main()
{
    srand(time(0)); //starts the random generator
    int firstX = rand()%199 + 1; //the X for our first function
    int firstY = rand()%199 + 1; //the Y for our first function
    int randX = rand()%199 + 1; //the random X for the 20 other functions
    int randY = rand()%199 + 1; //the random Y for the 20 other functions
    int arrayX [20]; //the array to hold the 20 different X's for the 20 other functions
    int arrayY [20]; //the array to hold the 20 different Y's for the 20 other functions
    float closeDistance; //the closest distance from our first function and 1 of the 20 other functions
    float farDistance; //the furthest distance from our first function and 1 of the 20 other functions
    int count; //our ''counter'' for our array

    cout<< "The x of our function is " << firstX << " and the y of our funtion is " << firstY << endl; //the output of our first function

    for(count=0; count<20; count++) // the for loop to generate our 20 random functions
    {
        arrayX[count] = randX; //inputs the random numbers into the array
        randX = rand()%199 + 1; //re do the randomness of our X

        arrayY[count] = randY; //inputs the random numbers into the array
        randY = rand()%199 + 1; //re do the randomness of our Y
    }


        farDistance = calcFarDistance(firstX, arrayX, firstY, arrayY); //calls out to the function to do the math of the furthest function

        closeDistance = calcCloseDistance(firstX, arrayX, firstY, arrayY); //calls out to the function to do the math of the closest function


    cout << endl; //adds space to our output

    cout << "The furthest distance from our first point to the second point is "<< farDistance << endl; //outputs the furthest distance

    cout << endl;

    cout << "The closest distance from out first point to the second point is "<< closeDistance << endl; //outputs the closest distance

    cout << endl << "X Coordinates" << endl << endl;

    for(count=0; count<20; count++)
    {
        cout << arrayX[count] << endl; //outputs all of the X's of the 20 functions
    }

    cout << endl << "Y Coordinates" << endl  << endl;

    for(count=0; count<20; count++)
    {
        cout << arrayY[count] << endl;//outputs all of the Y's of the 20 functions
    }

    cout << endl << "Distances" << endl << endl;

    calcDistance(firstX, arrayX, firstY, arrayY); //calls out to the function to calculate the distances between the functions and outputs them





    return 0;
}

/**************************************************************************************************************************************/

/*

Function Name: clacFarDistance
Purpose: To do the math to figure out the furthest distance from our first point to the 20 other functions
Incoming Parameters: firstX is the X of our first function, firstY is the Y of our first function,
                     arrayX holds the X's of the other functions, and arrayY holds the Y's of the other functions
Return Value: max is the furthest distance from our first function to the second function.


*/


float calcFarDistance(int firstX, int arrayX[], int firstY, int arrayY[]) //this function calculates the distance from our first point to the other 20 points
{
    float farDistance;
    float max = 0;
    int count;
    for(count=0; count<20; count++) //loops the math to make sure it checks all of the points
    {
    farDistance = (arrayX[count] - firstX)*(arrayX[count] - firstX) + (arrayY[count] - firstY)*(arrayY[count] - firstY);

    if(farDistance > max) //this checks all the distances and rewrites what max is to the highest value calculated
    {
        max = farDistance;

    }

    }

    return max;
}



/************************************************************************************************************************/


/*

Function Name: clacCloseDistance
Purpose: To do the math to figure out the closest distance from our first point to the 20 other functions
Incoming Parameters: firstX is the X of our first function, firstY is the Y of our first function,
                     arrayX holds the X's of the other functions, and arrayY holds the Y's of the other functions
Return Value: min is the closest distance from our first function to the second function.


*/



float calcCloseDistance(int firstX, int arrayX[], int firstY, int arrayY[])
{
    float closeDistance;
    float min = 90000;
    int count;
    for(count=0; count<20; count++) //loops the math to make sure it checks all of the points
    {
        closeDistance = (arrayX[count] - firstX)*(arrayX[count] - firstX) + (arrayY[count] - firstY)*(arrayY[count] - firstY);

    if(closeDistance < min) //this checks all the distances and rewrites what min is to the highest value calculated
    {
        min = closeDistance;
    }

    }

    return min;
}


/***************************************************************************************************************************************************/


/*

Function Name: clacDistance
Purpose: To do the math to figure out the distances from our first point to the 20 other functions
Incoming Parameters: firstX is the X of our first function, firstY is the Y of our first function,
                     arrayX holds the X's of the other functions, and arrayY holds the Y's of the other functions
Return Value: there is no return value since it is void but it "returns" the distances of our functions



*/


void calcDistance(int firstX, int arrayX[], int firstY, int arrayY[]) //this function calculates the distance from our first point to the other 20 points
{
    float distance;
    int count;
    for(count=0; count<20; count++) //loops the math to make sure it checks all of the points
    {
    distance = (arrayX[count] - firstX)*(arrayX[count] - firstX) + (arrayY[count] - firstY)*(arrayY[count] - firstY);

    cout << distance << endl; //outputs the distances

    }


}
