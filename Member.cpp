#include "Member.h"
#include <map>
#include <iostream>
using namespace std;

 
    int Member:: otherId = 0; //Initilization
    int Member::_count = 0; //Initilizationd

    Member::Member(){   //constructer 
      this->_id = otherId;
      _count++;
      otherId++;
    }
    
 
    int Member::getId(){ // implimentation return id;
        return this->_id;
    }
    
      void Member::follow(Member &newMember){
        //check if i'm the Member;
        if(&newMember == this){
            return;
        }
        //check if the Member is inside the Vector already;
        if(this->_listOfFollowing.count(newMember.getId()) == 1){
            return;
        }
        //add new follow member;
        this->_listOfFollowing.insert(pair<int , Member *>(newMember.getId() ,&newMember));
        newMember._listOfFollowers.insert(pair<int ,Member *>(this->_id , this));
    }


    void  Member::unfollow(Member &delMember){    

      //check if thr current Member his the newMember;
        if(&delMember == this){
        return;
        }
         //check if the Member is inside the  and erase him;
       if(this->_listOfFollowing.count(delMember.getId()) != 1){
           return;
       }
       this->_listOfFollowing.erase(delMember.getId());
       delMember._listOfFollowers.erase(this->_id);
        
    
     
     //"the Member not exist"
    }
  
  unsigned int  Member::numFollowers(){
       return _listOfFollowers.size();
   }
   unsigned int  Member::numFollowing(){
       return _listOfFollowing.size();
   }  
Member::~Member(){	 //implimentation
		                                     //update the num of members
		map<int,Member *>::iterator j=_listOfFollowers.begin();
		while(j!=_listOfFollowers.end()){                           //update my followers list of following
			if((j->second)->_listOfFollowing.count(this->_id)!=0)
		              (j->second)->_listOfFollowing.erase((j->second)->_listOfFollowing.find(this->_id));
			j++;
		}

		map<int,Member *>::iterator i=_listOfFollowing.begin();
		while(i!=_listOfFollowing.end()){                              //update my following num of followers
			if((i->second)->_listOfFollowers.count(this->_id)!=0)
		              (i->second)->_listOfFollowers.erase((i->second)->_listOfFollowers.find(this->_id));
			i++;
		}	
        _count--;
}