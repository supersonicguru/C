/*
    Program: IHPT Prob 2
    Author: Christian Spratt-Wilks
    Lab Section: L11
    Date: 10/6/2013
    Purpose: this program takes the inputs of the customer and calculate the customer's
    bill for a local cable company
    Algorithm: 1) Read the problem over and over to make sure you understand
                  what you need to be doing
               2) Make sure you know how to make and call a function before you start doing
                  the math
               3) Do the math for the needed functions
               4) Begain to write your code
               5) Run your program to see if there are any errors
               6) Put in different inputs to see if your code works correctly.



*/

#include <iostream>
#include <iomanip>

using namespace std;

float calcResidential(float , float , float , int); //the function that does the calculations for a residential customer
float calcBusiness(float , float , float , int , int); //the function that does the calculations for a business customer

int main()
{
   char customerType;  //the character input so the customer can choose what type of customer they are
   float finalResiBill; //the bill ammount for residential customer
   int resiPremChannels; //the ammount of premium channels a residential customer has
   int accountNumber; //the account number of the customer
   int customerCode; //the customer's code
   int serviceConnections; //the ammount of basic service connections that a business has
   float finalBusibill; //the bill ammount for business customers
   int busiPremChannels; //the ammount of premium channels a business customer has

   cout << "What type of customer are you? Type R for residential and B for business." << endl;
   cin >> customerType; //input of the type of customer that is asking for their bill

   if (customerType == 'R'){ //if statment for if it is a residential customer
        cout << "What is your account number?" << endl;
        cin >> accountNumber; //input of the customer's account number

        cout << "Please enter your code." << endl;
        cin >> customerCode; //input of the customer's code

        cout <<"How many premium channels do you have?" << endl;
        cin >> resiPremChannels; //input of the ammount of premium channels that the customer owns

    finalResiBill = calcResidential(4.50 , 20.50 , 7.50, resiPremChannels); //the ammount of money for each fee and the input of the premium channels
    cout << "Your account number: " << accountNumber << endl; //output of the customer's account number
    cout << "Your billing ammount is $" << setprecision(2) << fixed << finalResiBill << endl; //output of the bill for the customer

    }

         if (customerType == 'B') { //the if statement for if the customer is a business
            cout << "What is your account number?" << endl;
            cin >> accountNumber; //input of the customer's account number

            cout << "Please enter your code." << endl;
            cin >> customerCode; // input of the customer's code

            cout <<"How many premium channels do you have?" << endl;
            cin >> busiPremChannels; //input of the ammount of premium channels that the customer owns

            cout << "How many basic service connections do you have?" << endl;
            cin >> serviceConnections; //input of the ammount of basic service connections that the customer owns

            finalBusibill = calcBusiness(15.00 , 75.00 , 50.00 , busiPremChannels , serviceConnections); //the ammount of money for each fee and the number of premium channels and basic service connections
            cout << "Your account number: " << accountNumber << endl; //output of the customer's account number
            cout << "Your billing ammount is $" << setprecision(2) << fixed << finalBusibill << endl; //output for the bill of the customer
   }


    return 0;
}

/**********************************************************************************************************************************************/

    /*
    Function Name: calcResidential
    Purpose: this function is used to calculate the bill for a residential customer
    Incoming Parameters: resiProcessingFee is the fee for processing the bill
                         resiServiceFee is the fee for a basic service
                         resiChannelsFee is the fee for having premium channels
                         resiPremChannels is the ammount of premium channels the customer owns
    Return Value: resiBill is the ammount of the bill

    */


    float calcResidential(float resiProcessingFee , float resiServiceFee , float resiChannelsFee , int resiPremChannels){
        float resiBill;
        resiBill = resiProcessingFee + resiServiceFee + (resiChannelsFee * resiPremChannels);

        return resiBill;

}

/**************************************************************************************************************************************************************/

    /*
    Function Name: calcBusiness
    Purpose: this function is used to calculate the bill for a business customer
    Incoming Parameters: busiProcessingFee is the fee for processing the bill
                         busiServiceFee is the fee for a basic service
                         busiChannelsFee is the fee for having premium channels
                         busiPremChannels is the ammount of premium channels the customer owns
                         serviceConnections is the ammount of basic service connections the customer owns
    Return Value: busiBill is the ammount of the bill

    */

    float calcBusiness(float busiProcessingFee , float busiServiceFee , float busiChannelsFee , int busiPremChannels , int serviceConnections) {
        float busiBill;
            if (serviceConnections > 10) {
               busiBill = busiProcessingFee + busiServiceFee + ( (serviceConnections - 10) * 5.00) + (busiChannelsFee * busiPremChannels);
              } else {
                   busiBill = busiProcessingFee + busiServiceFee + (busiChannelsFee * busiPremChannels);
            }

            return busiBill;
     }




