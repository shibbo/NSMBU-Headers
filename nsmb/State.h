#pragma once

#include "types.h"

#define DECLARE_STATE(CLASS, NAME)                      \
    static State<CLASS> StateID_##NAME;                 \
    void beginState_##NAME();                           \
    void executeState_##NAME();                         \
    void endState_##NAME();

#define DECLARE_STATE_VIRTUAL(CLASS, NAME)              \
    static StateVirtual<CLASS> StateID_##NAME;          \
    virtual void beginState_##NAME();                   \
    virtual void executeState_##NAME();                 \
    virtual void endState_##NAME();

#define DECLARE_STATE_OVERRIDE(CLASS, NAME)             \
    static StateVirtual<CLASS> StateID_##NAME;          \
    void beginState_##NAME() override;                  \
    void executeState_##NAME() override;                \
    void endState_##NAME() override;

#define CREATE_STATE(CLASS, NAME)                       \
    State<CLASS> CLASS::StateID_##NAME                  \
        (&CLASS::beginState_##NAME,                     \
         &CLASS::executeState_##NAME,                   \
         &CLASS::endState_##NAME);

#define CREATE_STATE_VIRTUAL(CLASS, NAME)               \
    StateVirtual<CLASS> CLASS::StateID_##NAME           \
        (&CLASS::beginState_##NAME,                     \
         &CLASS::executeState_##NAME,                   \
         &CLASS::endState_##NAME,                       \
         &StateBase::sNullState);

#define CREATE_STATE_OVERRIDE(CLASS, BASECLASS, NAME)   \
    StateVirtual<CLASS> CLASS::StateID_##NAME           \
        (&CLASS::beginState_##NAME,                     \
         &CLASS::executeState_##NAME,                   \
         &CLASS::endState_##NAME,                       \
         &BASECLASS::StateID_##NAME);

// I don't feel like finding a lot of these
// so we can just define some here because why not
class StateBase 
{
public:
    inline StateBase() 
    {
        this->mID = sCurrentId++;
    }

    virtual ~StateBase()
    {

    }

    virtual s32 getRootId();

    inline bool isEqual(StateBase* other) 
    {
        return this->getRootId() == other->getRootId();
    }

    static StateBase sNullState;

    s32 mID;

private:
    static s32 sCurrentId;
};

template <class TOwner>
class State : public StateBase 
{
public:
    typedef void (TOwner::*funcPtr)();

    State(funcPtr begin, funcPtr execute, funcPtr end)
        : mBegin(begin), mExecute(execute), mEnd(end) { }

protected:
    funcPtr mBegin;      // 8
    funcPtr mExecute;    // 10
    funcPtr mEnd;        // 18
};

template <class TOwner>
class StateVirtual : public State<TOwner>
{
public:
    typedef void (TOwner::*funcPtr)();

    StateVirtual(funcPtr begin, funcPtr execute, funcPtr end, StateBase* baseState)
        : State<TOwner>(begin, execute, end), mBaseState(baseState) { }

    virtual ~StateVirtual()
    {

    }

    s32 getRootId() override 
    {
        if (mBaseState->mID != -1)
            return mBaseState->getRootId();

        return mID;
    }

private:
    StateBase* mBaseState;
};

class StateMethodExecuterBase 
{
public:
    virtual ~StateMethodExecuterBase();
    virtual StateBase* getCurrentState() = 0;
    virtual void execute() = 0;
};

template <class TOwner>
class StateMethodExecuter : public StateMethodExecuterBase 
{
public:
    StateBase* getCurrentState() override;
    void execute() override;

    TOwner* mOwner;                  // 4
    State<TOwner>* mCurrentState;    // 8
};

class StateExecuterBase 
{
public:
    virtual StateMethodExecuterBase* begin(StateBase* nextState) = 0;
    virtual void end(StateMethodExecuterBase* methodExecuter) = 0;
    virtual StateMethodExecuterBase* setState(StateBase* state) = 0;
    virtual void resetState(StateMethodExecuterBase* methodExecuter) = 0;
    virtual StateMethodExecuterBase* callBegin(StateMethodExecuterBase* methodExecuter) = 0;
};

template <class TOwner>
class StateExecuter : public StateExecuterBase 
{
public:
    StateMethodExecuterBase* begin(StateBase* nextState) override;
    void end(StateMethodExecuterBase* methodExecuter) override;
    StateMethodExecuterBase* setState(StateBase* state) override;
    void resetState(StateMethodExecuterBase* methodExecuter) override;
    StateMethodExecuterBase* callBegin(StateMethodExecuterBase* methodExecuter) override;

    StateMethodExecuter<TOwner> mMethodExecuter;     // 4
};

class StateMgr 
{
public:
    StateMgr(StateExecuterBase* executer, StateBase* firstState = &StateBase::sNullState);

    StateBase* getCurrentState();
    void execute();
    void changeState(StateBase* pNextState);

    StateExecuterBase* mExecutor;                    // 0
    StateBase* mNextState;                           // 4
    StateMethodExecuterBase* mCurrentMethodExecuter; // 8
    StateBase* mLastState;                           // C
};

template <class TOwner>
class StateWrapper 
{
public:
    virtual ~StateWrapper()
    {

    }

    StateExecuter<TOwner> mExecutor; // 0
    StateMgr mManager;               // 10

    inline void changeState(StateBase* nextState) 
    { 
        mManager.changeState(nextState); 
    }

    inline void execute() 
    { 
        mManager.execute(); 
    }

    inline StateBase* currentState() 
    { 
        return mExecutor.methodExecuter.currentState; 
    }
    
    inline StateBase* lastState()    
    { 
        return mManager.lastState;
    }
};

template <class TOwner>
class StateWrapperMulti 
{
public:
    virtual ~StateWrapperMulti()
    {

    }

    StateExecuter<TOwner> mExecutor;    // 0
    StateMgr mManager;                  // 10
    StateBase* _20;                     // 20

    inline void changeState(StateBase* nextState) 
    { 
        mManager.changeState(nextState); 
    }

    inline void execute() 
    { 
        mManager.execute(); 
    }

    inline StateBase* currentState() 
    { 
        return mExecutor.methodExecuter.currentState; 
    }
    
    inline StateBase* lastState()    
    { 
        return mManager.lastState;
    }
};