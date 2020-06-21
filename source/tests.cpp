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

TEST_CASE("test_copy_cons", "[copy_cons]")
{
    List<int> list1{ 1,2,3,4 };
    List<int> list2{ 5,6,7,8 };
    list1 = list2;
    REQUIRE(list1.front()==5);
    REQUIRE(list1.back()==8);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}




