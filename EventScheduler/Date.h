#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <vector> 
#include <ctime>

using namespace std;

class Date
{
	int day;
	int month;
	int year;
	bool doesTheDateHaveErrors = false;
	time_t now = time(0);
	char* dt = ctime(&now);
	
public:
	Date(string& date);
	void checkSize(string date);
	void charCounter(string date);
	void positionCheck(string date);
	void strToDate(string date);
	void maxDaysInAMonth(int day, int month, int year, string date);
	void checkDateValidity(int day, int month, int year, int maxDays, string date);
	void setIsItIncorrect();
	bool getIsItIncorrect();
	string dateToStr();
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

//public:
//	std::string result, month, year, day,hour,mi;
//	char d[2]={'0', '0'}, m[2]= { '0', '0' }, y[4]={ '0', '0', '0','0'}, h[2] = { '0', '0' }, min[2] = { '0', '0' };
//	
//	
//	std::string return_date();
//	std::string return_Reminder();
//	int return_valid_or(std::string d);
};

// To be deleted

//class vec {
//	
//public:
//	int id;
//	std::string eventName;
//	std::string startDate;
//	std::string endDate;
//	std::string place;
//	std::string startTime;
//	std::string reminderTime;
//	
//	bool Done;
//};
