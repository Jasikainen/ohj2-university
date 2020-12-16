#include "account.hh"
#include "utils.hh"
#include "instance.hh"
#include "course.hh"

using namespace std;

Account::Account(string full_name, string email, int account_number):
    full_name_(full_name),
    last_name_(""),
    first_name_(""),
    email_(email),
    account_number_(account_number)
{
    vector<string> name = utils::split(full_name_, ' ');
    last_name_ = name.back();
    first_name_ = name.front();
}

Account::~Account(){
}

void Account::print() const{
    cout << account_number_ << ": "
              << first_name_ << " "
              << last_name_  << ", "
              << email_ << endl;
}

string Account::get_email(){
    return email_;
}

void Account::add_enrolled_instance(Instance* course_instance){
    for ( auto instance : current_instances_ ){
        if ( instance == course_instance ){
            return;
        }
    }
    current_instances_.push_back(course_instance);
    cout << SIGNED_UP << endl;
}

void Account::complete_course(Instance* course_instance, Course* course){
    // Find the instance from accounts currently active courses
    for ( auto instance : current_instances_){
        // Course is completed and removed from students current courses
        if (instance == course_instance ){ 
            completed_courses_.push_back(course);
            current_instances_.erase( remove(current_instances_.begin(),
                                            current_instances_.end(),
                                            instance),
                                            current_instances_.end() );
            cout << COMPLETED << endl;
            return;
        }
    }
    cout << NO_SIGNUPS << endl;
}

unsigned int Account::amount_of_current_courses(){
    return current_instances_.size();
}

void Account::print_uncompleted(map<string, Course*> courses_){
    Instance* c_instance = nullptr;
    Course* c_course = nullptr;

    // Iterate through students current_instances_ and find
    // matching from Courses Instances.
    for ( auto students_instance : current_instances_ ){
        for( map<string, Course*>::iterator iter = courses_.begin();
                                            iter != courses_.end(); ++iter ){
            c_course = iter->second;
            unsigned int size = c_course->amount_of_courses_instances();

            // Iterate through current courses instances
            for ( unsigned int i = 0; i < size; ++i ){
                c_instance = c_course->get_instance_by_index(i);
                if ( c_instance == students_instance ){
                    cout << c_course->get_course_information()
                         << " "
                         << students_instance->return_instance_name() << endl;
                }
            }
        }
    }
}

void Account::print_completed(){
    unsigned int credit_points = 0;

    for ( auto students_course : completed_courses_ ){
        students_course->print_info(true);
        credit_points = credit_points + students_course->get_credits();
    }
    cout << "Total credits: " << credit_points << endl;
}


