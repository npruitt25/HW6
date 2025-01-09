#ifndef HASH_H
#define HASH_H

//-----------------------------------------------------------
//  Purpose:    Header file for the HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

//-----------------------------------------------------------
// Define the HashTable class interface
//-----------------------------------------------------------
class HashTable
{
 public:
   // Constructors
   HashTable(int size);
   HashTable(const HashTable & ht);
   ~HashTable();

   // Methods
   bool Insert(string key, string value);
   bool Search(string key, string &value);
   bool Delete(string key);
   void Print();
   void Read(string filename);

 private:
   // Private methods
   int Hash(string key);

   // Private data
   int Size;
   List *Table;
};

#endif