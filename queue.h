//Souriya Khaosanga
//CS163 HW#3



#include "avatar.h"

struct weapon
//This is the weapon specification
{
       char * name;
       char * damage;
       char * type;
       //These are the data members
};

struct queue_node
//this is the data structure 
//for the weapon type.
{
       weapon a_weapon;
       //contains the structure 
       //weapon
       queue_node * next;
       //contains the pointer to 
       //the next queue node
};





class queue
//this is the queue class which hides
//all the data from the application  
//The queue class us used for queueing 
//the weapon in the game and for the bag.
{
      public:
             queue(void);
             //constructor
             ~queue(void);
             //destructor
             int enqueue(const weapon &);
             //add at the end of queue
             int dequeue(weapon &);
             //take from the front and return
             //the weapon
             int peek_queue(weapon &);
             //used to peek at the queue
             int display_queue(void);
             //displays all the members
             //of the queue.
      private:
              queue_node * ptr;
              //this is the pointer to the 
              //rear of the queue.
             
      
};
