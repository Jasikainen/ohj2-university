/* Class: Account
  * ----------
  * Defines a student or a staff account in the university system.
  *
  * One account has basic information of user and the courses they
  * are appending to and those that they have completed.
  *
  * */
#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include "date.hh"
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Instance;
class Course;

const string NO_SIGNUPS = "No signups found on this instance.";
const string SIGNED_UP = "Signed up on the course instance.";
const string COMPLETED = "Course completed.";

class Account
{
public:
    /**
     * @brief Account constructor
     * @param full_name as "frontname lastname"
     * @param email
     * @param account_number
     */
    Account(string full_name, string email, int account_number);
    ~Account();


    /**
     * @brief print account info on one line
     */
    void print() const;

    /**
     * @brief get_email
     * @return email linked to this account
     */
    string get_email();

    /**
     * @brief add_enrolled_instance
     * @param course_instance that is added to students current courses
     */
    void add_enrolled_instance(Instance* course_instance);

    /**
     * @brief complete_course
     * @param course_instance that is searched from Students courses
     * @param course that is added to Students completed courses
     */
    void complete_course(Instance* course_instance, Course* course);

    /**
     * @brief amount_of_current_courses
     * @return the amount of currently active courses
     */
    unsigned int amount_of_current_courses();

    /**
     * @brief print_uncompleted
     * @param courses_ is the map of all courses in the university
     * This prints all uncompleted courses of student
     */
    void print_uncompleted(map <string, Course*> courses_);

    /**
     * @brief print_completed
     * This prints all completed courses for students account
     * with credit points corresponding to the courses
     */
    void print_completed();

private:
    string full_name_;
    string last_name_;
    string first_name_;
    string email_;
    const int account_number_;

    vector<Instance*> current_instances_;
    vector<Course*> completed_courses_;
};

#endif // ACCOUNT_HH
