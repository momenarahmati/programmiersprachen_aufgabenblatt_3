#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "list.hpp"


// Hilfsfunktionen, um indirekt auf die Member der Klasse List zuzugreifen (nur für die Tests!)
template <typename T>
size_t get_size(List<T> const& list_to_test) {return list_to_test.size_;}

template <typename T>
ListNode<T>* get_first_pointer(List<T> const& list_to_test) {return list_to_test.first_;}

template <typename T>
ListNode<T>* get_last_pointer(List<T> const& list_to_test) {return list_to_test.last_;}


//test case definitions for default constructor of list as well as empty and size for empty list
#include "sub_tests/default_constructed_list.test"

//test case definitions for push methods of list
#include "sub_tests/push_front.test"
#include "sub_tests/push_back.test"

//test case definitions for pop methods of list
#include "sub_tests/pop_front.test"
#include "sub_tests/pop_back.test"

//test case definitions for 

//test cases for element access of list
#include "sub_tests/front.test"
#include "sub_tests/back.test"

//test cases for retrieving iterators
#include "sub_tests/begin.test"
#include "sub_tests/end.test"

//iterator tests
#include "sub_tests/iterators/operator_star.test"
#include "sub_tests/iterators/operator_arrow.test"
#include "sub_tests/iterators/operator_equals.test"
#include "sub_tests/iterators/operator_does_not_equal.test"
#include "sub_tests/iterators/operator_iterate_forward.test"

// selbst definierten Testen
TEST_CASE("test_clear", "[test_clear]") 
{
    List<int> list1;
    list1.push_front(1);
    list1.push_front(2);
    list1.push_front(3);
    list1.clear();
    REQUIRE(list1.empty()==true);
}
/*
TEST_CASE("test_copy_cons", "[copy_cons]")
{
    List<int> list1;
    list1.push_front(1);
    list1.push_front(2);
    list1.push_front(3);
    List<int> list2{list1};
    REQUIRE(list1==list2);
} */

TEST_CASE("test_ZuweisungOP", "[ZuweisungOp]")
{
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    List<int> list2;
    list2 = list1;
    REQUIRE(list2.front()==1);
    REQUIRE(list2.back()==3);
}
TEST_CASE("test_reverse", "[reverse]")
{
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.reverse();
    REQUIRE(list1.front()==3);
    REQUIRE(list1.back()==1);
    /*
    List<int> list2 = reverse(list1);
    REQUIRE(list2.back()== 3);
    REQUIRE(list2.front()== 1);
    */
    }

TEST_CASE("vergleich zwei list", "[List_Vergleich]")
{
    List<int> list1;
    List<int> list2;
    REQUIRE(list1==list2);

    list1.push_back(1);
    list2.push_back(1);
    REQUIRE(list1 == list2);

    list1.push_back(4);
    list2.push_back(1);
    REQUIRE(list1 != list2);
}
/*
TEST_CASE(" move constructor ", "[ constructor ]")
{
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    //List<int> list2 = std::move(list);
    REQUIRE(0 == list.size());
    REQUIRE(list.empty());
    //REQUIRE(4 == list2.size());
}
TEST_CASE(" test_initializer_list ", "[ initializer_list]")
{
    List<int> int_list{ 9,5,38,100 };
    List<int> int_list1{ 1,2 };
    List<int> int_list2{ 5,6 };
    REQUIRE(int_list.front() == 9);
    List<int> a = List<int>{ 1,2 } + List<int>{ 5,6 };
    List<int>{1, 2, 5, 6};
}

*/
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}




