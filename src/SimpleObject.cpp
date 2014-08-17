//
//  SimpleObject.cpp
//  StateDesignPattern
//
//  Created by Mike Allison on 8/16/14.
//
//

#include "SimpleObject.h"

void Device::initialize(){
    mState =  new State1(this);
}

void State1::setState2(){
    delete mContext->mState;
    mContext->mState = new State2( mContext );
}

void State2::setState1(){
    delete mContext->mState;
    mContext->mState = new State1( mContext );
}