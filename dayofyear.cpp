#include "stdafx.h"
#include <stdlib.h> 
#include <array>
#include <string>
#include <locale>  
#include <iostream>
using namespace std;
#include <fstream>

class dayofyear 
{
public:
	dayofyear(int day);	// constructor with initial values for day or passed values
	dayofyear(string month, int day);
	void setDay(int day);  // set values for dayofyear
	void getDay();  // get day from keyboard
	void getMonth();
	void getDayperMo(); // get day from keyboard bounded by month 
	void print();

	//in/decrement
	dayofyear operator++();
	dayofyear operator--();

private:
	int myDay;
	string myMonth;
	int daysInMonth(int month);
	int calcDays();
	const string months[12] { "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER" } ;
	const int days[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	bool monthEntered = false;
};

dayofyear::dayofyear(int day = 0)
{
	myDay = day;
}

dayofyear::dayofyear(string month = "", int day=0)
{
	myMonth = month;
	myDay = day;
	monthEntered = true;
}

dayofyear dayofyear::operator++()
{
	myDay++;
	if (myDay == 366)
		myDay = 1;
	return *this;
}

dayofyear dayofyear::operator--()
{
	myDay--;
	if (myDay == 0)
		myDay = 365;
	return *this;
}

void dayofyear::setDay(int day)
{
	myDay = day;
}

int dayofyear::daysInMonth(int month)
{
	if ((month % 2 != 0 && month <= 7) || (month % 2 == 0 && month > 7))
		return 31;
	else if (month != 2)
		return 30;
	else if (month == 2)
	{
		return 28;
	}
	return -1;
}

int dayofyear::calcDays()
{	
	int mo = 0;
	int remaining = myDay;
	while (days[mo]<myDay && mo<12)
	{
		remaining -= daysInMonth(++mo);
	}
	myMonth = months[mo];
	return remaining;
}

void dayofyear::getDay()
{
	int d = 0;
	do
	{
		cout << "Enter day between 1-365: ";
		cin >> d;
		if (d < 1 || d>365)
			cout << "Invalid date" << endl;
	} while (d < 1 || d>365);
	myDay = d;
}

void dayofyear::getDayperMo()
{
  int mo = 0;
	while (days[mo]<myDay && mo<12)	{ ++mo;	}
	int d = 0;
	int upper = days[mo];
	int lower = days[mo] - daysInMonth(mo);
	do
	{
		cout << "Enter day for month of " << myMonth << ": ";
		cin >> d;
		if (d < lower || d>upper)
			cout << "Invalid date" << endl;
	} while (d < lower || d>upper);
	myDay = d;
}

void dayofyear::getMonth()
{
  int mo;
	do
	{
		cout << "Enter month as a value between 1-12: ";
		cin >> mo;
		if (mo < 1 || mo>12)
			cout << "Invalid month" << endl;
	} while (mo < 1 || mo>12);
	myMonth = months[mo-1];
  monthEntered = true;
}

void dayofyear::print()
{
  if(monthEntered)
  {
    cout << "Date is " << myMonth << " " << myDay << endl;
  }
  else
  {
    int day = calcDays();
	  cout << "Day " << myDay << " is " << myMonth << " " << day << endl;
  }
}

int main()
{
  cout << "Day of Year tester: " << endl;
	dayofyear day(0);
	day.getDay();
	day.print();
	cout << "\nDay and Month tester: " << endl;
	dayofyear daymo("", 0);
	daymo.getMonth();
	daymo.getDayperMo();
	daymo.print();
	return 0;
}

/*
Assuming that a year has 365 days, write a class named DayOfYear that takes an integer
representing a day of the year and translates it to a string consisting of the month
followed by day of the month. For example,
Day 2 would be January 2.
Day 32 would be February 1.
Day 365 would be December 31.
The constructor for the class should take as parameter an integer representing the day
of the year, and the class should have a member function print() that prints the day
in the month–day format. The class should have an integer member variable to represent
the day and should have static member variables holding string objects that can
be used to assist in the translation from the integer format to the month-day format.
Test your class by inputting various integers representing days and printing out their
representation in the month–day format


Modify the DayOfYear class, written in Programming Challenge 2, to add a constructor
that takes two parameters: a string object representing a month and an integer in
the range 0 through 31 representing the day of the month. The constructor should then
initialize the integer member of the class to represent the day specified by the month
and day of month parameters. The constructor should terminate the program with an
appropriate error message if the number entered for a day is outside the range of days
for the month given.
884 Chapter 14 More About Classes
Add the following overloaded operators:
++ prefix and postfix increment operators. These operators should modify the
DayOfYear object so that it represents the next day. If the day is already the end
of the year, the new value of the object will represent the first day of the year.
−− prefix and postfix decrement operators. These operators should modify the
DayOfYear object so that it represents the previous day. If the day is already the
first day of the year, the new value of the object will represent the last day of the
year.

*/
