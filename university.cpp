#include "university.hh"

using namespace std;

University::University():running_number_(111111)
{
}

University::~University(){
    for ( auto course : courses_ ){
        delete course.second;
    }

    for ( auto account : accounts_ ){
        delete account.second;
    }
}

void University::add_course(Params params){
    if ( courses_.find(params.at(0)) != courses_.end() ){
        cout << ALREADY_EXISTS << endl;
        return;
    } else {
        cout << NEW_COURSE << endl;
    }

    Course* n_course = new Course(params.at(0), params.at(1));
    courses_.insert( {n_course->get_code(), n_course} );
}

void University::print_courses(Params){
    for ( auto course : courses_ ){
        course.second->print_info(true);
    }
}

void University::print_course(Params params){
    if ( courses_.find(params.at(0)) == courses_.end() ){
        cout << CANT_FIND << params.at(0) << endl;
        return;
    }
    courses_.at(params.at(0))->print_long_info();
}

void University::add_account(Params params){
    for( map<int, Account*>::iterator iter = accounts_.begin();
                                 iter != accounts_.end(); ++iter ){
        if ( iter->second->get_email() == params.at(1) ){
            cout << ALREADY_EXISTS << endl;
            return;
        }
    }
    // Create new account and print its information
    int account_number = running_number_++;
    Account* n_account = new Account(params.at(0), params.at(1), account_number);
    accounts_.insert({account_number, n_account});
    cout << NEW_ACCOUNT << endl;
    n_account->print();
}

void University::print_accounts(Params){
    for ( auto account : accounts_ ){
        account.second->print();
    }
}

void University::print_account_info(Params params){
    map<int, Account*>::iterator iter = accounts_.find(stoi(params.at(0)));
    if ( iter == accounts_.end() ){
        cout << CANT_FIND << params.at(0) << endl;
        return;
    }
    iter->second->print();
}

void University::add_staff_to_course(Params params){
    if ( courses_.find(params.at(0)) == courses_.end() ){
        cout << CANT_FIND << params.at(0) << endl;
        return;
    }
    if ( accounts_.find(stoi(params.at(1))) == accounts_.end() ){
        cout << CANT_FIND << params.at(1) << endl;
        return;
    }
    courses_.at(params.at(0))->add_staff(accounts_.at(stoi(params.at(1))));
}

void University::add_instance(Params params){
    // Search for the course if it exists
    if ( courses_.find(params.at(0)) == courses_.end() ){
        cout << CANT_FIND << params.at(0) << endl;
        return;
    }
    // New instance is added on course and date to instance
    if ( not courses_.at(params.at(0))->has_instance(params.at(1)) ){
        Date* n_date = new Date(utils::today);
        Instance* n_instance = new Instance(params.at(1), n_date);

        courses_.at(params.at(0))->new_instance(n_instance);
        return;
    }
    cout << INSTANCE_EXISTS << endl;
}

void University::sign_up_on_course(Params params){
    if ( is_params(params) ){
        Account* c_account = accounts_.at(stoi(params.at(2)));
        Instance* c_instance = courses_.at(params.at(0))
                                            ->get_instance(params.at(1));

        // Add student to course if conditions are met
        if ( c_instance->add_student(c_account, utils::today) ){
            c_account->add_enrolled_instance(c_instance);
        }
    }
}

void University::complete_course(Params params){
    if ( is_params(params) ){
        Account* c_account = accounts_.at(stoi(params.at(2)));
        Instance* c_instance = courses_.at(params.at(0))
                                        ->get_instance(params.at(1));
        Course* c_course = courses_.at(params.at(0));
        // Complete course if conditions are met
        c_account->complete_course(c_instance, c_course);
    }
}

void University::print_signups(Params params){
    if ( courses_.find(params.at(0)) == courses_.end() ){
        cout << CANT_FIND << params.at(0) << endl;
        return;
    }
    courses_.at(params.at(0))->print_signups();
}

void University::print_study_state(Params params){
    if ( accounts_.find(stoi(params.at(0))) == accounts_.end() ){
        cout << CANT_FIND << params.at(0) << endl;
        return;
    }
    Account* c_account = accounts_.at(stoi(params.at(0)));

    cout << "Current:" << endl;
    c_account->print_uncompleted(courses_);
    cout << "Completed:" << endl;
    c_account->print_completed();
}

void University::print_completed(Params params){
    if ( accounts_.find(stoi(params.at(0))) == accounts_.end() ){
        cout << CANT_FIND << params.at(0) << endl;
        return;
    }
    Account* c_account = accounts_.at(stoi(params.at(0)));
    c_account->print_completed();
}

void University::set_date(Params params){
    utils::today = Date(stoi(params.at(0)), stoi(params.at(1)), stoi(params.at(2)));
    cout << "Date has been set to ";
    utils::today.print();
    cout << endl;
}

void University::advance_date(Params params){
    utils::today.advance_by(stoi(params.at(0)));
    cout << "New date is ";
    utils::today.print();
    cout << endl;
}

void University::advance_by_period(Params){
    utils::today.advance_by_period_length();
    cout << "New date is ";
    utils::today.print();
    cout << endl;
}

bool University::is_params(vector<string> params){
    // Search for the course if it exists
    if ( courses_.find(params.at(0)) == courses_.end() ){
        cout << CANT_FIND << params.at(0) << endl;
        return false;
    }
    // Search for instance under the course
    if ( not courses_.at(params.at(0))->has_instance(params.at(1)) ){
        cout << CANT_FIND << params.at(1) << endl;
        return false;
    }
    // Search for the account number
    if ( accounts_.find(stoi(params.at(2))) == accounts_.end() ){
        cout << CANT_FIND << params.at(2) << endl;
        return false;
    }
    return true;
}
