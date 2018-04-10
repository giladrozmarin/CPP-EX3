#include "Member.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Id function check") {  // check if object get the rught id  
	Member a,b,c,d,e,f;       
   
    CHECK(b.getId() == 1);
	CHECK(d.getId() == 3);
    CHECK(e.getId() == 4);
    CHECK(f.getId() == 5);
	CHECK(c.getId() == 2);
	CHECK(a.getId() == 0);    //check overload
    
}

TEST_CASE("num Of Following check") {  // 
   Member a,b,c;
	CHECK(a.numFollowing() == 0);
    a.follow(a); // check if member can follow after it self.
	CHECK(a.numFollowing() == 0);
    a.follow(b);
	a.follow(b); // chack if you can follow Member twice.
	b.follow(b);
	CHECK(a.numFollowing() == 1);
	CHECK(b.numFollowing() == 0);
	b.follow(a);
    b.follow(c);
	CHECK(b.numFollowing() == 2);
}

TEST_CASE("num  of Followers check") {
    Member a,b,c;
	CHECK(a.numFollowers() == 0);
    a.follow(a); // check if member can follow after it self.
	CHECK(a.numFollowers() == 0);
    a.follow(b);
	a.follow(b); // chack if you can follow Member twice.
	b.follow(b);
	CHECK(b.numFollowers() == 1);
	CHECK(a.numFollowers() == 0);
	c.follow(b);
   
	CHECK(b.numFollowers() == 2);
}

TEST_CASE("count check") {
    CHECK(Member::count() == 0);
    	Member first;
    CHECK(Member::count() == 1);
  	Member second;
    CHECK(Member::count() == 2);
	Member third;
    CHECK(Member::count() == 3);
}

TEST_CASE("follow function") {
   Member first,second,third;
	CHECK(second.numFollowers() == 0);
	CHECK(second.numFollowing() == 0);
   second.follow(second);
	CHECK(second.numFollowers() == 0);
	CHECK(second.numFollowing() == 0);
   first.follow(second);
	CHECK(second.numFollowers() ==1);
	CHECK(first.numFollowing() == 1);
   third.follow(second);
	CHECK(second.numFollowers() ==2);
	CHECK(third.numFollowing() == 1);
}

TEST_CASE("unfollow check") {
   Member first,second,third;
	CHECK(second.numFollowers() == 0);
	CHECK(second.numFollowing() == 0);
   second.unfollow(second);
	CHECK(second.numFollowers() == 0);
	CHECK(second.numFollowing() == 0);
   first.follow(second);
   third.follow(second);
   first.unfollow(second);
	CHECK(second.numFollowers() ==1);
	CHECK(first.numFollowing() == 0);
   third.unfollow(second);
	CHECK(second.numFollowers() ==0);
	CHECK(third.numFollowing() == 0);
}
