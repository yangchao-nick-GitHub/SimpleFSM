#include <iostream>
#include "fsm_student.hpp"

int main()
{
    auto state_machine_ptr = StudentFsm::create();
    state_machine_ptr->registerState<StudentStateGetup>();
    state_machine_ptr->registerState<StudentStateGotoSchool>();
    state_machine_ptr->registerState<StudentStateDoHomework>();
    state_machine_ptr->registerState<StudentStateSleep>();
    state_machine_ptr->initialState<StudentStateGetup>();

    return 0;
}
