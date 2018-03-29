#include <vector>
#include <iostream>
#include "Member.h"
using namespace std;
class Member{
private:
//int _numFollowers , _numFollowing;
vector <Member> _listOfFollowing; 
vector <Member> _listOfFollowers;
public: string name;


public:
Member() {
    _listOfFollowing;
    _listOfFollowers;
    this->name=name;
}

void follow(Member &newMember){
    //check if i'm the Member;
    if(&newMember == this){
        return;;
    }
    //chack if the Member is inside the Vector;
    int size = _listOfFollowing.size();
    for(auto const& i : _listOfFollowing){
        if(&newMember == &i){
            return;
        }
     }
     //add new follow member;
    _listOfFollowing.push_back(newMember);
}
void unfollow(Member &newMember){
    //check if i'm the Member;
    if(&newMember == this){
        return;;
    }
    //chack if the Member is inside the Vector;
    int size = _listOfFollowing.size();
    for(auto const& i : _listOfFollowing){
        if(&newMember == &i){
            return;
        }
     }
      for(auto const& i : _listOfFollowing){
        if(&newMember == &i){
             _listOfFollowing.erase(_listOfFollowing.begin()+1);
        }
     }
     for(auto const& i : _listOfFollowing){
           cout<<" "<< i.name;
        }
     //add new follow member;
   
}




    
};
int main(){
Member a,b,c,d,e;
a.name ="bar refali";
b.name = "nati";
c.name = "ben";
d.name = "gilad";
e.name = "moshe";
a.follow(e);
a.follow(b);
a.follow(c);
d.follow(a);
d.unfollow(a);
return 0;
}



