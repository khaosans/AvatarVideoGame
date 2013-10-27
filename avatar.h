//Souriya Khaosanga
//HW#3
//


#include <iostream>
#include <cstring>
#include <cctype>

const int MAX = 27;
const int SIZE1 = 25;
const int TEST = 25;


using namespace std;


struct avatar
{
       char * name;
       char * ranking;
       //contain pointers to 
       //a name a ranking and 
       //are dynamically allocated
 
};

struct stack_node
//stack data structure
{
       avatar a_avatar; // An avatar
       stack_node * next; //pointer to next
}; 


class stack
//this class is the data structure the 
//stack of avatars
{
      public:
             stack(void);
             //constructor
             ~stack(void);
             //destructor
             int push(const avatar & to_add);
             //function to push onto the stack
             int pop(avatar & at_top);
             //function that returns removes from 
             // the top of the stack
             int peek(avatar & at_top);
             //function used to look at the top
             int display_all(void);
             //functions displays all nodes/data 
             //members in the stack.pico 
      private:
             stack_node * head;
             //defines a head pointer to a 
             //stack of data 
      
};   

