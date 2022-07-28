#include "Scheduler.h"
#include<list>
#include <sqlite3.h>
#include <algorithm>
#include "Vec.h"
#include "date.h"
#include "TimeFromScratch.h"
#include <string>

int Scheduler::createDB(const char* s)
{
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB);

	return 0;
}

int Scheduler::createTable(const char* s)
{
	sqlite3* DB;
	char* messageError;

	std::string sql =
		"CREATE TABLE IF NOT EXISTS Scheduler("
		"Event_ID INTEGER PRIMARY KEY AUTOINCREMENT,"
		"Event_name TEXT NOT NULL UNIQUE,"
		"Location VARCHAR(100) NOT NULL ,"
		"Start_Date CHAR(80) NOT NULL UNIQUE ,"
		"End_Date VARCHAR(80) NOT NULL UNIQUE ,"
		"Event_start_time CHAR(80) NOT NULL ,"
		"Event_end_time CHAR(80) NOT NULL ,"
		"Reminder CHAR(80) NOT NULL,"
		"Done CHAR(6)   DEFAULT false);";

	std::string sql2 =
		"CREATE TABLE IF NOT EXISTS Scheduler_Done("
		"Event_ID INTEGER PRIMARY KEY AUTOINCREMENT,"
		"Event_name TEXT NOT NULL UNIQUE,"
		"Location VARCHAR(100) NOT NULL ,"
		"Start_Date CHAR(80) NOT NULL UNIQUE ,"
		"End_Date VARCHAR(80) NOT NULL UNIQUE ,"
		"Event_start_time CHAR(80) NOT NULL ,"
		"Event_end_time CHAR(80) NOT NULL ,"
		"Reminder CHAR(80) NOT NULL,"
		"Done CHAR(6)   DEFAULT true);";
	std::string sql3 =
		"CREATE TABLE IF NOT EXISTS Scheduler_Not_Done("
		"Event_ID INTEGER PRIMARY KEY AUTOINCREMENT,"
		"Event_name TEXT NOT NULL UNIQUE,"
		"Location VARCHAR(100) NOT NULL ,"
		"Start_Date CHAR(80) NOT NULL UNIQUE ,"
		"End_Date VARCHAR(80) NOT NULL UNIQUE ,"
		"Event_start_time CHAR(80) NOT NULL ,"
		"Event_end_time CHAR(80) NOT NULL ,"
		"Reminder CHAR(80) NOT NULL,"
		"Done CHAR(6)   DEFAULT false);";
	std::string sql4 =
		"CREATE TABLE IF NOT EXISTS Delete_History("
		"Event_ID INTEGER PRIMARY KEY AUTOINCREMENT,"
		"Event_name TEXT NOT NULL UNIQUE,"
		"Location VARCHAR(100) NOT NULL ,"
		"Start_Date CHAR(80) NOT NULL UNIQUE ,"
		"End_Date VARCHAR(80) NOT NULL UNIQUE ,"
		"Event_start_time CHAR(80) NOT NULL ,"
		"Event_end_time CHAR(80) NOT NULL ,"
		"Reminder CHAR(80) NOT NULL,"
		"Done CHAR(6)   DEFAULT false);";
	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}
	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql2.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}
	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql3.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}
	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql4.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}
	return 0;
}

int Scheduler::insertData(const char* s, Vec insertedRow, int table)
{
	sqlite3* DB;
	char* messageError;

	std::string  Event_name, Location, start_date, end_data, event_st, Reminder, event_sr_hour, event_end_hour, Done;

	bool g;

	Event_name = insertedRow.eventName;
	Location = insertedRow.place;
	start_date = insertedRow.startDate;
	end_data = insertedRow.endDate;
	event_st = insertedRow.startTime;
	Reminder = insertedRow.reminderTime;
	event_sr_hour = insertedRow.startTime;
	event_end_hour = insertedRow.endTime;
	Done = "false";


	er = new errorPanel;

	if (table == 0)
	{
		std::string sqlz("INSERT INTO Scheduler(Event_name, Location, Start_Date, End_Date ,Event_start_time,Event_end_time, Reminder,Done) VALUES('" + Event_name + "','" + Location + "','" + start_date + "','" + end_data + "','" + event_sr_hour + "','" + event_end_hour + "','" + Reminder + "','" + Done + "');");
		
		int exit = sqlite3_open(s, &DB);

		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */

		exit = sqlite3_exec(DB, sqlz.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK)
		{
			er->show();

			er->erPannel("Error in insertData function.");

			sqlite3_free(messageError);

		}
	}
	else if (table == 1)
	{
		std::string sqlz("INSERT INTO Scheduler_Done(Event_name, Location, Start_Date, End_Date, Event_start_time, Event_end_time, Reminder, Done) VALUES('" + Event_name + "','" + Location + "','" + start_date + "','" + end_data + "','" + event_sr_hour + "','" + event_end_hour + "','" + Reminder + "','" + Done + "');");
	
		int exit = sqlite3_open(s, &DB);

		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */

		exit = sqlite3_exec(DB, sqlz.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK)
		{
			er->show();
			er->erPannel("Error in insertData function.");


			sqlite3_free(messageError);

		}
	}
	else if (table == 2)
	{
		std::string sqlz("INSERT INTO Scheduler_Not_Done(Event_name, Location, Start_Date, End_Date ,Event_start_time,Event_end_time, Reminder,Done) VALUES('" + Event_name + "','" + Location + "','" + start_date + "','" + end_data + "','" + event_sr_hour + "','" + event_end_hour + "','" + Reminder + "','" + Done + "');");
		
		int exit = sqlite3_open(s, &DB);

		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sqlz.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK)
		{
			er->show();
			er->erPannel("Error in insertData function.");

			sqlite3_free(messageError);
		}
	}
	else if (table == 3)
	{
		std::string sqlz("INSERT INTO Delete_History(Event_name, Location, Start_Date, End_Date ,Event_start_time,Event_end_time, Reminder,Done) VALUES('" + Event_name + "','" + Location + "','" + start_date + "','" + end_data + "','" + event_sr_hour + "','" + event_end_hour + "','" + Reminder + "','" + Done + "');");

		int exit = sqlite3_open(s, &DB);

		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sqlz.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK)
		{
			er->show();
			er->erPannel("Error in insertData function.");

			sqlite3_free(messageError);
		}
	}
	return 0;
}

int Scheduler::updateData(const char* s, Vec editedV,Vec retrunV)
{
	std::string Event_name;
	sqlite3* DB;
	er = new errorPanel;
	char* messageError;

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	//exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	std::string sqll2("UPDATE Scheduler SET Location ='" + editedV.place + "' WHERE Event_name = '" + retrunV.eventName + "';");
	callExecute(s, sqll2);
	std::string sqll3("UPDATE Scheduler SET Start_Date ='" + editedV.startDate + "' WHERE Event_name = '" + retrunV.eventName + "';");
	callExecute(s, sqll3);
	std::string sqll4("UPDATE Scheduler SET End_Date ='" + editedV.endDate + "' WHERE Event_name ='" + retrunV.eventName + "';");
	callExecute(s, sqll4);
	std::string sqll5("UPDATE Scheduler SET Event_start_time ='" + editedV.startTime + "' WHERE Event_name ='" + retrunV.eventName + "';");
	callExecute(s, sqll5);
	std::string sqll6("UPDATE Scheduler SET Reminder ='" + editedV.reminderTime + "' WHERE Event_name ='" + retrunV.eventName + "';");
	callExecute(s, sqll6);
	std::string sqll7("UPDATE Scheduler SET Event_end_time ='" + editedV.endTime + "' WHERE Event_name ='" + retrunV.eventName + "';");
	callExecute(s, sqll7);
	std::string sqll1("UPDATE Scheduler SET Event_name ='" + editedV.eventName + "' WHERE Event_name ='" + retrunV.eventName + "';");
	callExecute(s, sqll1);
	if (editedV.Done == true) {
		std::string sql2("UPDATE Scheduler_Done SET Location ='" + editedV.place + "' WHERE Event_name = '" + retrunV.eventName + "';");
		callExecute(s, sql2);
		std::string sql3("UPDATE Scheduler_Done SET Start_Date ='" + editedV.startDate + "' WHERE Event_name = '" + retrunV.eventName + "';");
		callExecute(s, sql3);
		std::string sql4("UPDATE Scheduler_Done SET End_Date ='" + editedV.endDate + "' WHERE Event_name ='" + retrunV.eventName + "';");
		callExecute(s, sql4);
		std::string sql5("UPDATE Scheduler_Done SET Event_start_time ='" + editedV.startTime + "' WHERE Event_name ='" + retrunV.eventName + "';");
		callExecute(s, sql5);
		std::string sql6("UPDATE Scheduler_Done SET Reminder ='" + editedV.reminderTime + "' WHERE Event_name ='" + retrunV.eventName + "';");
		callExecute(s, sql6);
		std::string sql7("UPDATE Scheduler_Done SET Event_end_time ='" + editedV.endTime + "' WHERE Event_name ='" + retrunV.eventName + "';");
		callExecute(s, sql7);
		std::string sql1("UPDATE Scheduler_Done SET Event_name ='" + editedV.eventName + "' WHERE Event_name ='" + retrunV.eventName + "';");
		callExecute(s, sql1);
	}
	else {
		std::string sql2("UPDATE Scheduler_Not_Done SET Location ='" + editedV.place + "' WHERE Event_name = '" + retrunV.eventName + "';");
		callExecute(s, sql2);
		std::string sql3("UPDATE Scheduler_Not_Done SET Start_Date ='" + editedV.startDate + "' WHERE Event_name = '" + retrunV.eventName + "';");
		callExecute(s, sql3);
		std::string sql4("UPDATE Scheduler_Not_Done SET End_Date ='" + editedV.endDate + "' WHERE Event_name ='" + retrunV.eventName + "';");
		callExecute(s, sql4);
		std::string sql5("UPDATE Scheduler_Not_Done SET Event_start_time ='" + editedV.startTime + "' WHERE Event_name ='" + retrunV.eventName + "';");
		callExecute(s, sql5);
		std::string sql6("UPDATE Scheduler_Not_Done SET Reminder ='" + editedV.reminderTime + "' WHERE Event_name ='" + retrunV.eventName + "';");
		callExecute(s, sql6);
		std::string sql7("UPDATE Scheduler_Not_Done SET Event_end_time ='" + editedV.endTime + "' WHERE Event_name ='" + retrunV.eventName + "';");
		callExecute(s, sql7);
		std::string sql1("UPDATE Scheduler_Not_Done SET Event_name ='" + editedV.eventName + "' WHERE Event_name ='" + retrunV.eventName + "';");
		callExecute(s, sql1);
	}

	return 0;
}

//=============================
int Scheduler::updateDone(const char* s, Vec editedV)
{
	std::string eventName;
	sqlite3* DB;
	er = new errorPanel;
	char* messageError;
	int exit = sqlite3_open(s, &DB);
	std::string check;
	if (editedV.Done == true) {
		check = "true";
		insertData(s, editedV, 1);
		deleteData(s, editedV, 2);
	}
	else {
		check = "false";
		insertData(s, editedV, 2);
		deleteData(s, editedV, 1);
	}
	std::string sql8("UPDATE Scheduler SET Done ='" + check + "' WHERE Event_name ='" + editedV.eventName + "';");
	callExecute(s, sql8);
	
	return 0;
}
int Scheduler::deleteData(const char* s,Vec deletedRow,int table)
{
	sqlite3* DB;
	int exit = sqlite3_open(s, &DB);
	char* messageError;
	bool g = true;
	//----------------------------------------------------------
		////clear
		//		string sql = "DELETE FROM Scheduler;";
		//	callExecut2e(s, sql);
	//----------------------------------
	if (table == 0) {
		string sql2 = "DELETE FROM Scheduler WHERE Event_name ='" + deletedRow.eventName + "';";
		callExecut2e(s, sql2);
	}
	else if (table == 1) {
		string sql2 = "DELETE FROM Scheduler_Done WHERE Event_name ='" + deletedRow.eventName + "';";
		callExecut2e(s, sql2);
	}
	else if (table == 2) {
		string sql2 = "DELETE FROM Scheduler_Not_Done WHERE Event_name ='" + deletedRow.eventName + "';";
		callExecut2e(s, sql2);
	}
	else if (table == 3) {
		string sql2 = "DELETE FROM Delete_History WHERE Event_name ='" + deletedRow.eventName + "';";
		callExecut2e(s, sql2);
	}
	return 0;
}


int Scheduler::repla(const char* s, string ha)
{
	sqlite3* DB;

	int exit = 1;
	exit = sqlite3_open(s, &DB);
	sqlite3_stmt* stmta;
	row rowData;
	std::string trs = "true";
	std::string temp_doc;
	char* messageError;

	sqlite3_prepare(DB, "select * from Scheduler ", -1, &stmta, NULL);

	while ((sqlite3_step(stmta)) != SQLITE_DONE)
	{
		//load from sqlite db
		sqlite3_column_int(stmta, 0); 
		rowData.eventName = string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 1)));
		rowData.Place = string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 2)));
		rowData.startDate = string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 3)));
		rowData.endDate = string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 4)));
		rowData.startTime = string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 5)));
		rowData.endTime = string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 6)));
		rowData.reminderTime = string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 7)));
		rowData.Done = string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 8)));
		sqlite3_column_text(stmta, 7);
			cout << rowData.Place << endl;
		rowData.eventName.erase(remove(rowData.eventName.begin(), rowData.eventName.end(), ' '), rowData.eventName.end());
		rowData.Place.erase(remove(rowData.Place.begin(), rowData.Place.end(), ' '), rowData.Place.end());
		rowData.startDate.erase(remove(rowData.startDate.begin(), rowData.startDate.end(), ' '), rowData.startDate.end());
		rowData.endDate.erase(remove(rowData.endDate.begin(), rowData.endDate.end(), ' '), rowData.endDate.end());
		rowData.startTime.erase(remove(rowData.startTime.begin(), rowData.startTime.end(), ' '), rowData.startTime.end());
		rowData.endTime.erase(remove(rowData.endTime.begin(), rowData.endTime.end(), ' '), rowData.endTime.end());
		rowData.reminderTime.erase(remove(rowData.reminderTime.begin(), rowData.reminderTime.end(), ' '), rowData.reminderTime.end());
		rowData.Done.erase(remove(rowData.Done.begin(), rowData.Done.end(), ' '), rowData.Done.end());
		cout << rowData.eventName << endl;
		if (ha == rowData.eventName)
		{

			//sqlite3* DB;
			string sql("INSERT INTO Scheduler_Done(Event_name, Location, Start_Date, End_Date ,Event_start_time, Reminder,Done) VALUES('" + rowData.eventName + "',' " + rowData.Place + "',' " + rowData.startDate + "', '" + rowData.endDate + "',' " + rowData.startTime + "',' " + rowData.endTime + "','" + trs + "');");

			//sqlite3_close(DB);
			char* messageError;

			/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
			exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
			if (exit != SQLITE_OK)
			{
				cerr << "Error in Update function." << endl;
				sqlite3_free(messageError);
			}
			else
			{

				std::string sql3 = "DELETE FROM Scheduler  WHERE Event_name ='" + rowData.eventName + "';";
				char* messageError;
				exit = sqlite3_exec(DB, sql3.c_str(), NULL, 0, &messageError);
				if (exit != SQLITE_OK)
				{
					cerr << "Error in Update function." << endl;
					sqlite3_free(messageError);
				}
				else
				{
					cout << "Records inserted Successfully!" << endl;
				}
				cout << "Records inserted Successfully!" << endl;
				sqlite3_close(DB);
				int ka = 1;
				return ka;
				break;
			}

			break;
			break;
		}

		else
		{

		}

	}
	return 0;
}

vector<row> Scheduler::selectrows(const char* s)
{
	sqlite3* DB;

	int exit = 1;
	exit = sqlite3_open(s, &DB);
	sqlite3_stmt* stmta;
	row rowData;

	vector <row> rows;
	char* messageError;

	sqlite3_prepare(DB, "select * from Scheduler ", -1, &stmta, NULL);

	while ((sqlite3_step(stmta)) != SQLITE_DONE)
	{

		sqlite3_column_int(stmta, 0);
		rowData.eventName = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 1)));
		rowData.Place = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 2)));
		rowData.startDate = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 3)));
		rowData.endDate = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 4)));
		rowData.startTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 5)));
		rowData.endTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 6)));
		rowData.reminderTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 7)));
		rowData.Done = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 8)));

		//cout << f1.s2 << endl;
		rowData.eventName.erase(remove(rowData.eventName.begin(), rowData.eventName.end(), ' '), rowData.eventName.end());
		rowData.Place.erase(remove(rowData.Place.begin(), rowData.Place.end(), ' '), rowData.Place.end());
		rowData.startDate.erase(remove(rowData.startDate.begin(), rowData.startDate.end(), ' '), rowData.startDate.end());
		rowData.endDate.erase(remove(rowData.endDate.begin(), rowData.endDate.end(), ' '), rowData.endDate.end());
		rowData.startTime.erase(remove(rowData.startTime.begin(), rowData.startTime.end(), ' '), rowData.startTime.end());
		rowData.endTime.erase(remove(rowData.endTime.begin(), rowData.endTime.end(), ' '), rowData.endTime.end());
		rowData.reminderTime.erase(remove(rowData.reminderTime.begin(), rowData.reminderTime.end(), ' '), rowData.reminderTime.end());
		rowData.Done.erase(remove(rowData.Done.begin(), rowData.Done.end(), ' '), rowData.Done.end());
		rows.push_back(rowData);
	}
	return rows;
}
vector<row> Scheduler::selectDone(const char* s, int c)
{
	sqlite3* DB;

	int exit = 1;
	exit = sqlite3_open(s, &DB);
	sqlite3_stmt* stmta;
	row rowData;

	vector <row> rows;
	char* messageError;

	sqlite3_prepare(DB, "select * from Scheduler_Done ", -1, &stmta, NULL);

	while ((sqlite3_step(stmta)) != SQLITE_DONE)
	{

		sqlite3_column_int(stmta, 0);
		rowData.eventName = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 1)));
		rowData.Place = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 2)));
		rowData.startDate = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 3)));
		rowData.endDate = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 4)));
		rowData.startTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 5)));
		rowData.endTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 6)));
		rowData.reminderTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 7)));
		rowData.Done = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 8)));
		//cout << f1.s2 << endl;
		//f1.s1.erase(remove(f1.s1.begin(), f1.s1.end(), ' '), f1.s1.end());
		//f1.s2.erase(remove(f1.s2.begin(), f1.s2.end(), ' '), f1.s2.end());
		rowData.startDate.erase(remove(rowData.startDate.begin(), rowData.startDate.end(), ' '), rowData.startDate.end());
		rowData.endDate.erase(remove(rowData.endDate.begin(), rowData.endDate.end(), ' '), rowData.endDate.end());
		rowData.startTime.erase(remove(rowData.startTime.begin(), rowData.startTime.end(), ' '), rowData.startTime.end());
		rowData.endTime.erase(remove(rowData.endTime.begin(), rowData.endTime.end(), ' '), rowData.endTime.end());
		rowData.reminderTime.erase(remove(rowData.reminderTime.begin(), rowData.reminderTime.end(), ' '), rowData.reminderTime.end());
		rowData.Done.erase(remove(rowData.Done.begin(), rowData.Done.end(), ' '), rowData.Done.end());
		rows.push_back(rowData);
	}

	vector<row> sortedEvents;

	if (c == 1)
	{
		sortedEvents = sortByStartDate(rows);
		return sortedEvents;
	}
	else if (c == 2)
	{
		sortedEvents = sortByReminderTime(rows);
		return sortedEvents;
	}
	else
	{
		return rows;
	}
}

vector<row> Scheduler::selectDeleted(const char* s)
{
	sqlite3* DB;
	int exit = 1;
	exit = sqlite3_open(s, &DB);
	sqlite3_stmt* stmta;
	row rowData;
	vector <row> rows;

	sqlite3_prepare(DB, "select * from Delete_History ", -1, &stmta, NULL);

	while ((sqlite3_step(stmta)) != SQLITE_DONE)
	{

		sqlite3_column_int(stmta, 0);
		rowData.eventName = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 1)));
		rowData.Place = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 2)));
		rowData.startDate = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 3)));
		rowData.endDate = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 4)));
		rowData.startTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 5)));
		rowData.endTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 6)));
		rowData.reminderTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 7)));
		rowData.Done = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 8)));
		rowData.startDate.erase(remove(rowData.startDate.begin(), rowData.startDate.end(), ' '), rowData.startDate.end());
		rowData.endDate.erase(remove(rowData.endDate.begin(), rowData.endDate.end(), ' '), rowData.endDate.end());
		rowData.startTime.erase(remove(rowData.startTime.begin(), rowData.startTime.end(), ' '), rowData.startTime.end());
		rowData.endTime.erase(remove(rowData.endTime.begin(), rowData.endTime.end(), ' '), rowData.endTime.end());
		rowData.reminderTime.erase(remove(rowData.reminderTime.begin(), rowData.reminderTime.end(), ' '), rowData.reminderTime.end());
		rowData.Done.erase(remove(rowData.Done.begin(), rowData.Done.end(), ' '), rowData.Done.end());
		rows.push_back(rowData);
	}
	return rows;
}


vector<row> Scheduler::selectData(const char* s,int c)
{
	sqlite3* DB;

	int exit = 1;
	exit = sqlite3_open(s, &DB);
	sqlite3_stmt* stmta;
	row rowData;

	vector <row> rows;
	char* messageError;

	sqlite3_prepare(DB, "select * from Scheduler ", -1, &stmta, NULL);

	while ((sqlite3_step(stmta)) != SQLITE_DONE)
	{

		sqlite3_column_int(stmta, 0);
		rowData.eventName = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 1)));
		rowData.Place = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 2)));
		rowData.startDate = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 3)));
		rowData.endDate = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 4)));
		rowData.startTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 5)));
		rowData.endTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 6)));
		rowData.reminderTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 7)));
		rowData.Done = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmta, 8)));
		//cout << f1.s2 << endl;
		//f1.s1.erase(remove(f1.s1.begin(), f1.s1.end(), ' '), f1.s1.end());
		//f1.s2.erase(remove(f1.s2.begin(), f1.s2.end(), ' '), f1.s2.end());
		rowData.startDate.erase(remove(rowData.startDate.begin(), rowData.startDate.end(), ' '), rowData.startDate.end());
		rowData.endDate.erase(remove(rowData.endDate.begin(), rowData.endDate.end(), ' '), rowData.endDate.end());
		rowData.startTime.erase(remove(rowData.startTime.begin(), rowData.startTime.end(), ' '), rowData.startTime.end());
		rowData.endTime.erase(remove(rowData.endTime.begin(), rowData.endTime.end(), ' '), rowData.endTime.end());
		rowData.reminderTime.erase(remove(rowData.reminderTime.begin(), rowData.reminderTime.end(), ' '), rowData.reminderTime.end());
		rowData.Done.erase(remove(rowData.Done.begin(), rowData.Done.end(), ' '), rowData.Done.end());
		rows.push_back(rowData);
	}
	vector<row> sortedEvents;
	
	if (c == 1)
	{
		sortedEvents = sortByStartDate(rows);
		return sortedEvents;
	}
	else if (c == 2)
	{
		sortedEvents = sortByReminderTime(rows);
		return sortedEvents;
	}
	else
		return rows;
}

bool Scheduler::checkEventDateValidity(string tempStart, string tempEnd)
{
	//retreiving dates from the object and then creating an object out of the classes to use their functions
	
	Date start(tempStart);
	Date end(tempEnd);

	if (end.getYear() < start.getYear()) {
		return true;
	}
	else
	{
		if (end.getYear() > start.getYear()) {
			return false;
		}
		else {

			if (end.getMonth() < start.getMonth()) {
				return true;
			}
			else
			{
				if (end.getMonth() > start.getMonth()) {
					return false;
				}
				else
				{
					if (end.getDay() < start.getDay()) {
						return true;
					}
					else {
						return false;
					}
				}
			}
		}
	}
}


bool Scheduler::compareDate(string newStrDate, string previousStrDate)
{
	Date newDate(newStrDate);
	Date prevDate(previousStrDate);

	if (newDate.getYear() > prevDate.getYear())
	{
		return true;
	}
	else
	{
		if (newDate.getYear() == prevDate.getYear())
		{
			if (newDate.getMonth() > prevDate.getMonth())
			{
				return true;
			}
			else
			{
				if (newDate.getMonth() == prevDate.getMonth())
				{
					if (newDate.getDay() > prevDate.getDay())
					{
						return true;
					}
					else
					{
						if (newDate.getDay() == prevDate.getDay())
						{
							return true;
						}
						else
						{
							return false;
						}
					}
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
	}
}
vector<row> Scheduler::sortByStartDate(vector<row> sortedVector) 
{
	list<int>sorted;	
	sorted.sort();
	for (int i = 0; i < sortedVector.size(); i++)
	{
		std::string startDate1 = sortedVector.at(i).startDate;
		Date tempDate1(startDate1);

		for (int j = i + 1; j < sortedVector.size(); j++)
		{
			std::string startDate2 = sortedVector.at(j).startDate;
			Date tempDate2(startDate2);

			if (tempDate1.getYear() > tempDate2.getYear())
			{
				auto temp = sortedVector.at(i);
				sortedVector.at(i) = sortedVector.at(j);
				sortedVector.at(j) = temp;
			}
			else if (tempDate1.getYear() == tempDate2.getYear() && tempDate1.getMonth() > tempDate2.getMonth())
			{
				auto temp = sortedVector.at(i);
				sortedVector.at(i) = sortedVector.at(j);
				sortedVector.at(j) = temp;
			}
			else if (tempDate1.getYear() == tempDate2.getYear() && tempDate1.getMonth() == tempDate2.getMonth() && tempDate1.getDay() > tempDate2.getDay())
			{
				auto temp = sortedVector.at(i);
				sortedVector.at(i) = sortedVector.at(j);
				sortedVector.at(j) = temp;
			}
		}
	}
	vector<row> sortedRows;
	for (int i = 0; i < sortedVector.size(); i++)
	{
		sortedRows.push_back(sortedVector.at(i));
	}
	return sortedRows;
}
// needs to be worked on
vector<row> Scheduler::sortByReminderTime(vector<row> sortedVec) {

	for (int i = 0; i < sortedVec.size(); i++)
	{
		std::string strReminder1 = sortedVec.at(i).reminderTime;
		Time reminder1(strReminder1);

		for (int j = 0; j < sortedVec.size(); j++)
		{
			std::string strReminder2 = sortedVec.at(j).reminderTime;
			Time reminder2(strReminder2);

			if (reminder1.getHour() < reminder2.getHour())
			{
				auto temp = sortedVec.at(i);
				sortedVec.at(i) = sortedVec.at(j);
				sortedVec.at(j) = temp;
			}
			else if (reminder1.getHour() == reminder2.getHour() && reminder1.getMinute() < reminder2.getMinute())
			{
				auto temp = sortedVec.at(i);
				sortedVec.at(i) = sortedVec.at(j);
				sortedVec.at(j) = temp;
			}
		}
	}
	vector<row> sortedRows;
	for (int i = 0; i < sortedVec.size(); i++)
	{
		sortedRows.push_back(sortedVec.at(i));
	}
	return sortedRows;
}
/*		dateCode = to_string(sortedCodes[k]);
		if (dateCode.size()==3) 
		{
			dateCode.insert(1, ":");
			dateCode.insert(0, "0");
		}
		else if (dateCode.size() == 4)
		{
			dateCode.insert(2,":");
		}*/

int Scheduler::callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++) {
		// column name and value
		cout << azColName[i] << ": " << argv[i] << endl;
	}

	cout << endl;
	return 0;
}

void Scheduler::callExecute(const char* s, string sql)
{

	sqlite3* DB;
	char* messageError;
	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in updateData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records updated Successfully!" << endl;
}


void Scheduler::callExecut2e(const char* s, string sql)
{
	sqlite3* DB;
	
	char* messageError;
	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
	string sql2("COMMIT;");
	
	if (exit != SQLITE_OK) {
		cerr << "Error in deleteData function." << endl;
		sqlite3_free(messageError);

	}
	else
	{
		cout << "Records deleted Successfully!" << endl;

	}
	exit = sqlite3_exec(DB, sql2.c_str(), NULL, 0, &messageError);
}

int Scheduler::callExecut3e(const char* s, string sql)
{
	sqlite3* DB;
	char* messageError;
	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
	if (exit != SQLITE_OK) {
		sqlite3_free(messageError);
		return 0;
	}
	else
	{
		return 1;
	}
}

void Scheduler::callExecut4e(const char* s, string sql)
{

	sqlite3* DB;
	char* messageError;
	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {

		sqlite3_free(messageError);
	}
	else
	{

	}

}