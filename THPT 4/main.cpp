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
 srand(time(0));
 int numOfDice = 6;
 int dice[6];
 int remove;
 char rollAgain;

    for(int k=0; k< numOfDice; k++)
    {
        dice[k] = rand()%6+1;
    }

    for(int k=0; k< numOfDice; k++)
    {
        cout<< dice[k] << " ";
    }

    cout << "How many dice do you want to remove? :";
    cin >> remove;

    numOfDice = numOfDice - remove;

    cout << "Do you want to roll again? Enter Y for yes";
    cin >> rollAgain;

    if (rollAgain == 'Y')
    {
            for(int k=0; k< numOfDice; k++)
    {
        cout<< dice[k] << " ";
    }

    }

    return 0;
}
