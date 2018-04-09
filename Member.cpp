#include <iostream>
#include <map>
#include "Member.h"
using namespace std;


 int Member::count_members=0; //initilization
 int Member::nextId=0; // initilization

	Member::Member(){		  //implimentation construter
		count_members++;
		(*this).id=nextId;
		nextId++;
	}

	int Member::getId(){       //implimentation return id
		return this->id;
  	}


	int Member::numFollowing(){       //implimentation return num_of_Following
		return this->follows.size();
  	}

	int Member::numFollowers(){       //implimentation return num_of_Followers
		return this->followers.size();
  	}

	void Member::follow (Member &m){       //implimentation update following
		if(this->follows.count(m.getId())==0 && m.getId()!=this->id){
 			this->follows.insert(pair<int,Member *>(m.getId(),&m));
			m.followers.insert(pair<int,Member *>(this->id,this));
		}
	}

	void Member::unfollow (Member &m){       //implimentation update followers
		if(this->follows.count(m.getId())!=0){
		        this->follows.erase(m.getId());
			m.followers.erase(this->id);
		}
	}

	Member::~Member(){	 //implimentation
		count_members--;                                     //update the num of members
		map<int,Member *>::iterator j=followers.begin();
		while(j!=followers.end()){                           //update my followers list of following
			if((j->second)->follows.count(this->id)!=0)
		              (j->second)->follows.erase((j->second)->follows.find(this->id));
			j++;
		}

		map<int,Member *>::iterator i=follows.begin();
		while(i!=follows.end()){                              //update my following num of followers
			if((i->second)->followers.count(this->id)!=0)
		              (i->second)->followers.erase((i->second)->followers.find(this->id));
			i++;
		}	
	}
