/*
    Program:THPT 5
    Author: Christian Spratt-Wilks
    Lab Section: 11
    Date: 11/28/13
    Purpose: To display a menu of options for the customor and for the employee
*/



#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); //generates random numbers
    char seats[22][7]; //the array to make the seats
    int randomseats = rand()%2 + 1; //generates random
    char rows[7] = {'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G'}; //helps generate the letters for the columns
    char choice; //the input for how the customer choose how they will choose a seat
    int seatchoicerow; //the row that the customer chooses
    int seatchoicecol; //the column that the customer chooses
    char bookfirstclass; //to see if they booked a seat in first class
    char bookbusinessclass; //to see if they booked a seat in business class
    char bookeconomyclass; //to see if they booked a seat in economy class
    char ticketType; //to check the ticket type
    int randomrow; //a random generated row
    int randomcol; //a random generated column
    char choiceinput; //to check if the user is a customer or a employee
    int bookingprice = 0; //total amount of your bill
    char askToBook; //to see if the customer wish to book more seats
    int booked = 0; //how many seats were booked
    int notbooked = 0; //how many seats were notbooked
    int firstbooked = 0; //how many seats are booked in first class
    int businessbooked = 0; //how many seats are booked in business class
    int economybooked = 0; //how many seats are booked in economy class
    int flightmoney; //how much money  made in the flight

    cout << "Hello, here are the available seats" << endl;

    for(int r=0; r<7; r++)
    {
        cout<< "\t" << rows[r]; //generates the letters for the colums
    }

    cout << endl;

    for(int k=0; k<22; k++)
    {
        cout << "ROW " << k+1 << " \t"; //genenerates the letters for the rows

        for(int i=0; i<7; i++)
        {
        randomseats = rand()%2 + 1; //generates random 1's and 2's

        if(randomseats == 1)
        {
            seats[k][i] = '*' ;
        }

        if(randomseats == 2)
        {
            seats[k][i] = 'X' ;
        }

            cout << seats[k][i] << "\t"; //outputs the seats
        }
    cout << endl;

    }

    cout << "Welcome, if you are a customer press C, if you are an employee Press E." << endl;
    cin >> choiceinput; //to see if the user is a customer or an employee

    if(choiceinput == 'E' || choiceinput == 'e')
    {
        cout << "Heres an update of the seating chart." << endl;

            for(int r=0; r<7; r++)
    {
        cout<< "\t" << rows[r];
    }

    cout << endl;

    for(int k=0; k<22; k++)
    {
        cout << "ROW " << k+1 << " \t";

        for(int i=0; i<7; i++)
        {
        randomseats = rand()%2 + 1;

        if(randomseats == 1)
        {
            seats[k][i] = '*' ;

            notbooked = notbooked + 1; //counter for seats that are not booked
        }

        if(randomseats == 2)
        {
            seats[k][i] = 'X' ;

            booked = booked + 1; //counter for seats that are booked
        }

        if(k >= 0 && k <= 3)
        {
            if(seats[k][i] == 'X')
            {
                firstbooked++; //counter for seats booked in first class
            }

        }

         if(k >= 4 && k <= 7)
        {
            if(seats[k][i] == 'X')
            {
                businessbooked++; //counter for seats booked in business class
            }

        }

         if(k >= 8 && k <= 21)
        {
            if(seats[k][i] == 'X')
            {
                economybooked++; //counter for seats booked in economy class
            }

        }

            cout << seats[k][i] << "\t";
        }
    cout << endl;

    }

    cout << booked << " seats are booked and " << notbooked << " seats are not booked" << endl;
    cout << firstbooked << " seats have been booked in first class" << endl;
    cout << businessbooked << " seats have been booked in business class" << endl;
    cout << economybooked << " seats have been booked in economy class" << endl;
    flightmoney = (firstbooked * 3600) + (businessbooked * 1500) + (economybooked * 550);
    cout << "$" << flightmoney << " was taken for the entire flight";


    }

    if(choiceinput == 'C' || choiceinput == 'c')
    {
        do{

    cout << "If you would like to choose a seat press S" << endl;
    cout << "If you would like to choose a ticket type press T" << endl;
    cin >> choice; //user choice to how to book a seat

    if(choice == 'S' || choice == 's')
    {
        do{
        cout << "Please choose the row you wish to sit in" << endl;
        cin >> seatchoicerow; //row of choice


        cout << "Please choose the column you wish to sit in, A=1, B=2, C=3, etc" << endl;
        cin >> seatchoicecol; //column of choice
        }while(seatchoicerow > 22 || seatchoicerow < 1 || seatchoicecol > 7 || seatchoicecol < 1);


    if(seats[seatchoicerow][seatchoicecol] == 'X')
    {

        do
        {
            do{
            cout << "Please choose another seat, that seat is taken." << endl << endl;

            cout << "Please choose the row you wish to sit in" << endl;
            cin >> seatchoicerow;

            cout << "Please choose the column you wish to sit in, A=1, B=2, C=3, etc" << endl;
            cin >> seatchoicecol;
            }while(seatchoicerow > 22 || seatchoicerow < 1 || seatchoicecol > 7 || seatchoicecol < 1);

        }while (seats[seatchoicerow][seatchoicecol] == 'X');

    }

    if(seats[seatchoicerow][seatchoicecol] == '*')
    {
        if(seatchoicerow >= 1 && seatchoicerow <= 4)
        {
            cout << "Your ticket will cost $3600. Would you like to book this seat?" << endl;
            cout << "Y for yes N for no" << endl;
            cin >> bookfirstclass; //choice to book a first class seat

             if(bookfirstclass == 'Y' || bookfirstclass == 'y')
             {
                 bookingprice = bookingprice + 3600;
             }
        }

        if(seatchoicerow >= 5 && seatchoicerow <= 8)
        {
            cout << "Your ticket will cost $1500. Would you like to book this seat?" << endl;
            cout << "Y for yes N for no" << endl;
            cin >> bookbusinessclass; //choice to book a business class seat

            if(bookbusinessclass == 'Y' || bookbusinessclass == 'y')
             {
                 bookingprice = bookingprice + 1500;
             }
        }


        if(seatchoicerow >= 9 && seatchoicerow <= 22)
        {
            cout << "Your ticket will cost $550. Would you like to book this seat?" << endl;
            cout << "Y for yes N for no" << endl;
            cin >> bookeconomyclass; //choice to book a economy class seat

            if(bookeconomyclass == 'Y' || bookeconomyclass == 'y')
             {
                 bookingprice = bookingprice + 550;
             }
        }

    }

    }

 if(choice == 'T' || choice == 't')
    {
    cout << "What kind of ticket would you like?" << endl;
    cout << "Type F for First Class, B for Business Class, and E for Economy Class" << endl;
    cin >> ticketType; //type of ticket the customer chooses

    if(ticketType == 'F' || ticketType == 'f')
    {
        for(int r=0; r<7; r++)
    {
        cout<< "\t" << rows[r];
    }

    cout << endl;

    for(int k=0; k<4; k++)
    {
        cout << "ROW " << k+1 << " \t";

        for(int i=0; i<7; i++)
        {

            cout << seats[k][i] << "\t";
        }
    cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << "Please look at the seating chart above and compare it to the one below"<<endl;
    cout << "The * that was replaced with an X is now your seat"<<endl<<endl;

    do
    {
        randomrow = rand()%4; //generates a random row
        randomcol = rand()%8; //generates a random column
        seats[randomrow][randomcol]; //a random seat
    }while(seats[randomrow][randomcol] == 'X');

    seats[randomrow][randomcol] = 'X';

    for(int r=0; r<7; r++)
    {
        cout<< "\t" << rows[r];
    }

    cout << endl;

    for(int k=0; k<4; k++)
    {
        cout << "ROW " << k+1 << " \t";

        for(int i=0; i<7; i++)
        {

            cout << seats[k][i] << "\t";
        }
    cout << endl;
    }

    cout<<endl;
    cout<< "The ticket will cost $3600. Do you wish to book this seat?" << endl;
    cout << "Y for yes, N for no." << endl;
    cin>> bookfirstclass; //to see if the customer wants to book the seat

    if(bookfirstclass == 'Y' || bookfirstclass == 'y')
        {
            bookingprice = bookingprice + 3600;
        }

    }


    if(ticketType == 'B' || ticketType == 'b')
    {
        for(int r=0; r<7; r++)
    {
        cout<< "\t" << rows[r];
    }

    cout << endl;

    for(int k=4; k<8; k++)
    {
        cout << "ROW " << k+1 << " \t";

        for(int i=0; i<7; i++)
        {

            cout << seats[k][i] << "\t";
        }
    cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << "Please look at the seating chart above and compare it to the one below"<<endl;
    cout << "The * that was replaced with an X is now your seat"<<endl<<endl;

    do
    {
        randomrow = rand()%4+5; //generates a random row
        randomcol = rand()%8; //generates a random column
        seats[randomrow][randomcol];
    }while(seats[randomrow][randomcol] == 'X');

    seats[randomrow][randomcol] = 'X';

    for(int r=0; r<7; r++)
    {
        cout<< "\t" << rows[r];
    }

    cout << endl;

    for(int k=4; k<8; k++)
    {
        cout << "ROW " << k+1 << " \t";

        for(int i=0; i<7; i++)
        {

            cout << seats[k][i] << "\t";
        }
    cout << endl;
    }

    cout<<endl;
    cout<< "The ticket will cost $1500. Do you wish to book this seat?" << endl;
    cout << "Y for yes, N for no." << endl;
    cin>> bookbusinessclass; //to see if the customer wants to book the seat

    if(bookbusinessclass == 'Y' || bookbusinessclass == 'y')
        {
            bookingprice = bookingprice + 1500;
        }

    }

    if(ticketType == 'E' || ticketType == 'e')
    {
        for(int r=0; r<7; r++)
    {
        cout<< "\t" << rows[r];
    }

    cout << endl;

    for(int k=8; k<22; k++)
    {
        cout << "ROW " << k+1 << " \t";

        for(int i=0; i<7; i++)
        {

            cout << seats[k][i] << "\t";
        }
    cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << "Please look at the seating chart above and compare it to the one below"<<endl;
    cout << "The * that was replaced with an X is now your seat"<<endl<<endl;

    do
    {
        randomrow = rand()%13+9; //generates a random row
        randomcol = rand()%8; //generates a random column
        seats[randomrow][randomcol];
    }while(seats[randomrow][randomcol] == 'X');

    seats[randomrow][randomcol] = 'X';

    for(int r=0; r<7; r++)
    {
        cout<< "\t" << rows[r];
    }

    cout << endl;

    for(int k=8; k<22; k++)
    {
        cout << "ROW " << k+1 << " \t";

        for(int i=0; i<7; i++)
        {

            cout << seats[k][i] << "\t";
        }
    cout << endl;
    }

    cout<<endl;
    cout<< "The ticket will cost $550. Do you wish to book this seat?" << endl;
    cout << "Y for yes, N for no." << endl;
    cin>> bookeconomyclass; //to see if the customer wants to book the seat

        if(bookeconomyclass == 'Y' || bookeconomyclass == 'y')
        {
            bookingprice = bookingprice + 550;
        }

    }




    }

    cout << "Do you wish to book another seat? Type Y for yes and N for no." << endl;
    cin >> askToBook; //to see if the customer wish to book another seat

        }while(askToBook == 'Y' || askToBook == 'y');

    cout << "The total amount that you have to pay is $" << bookingprice << endl;
    }




    return 0;
}
