#include "roster.h"
#include <iostream>
#include <string>

using namespace std;


//Constructor that takes number of students in the roster.
Roster::Roster(int numStudents) {
    this->studentIndex = 0;
    this->numStudents = numStudents;
    this->classRosterArray = new Student * [numStudents];
}

//This function parses the string of student information into variables of various types.
void Roster::parse(string studentData) {
    //Default values for the student object
    string studentID = "";
    string firstName = "";
    string lastName = "";
    string emailAddress = "";
    int age = 0;
    int daysInCourse1 = 0;
    int daysInCourse2 = 0;
    int daysInCourse3 = 0;
    DegreeProgram degreeProgram = SECURITY;

    //Delimitter "," used to parse the student information into individual variables.
    int delR = studentData.find(",");
    studentID = studentData.substr(0, delR);

    int delL = delR + 1;
    delR = studentData.find(",", delL);
    firstName = studentData.substr(delL, delR - delL);
    
    delL = delR + 1;
    delR = studentData.find(",", delL);
    lastName = studentData.substr(delL, delR - delL);

    delL = delR + 1;
    delR = studentData.find(",", delL);
    emailAddress = studentData.substr(delL, delR - delL);

    delL = delR + 1;
    delR = studentData.find(",", delL);
    age = stoi(studentData.substr(delL, delR - delL));

    delL = delR + 1;
    delR = studentData.find(",", delL);
    daysInCourse1 = stoi(studentData.substr(delL, delR - delL));

    delL = delR + 1;
    delR = studentData.find(",", delL);
    daysInCourse2 = stoi(studentData.substr(delL, delR - delL));

    delL = delR + 1;
    delR = studentData.find(",", delL);
    daysInCourse3 = stoi(studentData.substr(delL, delR - delL));

    delL = delR + 1;
    delR = studentData.find(",", delL);
    string degree = "";
    degree = studentData.substr(delL, delR - delL);
    //Sets degreeProgram enum variable to correct degree.
    if ("SECURITY" == degree) {
        degreeProgram = SECURITY;
    }
    else if ("NETWORK" == degree) {
        degreeProgram = NETWORK;
    }
    else {
        degreeProgram = SOFTWARE;
    }

    //Call the add function to add the parsed data to the student object.
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

//Function to add students to the Student object "classRosterArray".
void Roster::add(string studentID, string firstName, string lastName,
        string emailAddress, int age, int daysInCourse1, int daysInCourse2,
        int daysInCourse3, DegreeProgram degreeProgram) {
    
    //Convert seperate completion days (daysInCourseX) into an array.
    int completionDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 }; 
    
    classRosterArray[studentIndex++] = new Student(studentID, firstName, lastName, emailAddress,
        age, completionDays, degreeProgram);

}

//The remove function will, from the user's point of view, remove a student from the roster based on their student ID. 
void Roster::remove(string studentID) {
    bool studentExists = false; //bool to check whether or not student is found

    //Loops through to try and find student ID
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) { 
            //If student is found, "remove" from roster by hiding them, and moving the other students up in the array.
            studentExists = true;
            cout << "Student successfully removed.\n";
            delete classRosterArray[i];
            for (int j = i; j < numStudents - 1; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
        }
    }
    if (studentExists == false){
        cout << "Error: student with ID of " << studentID << " was not found.\n";
    }
    else {
        numStudents--; //Ensures only the valid students are printed, assuming a student was removed.
    }
}

//Calls the print function for each student.
void Roster::printAll() {
    for (int i = 0; i < numStudents; i++) {
        classRosterArray[i]->print();
    }
}

//Prints the average days a student will spend on any given course.
void Roster::printAverageDaysInCourse(string studentID) {
    int avgDays = 0;
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            avgDays += classRosterArray[i]->getCompletionDays()[0];
            avgDays += classRosterArray[i]->getCompletionDays()[1];
            avgDays += classRosterArray[i]->getCompletionDays()[2];
            avgDays = avgDays / 3;

            cout << "The average days for student " << studentID << " is " << avgDays << "\n";
        }
    }
}

//Looks for students with an invalid email address. A valid email address contains a '.', '@', and no spaces.
void Roster::printInvalidEmails() {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getEmailAddress().find(" ") != string::npos 
            || classRosterArray[i]->getEmailAddress().find(".") == string::npos
            || classRosterArray[i]->getEmailAddress().find("@") == string::npos) {
            cout << "Student " << classRosterArray[i]->getStudentID() << " has an invalid email address of "
                << classRosterArray[i]->getEmailAddress() << "\n";
        }
    }
}

//Prints information about every student with a specified degree program.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "The students with degree program of " << degreeProgramStrings[DegreeProgram(degreeProgram)] << ": " << "\n";
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

//Destructor
Roster::~Roster() {

}

