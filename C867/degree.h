#pragma once
#include <string>
//Define an enumerated data type "DegreeProgram" for the degree programs containing 
//the data type values: SECURITY, NETWORK, and SOFTWARE

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE }; //Types of degree programs.

//Enumeration in string form for clarity when printing to console.
static const std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };