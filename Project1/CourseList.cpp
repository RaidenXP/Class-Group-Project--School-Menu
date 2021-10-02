/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 2
*************************/

#include "CourseList.h"

using namespace std;

const int CourseList::CAP = 10;

CourseList::CourseList() 
{
	courseList.reserve(CAP);
}

CourseList::CourseList(int newCap) 
{
	courseList.reserve(newCap);
}

CourseList::CourseList(const vector<Course>& otherList) 
{
	courseList = otherList;
}

void CourseList::addCourse(const Course& newCourse)
{
	if (courseList.size() >= courseList.capacity()) 
	{
		courseList.reserve(courseList.capacity() * 2);
	}

	courseList.push_back(newCourse);
}

double CourseList::getCourseUnits(const string& prefix,
	int number) const
{
	for (auto elem : courseList) 
	{
		if (elem.getCoursePrefix() == prefix
			&& elem.getCourseNo() == number) 
		{
			return elem.getCourseUnits();
		}
	}

	return 0.0;
}

bool CourseList::searchCourse(const string& prefix, int number) const 
{
	for (auto elem : courseList) 
	{
		if (elem.getCoursePrefix() == prefix
			&& elem.getCourseNo() == number) 
		{
			return elem.getCourseUnits();
		}
	}

	return false;
}

CourseList& CourseList::operator=(const CourseList& otherList)
{
	if (&otherList != this)
	{
		courseList = otherList.courseList;
	}
	else
	{
		cerr << "Attempted assignment to self.";
	}

	return *this;
}

CourseList::~CourseList() 
{}