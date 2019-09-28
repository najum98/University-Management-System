#include "FMClass.h"
#include "StudentHeader.h"
#include "CourseHeader.h"
#include "UniHeader.h"


FacultyMember::FacultyMember()
{
	id1 = 0;
	degree = " ";
	yearsOfService = 0;
}
FacultyMember::FacultyMember(int id, string deg, int yos) :PUCITPerson(id)
{
degree = deg;
yearsOfService = yos;
for (int i = 0; i < 3; i++)
{
Teacher[i] = nullptr;
TAlist[i] = nullptr;
}
//cout << "FM parametrized ctor cld\n";
}
int FacultyMember::getID()
{
	return id1;
}
bool FacultyMember::AssignCourse(Course* cptr)
{
	int count = 0;
	if (this->getYOS() >= 5)
	{
		if (cptr->getFmptr() == nullptr) //kya is course ke pas vacancy hy new teacher k lie??
		{
			for (int i = 0; i < 3; i++)
			{

				if (getTeacher(i) != nullptr)
					count++;
			}
			if (count <= 3)
			{
				for (int i = 0; i < 3; i++)
				{
					if (getTeacher(i) == nullptr)
					{
						Teacher[i] = cptr;
						cptr->addFM(*this);
						//cout << "Crs Asignd\n";
						return true;
					}
				}
			}
		}
	}
	else if (getYOS() < 5 && getYOS() >= 0)
	{
		count = 0;
		if (cptr->getFmptr() == nullptr) //kya is course ke pas vacancy hy new teacher k lie??
		{
			for (int i = 0; i < 3; i++)
			{
				if (getTeacher(i) != nullptr)
					count++;
			}
			if (count <= 2)
			{
				for (int i = 0; i < 3; i++)
				{
					if (getTeacher(i) == nullptr)
					{
						Teacher[i] = cptr;
						cptr->addFM(*this);
						//cout << "Crs Asignd\n";
						return true;
					}
				}
			}
		}
	}
	cout << "Crs Not Asignd\n";
	return false;
}
bool FacultyMember::removeCourse(int cid)
{
	for (int i = 0; i < 3; i++)
	{
		if (Teacher[i] == nullptr)
			continue;
		if (Teacher[i]->getID() == cid)
		{
			Teacher[i]->removeFM(*this);
			Teacher[i] = nullptr;
			//cout << "Crs rmvd\n";
			return true;
		}
	}
	//cout << "Crs not rmvd\n";
	return false;
}
bool FacultyMember::assignTA(Student* sptr, Course* cptr)
{
	for (int i = 0; i < 3; i++)
	{

		if (TAlist[i] == nullptr)
		{
			//obj = new Course;
			if (sptr->getCGPA() >= 3 && sptr->VacancyForCourse(cptr) && cptr->availabilityOfTA())
			{
				TAlist[i] = sptr;
				sptr->CrsofTA(cptr);
				cptr->AssigningTAtoCourse(sptr);
				//delete obj;
				//cout << "TA Assigned\n";
				return true;
			}
		}
	}
	//cout << "TA not Assigned\n";
	return false;

}
bool FacultyMember::removeTA(Student* sptr,Course* cptr)
{
	for (int i = 0; i < 3; i++)
	{
		if (TAlist[i] != nullptr)
		{
			if (!sptr->VacancyForCourse(cptr) && !cptr->availabilityOfTA())
			{
				TAlist[i] = nullptr;
				cptr->removingTAfromCourse(sptr);
				sptr->removingCrsFromTA(cptr);
				//cout << "TA removed\n";
				return true;

			}
		}

	}
	//cout << "TA not removed\n";
	return false;
}
int FacultyMember::getYOS()
{
	return yearsOfService;
}
Course* FacultyMember::getTeacher(int index)
{
	return Teacher[index];
}
void FacultyMember::showCourses()
{
	for (int i = 0; i < 3; i++)
	{
		if (Teacher[i] == nullptr)
			continue;
		cout << "Course ID: " << Teacher[i]->getID() << endl;
	}
}
void FacultyMember::showTA()
{
	for (int i = 0; i < 3; i++)
	{
		if (TAlist[i] == nullptr)
			continue;
		cout << "TA ID: " << TAlist[i]->getID() << endl;
	}
}
FacultyMember::~FacultyMember()
{
	delete[]Teacher;
	delete[]TAlist;
}
