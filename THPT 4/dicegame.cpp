/*
    Program: THPT 4
    Author: Christian Spratt-Wilks
    Lab Section: 11
    Date: 11/22/13
    Purpose: To code a dice game so up to 2 people can play agaisnt each other.

*/




#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

 srand(time(0)); //to generate random numbers
 int numOfDice = 6; //the number of dice being rolled
 int dice[6]; //the dice
 int remove; //the number of dice being removed
 char rollAgain; //asking to roll again
 char restart; //ask to restart the game

 do{ // used to restart the whole game
    for(int k=0; k< numOfDice; k++)
    {
        dice[k] = rand()%6+1; //help generate the 6 days
    }

    for(int k=0; k< numOfDice; k++)
    {
        cout << dice[k] << " "; //the dices being outputed
    }
    cout << endl;

    cout << "How many dice do you want to remove? :";
    cin >> remove; //number of dice being removed

    numOfDice = numOfDice - remove; //math for the dice

    cout << "Do you want to roll again? Enter Y for yes";
    cin >> rollAgain; //asking the person to roll again

    if (rollAgain == 'Y' || rollAgain == 'y')
    {
            for(int k=0; k< numOfDice; k++)
    {
        cout<<  dice[k] << " "; //dice output
    }

    cout << endl;
    }

    cout << "Would you like to restart the game? Type Y for yes";
    cin >> restart; //restarts the game;

    }while(restart != 'Y'); //to restart the game



    return 0;
}
