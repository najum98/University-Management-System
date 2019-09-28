#ifndef FacultyMemberENC
#define FacultyMemberENC
#include <iostream>
#include <string>
#include "PUCITPerson.h"
#include "CourseHeader.h"

class FacultyMember : public PUCITPerson
{
	string degree;
	int yearsOfService;
	Course* Teacher[3];
	Student* TAlist[3];
	//Course* obj; //Course ka function TAofCourse ko assignTA me access krny k liye bnaya hh ye
public:
	FacultyMember();
	FacultyMember(int id, string deg, int yos);
	bool AssignCourse(Course* cptr);
	bool removeCourse(int cid);
	int getID();
	int getYOS();
	bool assignTA(Student* sptr, Course* cptr);
	bool removeTA(Student* sptr,Course* cptr);
	Course* getTeacher(int index);
	void showCourses();
	void showTA();
	~FacultyMember();
};
#endif