#include "Date.h"
#include<iostream>
#include <cmath>

Date::Date(string& date)
{
	checkSize(date);
}

void Date::checkSize(string date)
{
	while ((date.size() < 8) || (date.size() > 10))
	{
		setIsItIncorrect();
	}
	charCounter(date);
}

void Date::charCounter(string date)
{
	int nDashes = 0;
	int nNonIntegers = 0;

	// Loop to check how many dashes and non-integer characters (if exist) are there 
	for (int i = 0; i < date.size(); i++)
	{
		if (date[i] == '-')
		{
			nDashes++;
		}

		if (((date[i] > '9') || (date[i] < '0')) && date[i] != '-')
		{
			nNonIntegers++;
		}
	}
	if (nDashes != 2 || nNonIntegers != 0)
	{
		setIsItIncorrect();
	}
	positionCheck(date);
}

void Date::positionCheck(string date)
{
	while ((date[4] != '-') && (date[5] != '-' && date[6] != '-'))
	{
		setIsItIncorrect();
	}

	strToDate(date);
}

void Date::strToDate(string date)
{
	// Finding the positions of the dash character
	int firstDashPosition = date.find_first_of('-');
	int lastDashPosition = date.find_last_of('-');

	// Splitting the string into day, month and year then converting them from string to integers
	string yearSubString = date.substr(0, firstDashPosition);
	int tempYear = stoi(yearSubString);


	string monthSubString = date.substr(firstDashPosition + 1, (lastDashPosition - firstDashPosition) - 1);
	int tempMonth = stoi(monthSubString);

	string daySubString = date.substr(lastDashPosition + 1);
	int tempDay = stoi(daySubString);

	maxDaysInAMonth(tempDay, tempMonth, tempYear, date);

}

// Defines the maximum number of days a month can have based on the month and year (leap year)
void Date::maxDaysInAMonth(int day, int month, int year, string date)
{
	int maxDays;
	switch (month)
	{

	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		maxDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		maxDays = 30;
		break;
	case 2:
		maxDays = 28;

		if (year % 4 == 0)
		{
			maxDays = 29;
		}
		break;

	default:
		setIsItIncorrect();
	}
	checkDateValidity(day, month, year, maxDays, date);
}

//Checks whether the date the user entered actually exists in the calendar 
void Date::checkDateValidity(int day, int month, int year, int maxDays, string date)
{
	bool validity[3];

	// Checking validity of each date separately
	if (day <= maxDays && day > 0)
	{
		validity[0] = true;
	}
	else
	{
		validity[0] = false;
	}

	if (month > 0 && month <= 12)
	{
		validity[1] = true;
	}
	else
	{
		validity[1] = false;
	}

	if (year < 0)
	{
		validity[2] = false;
	}
	else
	{
		validity[2] = true;
	}

	// Checking the validity of all of them together to see whether the date is valid or not
	if (!(validity[0] && validity[1] && validity[2]))
	{
		setIsItIncorrect();
	}
	else
	{
		dateToStr();
		setDay(day);
		setMonth(month);
		setYear(year);
	}
}

void Date::setIsItIncorrect()
{
	this->doesTheDateHaveErrors = true;
}

bool Date::getIsItIncorrect()
{
	return doesTheDateHaveErrors;
}


string Date::dateToStr()
{
	string date = to_string(year) + '-' + (to_string(month)) + '-' + (to_string(day));
	return date;
}

// Setters and getters
int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}
void Date::setDay(int Day)
{
	this->day = Day;
}

void Date::setMonth(int Month)
{
	this->month = Month;
}

void Date::setYear(int Year)
{
	this->year = Year;
}

//std::string Date::return_date()
//{
//	cout << "Please Enter Day in format dd :" << endl;
//
//	while (true)
//	{
//
//		cin >> d;
//		if (atoi(d) > 0 && atoi(d) < 31)
//		{
//			if (d[1] == NULL || d[0] == NULL)
//			{
//				cout << "Please Enter Valid day in format dd :" << endl;
//			}
//			else
//			{
//
//				day = d;
//
//				break;
//			}
//		}
//		else
//		{
//			cout << "Please Enter Valid day in format dd :" << endl;
//		}
//	}
//
//
//	cout << "Please Enter Month in format MM :" << endl;
//
//	while (true)
//	{
//
//		cin >> m;
//		if (atoi(m) > 0 && atoi(m) < 13)
//		{
//			if (m[1] == NULL || m[0] == NULL)
//			{
//				cout << "Please Enter Valid Month in format MM :" << endl;
//			}
//			else
//			{
//
//				month = m;
//
//				break;
//			}
//		}
//		else
//		{
//			cout << "Please Enter Valid Month in format MM :" << endl;
//		}
//	}
//
//
//	cout << "Please Enter Year of Event in format yyyy :" << endl;
//
//	while (true)
//	{
//
//		cin >> y;
//		if (atoi(y) > 0 && atoi(y) < 10000)
//		{
//			if (y[0] == NULL || y[1] == NULL || y[2] == NULL || y[3] == NULL)
//			{
//				cout << "Please Enter Year  in format yyyy :" << endl;
//			}
//			else
//			{
//
//				year = y;
//
//				break;
//			}
//		}
//		else
//		{
//			cout << "Please Enter Year  in format yyyy :" << endl;
//		}
//	}
//
//
//	result = year + "-" + month + "-" + day;
//	cout << result << endl;
//	return result;
//
//
//}
//
//std::string Date::return_Reminder()
//{
//	cout << "Please Enter The Hour You want To Reminder in in format (hh):" << endl;
//	while (true)
//	{
//
//		cin >> h;
//		if (atoi(h) > 0 && atoi(h) < 25)
//		{
//			if (h[1] == NULL || h[0] == NULL)
//			{
//				cout << "Please Enter Valid Hour You want To Reminder in in format (hh):" << endl;
//			}
//			else
//			{
//
//				hour = h;
//
//				break;
//			}
//		}
//		else
//		{
//			cout << "Please Enter Valid Hour You want To Reminder in in format (hh):" << endl;
//		}
//	}
//
//	cout << "Please Enter The Minutes You want To Reminder in in format (mm):" << endl;
//	while (true)
//	{
//
//		cin >> min;
//		if (atoi(min) > 0 && atoi(min) < 60)
//		{
//			if (min[1] == NULL || min[0] == NULL)
//			{
//				cout << "Please Enter Valid Minutes You want To Reminder in in format (mm):" << endl;
//			}
//			else
//			{
//
//				mi = min;
//
//				break;
//			}
//		}
//		else
//		{
//			cout << "Please Enter Valid Minutes You want To Reminder in in format (mm):" << endl;
//		}
//	}
//
//	return (hour + ":" + mi);
//}