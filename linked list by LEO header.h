#ifndef LINKED_LIST_BY_LEO_HEADER_H_INCLUDED
#define LINKED_LIST_BY_LEO_HEADER_H_INCLUDED
#include "node.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LinkedList
{
  Node<T> *m_begin;
  Node<T> *m_tail;


  int m_size = 0;
public:
  LinkedList ()
  {
        int n;

        cout << "Enter a size of the list: ";

        cin >> n;

        cout << endl;

        cout << "Enter numbers or letters: " << endl;


        int a;

        for(int i = 0; i < n; i++)
        {
            cin >> a;
            this -> push_back(a);
        }
  }

  int size () // ok
  {
      return m_size();
  }

  void swap(int* a, int* b)
  {
      int t = *a;
      *a = *b;
      *b = t;
  }

  /*Inserts node with input value to specified position*/
  void insert (T value, int pos) // ok
  {
      Node<T>* insert = m_begin;
        for(int i = 0; i < pos-2; i++)
        {
            insert = insert -> next;
        }

        if(pos == 1)
        {
            Node<T>* newNode = new Node<T>;
            newNode -> value = value;
            newNode -> next = m_begin;
            m_begin -> prev = newNode;
            m_begin = newNode;
        }
        else if (pos == m_size+1)
        {
          Node<T>* newNode = new Node<T>;
            newNode -> value = value;
            newNode -> prev = m_tail;
            m_tail -> next = newNode;
            m_tail = newNode;
        }
        else
        {
            Node<T>* newNode = new Node<T>;
            newNode -> value = value;
            newNode -> next = insert -> next;
            newNode -> prev = insert;
            insert -> next = newNode;
            newNode -> next -> prev = newNode;
        }
        m_size++;

  }

  /*Inserts node with input value in the end of the list */
  void *push_back (T value)//ok
  {
    Node<T> *move = new Node<T>;
    move -> value = value;

    if(m_size == 0)
    {
        m_begin = move;
        m_tail = move;
    }
    else
    {
        m_tail -> next = move;
        move -> prev = m_tail;
        m_tail = move;
    }

    m_size++;
  }

  /*Finds first node from the begin with given value*/
  Node<T>* find (T value) // ok
  {
      Node<T>* bobb = m_begin;
      for(int i = 0; i < m_size; i++)
      {
          if(bobb->value == value)
          {
              return bobb;
          }
          bobb = bobb -> next;
      }
    return nullptr;
  }

  T get (int pos) // ok
  {
      Node<T>* bobb = m_begin;
      for(int i = 1; i < pos; i++)
      {
          bobb = bobb -> next;
      }
    return bobb -> value;
  }

  /*removes input node*/
  void remove (T x) // ok
  {
      Node<T>* node = find(x);
      int flag = 0;

        if(m_size == 1)
        {
            clear();
            flag ++;
        }

        if (!(node -> prev == nullptr || node -> next == nullptr) && flag != 1)
        {
        node -> next -> prev = node -> prev;
        node -> prev -> next = node -> next;
        m_size--;
        node -> next = nullptr;
        node -> prev = nullptr;
        flag ++;
        }

        if(node -> prev == nullptr && flag != 1)
        {
            node -> next -> prev = nullptr;
            m_size--;
            m_begin = node -> next;
            node -> next = nullptr;
            node -> prev = nullptr;
            flag++;
        }

        if(node ->next== nullptr && flag != 1)
        {
            node -> prev -> next = nullptr;
            m_size--;
            m_tail = node -> prev;
            node -> next = nullptr;
            node -> prev = nullptr;
        }
        //delete node;

         // Всё, он стёрт навсегда.
  }

  /*Reverses the list*/
  void reverse () // ok
  {
    Node<T>* current = m_begin;
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;

    while(current != nullptr)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    m_begin = prev;

  }


  /*Clears the list*/
  void clear () // ok
  {
      m_begin = nullptr;
      m_tail = nullptr;
      m_size = 0;
  }

  /*Prints list to stdout*/
  void print_list ()//ok
  {
      Node<T> *temp = m_begin;
      if(m_size > 0)
      {
      cout << temp->value << " ";
      }

      for(int i = 0; i < m_size-1; i++)
      {
          temp = temp -> next;
          cout << temp -> value << " ";
      }
      cout << endl;
  }

  ~LinkedList ()
  {
  }
};


#endif // LINKED_LIST_BY_LEO_HEADER_H_INCLUDED
