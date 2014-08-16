//
//  SimpleObject.cpp
//  StateDesignPattern
//
//  Created by Mike Allison on 8/16/14.
//
//

#include "SimpleObject.h"

void Device::initialize(){
    mState = State1Ref( new State1(this) ); 
}

void State1::setState2(){
    mContext->mState = State2Ref( new State2( mContext ) );
}

void State2::setState1(){
    mContext->mState = State1Ref( new State1( mContext ) );
}