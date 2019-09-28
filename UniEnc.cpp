#include "UniHeader.h"
#include <string>
#include <iostream>

University::University()
{
	for (int i = 0; i < 100; i++)
	{
		clist[i] = nullptr;
	}
	for (int i = 0; i < 1000; i++)
	{
		slist[i] = nullptr;
	}
	for (int i = 0; i < 50; i++)
	{
		flist[i] = nullptr;
	}
}

bool University:: addNewCourse(int id, string name)
{
	if (this->searchcourse(id) == -1){
		for (int i = 0; i < 100; i++)
		{
			if (clist[i] == nullptr)
			{
				clist[i] = new Course(id,name);
				return true;
			}
		}
	}
	return false;
}
bool University::addNewStudent(int id,double CGPA)
{
	if (this->searchstudent(id) == -1)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (slist[i] == nullptr)
			{
				slist[i] = new Student(id,CGPA);
				return true;
			}
		}
	}
	return false;
}
int University::searchstudent(int sid)
{
	for (int i = 0; i < 1000; i++)
	{
		if (this->slist[i] != nullptr)
		{
			if (this->slist[i]->getID() == sid)
				return i;
		}
	}
	return -1;
}
int University::searchcourse(int cid)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->clist[i] != nullptr)
		{
			if (this->clist[i]->getID() == cid)
			{
				return i;
			}
		}
	}
	return -1;
}

bool University::studentaddcourse(int sid, int cid)
{
	if (this->searchstudent(sid) != -1 && this->searchcourse(cid) != -1)
		return this->slist[this->searchstudent(sid)]->addCourse(*(this->clist[this->searchcourse(cid)]));
	return false;
}
bool University::studentdropcourse(int sid, int cid)
{
	if (this->searchstudent(sid) != -1 && this->searchcourse(cid) != -1)
		return this->slist[this->searchstudent(sid)]->dropCourse(cid);
	return false;
}
void University::displaystudentinfo(int sid)
{
	this->slist[this->searchstudent(sid)]->showCourses();
}
void University::displaycourseinfo(int cid)
{
	this->clist[this->searchcourse(cid)]->showStudents();
}
Course* University:: getCLIST(int i)
{
	return clist[i];
}
bool University::addNewFacultyMember(int id,string deg,int yos)
{
	if (searchcourse(id) == -1)
	{
		for (int i = 0; i < 50; i++)
		{
			if (flist[i] == nullptr)
			{
				flist[i] = new FacultyMember(id, deg, yos);
				//cout << "New fm added\n";
				return true;
			}
		}
	}
	return false;
}
int University::searchFM(int id)
{
	for (int i = 0; i < 50; i++)
	{
 		if (flist[i] != nullptr)
		{
			if (flist[i]->getID() == id)
			{
				return i;
			}
		}
	}
	return -1;
}
bool University::AssignCourseToFacultyMember(int fid,int cid)
{
	if (this->searchFM(fid) != -1 && this->searchcourse(cid) != -1)
		return flist[searchFM(fid)]->AssignCourse((clist[searchcourse(cid)]));
	return false;
}
bool University::RemoveCourseFromFM(int fid, int cid)
{
	if (this->searchFM(fid) != -1 && this->searchcourse(cid) != -1)
		return flist[searchFM(fid)]->removeCourse(cid);
	return false;
}
bool University::AssignTAtoFacultyMember(int fid,int sid,int cid)
{
	if (this->searchFM(fid) != -1 && this->searchcourse(cid) != -1 && this->searchstudent(sid) != -1)
		return flist[searchFM(fid)]->assignTA(slist[searchstudent(sid)], clist[searchcourse(cid)]);
	return false;
}
bool University::RemoveTAfromFacultyMember(int fid, int sid, int cid)
{
	if (this->searchFM(fid) != -1 && this->searchcourse(cid) != -1 && this->searchstudent(sid) != -1)
		return flist[searchFM(fid)]->removeTA(slist[searchstudent(sid)], clist[searchcourse(cid)]);
	return false;
}
void University::ShowCoursesofFM(int fid)
{
	flist[searchFM(fid)]->showCourses();
}
void University::ShowTAofFM(int fid)
{
	flist[searchFM(fid)]->showTA();
}
void University::showTeacherofCourse(int cid)
{
	clist[searchcourse(cid)]->showTeacher();
}
void University::showTAofCourse(int cid)
{
	clist[searchcourse(cid)]->showTA();
}
void University::ShowCourseofTA(int sid)
{
	slist[searchcourse(sid)]->showCourse();
}
University::~University()
{
	delete[]flist;
	delete[]slist;
	delete[]clist;

}

