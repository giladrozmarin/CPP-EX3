/**
 * Member.h
 * 
 * Created on: 02/04/18
 *    Author : nati & gilad 
 * 
 * */

#pragma once
#include <iostream>
#include <map>



class Member{
    private: 
      std::map <int,Member *> _listOfFollowing; 
      std::map <int,Member *> _listOfFollowers; // 
      int _id; // the id of the member
     static int  _count; // count the active member on network
     static int otherId;

    public:
    Member();   //constructer
    ~Member(); //distruter
    void follow(Member&); //follow the Member
    void unfollow(Member&);//unfollow the Member
    int getId();
    unsigned  int numFollowing(); // return the number of frineds Member follwing;
    unsigned int numFollowers(); //// return the number of frineds that follwes the Member;
    static int count(){   //return the number of the members in the Network
		return _count;
    }
};