#ifndef _FSM_BASE_H_
#define _FSM_BASE_H_

#include <iostream>
#include <memory>
#include <map>
#include <mutex>

/* 状态对象 */
template<typename StateMachineClass>
class FsmState {
public:
    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void Transfer() = 0;

    void setFsmMachine(StateMachineClass* state_machine)
    {
        state_machine_ = state_machine;
    }
protected:
    StateMachineClass* state_machine_ {nullptr};
};

template<typename StateMachineType, typename StateType>
class BaseStateMachine {
public:
~BaseStateMachine()
{
    if (cur_state_) {
        cur_state_->exit();
    }
}

template <typename StateClass>
void initialState()
{
changeState<StateClass>();
}

template<typename StateClass>
void registerState()
{
    auto state_type = StateClass::getStateEnum();
    if (state_map_.find(state_type) != state_map_.end()) {
        return ;
    }
    state_map_[state_type] = std::make_shared<StateClass>();
}

template<typename NewStateClass>
void changeState()
{
    auto state_type = NewStateClass::getStateEnum();
    auto it = state_map_.find(state_type);
    if (it == state_map_.end() || !it->second) {
        return ;
    }
    auto old_state = cur_state_;
    auto new_state = it->second;

    if (old_state) {
        old_state->exit();
    }
    cur_state_ = new_state;

    /* 
        状态对象轮转时总是会访问状态机的一些公共资源，而且公共资源需要共享, 
        所以需要把状态机管理信息放置到每个状态对象，每个状态对象才能保存上下文 
    */
    new_state->setFsmMachine(getThis());
    new_state->enter();
}

    StateMachineType* getThis() { return static_cast<StateMachineType*>(this); }

public:
    std::shared_ptr<FsmState<StateMachineType>> cur_state_ {nullptr};
    std::map<StateType, std::shared_ptr<FsmState<StateMachineType>>> state_map_;
};




#endif
