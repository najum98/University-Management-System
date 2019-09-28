#ifndef UniEnc
#define UNIEnc
#include "StudentHeader.h"
#include "FMClass.h"
class University
{ 
protected:
	Course* clist[100];
	Student* slist[1000];
	FacultyMember* flist[50];
public:
	University();
	bool addNewCourse(int id, string name);
	bool addNewStudent(int id, double CGPA);
	int searchstudent(int sid);
	int searchcourse(int cid);
	bool studentaddcourse(int sid, int cid);
	bool studentdropcourse(int sid, int cid);
	void displaystudentinfo(int sid);
	void displaycourseinfo(int cid);
	Course* getCLIST(int i);
	bool addNewFacultyMember(int id, string deg, int yos );
	int searchFM(int id);
	bool AssignCourseToFacultyMember(int fid, int cid);
	bool RemoveCourseFromFM(int fid, int cid);
	bool AssignTAtoFacultyMember(int fid, int sid, int cid);
	bool RemoveTAfromFacultyMember(int fid, int sid,int cid);
	void ShowCoursesofFM(int fid);
	void ShowTAofFM(int fid);
	void showTeacherofCourse(int cid);
	void showTAofCourse(int cid);
	void ShowCourseofTA(int sid);
	~University();
};
#endif