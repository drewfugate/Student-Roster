#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;


class Student
{
public:
	const static int daysArraySize = 3; //Constant size for the array of completion days
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int completionDays[daysArraySize]; //Array of number of days to complete each course
	DegreeProgram degreeProgram;

public:
	//Constructor for Student object
	Student(string StudentID, string firstName, string lastName, string emailAddress, int age,
		int completionDays[], DegreeProgram degreeProgram);
	~Student(); //Destructor

	//Getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getCompletionDays();
	DegreeProgram getDegreeProgram();

	//Setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setCompletionDays(int completionDays[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print(); //Prints information about a student.


};

