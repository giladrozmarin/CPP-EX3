#pragma once
#include <iostream>
#include <map>


class Member{


static int count_members; //the number of the member in the network
static int nextId; // the id of the next member that sign up

	int id;                     //the id of the member
        std::map <int, Member *> follows;  //the friends the member following
	std::map <int, Member *> followers;  //the members that follows the member
 	
	public:
  	Member();		 //construter
	~Member();		 //destruter
	int getId();		 //return the id of the member 
        int numFollowing();      //return the number of friends the member following
	int numFollowers();      //return the number of friends that follows the member
	void follow (Member &);	 //follow after the Member - input 
	void unfollow (Member &);  //unfollow after the Member - input
	
	static int count(){   //return the number of the members in the Network
		return count_members;
  	}
};
