//----------------------------------------------
// Purpose: Implement (key,value) List class.
// Author:  John Gauch
//----------------------------------------------

#include "list.h"

//----------------------------------------------
// Constructor function.
//----------------------------------------------
List::List()
{
   Head = NULL;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
List::List(const List & list)
{
   // Create first node
   LNode *copy = new LNode();
   Head = copy;

   // Walk list to copy nodes
   LNode *ptr = list.Head;
   while (ptr != NULL)
   {
      copy->Next = new LNode();
      copy = copy->Next;
      copy->Key = ptr->Key;
      copy->Value = ptr->Value;
      copy->Next = NULL;
      ptr = ptr->Next;
   }

   // Tidy first node
   copy = Head;
   Head = copy->Next;
   delete copy;
}

//----------------------------------------------
// Destructor function.
//----------------------------------------------
List::~List()
{
   // Walk list to delete nodes
   while (Head != NULL)
   {
      LNode *ptr = Head;
      Head = Head->Next;
      delete ptr;
   }
}

//----------------------------------------------
// Insert data into linked list.
//----------------------------------------------
bool List::Insert(string key, string value)
{
    // Walk list to find node
    LNode *ptr = Head;
    while (ptr != NULL)
    {
        if (ptr->Key == key)
        {
            // Update node value if key found
            ptr->Value = value;
            return true;
        }
        ptr = ptr->Next;
    }

    // Insert new node if key not found
    LNode *newNode = new LNode();
    newNode->Key = key;
    newNode->Value = value;
    newNode->Next = Head;
    Head = newNode;
    return true;
}


//----------------------------------------------
// Search for data in linked list.
//----------------------------------------------
bool List::Search(string key, string &value)
{
   // Walk list to find node
   LNode *ptr = Head;
   while ((ptr != NULL) && (ptr->Key != key))
      ptr = ptr->Next;

   // Return value if key found
   if (ptr != NULL)
   {
      value = ptr->Value;
      return true;
   }
   return false;
}

//----------------------------------------------
// Delete data from linked list.
//----------------------------------------------
bool List::Delete(string key)
{
   // Walk list to find node
   LNode *ptr = Head;
   while ((ptr != NULL) && (ptr->Key != key))
      ptr = ptr->Next;

   // Swap data with head node
   if (ptr == NULL)
      return false;
   ptr->Key = Head->Key;
   ptr->Value = Head->Value;

   // Delete head node
   ptr = Head;
   Head = Head->Next;
   delete ptr;
   return true;
}

//----------------------------------------------
// Print all records in linked list.
//----------------------------------------------
void List::Print()
{
   LNode *ptr = Head;
   while (ptr != NULL)
   {
      cout << ptr->Key << " " << ptr->Value << endl;
      ptr = ptr->Next;
   }
}

//----------------------------------------------
// Check to see if list is empty.
//----------------------------------------------
bool List::IsEmpty()
{
   return (Head == NULL);
}

//----------------------------------------------
// Count number of nodes in a list.
//----------------------------------------------
int List::Count()
{
   int count = 0;
   LNode *ptr = Head;
   while (ptr != NULL)
   {
      count++;
      ptr = ptr->Next;
   }
   return count;
}