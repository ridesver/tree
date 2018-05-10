#include <catch.hpp>
#include <sstream>
#include "tree.hpp"

using namespace std;

TEST_CASE("print")
{
	tree_t<int> tree;
	tree.insert(10);
	tree.insert(15);
	tree.insert(8);
	tree.insert(12);
	tree.insert(17);
	tree.insert(1);
	tree.insert(2);
	string result{
		"------------17\n"
		"--------15\n"
		"------------12\n"
		"----10\n"
		"--------8\n"
		"----------------2\n"
		"------------1\n" };
	ostringstream ostream;
	tree.print(ostream);
	REQUIRE(ostream.str() == result);
}

TEST_CASE("insert")
{
	tree_t<double> tree;
	tree.insert(4.3);
	tree.insert(11.9);
	tree.insert(3.1);
	string result{
		"--------11.9\n"
		"----4.3\n"
		"--------3.1\n" };
	ostringstream ostream;
	tree.print(ostream);
	REQUIRE(ostream.str() == result);
}

TEST_CASE("find")
{
	tree_t<int> tree;
	tree.insert(3);
	tree.insert(1);
	tree.insert(2);
	REQUIRE(tree.find(1) == true);
	REQUIRE(tree.find(2) == true);
	REQUIRE(tree.find(7) == false);
}

TEST_CASE("remove")
{
	tree_t<int> tree;
	tree.insert(5);
	tree.insert(4);
	tree.insert(8);
	tree.insert(7);
	tree.insert(9);
	REQUIRE(tree.remove(11) == false);
	REQUIRE(tree.remove(8) == true);

	string result{
		"--------9\n"
		"------------7\n"
		"----5\n"
		"--------4\n" };
	ostringstream ostream;
	tree.print(ostream);
	REQUIRE(ostream.str() == result);
}

TEST_CASE("operator ==")
{
	tree_t<int> tree1, tree2;
	tree1.insert(3);
	tree1.insert(2);
	tree1.insert(1);
	tree1.insert(0);

	tree2.insert(3);
	tree2.insert(2);
	tree2.insert(1);
	tree2.insert(0);

	REQUIRE((tree1 == tree2) == true);
	tree1.insert(8);
	REQUIRE((tree1 == tree2) == false);
}

TEST_CASE("initializer_list")
{
	tree_t<float> tree{ 1.2,2.0,0.9,5.4 };
	string result{
		"------------5.4\n"
		"--------2\n"
		"----1.2\n"
		"--------0.9\n" };
	ostringstream ostream;
	tree.print(ostream);
	REQUIRE(ostream.str() == result);
}
