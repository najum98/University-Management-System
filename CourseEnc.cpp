#include "CourseHeader.h"
#include "StudentHeader.h"
#include "FMClass.h"
#include <string>
#include <iostream>


Course::Course(int ID, string Name)
{
	id = ID;
	name = Name;
	for (int i = 0; i < 100; i++)
	{
		sptr[i] = nullptr;
	}

}
Course::Course()
{
	id = 0;
	name = " ";
	for (int i = 0; i < 100; i++)
	{
		sptr[i] = nullptr;
	}
}
void Course::setID(int ID)
{
	id = ID;
}
int Course::getID()
{
	return id;
}
void Course::setName(string Name)
{
	name = Name;
}
string Course::getName()
{
	return name;
}
bool Course::addStudent(Student& s)
{
	for (int i = 0; i < 100; i++)
	{
		if (sptr[i] == nullptr)
		{
			sptr[i] = &s;
			//cout << "Student added successfully\n";
			return true;
		}
		
	}
	//cout << "Can't add student\n";
	return false;
}
Student* Course::searchStudent(int sid)
{
	for (int i = 0; i < 100; i++)
	{
		if (sptr[i] == nullptr)
		{
			continue;
		}
		if (sptr[i]->getID() == sid)
		{
			//cout << "Student found\n";
			return sptr[i];
		}

	}
	//cout << "Student not found\n";
	return nullptr;
}
bool Course:: removeStudent(Student& s)
{
	for (int i = 0; i < 5; i++)
	{
		if (sptr[i] == nullptr)
		{
			continue;
		}
		if (sptr[i]->getID() == s.getID())
		{
			sptr[i] = nullptr;
			//cout << "Student removed successfully\n";
			return true;
		}
	}
	//cout << "No such student is found\n";
	return false;
}
void Course::showStudents()
{
	for (int i = 0; i < 100; i++)
	{
		if (sptr[i] == nullptr)
		{
			continue;
		}
		if (sptr[i] != nullptr)
		{
		cout << "Student ID: " << sptr[i]->getID() << endl;
		}
	}
}
Student* Course::getSptr(int index)
{
	return sptr[index];
}
FacultyMember* Course::getFmptr()
{
	return fmptr;
}
bool Course::addFM(FacultyMember& fm)
{
	if (fmptr == nullptr)
	{
		fmptr = &fm;
		//cout << "FM added in the course\n";
		return true;
	}
	return false;
}
bool Course::removeFM(FacultyMember& fm)
{
	if (fmptr == nullptr)
	{
		return false;
	}
	
	else if (fmptr->getID() == fm.getID())
	{
		fmptr = nullptr;
		return true;
	}
	
	return false;
}
bool Course::availabilityOfTA()
{
	if (TA == nullptr)
	{
		//cout << "TA can be assigned to this course\n";
		return true;
	}
	//cout << "This course already has a TA\n";
	return false;

}
bool Course::AssigningTAtoCourse(Student* sptr)
{
	if (availabilityOfTA())
	{
		TA = sptr;
		//cout << "TA successfully assigned to Course\n";
		return true;
	}
	else
		//cout << "TA cant be assigned to this course\n";
	return false;

}
bool Course:: removingTAfromCourse(Student* sptr)
{
	if (TA == sptr)
	{
		TA = nullptr;
		//cout << "TA removed from course\n";
		return true;
	}
	//cout << "TA cannot removed from course\n";
	return false;
}
void Course::showTeacher()
{
	if (fmptr != nullptr)
		cout << "Teacher ID: " << fmptr->getID() << endl;
	else
		cout << "This course has no teacher assigned to it\n";
}
void Course::showTA()
{
	if (TA != nullptr)
		cout << "TA ID: " << TA->getID() << endl;
	else
		cout << "This course has no TA assigned to it\n";
}
Course::~Course()
{
	delete[]sptr;
	delete fmptr;
	delete TA;
}