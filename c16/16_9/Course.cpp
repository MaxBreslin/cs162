#include <iostream>
#include <cstring>

#include "Course.h"
#include "Student.h"
using namespace std;

Course InitCourse() {
	Course course;
	course.numStudents = 0;
	return course;
}

Student FindStudentHighestGPA(Course course) {
   Student topStudent = course.roster[0];
   for (int i = 0; i < course.numStudents; i++) {
      if (GetGPA(course.roster[i]) > GetGPA(topStudent)) {
         topStudent = course.roster[i];
      }
   }
   return topStudent;
}

Course AddStudent(Student student, Course course) {
	course.roster[course.numStudents].gpa = student.gpa;
	strcpy(course.roster[course.numStudents].last, student.last);
	strcpy(course.roster[course.numStudents].first, student.first);
	course.numStudents++;
	return course;
}