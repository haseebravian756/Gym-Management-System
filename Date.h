#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Date
{
private:

	int time;
	int day;
	int month;
	int year;

public:

	//------------------------------Default Constructor------------------------------//

	Date()
	{
		time = 0;
		day = 0;
		month = 0;
		year = 0;
	}

	//------------------------------Setters------------------------------//


	Date& setTime(int t)
	{
		time = t;

		return *this;
	}
	Date& setDay(int d)
	{
		day = d;

		return *this;
	}
	Date& setMonth(int m)
	{
		month = m;

		return *this;
	}
	Date& setYear(int y)
	{
		year = y;

		return *this;
	}

	//------------------------------Getters------------------------------//

	int getTime()
	{
		return time;
	}
	int getDay()
	{
		return day;
	}
	int getMonth()
	{
		return month;
	}
	int getYear()
	{
		return year;
	}

	//------------------------------Increment Functions------------------------------//

	void incTime()
	{
		time++;
	}
	void incDay()
	{
		day++;
	}
	void incMonth()
	{
		month++;
		if (month == 12)
		{
			month = 0;
			year++;
		}
	}
	void incYear()
	{
		year++;
	}
};