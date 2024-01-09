#define CATCH_CONFIG_MAIN
#include <sstream>
#include "catch.h"
#include "enemy.h"

TEST_CASE("Default constructor working correctly?", "[constructors]"){
	Enemy e;
	REQUIRE( e.getName() == "No name" );
	REQUIRE( e.getHp() == 100 );
	REQUIRE( e.getSpeed() == 0.0f );
}

TEST_CASE("Parameterized constructor working correctly?", "[constructor]"){
	Enemy e("Bad Guy", 250, 0.45f);
	REQUIRE( e.getName() == "Bad Guy" );
	REQUIRE( e.getHp() == 250 );
	REQUIRE( e.getSpeed() == 0.45f );
}

TEST_CASE("Setters working properly?", "[setters]"){
	Enemy e;
	REQUIRE_THROWS( e.setName("") );
	REQUIRE_THROWS( e.setName("JoeWalterBuckinghamshiresonington") );
	REQUIRE_THROWS( e.setHp(-1.0) );
	REQUIRE_THROWS( e.setSpeed(-0.1) );
	REQUIRE_THROWS( e.setSpeed(1.1) );
	REQUIRE_NOTHROW( e.setName("Bad Guy") );
	REQUIRE_NOTHROW( e.setHp(0) );
	REQUIRE_NOTHROW( e.setHp(255) );
	REQUIRE_NOTHROW( e.setSpeed(0.0f) );
	REQUIRE_NOTHROW( e.setSpeed(1.0f) );
}

TEST_CASE("Overloaded stream working?", "[stream]"){
	Enemy e;
	std::stringstream ss;
	ss << e;
	std::string str = ss.str();
	REQUIRE( str == "No name, 100, 0" );
	Enemy f("Bad Guy", 250, 0.45);
	ss.str("");
	ss.clear();
	ss << f;
	str = ss.str();
	REQUIRE( str == "Bad Guy, 250, 0.45" );
}
