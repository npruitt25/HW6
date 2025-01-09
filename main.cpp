#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
#include "hash.h"

using namespace std;

int main()
{
   HashTable hash(100);

   hash.Read("phone.sort.txt");

   hash.Print();

   hash.Insert("Betty White", "479-123-4567");
   hash.Insert("Santa Claus", "479-456-7890");

   string found;
   if(hash.Search("Santa Claus", found))
   {
        cout << "Found Santa Claus at: " << found << endl;
   } else
   {
        cout << "Santa Claus not found." << endl;
   }

   if(hash.Search("Sirius Black", found))
   {
        cout << "Found Sirius Black at: " << found << endl;
   } else
   {
        cout << "Sirius Black not found." << endl;
   }

   if(hash.Delete("Betty White"))
   {
        cout << "Deleted Betty White" << endl;
   }

   cout << endl;

    HashTable hash2(10100);
   int choice = 0;
   char keepGoing = 'Y';

    cout << "Upload file" << endl;
    string file;
    cout << "File name: ";
    cin >> file;
    hash2.Read(file);

   while (tolower(keepGoing) != 'n')
   {   

        cout << "Would you like to (select number):\n" <<  "(1) insert a name and number into the table?\n" <<
        "(2) search the table for someone?\n" << 
        "(3) delete an entry?\n" << "(4) print the table?\n";
        cin >> choice;
        if (choice == 1)
        {
            string first, last, num, wholeName;
            cout << "First name, last name, and number: ";
            cin >> first >> last >> num;
            wholeName = first + " " + last;
            if(hash2.Insert(wholeName, num))
            {
                cout << wholeName << " " << num << " inserted" << endl;
            }else 
            {
                cout << "Insertion unsuccessfull" << endl;
            }
        } else if (choice == 2)
        {
            string first, last, wholeName, found;
            cout << "First name and last name: " << endl;
            cin >> first >> last;
            wholeName = first + " " + last;
            if(hash2.Search(wholeName, found))
                {
                    cout << "Found " << wholeName << " at: " << found << endl;
                } else
                {
                    cout << wholeName << " not found." << endl;
                }
        } else if (choice == 3)
        {
            string first, last, deleteName;
            cout << "First name and last name: ";
            cin >> first >> last;
            deleteName = first + " " + last;
            if (hash2.Delete(deleteName))
            {
                cout << deleteName << " deleted" << endl;
            } else
            {
                cout << deleteName << " not found." << endl;
            }
        } else if (choice == 4)
        {
            cout << "Printing phone book" << endl;
            hash2.Print();
        } else
        {
            cout << "Invalid choice" << endl;
        }

     cout << "Would you like to do keep going? Y/n ";
     cin >> keepGoing;  
     keepGoing = tolower(keepGoing); 
     cin.ignore();
   }

   return 0;
}

