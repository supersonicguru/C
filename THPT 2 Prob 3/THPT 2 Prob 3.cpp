/*
    Program: THPT 2 Prob 3
    Author: Christian Spratt-Wilks
    Lab Section: L11
    Date: 10/7/13
    Purpose: This program calcualtes and prints out a student's average out of
             their 4 test grades and tells them if they are able to take the
             next course.
    Algorithm: 1) Read the problem so you know what to do
               2) Make sure you know how to produce output with your function
               3) Make sure you know what type of variables you need for your
                  function
               4) Begain writing out the functions need to do on paper and make
                  a prototype code on paper or in code blocks to see if your
                  ideas work
               5) Begain writing the code
               6) When finished make sure you test the program several times
                  before you feel like you are done with it


*/

#include <iostream>
#include <iomanip>

using namespace std;

float calcAverage(int , int , int , int); //this function calculates the average
char getLetterGrade(float); //this function produces the letter grade of the average
void enformStudent(char , float); //this function produces the output of weither or not the student can take the next course or not


int main()
{
    int firstTest; //this is the student's first test grade
    int secondTest; //this is the student's second test grade
    int thirdTest; //this is the student's third test grade
    int fourthTest; //this is the student's fourth test grade
    float average; //this is the average of the 4 test grades
    char letterGrade; //this is the letter grade of the average

    cout << "Enter the first test grade: " << endl;
    cin >> firstTest; //the student enters their first test grade

    cout << "Enter the second test grade: " << endl;
    cin >> secondTest; //the student enters their second test grade

    cout << "Enter the third test grade: " << endl;
    cin >> thirdTest; //the student enters their third test grade

    cout << "Enter the fourth test grade: " << endl;
    cin >> fourthTest; //the student enters their fourth test grade

    average = calcAverage(firstTest , secondTest , thirdTest , fourthTest); //this calls the function calcAverage

    letterGrade = getLetterGrade(average); //this calls the function getLetterGrade

    enformStudent(letterGrade , average); //this calls the funciton enformStudent




    return 0;
}
/**************************************************************************************************************************************/

/*
    Function Name: calcAverage
    Purpose: To calculate the average of the test grades
    Incoming Parameters: firstTest is the first test grade, secondTest is the
                         second test grade, thirdTest is the third test grade
                         fourthTest is the fourth test grade
    Return Value: average is the average of the test grades



*/

float calcAverage(int firstTest , int secondTest , int thirdTest , int fourthTest) { //this function calculates the average
    float average;
    average = (firstTest + secondTest + thirdTest + fourthTest) / 4.00; //this is the math for the average

    return average;

}

/*********************************************************************************************************/

/*
    Function Name: getLetterGrade
    Purpose: to produe the letter grade of the average
    Incoming Parameters: average is the average of the test grades
    Return Value: letterGrade is the letter grade os the average


*/

char getLetterGrade(float average) { //this function produces the letter grade of the average
    char letterGrade;

    if (average >= 90) {//if the average is grater than or equal to 90 it makes letterGrade an A
        letterGrade = 'A';
    }
    else if (average >= 80) { //if the average is grater than or equal to 80 it makes letterGrade a B
        letterGrade = 'B';
    }
    else if (average >= 70) { //if the average is grater than or equal to 70 it makes letterGrade a C
        letterGrade = 'C';
    }
    else if (average >= 60) { //if the average is grater than or equal to 60 it makes letterGrade a D
        letterGrade = 'D';
    }
    else if (average <= 59) { //if the average is grater than or equal to 59 it makes letterGrade a F
        letterGrade = 'F';
    }

    return letterGrade;

}

/************************************************************************************************************************************************************/

/*
    Function Name: enformStudent
    Purpose: to output the average, its letter grade, and weither or not the student can take the next course
    Incoming Parameters: letterGrade is the letter grade of the average and average is the average of the test grades
    Return Value:there is no return value since it is void but it "returns" the output in the if statements


*/

 void enformStudent(char letterGrade , float average) { //this function produces the output for weither the student can take the next course or not
    if(letterGrade == 'A'){
        cout << endl << "Your average is: " <<  setprecision(2) << fixed << average << " which is an " << letterGrade << ". You can take the next course."; //this produces the output for when the grade is an A
}
    else if(letterGrade == 'B') {
        cout << endl << "Your average is: " <<  setprecision(2) << fixed << average << " which is a " << letterGrade << ". You can take the next course."; //this produces the output for when the grade is a B
    }
    else if(letterGrade == 'C') {
        cout << endl << "Your average is: " <<  setprecision(2) << fixed << average << " which is a " << letterGrade << ". You can take the next course."; //this produces the output for when the grade is a C
    }
    else if(letterGrade == 'D') {
        cout << endl << "Your average is: " <<  setprecision(2) << fixed << average << " which is a " << letterGrade << ". You can take the next course."; //this produces the output for when the grade is a D
    }
    else if(letterGrade == 'F') {
        cout << endl << "Your average is: " <<  setprecision(2) << fixed << average << " which is a " << letterGrade << ". You can not take the next course."; //this produces the output for when the grade is a F
    }
 }
