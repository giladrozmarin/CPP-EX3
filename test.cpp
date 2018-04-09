#include "Member.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("testing the getId function") {
	Member first;
    CHECK(first.getId() == 0);
  	Member second;
    CHECK(second.getId() == 1);
	Member third;
    CHECK(third.getId() == 2);
}

TEST_CASE("testing the numFollowing function") {
   Member first,second,third;
	CHECK(first.numFollowing() == 0);
   first.follow(first);
	CHECK(first.numFollowing() == 0);
   first.follow(second);
	CHECK(first.numFollowing() == 1);
   first.follow(second);
	CHECK(first.numFollowing() == 1);
   first.follow(third);
	CHECK(first.numFollowing() == 2);
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
