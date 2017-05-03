#include <iostream>
#include <string>
using namespace std;

struct chainNode 
{
   // data members
   string name;
   double num;
   chainNode *next;

   // constructors come here
   chainNode() {}

   
   chainNode(string name, double num)
      {this->name = name;
       this->num = num;}

   
   chainNode(string name, double num, chainNode* next)
      {this->name = name;
       this->num = num;
       this->next = next;}
};


class hashmap 
{
public:
  // constructors and destructor defined here
  hashmap();
  ~hashmap();

  // ADT methods
  void append(string name, double num);
  bool search(string name);
  double getValue(string name);
	  
  // other ADT methods defined here
  void output() const;
  chainNode* firstNode;
  chainNode* lastNode;
 
protected:
//  hash array[32]; //ascii from 0 to 127, four possible values per bucket
  int listSize;          
};

hashmap::hashmap()
{// Constructor.
   firstNode = NULL;
   listSize = 0;
}

hashmap::~hashmap()
{// Chain destructor. Delete all nodes 
 // in chain.
   while (firstNode != NULL)
   {// delete firstNode
      chainNode* nextNode = firstNode->next;
      delete firstNode;
      firstNode = nextNode;
   }
}

void hashmap::append(string name, double num)
{
  if(firstNode == NULL)
  {
    firstNode = new chainNode(name, num, NULL);
    lastNode = firstNode;
  }
  else
  {
    lastNode->next = new chainNode(name, num, NULL);
    lastNode = lastNode->next;
  }
  listSize++;
}

void hashmap::output() const
{
   // move to desired node
   chainNode* currentNode = firstNode;
//   for (int i = 0; i < listSize; i++)
   while( currentNode != NULL )
   {
      cout << currentNode->name << " " << currentNode->num << endl;
      currentNode = currentNode->next;
   }
}

    
bool hashmap::search(string name)
{
  chainNode* pointer = firstNode;
  while(pointer != NULL)
 // for(int i = 0; i < listSize; i++)
  {
    if( pointer->name.compare(name) == 0 )
    {
      cout << pointer->name << " " << pointer->num << endl;
      return true;
    }

    //if( pointer->next != NULL)
    //{
      pointer = pointer->next;
    //}
    //else
    //{
     // break;
    //}
  }
  return false;
}
	

double hashmap::getValue(string name)
{
  chainNode* pointer = firstNode;
  while(pointer != NULL)
 // for(int i = 0; i < listSize; i++)
  {
    if( pointer->name.compare(name) == 0 )
    {
      cout << pointer->name << " " << pointer->num << " " << endl;
      return pointer->num;
    }

    //if( pointer->next != NULL)
    //{
      pointer = pointer->next;
    //}
    //else
    //{
     // break;
    //}
  }
  cout << "error: nothing returned in getValue, returning 0" << endl;
  return 0;
}



int hashFunction(int val)
{
  int hf = val % 32;
  return hf;
}

hashmap hash[32];


int main()
{
  ios_base::sync_with_stdio(false);
  string first = "apple", second = "Apple", third = "banana";
  int a;
  a = hashFunction( first.at(0) );
  hash[a].append(first, 1.0001);
  if(hash[a].search( first ))
  {
    cout << hash[a].getValue( first ) << endl;
  }
  a = hashFunction( second.at(0) );
  hash[a].append(second, 2.002); 
  if(hash[a].search( second ))
  {
    cout << hash[a].getValue( second ) << endl;
  }
  a = hashFunction( third.at(0) );
  hash[a].append(third, 3.03); 
  if(hash[a].search( third ))
  {
    cout << hash[a].getValue( third ) << endl;
  }


return 0;
}

