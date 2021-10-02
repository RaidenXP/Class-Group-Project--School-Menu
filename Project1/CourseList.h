/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 2
*************************/

#ifndef COURSELIST_H
#define COURSELIST_H

#include <vector>

#include "Course.h"

class CourseList
{
public:

	CourseList();
	CourseList(int); 
	CourseList(const std::vector<Course>&);

	void addCourse(const Course&);

	double getCourseUnits(const std::string&, int) const;

	bool searchCourse(const std::string&, int) const;

	CourseList& operator=(const CourseList&);

	~CourseList();

private:
	std::vector<Course> courseList;	
	static const int CAP;
};

#endif