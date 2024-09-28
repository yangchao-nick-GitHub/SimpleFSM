#include <iostream>
#include <mutex>
#include <memory>
#include <chrono>
#include <thread>
#include <map>

#include "fsm_student.hpp"

using std::cout;
using std::endl;

void StudentStateGetup::enter()
{
    cout << "enter get up state" << endl;
    Transfer();
}

void StudentStateGetup::exit()
{
    cout << "exit get up state" << endl;    
}

void StudentStateGetup::Transfer()
{
    if (state_machine_->condition_1_) {
        state_machine_->changeState<StudentStateGotoSchool>();
    }
}

void StudentStateGotoSchool::enter() 
{
    cout << "enter goto school state" << endl;
    Transfer();
}

void StudentStateGotoSchool::exit()
{
    cout << "exit goto school state" << endl;
}

void StudentStateGotoSchool::Transfer()
{
    if (state_machine_->condition_2_) {
        state_machine_->changeState<StudentStateDoHomework>();
    }
}

void StudentStateDoHomework::enter()
{
    cout << "enter do homework state" << endl;
    Transfer();
}

void StudentStateDoHomework::exit()
{
    cout << "exit do homework state" << endl;
}

void StudentStateDoHomework::Transfer()
{
    if (state_machine_->condition_3_) {
        state_machine_->changeState<StudentStateSleep>();
    }
}

void StudentStateSleep::enter()
{
    cout << "enter sleep state" << endl;
    Transfer();
}

void StudentStateSleep::exit()
{
    cout << "exit sleep state" << endl;
}

void StudentStateSleep::Transfer()
{
    if (state_machine_->condition_4_) {
        state_machine_->changeState<StudentStateGetup>();
    }
}


