//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "hash.h"

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
   Size = size;
   Table = new List[Size];
}

//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
HashTable::HashTable(const HashTable & ht)
{
   Size = ht.Size;
   Table = new List[Size];
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
   Size = 0;
   delete [] Table;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
bool HashTable::Insert(string key, string value)
{
   // Find hash index
   int index = Hash(key);
   return Table[index].Insert(key, value);
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool HashTable::Search(string key, string &value)
{
   // Find hash index
   int index = Hash(key);
   return Table[index].Search(key, value);
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
bool HashTable::Delete(string key)
{
   // Find hash index
   int index = Hash(key);
   return Table[index].Delete(key);
}

//-----------------------------------------------------------
// Primary hash function
//-----------------------------------------------------------
int HashTable::Hash(string key)
{
   long int num = 42;
   for (int i = 0; i < int(key.length()); i++)
      num = (num * 17 + key[i]) % Size;
   return num;
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
   for (int index=0; index<Size; index++)
      Table[index].Print();
}

void HashTable::Read(string filename)
{
    ifstream din(filename);

    if (din.fail())
    {
        cout << "Could not open file" << endl;
    }

    string line;
    int count = 0;
    while (getline(din, line) && count < 10000)
    {
        int word1 = line.find(' ');
        int word2 = line.find(' ', word1 + 1);

        if (word1 >= 0 && word2 >= 0)
        {
            string lastName = line.substr(0, word1);
            string firstName = line.substr(word1 + 1, word2 - word1 - 1);
            string number = line.substr(word2 + 1);

            string name = firstName + " " + lastName;

            Insert(name, number);
            count++;
        }
    }
    din.close();
}