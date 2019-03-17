#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "DBoperate.h"
#include <string>
using namespace std;

class Schedule
{
public:
	Schedule();
private:
	void initMainSchedulebyClass(const char*, string, int);//(学院名称，班级编号，班级人数)
	DBoperate db;
};

#endif

