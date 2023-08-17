#include "roster.h"
#include <iostream>

using namespace std;

int main() {
	const int numStudents = 5;
	//Print to console course title, C++, student ID, and name.
	cout << "C867, C++, 010306572, Drew Fugate\n";
	
	//Array of unparsed student data.
	string studentData[numStudents]
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Drew,Fugate,dfuga13@wgu.edu,24,30,32,35,SOFTWARE"
	};
	
	Roster classRoster(numStudents); //Instance of the Roster class.
	
	//Parse and add all students to object classRosterArray
	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]);
	}

	classRoster.printAll(); //Print information about every student.

	classRoster.printInvalidEmails(); //Print all invalid emails.

	//Print average days in course for all students.
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}

	classRoster.printByDegreeProgram(SOFTWARE); //Prints information about all students in the Software degree.
	classRoster.remove("A3"); //Removes student with ID "A3".
	classRoster.printAll(); //Checks to ensure student was removed.
	classRoster.remove("A3"); //Ensures previously removed student is not found.

	return 0;
}