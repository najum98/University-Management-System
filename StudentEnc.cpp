#include "StudentHeader.h"
#include "UniHeader.h"
#include <iostream>

Student::Student(int ID1,double CGPA) :PUCITPerson(ID1)
{
	cgpa = CGPA;
	for (int i = 0; i < 6; i++)
	{
		cptr[i] = nullptr;
	}
}
void Student::setCGPA(double CGPA)
{
	cgpa = CGPA;
}
double Student::getCGPA()
{
	return cgpa;
}
void Student::setID(int ID1)
{
	id1 = ID1;
}
int Student::getID()
{
	return id1;
}
bool Student::addCourse(Course& c)
{
	for (int i = 0; i < 6; i++)
	{
		if (cptr[i] == nullptr)
		{
			cptr[i] = &c;
			c.addStudent(*this);
			return true;
		}
		else if (cptr[i] == &c)
		{
			return false;
		}
	}
	return false;
}
Course* Student::searchCourse(int cid)
{
	for (int i = 0; i < 6; i++)
	{
		if (cptr[i] == nullptr)
		{
			continue;
		}
		if (cptr[i]->getID() == cid)
		{
			cout << "Course found with name of " << cptr[i]->getName() << endl;
			return cptr[i];
		}
		
	}
		cout << "Course not found\n";
		return nullptr;
}
bool Student::dropCourse(int cid)
{
	for (int i = 0; i < 6; i++)
	{
		if (cptr[i] == nullptr)
		{
			continue;
		}
		if (cptr[i]->getID() == cid)
		{
			cptr[i]->removeStudent(*this);
			cptr[i] = nullptr;
			return true;
		}
	}
	return false;

}
void Student::showCourses()
{
	for (int i = 0; i < 6; i++)
	{
		if (cptr[i] == nullptr)
		{
			continue;
		}
		if (cptr[i] != nullptr)
		{
			cout << "Course ID: " << cptr[i]->getID() << endl;
		}
	}
}
Course* Student:: getCptr(int index)
{
	return cptr[index];
}
bool Student::VacancyForCourse(Course* cptr1)
{
	for (int i = 0; i < 6; i++)
	{
		if (cptr[i] == nullptr)
			continue;
		if (cptr[i] == cptr1)
		{
			//cout << "This student is enrolled in this course so he can't become the TA of this course\n";
			return false;
		}
	}
	if (courseForTAship == nullptr)
	{
		//cout << "This student can be assigned a TA to a course\n";
		return true;
	}
	//cout << "This student is already a TA\n";
	return false;
}
//void Student:: copyClist()
//{
//	obj = new University;
//	for (int i = 0; i < 100; i++)
//	{
//		CLISTinStudent[i] = (obj->getCLIST(i));
//	}
//	delete obj;
//}
bool Student::CrsofTA(Course* cptr1)
{
	//copyClist();
	/*for (int i = 0; i < 5; i++)
	{
		if (u->getCLIST[i] == nullptr)
			continue;
		if ((u->getCLIST[i])->getID() == cid)
		{*/
	if (VacancyForCourse(cptr1))
	{
		courseForTAship = cptr1;
		//cout << "Course has been assigned for TAship to this student\n";
		return true;
	}
	else
	//cout << "Course cannot be assigned for TAship to this student\n";
	return false;
}
bool Student::removingCrsFromTA(Course* cptr1)
{
	if (courseForTAship == cptr1)
	{
		courseForTAship = nullptr;
		//cout << "Course removed from student\n";
		return true;
	}
	else
		//cout << "Course not removed from student\n";
	return false;
}
void Student::showCourse()
{
	if (courseForTAship != nullptr)
	{
		cout << "Course ID: " << courseForTAship->getID() << endl;
		cout << "Course Name: " << courseForTAship->getName() << endl;
	}
}
Student::~Student()
{
	delete[]cptr;
	delete courseForTAship;
}
