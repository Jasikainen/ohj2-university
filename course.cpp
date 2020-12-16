#include "course.hh"

using namespace std;

Course::Course(string code, string name, int credits):
    course_code_(code),
    name_(name),
    credits_(credits)
{

}

Course::~Course(){
    for ( Instance* instance : instances_ ){
        delete instance;
    }
}

void Course::print_info(bool print_new_line){
    cout << course_code_ << " : " << name_;
    if( print_new_line ){
        cout << endl;
    }
}

void Course::print_staff(){
    cout << "* Staff: " << endl;
    for ( auto account : course_staff_ ){
        account->print();
    }
}

void Course::print_long_info(){
    cout << "* Course name: " << name_ << endl
         << "* Code: " << course_code_ << endl;
    print_staff();
    cout << "* Instances: " << endl;

    for ( auto instance : instances_ ){
        instance->print();
    }
}

void Course::print_signups(){
    for ( auto instance : instances_ ){
        instance->print();
        instance->print_students();
    }
}

void Course::add_staff(Account* new_staff){
    for ( unsigned int i = 0; i < course_staff_.size(); ++i ){
        if ( course_staff_.at(i) == new_staff ){
            cout << STAFF_EXISTS << endl;
            return;
        }
    }
    course_staff_.push_back(new_staff);
    cout << STAFF_ADDED << endl;
}

void Course::new_instance(Instance* n_instance){
    // Add new instance to vector of instaces under course
    instances_.push_back(n_instance);
    cout << INSTANCE_ADDED << endl;
}

bool Course::has_instance(const string& name){
    for ( auto instance : instances_ ){
        if ( instance->is_named(name) ){
            return true;
        }
    }
    return false;
}

Instance* Course::get_instance(string name){
    for ( Instance* instance : instances_ ){
        if ( instance->is_named(name) ){
            return instance;
        }
    }
    return nullptr;
}

const string Course::get_code() const{
    return course_code_;
}

int Course::get_credits() const{
    return credits_;
}

unsigned int Course::amount_of_courses_instances(){
    return instances_.size();
}

Instance* Course::get_instance_by_index(unsigned int i){
    return instances_.at(i);
}

string Course::get_course_information(){
    return course_code_ + " : " + name_;
}





