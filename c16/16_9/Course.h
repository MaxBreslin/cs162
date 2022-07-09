#ifndef COURSE_H_
#define COURSE_H_

#include "Student.h"

struct Course {
	Student roster[20];
	int numStudents;
};

Course InitCourse();
Student FindStudentHighestGPA(Course course);
Course AddStudent(Student student, Course course);

#endif