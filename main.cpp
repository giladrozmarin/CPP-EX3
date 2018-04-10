#include "Member.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("testing the getId function") {
	Member a,b,c,d,e,f;
    CHECK(a.getId() == 0);
    CHECK(b.getId() == 1);
    CHECK(c.getId() == 2);
	CHECK(d.getId() == 3);
    CHECK(e.getId() == 4);
    CHECK(f.getId() == 5);
    
}

TEST_CASE("testing the numFollowing function") {
   Member a,b,c;
	CHECK(a.numFollowing() == 0);
    a.follow(a);
	CHECK(a.numFollowing() == 0);
    a.follow(b);
	b.follow(b);
	CHECK(a.numFollowing() == 1);
	CHECK(b.numFollowing() == 0);
    a.follow(b);
	CHECK(a.numFollowing() == 1);
    a.follow(c);
	CHECK(a.numFollowing() == 2);
}

TEST_CASE("testing the numFollowers function") {
   Member first,second,third;
	CHECK(second.numFollowers() == 0);
   second.follow(second);
	CHECK(second.numFollowers() == 0);
   first.follow(second);
	CHECK(second.numFollowers() == 1);
   first.follow(second);
	CHECK(second.numFollowers() == 1);
   third.follow(second);
	CHECK(second.numFollowers() == 2);
}

TEST_CASE("testing the count function") {
    CHECK(Member::count() == 0);
    	Member first;
    CHECK(Member::count() == 1);
  	Member second;
    CHECK(Member::count() == 2);
	Member third;
    CHECK(Member::count() == 3);
}

TEST_CASE("testing the follow function") {
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

TEST_CASE("testing the unfollow function") {
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
