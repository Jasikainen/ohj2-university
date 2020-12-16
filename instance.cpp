#include "instance.hh"
#include "course.hh"

using namespace std;

Instance::Instance(string name, Date* date):
    instance_name(name),
    instance_date(date)
{

}

Instance::~Instance(){
    delete instance_date;
}

void Instance::print(){
    cout << instance_name << endl;
    cout << INDENT << "Starting date: " << instance_date->get_day() << "." <<
                 instance_date->get_month() << "." <<
                 instance_date->get_year() << endl;
    cout << INDENT << "Amount of students: " << accounts_.size() << endl;
}

void Instance::print_students(){
    for ( auto account : accounts_ ){
        cout << INDENT; account->print();
    }
}

bool Instance::is_named(string name_to_find){
    if ( instance_name == name_to_find ){
        return true;
    }
    return false;
}

bool Instance::add_student(Account* student, Date today){
    // Student may not be in the course already
    for ( auto account : accounts_ ){
        if ( account == student ){
            cout << ALREADY_REGISTERED << endl;
            return false;
        }
    }
    // Check if the deadline has not passed
    if ( instance_date->operator <(today) ){
        cout << LATE << endl;
        return false;
    }
    accounts_.push_back(student);
    return true;
}

string Instance::return_instance_name(){
    return instance_name;
}
