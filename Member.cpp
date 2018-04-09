#include "Member.h"
#include <vector>
#include <iostream>
using namespace std;

 
    vector<Member> _listOfFollowing; 
    vector<Member> _listOfFollowers;
    int _id;
    int Member::_count=0; //initilization
  //  int  _count;
    Member::Member(){
      _id++;
      _count++;
    }
    
     Member::~Member(){
      _count--;
    }
    

    void Member::follow(Member &newMember){
        //check if i'm the Member;
        if(&newMember == this){
            return;
        }

        //check if the Member is inside the Vector already;
        for(Member const& i : _listOfFollowing){
         if(newMember._id == i._id){
            return;
         }
        }

        //add new follow member;
        _listOfFollowing.push_back(newMember);
        newMember._listOfFollowers.push_back(*this);
    }

    void  Member::unfollow(Member &delMember){    
        int count = 0;
      //check if thr current Member his the newMember;
        if(&delMember == this){
        return;
        }
         //check if the Member is inside the Vector and erase him;
        for(Member const& i : _listOfFollowing){
        if(delMember._id == i._id){
           _listOfFollowing.erase(_listOfFollowing.begin()+count);
            break;
        }
         count++;
     }
     count = 0;
     for(Member j : _listOfFollowers){
      if(j._id == _id){
           cout << _id << endl; 
            delMember._listOfFollowers.erase(_listOfFollowers.begin() + count);
                     return;
                }
                count++;
     }
     //"the Member not exist"
} 
  
  unsigned int  Member::numFollowers(){
       return _listOfFollowers.size();
   }
   unsigned int  Member::numFollowing(){
       return _listOfFollowing.size();
   }