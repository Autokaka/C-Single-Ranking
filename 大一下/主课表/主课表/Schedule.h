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
	void initMainSchedulebyClass(const char*, string, int);//(ѧԺ���ƣ��༶��ţ��༶����)
	DBoperate db;
};

#endif

