/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 2
*************************/

#include "StudentList.h"

using namespace std;

StudentList::StudentList() 
{
	studentList = new list<Student>;
}

StudentList::StudentList(const StudentList& newList)
{
	studentList = new list<Student>;
	*studentList = *(newList.studentList);
}

StudentList& StudentList::operator=(const StudentList& otherList)
{
	if (&otherList != this)
	{
		*studentList = *(otherList.studentList);
	}
	else
	{
		cerr << "Attempted assignment to self.";
	}
	return *this;
}

void StudentList::addStudent(const Student& newStudent)
{
	studentList->push_back(newStudent);
}

int StudentList::getNoOfStudents() const
{
	return static_cast<int>(studentList->size());
}

void StudentList::printStudentByID(int studentID) const
{

	if (studentList->size() == 0)
	{
		cerr << "List is empty.";
	}
	else
	{
		auto current = studentList->begin();

		while (current != studentList->end())
		{
			if (current->getID() == studentID)
			{
				current->printStudentInfo();
				current = studentList->end();
			}
			else
				if(++current == studentList->end())
					cout << "No student with ID " <<
				studentID << " found in the list." << endl;
		}

	}
}

void StudentList::printStudentsByCourse(const string& cPre, 
	int cNum) const
{
	if (studentList->size() == 0)
		cerr << "List is empty.";
	else
	{
		bool found = false;

		for (auto elem : *studentList)
		{
			if (elem.getNumberOfCourses() > 0)
			{
				if (elem.courseIsCompleted(cPre, cNum))
				{
					elem.printStudent();
					found = true;
				}
			}
		}

		if (!found) cout << "No student completed " << cNum << endl;
	}
}

void StudentList::printStudentByName(const string& lastName) const
{
	if (studentList->size() == 0)
	{
		cerr << "List is empty.";
	}
	else
	{
		bool found = false;

		for(auto elem : *studentList)
		{
			if (elem.Person::getLastName() == lastName)
			{
				elem.printStudent();
				found = true;
			}
		}

		if (!found)
		{
			cout << "No student with last name " 
				<< lastName << " is in the list." <<endl;
		}
	}
}

//Le, Emily
void StudentList::printStudentByFirstName(const string& firstName) const
{
	if (studentList->size() == 0)
	{
		cerr << "List is emmpty.";
	}
	else
	{
		bool found = false;

		for(auto elem : *studentList)
		{
			if(elem.Person::getFirstName() == firstName)
			{
				elem.printStudent();
				found = true;
			}
		}

		if (!found)
		{
			cout << "No student with first name " 
				<< firstName << " is in the list." <<endl;
		}
	}
}

void StudentList::printStudentsOnHold() const
{
	if (studentList->size() == 0)
		cerr << "List is empty.";
	else
	{
		bool found = false;

		for (auto elem : *studentList)
		{
			if (!(elem.isTuitionPaid()))
			{
				elem.printStudentInfo(); 
				found = true;
			}
		}

		if (!found) cout << "There are no students on hold." << endl;
	}
}

void StudentList::printAllStudents() const
{
	if (studentList->size() == 0)
		cerr << "List is empty.";
	else
	{
		for (auto elem : *studentList)
		{
			elem.printStudentInfo();
		}
	}
}

//Tran, Nathan
double StudentList::getGpaAvgOfAll() const
{
	double avg = 0.0;
	for(auto elem : *studentList)
	{
		avg += elem.getGpa();
	}

	return avg /= static_cast<double>(studentList->size());
}

//Dawson, Tallis
void StudentList::printCourseAverageGPA(const string& cPre, int cNum) const
{
	if (studentList->size() <= 0)
		cerr << "List is empty.";
	else
	{
		double avgGPA = 0.0;
		int numStudents = 0;

		for (auto elem : *studentList)
		{
			if (elem.getNumberOfCourses() > 0)
			{
				if (elem.courseIsCompleted(cPre, cNum))
				{
					avgGPA += elem.getGpa();
					++numStudents;
				}
			}
		}

		if (numStudents > 0)
		{
			cout << "Total number of Students enrolled in ";
			cout << cPre << " " << cNum << ": ";
			cout << numStudents << endl;
			cout << endl;

			cout << "Average GPA: ";
			avgGPA /= numStudents;
			cout << fixed << setprecision(2);
			cout << avgGPA << endl;
		}
		else
		{
			cout << "No student completed " << cNum << endl;
		}
	}
}

void StudentList::destroyStudentList()
{
	studentList->clear();
}

StudentList::~StudentList()
{
	delete studentList;
	studentList = nullptr;
}