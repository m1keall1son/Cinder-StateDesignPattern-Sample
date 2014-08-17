//
//  SimpleObject.h
//  StateDesignPattern
//
//  Created by Mike Allison on 8/16/14.
//
// lifted from: http://www.codeproject.com/Articles/509234/The-State-Design-Pattern-vs-State-Machine

#pragma once

//abstract class base that only contains a name

class SimpleObjectBase {
    
public:
    
    SimpleObjectBase():mName(""){}
    SimpleObjectBase( const std::string& name ):mName(name){}
    virtual ~SimpleObjectBase(){}
    
    const std::string& getName(){ return mName; }
    void setName( const std::string& name ){ mName = name; }
    
private:
    std::string mName;
    
};

//abstract state base, contains only a global function but could have other virtual functions

class StateBase : public SimpleObjectBase {
    
public:
    
    StateBase(){}
    StateBase( const std::string& name ):SimpleObjectBase(name){}
    virtual ~StateBase(){}
    virtual void setState1() = 0;
    virtual void setState2() = 0;
    
    //Common function, could be virtual and implementation specific
    void printState() { std::cout << getName() <<std::endl; }
    
};

//Device is a genertic object that maintains state and theoretically needs different implementation based on that state
//Device is the context for the states

class Device : public SimpleObjectBase {
    
public:
    Device() { initialize(); }
    Device( const std::string& name ):SimpleObjectBase(name) { initialize(); }
    
    void somethingHappend(){
        mState->setState2();
    }
    void somethingElseHappend(){
        mState->setState1();
    }
    
    void printState(){
        mState->printState();
    }
    
private:
    
    void initialize();
    
    StateBase* mState;
    
    friend class State1;
    friend class State2;
};

//Concrete states that inherit the base class, these know how and when to swtich to one another. the Contex doest need to know more than how to call the vitual state change functions, the states do the rest.  They can look into the context for more information if need be via the context ptr.

class State1 : public StateBase {
    
public:
    explicit State1( Device * context ) : StateBase("State1"), mContext(context) {}
    
    void setState1(){
        //Do nothing I am in State 1
    }
    void setState2();
    
private:
    
    Device* mContext;
    
};

class State2 : public StateBase {
    
public:
    explicit State2( Device * context ) : StateBase("State2"), mContext(context) {}
    
    void setState1();
    void setState2(){
        //Do nothing I am in State 2
    }
    
private:
    Device* mContext;
    
};



