/* Class: Course
 * ----------
 * TIE-02201/TIE-02207 SPRING 2020
 * ----------
 * Class that represents a single course, with name and code, staff and instances.
 *
 * */
#ifndef COURSE_HH
#define COURSE_HH

#include <string>
#include <vector>
#include <iostream>
#include "account.hh"
#include "instance.hh"

using namespace std;

const string STAFF_ADDED = "A new staff member has been added.";
const string INSTANCE_ADDED = "A new instance has been added.";
const string STAFF_EXISTS = "Error: Staff member already added on this course.";

class Course
{
public:
    /**
     * @brief Course
     * @param code unique code for the course, used a s id
     * @param name
     * @param credits
     */
    Course(string code, string name, int credits = 5);

    // Destructor. Also deletes the created instances, if any.
    ~Course();

    /**
     * @brief print_info
     * @param print_new_line
     * Print short course info, if print_new_line, the also a newline at the end.
     */
    void print_info(bool print_new_line);

    /**
     * @brief print_staff
     * Print all staff of the course.
     */
    void print_staff();

    /**
     * @brief print_long_info
     * Print longer course info, with staff and instances.
     */
    void print_long_info();

    /**
     * @brief print_signups
     * @param today
     * Print all signups on active courses.
     */
    void print_signups();

    /**
     * @brief add_staff
     * @param new_staff
     * Add a staff member to course.
     */
    void add_staff(Account* new_staff);

    /**
     * @brief new_instance
     * @param n_instance to be added.
     * Add a new instance to the course.
     * @note Course will handle the deletion of all instances associated with it
     */
    void new_instance(Instance* n_instance);

    /**
     * @brief has_instance
     * @param name
     * @return true if course has instance named given name, false otherwise
     */
    bool has_instance(const string& name);

    /**
     * @brief get_instance
     * @param name
     * @return instance named given name, nullptr otherwise
     */
    Instance* get_instance(string name);

    /**
     * @brief get_code
     * @return the course code.
     */
    const string get_code() const;

    /**
     * @brief get_credits
     * @return the amount of credits this course is valued.
     */
    int get_credits() const;

    /**
     * @brief amount_of_courses_instances
     * @return the amount of instances for course
     */
    unsigned int amount_of_courses_instances();

    /**
     * @brief get_instance_by_index
     * @param i the index which is used to get instance from
     * the vector instances_
     * @return pointer to Instance object
     */
    Instance* get_instance_by_index(unsigned int i);

    /**
     * @brief get_course_information
     * @return courses code and name in wanted from
     */
    string get_course_information();

private:
    string course_code_;
    string name_;
    vector<Account*> course_staff_;
    vector<Instance*> instances_;
    int credits_;
};

#endif // COURSE_HH

