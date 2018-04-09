/**
 * Member.h
 * 
 * Created on: 02/04/18
 *    Author : nati & gilad 
 * 
 * */
#include <iostream>
 #include <vector>
 
 
 
#pragma once
class Member{
    private: 
      std::vector <Member> _listOfFollowing; 
      std::vector <Member> _listOfFollowers;
      int _id;
     static int  _count;

public:
Member();
~Member();
void follow(Member&);
void unfollow(Member&);
unsigned  int numFollowing();
unsigned int numFollowers();
static int count(){   //return the number of the members in the Network
		return _count;
}
};