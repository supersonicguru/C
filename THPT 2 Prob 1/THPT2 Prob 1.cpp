    /*
    Program: IHPT Prob 1
    Author: Christian Spratt-Wilks
    Lab Section: L11
    Date: 10/6/2013
    Purpose: This program is calculates and prints out the cell phone bill for a
    cell phone company.It will ask the person to put in the plan that they have and how
    many minutes were used.
    Algorithm:  1) read the problem several times to understand it
                2) figure out the math you need for the code
                3) write the code
                4) look over the code several times and run it to make sure there
                are no errors
                5) use different inputs to see if the math is done correctly
    */



#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int regMinutes;     //the minutes used for the regular phone plan
    int premMinutesAM;  //the minutes used for the premium phone plan between 6am and 6pm
    int premMinutesPM;  //the minutes used for the premium phone plan between 6pm and 6am
    float regCost;      //the cost for the regular phone plan
    float premCostAM;   //one part of the cost for the premium phone plan if you exceeded the number of free minutes between 6am and 6pm
    float premCostPM;   //one part of the cost for the premium phone plan if you exceeded the number of free minutes between 6pm and 6am
    float premFinalCost; // the final cost for the premium phone plan
    char phonePlan;     //the user input for what type of phone plan they have

    cout << "What phone plan do you have? Type R for Regular and P for Premium" << endl;
    cin >> phonePlan; //the user input their phone plan

    if (phonePlan == 'R') {
        cout << "How many minutes did you use?" << endl;
        cin >> regMinutes;
            if (regMinutes > 200)
                regCost = 20.00 + (regMinutes - 200) * 0.15; //the math for the phone bill if they exceed 200 minutes
            else
                regCost = 20.00; //if the user do not go over 200 minutes this is their phone bill
                cout << "Your phone bill is $" << setprecision(2) << fixed << regCost << endl; //the bill output for the regular phone plan

    }

    if(phonePlan == 'P'){
        cout << "How many minutes have you used between 6am and 6pm?" << endl;
        cin >> premMinutesAM;

        cout << "How many minutes have you used between 6pm and 6am?" << endl;
        cin >> premMinutesPM;
            if (premMinutesAM > 100){
                premCostAM = (premMinutesAM - 100) * 0.10; //the math for the phone bill if you exceed 100 minutes
            }
            if (premMinutesPM > 300) {
                premCostPM = (premMinutesPM - 300) * 0.05; //the math for the phone bill if you exceed 300 minutes
                premFinalCost = premCostAM + premCostPM + 35.00; //the math for the final out come of the phone bill
                }
            else{
                premFinalCost = 35.00; //if the user does not go over their minute limits this is their phone bill
            }

            cout << "Your phone bill is $" << premFinalCost; //the bill output for the premium phone plan
    }

    return 0;
}
