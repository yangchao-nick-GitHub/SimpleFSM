#ifndef _FSM_STUDENT_H_
#define _FSM_STUDENT_H_

#include "fsm_base.hpp"

enum class StudentState
{
    GETUP    = 0,
    GOTO_SCHOOL = 1,
    DO_HOMEWORK = 2,
    SLEEP    = 3
};

class StudentFsm : public BaseStateMachine<StudentFsm, StudentState> {
public:
    static std::shared_ptr<StudentFsm> create() {
        return std::make_shared<StudentFsm>();
    }

    bool condition_1_ {true};
    bool condition_2_ {true};
    bool condition_3_ {true};
    bool condition_4_ {false};
};

class StudentStateGetup : public FsmState<StudentFsm> {
public:
    virtual void enter();
    virtual void exit();
    virtual void Transfer();
    static StudentState getStateEnum() { return StudentState::GETUP; }
};

class StudentStateGotoSchool : public FsmState<StudentFsm> {
public:
    virtual void enter();
    virtual void exit();
    virtual void Transfer();
    static StudentState getStateEnum() { return StudentState::GOTO_SCHOOL; }
};

class StudentStateDoHomework : public FsmState<StudentFsm> {
public:
    virtual void enter() override;
    virtual void exit() override;
    virtual void Transfer() override;
    static StudentState getStateEnum() { return StudentState::DO_HOMEWORK; }
};

class StudentStateSleep : public FsmState<StudentFsm> {
public:
    virtual void enter() override;
    virtual void exit() override;
    virtual void Transfer() override;
    static StudentState getStateEnum() { return StudentState::SLEEP; }
};

#endif
