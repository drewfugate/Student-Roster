#include "student.h"


Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age,
	int completionDays[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) {
		this->completionDays[i] = completionDays[i];
	}
	this->degreeProgram = degreeProgram;
}

//Destructor
Student::~Student() {

}

//Getters
string Student::getStudentID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmailAddress() {
	return this->emailAddress;
}

int Student::getAge() {
	return this->age;
}

int* Student::getCompletionDays() {
	return this->completionDays;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

//Setters
void Student::setStudentID(string studentID){
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setCompletionDays(int completionDays[]){
	for (int i = 0; i < daysArraySize; i++) {
		this->completionDays[i] = completionDays[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

//Prints information about a student, along with the necessary information for readability such as "First Name".
void Student::print() {
	cout << this->getStudentID() << "\t";
	cout << "First Name: " << this->getFirstName() << "\t";
	cout << "Last Name: " << this->getLastName() << "\t";
	cout << "Email Address: " << this->getEmailAddress() << "\t";
	cout << "Age: " << this->getAge() << "\t";
	cout << "daysInCourse: {" << getCompletionDays()[0] << ", " << getCompletionDays()[1] << 
		", " << getCompletionDays()[2] << "}" << "\t";
	cout << "Degree Program: " << degreeProgramStrings[getDegreeProgram()] << "\n";
}


