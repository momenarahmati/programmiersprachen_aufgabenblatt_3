#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cassert>
#include <cstddef>  //ptrdiff_t
#include <iterator> //std::bidirectional_iterator_tag
#include <iostream>

#include <initializer_list>

template <typename T>
class List;

template <typename T>
struct ListNode {
  T         value = T{};
  ListNode* prev = nullptr;
  ListNode* next = nullptr;
};


//TODO: Implementierung der Methoden des Iterators 
//      (nach Vorlesung STL-1 am 09. Juni) (Aufgabe 3.12)
template <typename T>
struct ListIterator {
  using Self              = ListIterator<T>;
  using value_type        = T;
  using pointer           = T*;
  using reference         = T&;
  using difference_type   = ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;


  /* DESCRIPTION  operator*() member access through pointer to member*/
  T&  operator*()  const {
    if(nullptr == node) {
      throw "Iterator does not point to valid node";
    }
    return (*node).value;
    //TODO: remaining implementation of derefenciation of 
    //      iterator using operator* (Aufgabe 3.12 - Teil 1)

  } //call *it

  /* DESCRIPTION  operator->() c2->radius() accsess through pointer to member  */
  T* operator->() const {
    if(nullptr == node) {
      throw "Iterator does not point to valid node";
    }
    return &(node->value);
    //TODO: remaining implementation of derefenciation of 
    //      iterator using operator-> (Aufgabe 3.12 - Teil 2)
  }  //call it->method() or it->member


  /* PREINCREMENT, call: ++it, advances one element forward /gibt den ein Element weiter  */
  ListIterator<T>& operator++() {
    if(nullptr == node) {
      throw "Iterator does not point to valid node";
    }
    node = (*node).next;
    return *this;
    //TODO: Implement Postincrement-Operation for Iterator
    //      (Aufgabe 3.12 - Teil 3)
    
  }

  /* POSTINCREMENT (signature distinguishes the iterators), 
                    call:  it++, advances one element forward// gibt ein Element Weiter*/
  ListIterator<T> operator++(int) {
    if(nullptr == node) {
      throw "Iterator does not point to valid node";
    }
    ListIterator<T> temp = *this;
    ++*this;
    return temp;
    //TODO: Implement Postincrement-Operation for Iterator
    //      (Aufgabe 3.12 - Teil 4)

  }


  /* guckt ob zwei Listen Iterator gleich sind */
  bool operator==(ListIterator<T> const& x) const {
      return (node == x.node);
    //TODO: Implement Equality-Operation for Iterator
    //      (Aufgabe 3.12 - Teil 5)
    // Iterators should be the same if they refer to the same node
  } // call it: == it

  /* guckt ob zwei Listen Iterator nicht gleich sind */
  bool operator!=(ListIterator<T> const& x) const {
    //TODO: Implement Inequality-Operation for Iterator  
    //      (Aufgabe 3.12 - Teil 6)
    // Reuse operator==
      return (node != x.node);
  } // call it: != it

  /* Advances Iterator */
  ListIterator<T> next() const {
    if (nullptr != node) {
      return ListIterator{node->next};
    } else {
      return ListIterator{nullptr};
    }
  }


  ListNode <T>* node = nullptr;
};



template <typename T>
class List {
  public:

    //friend declarations for testing the members   
    template <typename TEST_TYPE>
    friend size_t get_size(List<TEST_TYPE> const& list_to_test);
    template <typename TEST_TYPE>
    friend ListNode<TEST_TYPE>* get_first_pointer(List<TEST_TYPE> const& list_to_test);
    template <typename TEST_TYPE>
    friend ListNode<TEST_TYPE>* get_last_pointer(List<TEST_TYPE> const& list_to_test);

    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = T const*;
    using reference       = T&;
    using const_reference = T const&;
    using iterator        = ListIterator<T>;

    // not fully implemented yet
    // TODO: do not forget about the initialiser list! (Aufgabe 3.2)
    /* ... */
    List() :
        size_{0},
        first_{nullptr},
        last_{nullptr}
    {}

    // test and implement:
    //TODO: Copy-Konstruktor using Deep-Copy semantics (Aufgabe 3.5)
    /*
    List(List<T> const& list):
        size_{0},
        first_{nullptr},
        last_{nullptr}  {
        auto i = list.begin();
        while (i != list.end()) 
        {
            push_back(*i);
            ++i;
        }
    }
    */
    // test and implement:
    // TODO: Move-Konstruktor (Aufgabe 3.9)

    //TODO: Initializer-List Konstruktor (3.10 - Teil 1)
    /* ... */
    // test and implement:
    List(std::initializer_list<T> ini_list) {
      //not implemented yet
    }

    /* ... */
    // test and implement:
    //TODO: (unifying) Assignment operator (Aufgabe 3.6)
    List<T>& operator=(List<T>& list1)
    {
        clear();
        for (auto i = list1.begin(); i != list1.end(); ++i)
        {
            push_back(*i);
        }
        return *this;
    }


    /* ... */
    // test and implement:
    //operator== (Aufgabe 3.8)
    bool operator==(List const& rhs) const
    {
        ListNode<T>* current = first_;
        ListNode<T>* current_rhs = rhs.first_;
        if (size() != rhs.size())
        {
            return false;
        }
        while (current != nullptr)
        {
            if (current->value != current_rhs->value)
            {
                return false;
            }
            current = current->next;
            current_rhs = current_rhs->next;
        }
        return true;
    }
    //operator!= (Aufgabe 3.8)
    bool operator!=(List const& rhs) const
    {
        ListNode<T>* current = first_;
        ListNode<T>* current_rhs = rhs.first_;
        if (size() != rhs.size()) {
            return true;
        }

        while (current != nullptr) {
            if (current->value != current_rhs->value) {
                return true;
            }
            current = current->next;
            current_rhs = current_rhs->next;
        }
        return false;
    }


    /* ... */
      //TODO: begin-Method returning an Iterator to the 
      //first element in the List (Aufgabe 3.9)
    ListIterator<T> begin() {
        if (empty()) {
            return ListIterator<T>{nullptr};
        }
        return ListIterator<T>{first_};
    }

    /* ... */
    //TODO: end-Method returning an Iterator to element after (!) 
    //the last element in the List (Aufgabe 3.9)
    ListIterator<T> end()  {
        return ListIterator<T>{nullptr};
    }

    /* ... */ 
    // test and implement:
    //(Aufgabe 3.4)
    void clear() 
    {
        if (empty() == true) {
            std::cout<< "List is empty :) \n";
        }
        else {
            while (first_ != nullptr && last_ != nullptr) {
                pop_front();
            }
        }
    }

    /* (Aufgabe 3.4)... */
    ~List() {
        clear();
    }


    /*  */
    //TODO: member function insert (Aufgabe 3.13)
    void insert(ListIterator<T> const& position, T const& objekt)
    {
        if (position == begin()) { push_front(objekt); }
        else {
            ListNode<T>* addNode = new ListNode<T>{ objekt,position.nodePointer()->prev,position.nodePointer() };
            position.nodePointer()->prev = addNode;
            addNode->prev->next = addNode;
        }
        ++size_;
    }

    /* ... */
    //TODO: member function insert (Aufgabe 3.14)

    /* ... */

    //TODO: member function reverse (Aufgabe 3.7 - Teil 1)
    void reverse()
    {
        ListNode<T>* node = first_;
        ListNode<T>* temp = nullptr;
        while (node != nullptr)
        {
            temp = (*node).next;
            (*node).next = (*node).prev;
            (*node).prev = temp;
            if (temp == nullptr) 
            {
                last_ = first_;
                first_ = node;
            }
            node = temp;
        }
    }

    /* (Aufgabe 3.3)... */
    void push_front(T const& element) {
        ListNode<T>* node = new ListNode<T>{element,nullptr,nullptr};
        if (empty() == true) {
            first_ = node;
            last_ = node;
        }
        else {
            node->next = first_;
            first_->prev = node;
            first_ = node;
        }
        ++size_;
    }

    /* (Aufgabe 3.3)... */
    void push_back(T const& element) {
        ListNode<T>* node = new ListNode<T>{element,nullptr,nullptr};
        if (empty() == true) {
            first_ = node;
            last_ = node;
        }
        else {
            last_->next = node;
            node->prev = last_;
            last_ = node;
        }
        ++size_;
    }

    /* (Aufgabe 3.3)... */
    void pop_front() {
      if(empty()) {
        throw "List is empty";
      }
      
      assert(!empty());
      if(size()==1)
      {
          delete first_;
          first_ = nullptr;
          last_ = nullptr;
          --size_;
      }   
      else {
          auto temp = first_->next;
          delete first_;
          first_ = temp;
          first_->prev = nullptr;
          --size_;
      }
    }

    /* (Aufgabe 3.3)... */
    void pop_back() {
       
      if(empty()) {
        throw "List is empty";
      }
      assert(!empty());
      if (size() == 1) {
          delete first_;
          first_ = nullptr;
          last_ = nullptr;
          --size_;
      }
      else {
          auto temp = last_->prev;
          delete last_;
          last_ = temp;
          last_->next = nullptr;
          --size_;
      }
    }

    /* (Aufgabe 3.3)... */
    T& front() {
      if(empty()) {
        throw "List is empty";
      }
      assert(!empty());
      return first_->value;
      
    }

    /* (Aufgabe 3.3)... */
    T& back() {
      if(empty()) {
        throw "List is empty";
      }
      
      assert(!empty());
      return last_->value;
    }

    /* (Aufgabe 3.2)... */
    bool empty() const {
      return size_ == 0;
    };


    /* (Aufgabe 3.2) ... */
    std::size_t size() const{      
      return size_;
  };


  // list members
  private: 
    std::size_t size_;
    ListNode<T>* first_;
    ListNode<T>* last_;
};

/* ... */
//TODO: Freie Funktion reverse 
//(Aufgabe 3.7 - Teil 2, benutzt Member-Funktion reverse)
template<typename T>
List<T> reverse(List<T> const& list)
{
    List<T> list1(list);
    list1.reverse();
    return list1;
}

/* ... */
//TODO: Freie Funktion operator+ (3.10 - Teil 2)


#endif // # define BUW_LIST_HPP
