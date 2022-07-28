#include "TimeFromScratch.h"


Time::Time(std::string& time)
{
	checkSize(time);
}

void Time::checkSize(std::string time)
{
	if (time.size() == 4 || time.size() == 5)
	{
		columnCounter(time);
	}
	else
	{
		setIsItIncorrect();
	}
}

void Time::columnCounter(std::string time)
{
	int nNonIntegers = 0;
	int nColumns = 0;
	for (int i = 0; i < time.size(); i++)
	{
		if (time[i] == ':')
			nColumns++;

		if ((time[i] > '9' || time[i] < 0) && time[i] != ':')
			nNonIntegers++;
	}
	if (nColumns != 1 || nNonIntegers != 0)
	{
		setIsItIncorrect();
	}

	strToTime(time);
}

void Time::strToTime(std::string time)
{
	//Finding position of the column then getting the substrings for the hours and minutes then converting them to integers
	
	int positionOfColumn = time.find_first_of(':');
	
	std::string hourSubString = time.substr(0, positionOfColumn);
	std::string minuteSubString = time.substr( positionOfColumn+1);
	
	int tempHour = stoi(hourSubString);
	int tempMinute = stoi(minuteSubString);
	
	checkTimeValidity(tempHour, tempMinute, time, minuteSubString);
}

void Time::checkTimeValidity(int hour, int minute, std::string time, std::string minuteSubString)
{
	
	if ((hour > 23) || (hour < 0) || (minute > 59) || (minute < 0))
	{
		setIsItIncorrect();
	}

	if (minute < 10)
	{
		if (minuteSubString[0] != '0')
		{
			setIsItIncorrect();
		}
	}

	timeToStr();
	setHour(hour);
	setMinute(minute);
}

std::string Time::timeToStr()
{
	std::string time = std::to_string(hour);
	time = time.append(":");
	if (minute < 10)
	{
		time = time.append("0" + std::to_string(minute));
	}
	else
	{
		time = time.append(std::to_string(minute));
	}
	return time;
}

// Setters and getters
void Time::setHour(int hour)
{
	this->hour = hour;
}

void Time::setMinute(int minute)
{
	this->minute = minute;
}

void Time::setIsItIncorrect()
{
	this->isItIncorrect = true;
}

int Time::getHour()
{
	return this->hour;
}

int Time::getMinute()
{
	return this->minute;
}

bool Time::getIsItIncorrect()
{
	return isItIncorrect;
}