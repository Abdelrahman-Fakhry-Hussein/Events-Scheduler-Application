#pragma once
#include <sqlite3.h>
#include <iostream>
#include <ctime>
#include <queue>
#include <list>
#include <vector>
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include "errorpanel.h"
#include "Date.h"
#include "Vec.h"
#include "TimeFromScratch.h"


struct row
{
	std::string eventName, Place, startDate, endDate, startTime, endTime, reminderTime, Done;

};

class Scheduler
{

public:

	 int createDB(const char* s);
	 int createTable(const char* s);
	 int deleteData(const char* s,Vec,int);
	 int insertData(const char* s,Vec,int);
	 void callExecute(const char* s, std::string sql);
	 int updateData(const char* s,Vec,Vec);
	 int updateDone(const char* s,Vec);
	 vector<row> selectDone(const char* s,int);
	 vector<row> selectData(const char* s,int);
	 vector<row> selectDeleted(const char* s);
	 vector<row> selectrows(const char* s);
	static int callback(void* NotUsed, int argc, char** argv, char** azColName);
	 int repla(const char* s, string h);
	 bool compareDate(string newStrDate, string previousStrDate);
	 bool checkEventDateValidity(string tempStart, string tempEnd);
	 vector<row> sortByStartDate(vector<row> v);
	 vector<row> sortByReminderTime(vector<row> L_Reminder_Time);
	 //int takeDate(string da, string m);
	 void callExecut2e(const char* s, string sql);
	 int callExecut3e(const char* s, string sql);
	 void callExecut4e(const char* s, string sql);
	 //bool retErrorFlag(const char* s,vec inserted);
private:
	errorPanel* er;

};

