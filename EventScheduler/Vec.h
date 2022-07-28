#pragma once
#include <string>


class Vec {

public:
	int id;
	std::string eventName;
	std::string startDate;
	std::string endDate;
	std::string place;
	std::string startTime;
	std::string endTime;
	std::string reminderTime;
	bool Done;
	bool missedEvent;

	void vecIntialize();
	void vecAdd(Vec);
	int getVecSize();
	static int getEditedRow();
	int setEditedRow(int);
	bool getEditedRowDone(int);
	bool getEditFlag();
	bool inVec(std::string);
	void setEditFlag(bool);
	void vecEdit(Vec);
	void vecDelete(int);
	void vecCheck(int);
	bool MissedEvents(Vec rowEvent);
	Vec vecRet(int);
	int getIdFromName(std::string);
};
