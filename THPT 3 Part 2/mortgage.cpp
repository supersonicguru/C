/*
    Program: THPT 3 Part 2
    Author: Christian Spratt-Wilks
    Lab Section: 11
    Date: 11/5/13
    Purpose:The purpose of this program is to calculate and output the payoff of a mortgage loan.
*/

#include <iostream>
#include<math.h> //allows me to use exponents
#include <iomanip> //allows me to show only 2 decimal places

using namespace std;

float validInfo(float, float, float); //checks if the info inputed is valid
float calcMortgageLoan(float, float, float); //calculates the monthly payment of the mortgage loan
void calcAmortization(float, float, float, float, float, float); //calculates the amortization for each month

int main()
{
    float loanBorrowed; //the amount of the loan
    float interestRate; //the interest rate of the loan
    float loanYears; //the amount of years you have to pay off the loan
    float valid; //to check if the input was valid
    float monthlyInterest; //the interest each month
    float loanMonths; //the amount of months you have to pay off the loan
    float monthlyPayment; //the amount you have to pay each month
    float currentMonthlyInterest; //the currect interest for that month
    float principalForMonth; // the principal for the month
    float newPrincipal; //the new principal
    char answer; //to see if the person would like to calculate another loan

    do // the loop to do everything all over again
    {

do{ // to loop the input untill the input is valid
    cout << "What is the ammount of your loan?" << endl;
    cin >> loanBorrowed; //the input of the loan amount

    cout << "What is the annual interest rate of your loan?" << endl;
    cin >> interestRate; //the interest rate of the loan

    cout << "What is the number of years of the loan?" << endl;
    cin >> loanYears; //the amount of years to pay off the loan

    valid = validInfo(loanBorrowed, interestRate, loanYears); //calls the function to see if the input is valid

}while(valid == 0);

monthlyInterest = interestRate/(12*100); //the math for the interest each month
loanMonths = loanYears * 12; //the math to see how many months is granted for the loan

monthlyPayment = calcMortgageLoan(loanBorrowed, monthlyInterest, loanMonths); //calls the function to do that math for the monthly payment

cout << "Your monthly payment is $"<< setprecision(2) << fixed << monthlyPayment; // out puts the monthly payment

 calcAmortization(currentMonthlyInterest, loanBorrowed, monthlyInterest,principalForMonth, monthlyPayment, newPrincipal); //calls the funtion to calculate and output the amortization

 cout << endl << "Would you like to do calculate another loan? Type Y for yes, Other keys for no."; //asks the user if they wish to calculate another loan
 cin >> answer; //the user's answer


    } while(answer == 'Y' || answer == 'y');

    return 0;
}

/********************************************************************************************************************************************************/

/*

Function Name: validInfo
Purpose: To check if the user's input is valid
Incoming Parameters: loanBorrowed is the amount of money borrowed, interetRate is the interest rate of the loan, and loanYears
is the number of years you have to pay off the loan
Return Value: it returns valid which will either be 0 or 1.


*/

float validInfo(float loanBorrowed, float interestRate, float loanYears) //checks if the input is valid
{
    float valid;

    if(loanBorrowed <= 0 || interestRate <= 0 || loanYears <= 0) //checks if the input is below or equal to 0
    {
        valid = 0;
    }
    else
    {
        valid = 1;
    }


    return valid;
}

/*****************************************************************************************************************************************/

/*

Function Name: calcMortgageLoan
Purpose: To calculate the monthly payment of the loan
Incoming Parameters: loanBorrowed is the amount of money borrowed, interetRate is the interest rate of the loan, and loanMonths
is the number of months you have to pay off the loan
Return Value: returns monthlyPayment which is the monthly payment for the loan

*/


float calcMortgageLoan(float loanBorrowed, float monthlyInterest, float loanMonths)
{
    float monthlyPayment;

    monthlyPayment = loanBorrowed * (monthlyInterest/ (1 - (pow(1+ monthlyInterest, -1* loanMonths))));

    return monthlyPayment;
}

/******************************************************************************************************************************************/


/*

Function Name: clacAmortization
Purpose: To calculate and output the monthly interest, the amount of principal you have to pay for the month,
         and the new balance of the principal
Incoming Parameters: currentMonthlyInterest is the current interest for the month, loanBorrowed is the amount of money borrowed,
monthlyInterest is the interest for that month, principalForMonth is the principal for the month, monthlyPayment is the amount you have to pay for the month
, and newPrincipal is the new principal amount that you have to pay.
Return Value: since it is void it doesn't return anything but it "returns"  the output that the function is generating


*/



void calcAmortization(float currentMonthlyInterest, float loanBorrowed, float monthlyInterest, float principalForMonth, float monthlyPayment, float newPrincipal) //calculates and outputs the amortization
{
    int count = 0; // the "counter" for the periods
    do //loops till the loanBorrowed parameter equals 0
    {
            currentMonthlyInterest = loanBorrowed * monthlyInterest; //the math for the current monthly interest
            principalForMonth = monthlyPayment - currentMonthlyInterest; //the math for the principal for the month
            newPrincipal = loanBorrowed - principalForMonth; //the new principal of the loan
            loanBorrowed = newPrincipal; //makes loanBorrowed equal whatever newPrincipal becomes
            count = count + 1; //increases the "counter" by 1 everytime this loops

            cout<< endl;

            cout<< "Period"<<count<<endl<<endl; //output the period.
            cout<< "Your current monthly interest is $" << currentMonthlyInterest << endl; //outputs the current monthly interest
            cout<< "The ammount of principal you have to pay for this month is $"<< principalForMonth << endl; //outputs the principal for the month
            cout<< "The new balance of your principal is now $" << newPrincipal << endl; //outputs the new balance of the principal

    } while(loanBorrowed > 0);

}
