#ifndef LIST_H
#define LIST_H

//-----------------------------------------------------------
//  Purpose:    Header file for the List class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;

//-----------------------------------------------------------
// List data node definition
//-----------------------------------------------------------
class LNode
{
 public:
   string Key;
   string Value;
   LNode *Next;
};

//-----------------------------------------------------------
// Define the List class interface 
//-----------------------------------------------------------
class List
{
 public:
   // Constructors
   List();
   List(const List & list);
    ~List();

   // Methods
   bool Insert(string key, string value);
   bool Search(string key, string &value);
   bool Delete(string key);
   void Print();
   bool IsEmpty();
   int Count();

 private:
     LNode * Head;
};

#endif