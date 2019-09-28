#ifndef StudentEnc
#define StudentEnc
#include "CourseHeader.h"
#include "PUCITPerson.h"
class University;
class Student:public PUCITPerson
{
	double cgpa;
	Course* cptr[6];
	Course* courseForTAship;
	//Course* CLISTinStudent[100];
	//University* obj;
public:
	Student(int ID1=0,double cgpa=0.0);
	void setID(int ID1);
	int getID();
	bool addCourse(Course& c);
	Course* searchCourse(int cid);
	bool dropCourse(int cid);
	void showCourses();
	Course* getCptr(int index);
	void setCGPA(double CGPA);
	double getCGPA();
	bool VacancyForCourse(Course* cptr1);
	//void copyClist();
	bool CrsofTA(Course* cptr1);
	bool removingCrsFromTA(Course* cptr1);
	void showCourse();
	~Student();
};



#endif