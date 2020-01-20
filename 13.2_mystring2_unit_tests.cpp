// Datei: mystring2_unit_tests.cpp

#include "catch.h"
#include <string>

#include "CharListenKnoten.h"
#include "MyString2.h"

void friend_append_internal(MyString2& s, char p_data)
{
	s.append_internal(p_data);
}

void friend_delete_internal(MyString2& s)
{
	s.delete_internal();
}

CharListenKnoten* friend_deep_copy_internal(MyString2& s)
{
	return s.deep_copy_internal();
}

TEST_CASE("Pruefung der Methoden CharListenKnoten::get_data() / CharListenKnoten::set_data()") {

	// Funktioniert nur, falls ein parameterloser Konstruktor existiert.
	// Ansonsten z.B. CharListenKnoten k{ 'x' , nullptr }; falls so definiert ...
	/* MyString2::*/ CharListenKnoten k;

	k.set_data('a');
	REQUIRE(k.get_data() == 'a');

	k.set_data('b');
	REQUIRE(k.get_data() == 'b');
}

TEST_CASE("Pruefung der Methoden CharListenKnoten::get_next() / ::set_next()") {

	CharListenKnoten k1, k2;

	REQUIRE(k1.get_next() == nullptr);
	REQUIRE(k2.get_next() == nullptr);

	k1.set_next(&k2);

	REQUIRE(k1.get_next() == &k2);
	REQUIRE(k2.get_next() == nullptr);
}

TEST_CASE("Pruefung des Konstruktors MyString2(std::string )") {

	MyString2 s = std::string{ "abc" };

	REQUIRE(s.get_anker() != nullptr);
	REQUIRE(s.get_anker()->get_data() == 'a');
	REQUIRE(s.get_anker()->get_next() != nullptr);
	REQUIRE(s.get_anker()->get_next()->get_data() == 'b');
	REQUIRE(s.get_anker()->get_next()->get_next() != nullptr);
	REQUIRE(s.get_anker()->get_next()->get_next()->get_data() == 'c');
	REQUIRE(s.get_anker()->get_next()->get_next()->get_next() == nullptr);
}

TEST_CASE("Pruefung der Methode void MyString2::append_internal(char p_data)") {

	SECTION("MyString2::append_internal() bei einem leeren MyString2") {

		MyString2 s;
		REQUIRE(s.get_anker() == nullptr);

		friend_append_internal(s, 'x');

		REQUIRE(s.get_anker() != nullptr);
		REQUIRE(s.get_anker()->get_data() == 'x');
		REQUIRE(s.get_anker()->get_next() == nullptr);
	}

	SECTION("MyString2::append_internal() bei einem nicht-leeren MyString2") {

		MyString2 s = std::string{ "a" };
		REQUIRE(s.get_anker() != nullptr);
		REQUIRE(s.get_anker()->get_data() == 'a');
		REQUIRE(s.get_anker()->get_next() == nullptr);

		friend_append_internal(s, 'y');

		REQUIRE(s.get_anker() != nullptr);
		REQUIRE(s.get_anker()->get_data() == 'a');
		REQUIRE(s.get_anker()->get_next() != nullptr);
		REQUIRE(s.get_anker()->get_next()->get_data() == 'y');
		REQUIRE(s.get_anker()->get_next()->get_next() == nullptr);

		friend_append_internal(s, 'z');

		REQUIRE(s.get_anker() != nullptr);
		REQUIRE(s.get_anker()->get_data() == 'a');
		REQUIRE(s.get_anker()->get_next() != nullptr);
		REQUIRE(s.get_anker()->get_next()->get_data() == 'y');
		REQUIRE(s.get_anker()->get_next()->get_next() != nullptr);
		REQUIRE(s.get_anker()->get_next()->get_next()->get_data() == 'z');
		REQUIRE(s.get_anker()->get_next()->get_next()->get_next() == nullptr);
	}
}

TEST_CASE("Pruefung der Methode void MyString2::deep_copy_internal()") {

	MyString2 s = std::string("abc");

	REQUIRE(s.get_anker() != nullptr);
	REQUIRE(s.get_anker()->get_data() == 'a');
	REQUIRE(s.get_anker()->get_next() != nullptr);
	REQUIRE(s.get_anker()->get_next()->get_data() == 'b');
	REQUIRE(s.get_anker()->get_next()->get_next() != nullptr);
	REQUIRE(s.get_anker()->get_next()->get_next()->get_data() == 'c');
	REQUIRE(s.get_anker()->get_next()->get_next()->get_next() == nullptr);

	SECTION("MyString2::deep_copy_internal()") {

		CharListenKnoten* ptr = friend_deep_copy_internal(s);

		REQUIRE(ptr != nullptr);
		REQUIRE(ptr != s.get_anker());
		REQUIRE(ptr->get_data() == 'a');
		REQUIRE(ptr->get_next() != nullptr);
		REQUIRE(ptr->get_next() != s.get_anker()->get_next());
		REQUIRE(ptr->get_next()->get_data() == 'b');
		REQUIRE(ptr->get_next()->get_next() != nullptr);
		REQUIRE(ptr->get_next()->get_next() != s.get_anker()->get_next()->get_next());
		REQUIRE(ptr->get_next()->get_next()->get_data() == 'c');
		REQUIRE(ptr->get_next()->get_next()->get_next() == nullptr);
	}
}

TEST_CASE("Pruefung des Copy-Konstruktors von MyString2") {

	MyString2 s = std::string{ "abc" };
	MyString2 s2 = s;

	REQUIRE(s2.get_anker() != nullptr);
	REQUIRE(s2.get_anker() != s.get_anker());
	REQUIRE(s2.get_anker()->get_data() == 'a');
	REQUIRE(s2.get_anker()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next() != s.get_anker()->get_next());
	REQUIRE(s2.get_anker()->get_next()->get_data() == 'b');
	REQUIRE(s2.get_anker()->get_next()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next()->get_next() != s.get_anker()->get_next()->get_next());
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_data() == 'c');
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_next() == nullptr);
}

TEST_CASE("Pruefung des Assignment Operators von MyString2") {

	MyString2 s = std::string{ "abc" };
	MyString2 s2 = std::string{ "def" };

	CharListenKnoten* p1 = s2.get_anker();
	REQUIRE(p1 != nullptr);
	CharListenKnoten* p2 = s2.get_anker()->get_next();
	REQUIRE(p2 != nullptr);
	CharListenKnoten* p3 = s2.get_anker()->get_next()->get_next();
	REQUIRE(p3 != nullptr);

	s2 = s;

	REQUIRE(s2.get_anker() != nullptr);
	REQUIRE(s2.get_anker() != s.get_anker());
	REQUIRE(s2.get_anker() != p1);
	REQUIRE(s2.get_anker()->get_data() == 'a');
	REQUIRE(s2.get_anker()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next() != s.get_anker()->get_next());
	REQUIRE(s2.get_anker()->get_next() != p2);
	REQUIRE(s2.get_anker()->get_next()->get_data() == 'b');
	REQUIRE(s2.get_anker()->get_next()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next()->get_next() != s.get_anker()->get_next()->get_next());
	REQUIRE(s2.get_anker()->get_next()->get_next() != p3);
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_data() == 'c');
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_next() == nullptr);
}

TEST_CASE("Pruefung der Methode unsigned int MyString2::length()") {

	SECTION("MyString2::length() bei einem leeren MyString2") {
		MyString2 s;
		REQUIRE(s.length() == 0);
	}

	SECTION("MyString2::length() bei einem nicht-leeren MyString2") {
		MyString2 s = std::string{ "abc" };
		REQUIRE(s.length() == 3);
	}
}

TEST_CASE("Pruefung der Methode char MyString2::at(unsigned int pos)") {

	SECTION("MyString2::at() bei einem leeren MyString2") {
		MyString2 s;
		REQUIRE(s.at(0) == '\0');
		REQUIRE(s.at(99) == '\0');
	}

	SECTION("MyString2::at() bei einem nicht-leeren MyString2") {
		MyString2 s = std::string{ "abc" };
		REQUIRE(s.at(0) == 'a');
		REQUIRE(s.at(1) == 'b');
		REQUIRE(s.at(2) == 'c');
		REQUIRE(s.at(3) == '\0');
		REQUIRE(s.at(4) == '\0');
		REQUIRE(s.at(5) == '\0');
		REQUIRE(s.at(99) == '\0');
	}
}

TEST_CASE("Pruefung der Methode MyString2 MyString2::operator+(char c)") {

	MyString2 s;

	MyString2 s2 = s + 'x';
	REQUIRE(s2.get_anker() != nullptr);
	REQUIRE(s2.get_anker()->get_data() == 'x');
	REQUIRE(s2.get_anker()->get_next() == nullptr);
	REQUIRE(s2.length() == 1);
	REQUIRE(s2.get_anker() != s.get_anker());

	MyString2 s3 = s2 + 'y';
	REQUIRE(s3.get_anker() != nullptr);
	REQUIRE(s3.get_anker()->get_data() == 'x');
	REQUIRE(s3.get_anker()->get_next() != nullptr);
	REQUIRE(s3.get_anker()->get_next()->get_data() == 'y');
	REQUIRE(s3.get_anker()->get_next()->get_next() == nullptr);
	REQUIRE(s3.length() == 2);
	REQUIRE(s3.get_anker() != s2.get_anker());
	REQUIRE(s3.get_anker()->get_next() != s2.get_anker()->get_next());

}

TEST_CASE("Pruefung der Methode std::string MyString2::to_string()") {

	SECTION("MyString2::to_string() bei einem leeren MyString2") {
		MyString2 s;
		REQUIRE(s.to_string() == std::string(""));
	}

	SECTION("MyString2::to_string() bei einem nicht-leeren MyString2") {
		MyString2 s = std::string("abc");
		REQUIRE(s.to_string() == std::string("abc"));
	}
}
