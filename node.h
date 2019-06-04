#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include<iostream>
using namespace std;

template<typename T>
class Node
{
public:
  Node *prev = nullptr;
  Node *next = nullptr;
  T value;
};

#endif // NODE_H_INCLUDED
