#pragma once
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>

using namespace std;

class Roster
{
public:
	int studentIndex;
	int numStudents;
	Student** classRosterArray;

	Roster(int numStudents); //Constructor
	~Roster(); //Destructor

	//Parse studentData table
	void parse(string studentData);

	//Add the student objects to classRosterArray
	//Set the instance variables and update the roster.
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	//Removes students from roster by Student ID. If the ID doesn't exist, the
	//function prints an error message indicating that the student was not found.
	void remove(string StudentID);

	//Prints a complete tab-separated list of student data in the provided format:
	//A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20
	//[tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll()
	//function should loop through all the students in classRosterArray and call the
	//print() function for each student.
	void printAll();

	//Prints the student's average number of days in the three courses. Identified by studentID
	void printAverageDaysInCourse(string studentID);

	//Verifies student email addresses and displays all invalid email addresses to the users.
	void printInvalidEmails();

	//Prints out student information for a degree program specified by an enumerated type.
	void printByDegreeProgram(DegreeProgram degreeProgram);
};

