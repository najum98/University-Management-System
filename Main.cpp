#include <iostream>
#include <string>
using namespace std;
#include "StudentHeader.h"
#include "FMClass.h"
#include "UniHeader.h"
int ci, si = 0;int againm = 2;
University obj;
void Menu()
{
	int choice = 0;
	cout << "\n                                         Welcome to University Database \n\n\n";
	cout << "--> Enter 1 to create a new course\n";
	cout << "--> Enter 2 to create a new student\n";
	cout << "--> Enter 3 to search a course\n";
	cout << "--> Enter 4 to search a student\n";
	cout << "--> Enter 5 for a student to add a particular course\n";
	cout << "--> Enter 6 for a student to drop a particular course\n";
	cout << "--> Enter 7 to display information of all the courses a particular student has added\n";
	cout << "--> Enter 8 to display information of all the students enrolled in a particular course\n";
	cout << "--> Enter 9 to create a new faculty member\n";
	cout << "--> Enter 10 to assign course to faculty member\n";
	cout << "--> Enter 11 to removed course from a faculty member\n";
	cout << "--> Enter 12 to assign TA to a faculty member\n";
	cout << "--> Enter 13 to remove TA from a faculty member\n";
	cout << "--> Enter 14 to see courses assigned to a faculty member\n";
	cout << "--> Enter 15 to see TA's assigned to a faculty member\n";
	cout << "--> Enter 16 to see the teacher of a course\n";
	cout << "--> Enter 16 to see the TA of a course\n";
	cout << "--> Enter 18 to see course of TA\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
			  int ID = 0;
			  string Name = " ";
			  cout << "Enter the ID of the course you want to add\n"; cin >> ID;
			  cout << "Enter the name of the course you want to add\n"; cin >> Name;
			  if (obj.addNewCourse(ID, Name))
				  cout << "Course has been added Successfully\n";
			  else
				  cout << "Sorry! Course isn't added\n";
			  cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			  break;
	}
	case 2:
	{
			  int ID = 0; double CGPA = 0;
			  cout << "Enter the ID of the student you want to add\n"; cin >> ID;
			  cout << "Enter the CGPA of the student you want to add\n"; cin >> CGPA;
			  while (CGPA<0 || CGPA>4)
			  {
				  cout << "That's not a valid CGPA. Enter valid value\n";
				  cin >> CGPA;
			  }
			  if (obj.addNewStudent(ID,CGPA))
				  cout << "Student has been added Successfully\n";
			  else
				  cout << "Sorry! Student isn't added\n";
			  
			  againm = 2;
			  cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			  break;
	}
	case 3:
	{
			  int count = 0;
			  int ID = 0;
			  cout << "Enter the ID of the course you want to search\n"; cin >> ID;
			  if (obj.searchcourse(ID) != -1)
				  cout << "Yes this course is available!\n";
			  else
				  cout << "No, this course is not available\n";
			  cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			  break;
	}
	case 4:
	{
			  int ID,count = 0;
			  cout << "Enter the ID of the student you want to search\n"; cin >> ID;
			  
			  if (obj.searchstudent(ID) != -1)
				  cout << "Yes this student is  available!\n";
			  else
				  cout << "No, this student is not available\n";

			  cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			  break;
	}
	case 5:
	{
			  int cid, sid,count = 0;
			  cout << "Enter the ID of a student who wants to add a course\n"; cin >> sid;
			  cout << "Enter the ID of course this student wants to add\n"; cin >> cid;
			  
			  if (obj.studentaddcourse(sid, cid))
				  cout << "Course has been added successfully\n";
			  else
				  cout << "Sorry, course addition failed\n";
			  
			  cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			  break;
	}
	case 6:
	{
			  int cid, sid, count = 0;
			  cout << "Enter the ID of a student who wants to drop a course\n"; cin >> sid;
			  cout << "Enter the ID of course this student wants to drop\n"; cin >> cid;
			
			  if (obj.studentdropcourse(sid, cid))
				  cout << "Course has been dropped successfully\n";
			  else
				  cout << "Sorry, course dropage failed\n";
			  
			  cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			  break;
	}
	case 7:
	{
			  int sid,count = 0;
			  cout << "Enter the ID of student about whose courses you want to know\n"; cin >> sid;
			  
			  obj.displaystudentinfo(sid);

			  cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			  break;
	}
	case 8:
	{
			  int cid, count = 0;
			 cout << "Enter the ID of course about whose courses you want to know\n"; cin >> cid;
			 
			 obj.displaycourseinfo(cid);

			 cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			  break;
	}
	case 9:
	{
			  int id,yos, count = 0;
			  string deg;
			  cout << "Enter the ID of the faculty member\n"; cin >> id;
			  cout << "Enter the experience(in years) of the faculty member\n"; cin >> yos;
			  cout << "Enter the qualification fo the faculty member\n"; cin >> deg;
			  if (obj.addNewFacultyMember(id, deg, yos))
				  cout << "Faculty Member Created Successfully\n";
			  else
				  cout << "Faculty Member Creation Failed\n";
			  cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			  break;
	}
	case 10:
	{
			   int fid, cid,count = 0;
			   cout << "Enter the ID of the course\n"; cin >> cid;
			   cout << "Enter the ID of the faculty member\n"; cin >> fid;
			   if (obj.AssignCourseToFacultyMember(fid, cid))
				   cout << "Course assigned to faculty member\n";
			   else
				   cout << "Course cant be assigned to faculty member\n";
			   cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			   break;
	}
	case 11:
	{
			   int fid, cid, count = 0;
			   cout << "Enter the ID of the course\n"; cin >> cid;
			   cout << "Enter the ID of the faculty member\n"; cin >> fid;
			   if (obj.RemoveCourseFromFM(fid, cid))
				   cout << "Course removed from faculty member\n";
			   else
				   cout << "Course cant be removed from faculty member\n";
			   cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			   break;
	}
	case 12:
	{
			   int fid, sid, cid, count = 0;
			   cout << "Enter the ID of the faculty member\n"; cin >> fid;
			   cout << "Enter the ID of the student\n"; cin >> sid;
			   cout << "Enter the ID of thee course\n"; cin >> cid;
			   if (obj.AssignTAtoFacultyMember(fid, sid, cid))
				   cout << "TA assigned successfully\n";
			   else
				   cout << "TA cannot be assigned\n";
			   cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			   break;
	}
	case 13:
	{
			   int fid, sid, cid, count = 0;
			   cout << "Enter the ID of the faculty member\n"; cin >> fid;
			   cout << "Enter the ID of the student\n"; cin >> sid;
			   cout << "Enter the ID of thee course\n"; cin >> cid;
			   if (obj.RemoveTAfromFacultyMember(fid, sid, cid))
				   cout << "TA removed successfully\n";
			   else
				   cout << "TA cannot be removed\n";
			   cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			   break;
	}
	case 14:
	{
			   int fid, count = 0;
			   cout << "Enter the ID of faculty member about whose courses you want to know\n"; cin >> fid;

			   obj.ShowCoursesofFM(fid);

			   cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			   break;
	}
	case 15:
	{
			   int fid, count = 0;
			   cout << "Enter the ID of faculty member about whose TA's you want to know\n"; cin >> fid;

			   obj.ShowTAofFM(fid);

			   cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			   break;
	}
	case 16:
	{
			   int cid, count = 0;
			   cout << "Enter the ID of course about whose teacher you want to know\n"; cin >> cid;

			   obj.showTeacherofCourse(cid);

			   cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			   break;
	}
	case 17:
	{
			   int cid, count = 0;
			   cout << "Enter the ID of course about whose TA you want to know\n"; cin >> cid;

			   obj.showTAofCourse(cid);

			   cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			   break;
	}
	case 18:
	{
			   int sid, count = 0;
			   cout << "Enter the ID of TA about whose course you want to know\n"; cin >>sid;

			   obj.ShowCourseofTA(sid);

			   cout << "Enter 0 to go back to menu again OR Enter any key to exit\n"; cin >> againm;
			   break;
	}
	}

}

void main()
{
	
	//Course c1(001, "oop");
	//Student s1(546, 3);
	//FacultyMember f1(12, "a", 13);
	//obj.AssignCourseToFacultyMember(12, 001);
	//s1.VacancyForCourse(&c1);
	//s1.addCourse(c1);
	//c1.availabilityOfTA();
	/*c1.AssigningTAtoCourse(&s1);
	c1.AssigningTAtoCourse(&s1);*/
	/*f1.assignTA(&s1, &c1);
	f1.removeTA(&s1, &c1);*/
	obj.addNewCourse(3, "oop");
	obj.addNewFacultyMember(1, "deg", 5);
	obj.addNewStudent(2, 3);
	Menu();
	while (againm == 0)
	{
		system("cls");
		Menu();
	}

}