#ifndef CourseEnc
#define CourseEnc
using namespace std;
#include <string>

class Student;
class FacultyMember;

class Course
{
	int id;
	string name;
	Student* sptr[100];
	FacultyMember* fmptr;
	Student* TA;
public:
	Course(int ID, string Name);
	Course();
	void setID(int ID);
	int getID();
	void setName(string Name);
	string getName();
	bool addStudent(Student& s);
	Student* searchStudent(int sid);
	bool removeStudent(Student& s);
	void showStudents();
	Student* getSptr(int index);
	bool addFM(FacultyMember& fm);
	FacultyMember* getFmptr();//fmptr isliye get krty hyn k check krskyn k course k pas vacancy b h k nh??
	bool removeFM(FacultyMember& fm);
	bool availabilityOfTA();
	bool AssigningTAtoCourse(Student* sptr);
	bool removingTAfromCourse(Student* sptr);
	void showTeacher();
	void showTA();
	~Course();

	
};


#endif