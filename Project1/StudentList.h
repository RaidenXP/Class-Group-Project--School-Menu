/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 2
*************************/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>

#include <list>
#include <algorithm>

class StudentList
{
public:

	StudentList();
	StudentList(const StudentList&);

	StudentList& operator=(const StudentList&);

	void addStudent(const Student&);

	int getNoOfStudents() const;

	//Tran, Nathan
	double getGpaAvgOfAll() const;
	//Le, Emily
	void printStudentByFirstName(const std::string&) const;
	//Dawson, Tallis
	void printCourseAverageGPA(const std::string&, int) const;
 
	void printStudentByID(int) const;
	void printStudentsByCourse(const std::string&, int) const;
	void printStudentByName(const std::string&) const;
	void printStudentsOnHold() const;
	void printAllStudents() const;

	void destroyStudentList();

	~StudentList();

private:
	std::list<Student> *studentList;

};

#endif