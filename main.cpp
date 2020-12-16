// Ohjelmointi 2: Perusteet / TIE-02201
// Project 3: University
// Creator: Jani Asikainen - jani.asikainen@tuni.fi - 269362
// 17.4.2020
//
// This program is for keeping track of Universitys courses and their instances
// but also the people working or studying there.
// The main task is to work as of a tool for universitys staff and students to
// find information about the courses.
//
// The courses may have multiple instances which means the course may be held
// at spring or fall of some year. The courses may have accounts assigned
// as courses staff. Students may enroll to courses and after the completion
// students get a record of completed courses.
//
// Theres a command to get help for the use of program. More detailed
// information of programs utilies are printed by using the help command.


#include "utils.hh"
#include "cli.hh"
#include "university.hh"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

const std::string PROMPT = "Uni> ";


int main()
{
    University* university = new University();
    Cli cli(university, PROMPT);
    while ( cli.exec() ){}

    delete university;
    return EXIT_SUCCESS;
}
