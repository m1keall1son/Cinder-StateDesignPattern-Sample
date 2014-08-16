//
//  SimpleObject.h
//  StateDesignPattern
//
//  Created by Mike Allison on 8/16/14.
//
//

#pragma once

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


class Device;

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

using StateBaseRef = std::shared_ptr<StateBase>;

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
    
    StateBaseRef mState;
    
    friend class State1;
    friend class State2;
};

using State1Ref = std::shared_ptr<class State1>;
using State2Ref = std::shared_ptr<class State2>;

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



