/* Class: Instance
 * ----------
 * TIE-02201/TIE-02207 SPRING 2020
 * ----------
 * Class that represent a single instance.
 *
 * This instance keep track of instances name and the date which represents
 * the deadline for course enrollment. Instance has also a vector of students
 * attending to the instance.
 *
 * */
#ifndef INSTANCE_HH
#define INSTANCE_HH

#include "account.hh"
#include "date.hh"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Forward-declaration of Course, so that instance can point to the course it belongs to.
class Course;

const string ALREADY_REGISTERED = "Error: Student has already registered on this course.";
const string LATE = "Error: Can't sign up on instance after the starting date.";
const string INDENT = "    ";

class Instance
{
public:
    /**
     * @brief Instance
     * @param instance_name
     * @param instance_date as a Date object
     */
    Instance(string instance_name, Date* instance_date);

     // Instance destructor. Also deletes created date.
    ~Instance();

    /**
     * @brief print
     * Prints basic information of instance:
     * Name, starting date and the amount of students enrolled
     */
    void print();

    /**
     * @brief print_students
     * Print students attended to the instance
     */
    void print_students();

    /**
     * @brief is_named
     * @param name_to_find instances name that is searched
     * Returns true if instances name is same as requested
     */
    bool is_named(string name_to_find);

    /**
     * @brief add_student
     * @param student Account of student to be added to instance of course
     * @param today Current date that is compared to instances starting date
     * Returns true if account may be enrolled to the instance
     */
    bool add_student(Account* student, Date today);

    /**
     * @brief return_instance_name
     * @return instances name
     */
    string return_instance_name();

private:
    vector<Account*> accounts_;
    string instance_name;
    class Date* instance_date;
};

#endif // INSTANCE_HH

