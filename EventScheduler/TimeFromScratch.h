#pragma once
#include <iostream>
#include <string>

class Time
{
	int hour;
	int minute;
	bool isItIncorrect = false;

public:
	Time(std::string& time);

	void checkSize(std::string time);
	void columnCounter(std::string time);
	void strToTime(std::string time);
	void checkTimeValidity(int hour, int minute, std::string time, std::string minuteSubString);
	std::string timeToStr();
	void setHour(int hour);
	void setMinute(int minute);
	void setIsItIncorrect();
	int getHour();
	int getMinute();
	bool getIsItIncorrect();
};

