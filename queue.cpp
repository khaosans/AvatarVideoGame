//Souriya Khaosanga
//CS163 HW2
//queue.cpp

#include "player.h"

//This file is where all the queue class
//functions are defined.  


queue::queue(void)
//construtor
//Contains no arugments.
{
      ptr = NULL;
      //intialize the pointer
}

queue::~queue(void)
//destructor
//Contains no arguments.
{
      queue_node * current = ptr;
      //create a temporary and set it
      //equal to the rear
      
      if(current == NULL)
      //if the empty list
      {
             return;
             //nothing to do
      }
      
      if(current == current->next)
      //if the list has only one node
      {
             delete current;
             //deallocate the current node
             current = NULL;
             //set the current pointer to null
             
      }
      else
      {
             while(current != current->next)
             {
                  ptr = current ->next;
                  //traverse the pointer
                  
                  delete current;
                  //de allocate the ptr
                  
                  current = current->next;
                  //traverse to the next
             }
             
             ptr = current;
             //set current to the pointer
             
             delete ptr;
             //delete the ptr
             
             ptr = NULL;
             //set the pointer to null to
             //deallocate
      }           
      
}

int queue::enqueue(const weapon & to_add)
//Function adds to the rear of the 
//circular link list.
//Argument is the weapon structure which
//is essentially passed by constant reference.
{
      queue_node * temp;
      //create a temporary pointer   
        
      if(ptr == NULL)
      //create one single node
      //when list is empty
      {
             ptr = new queue_node;
             //create a new node
             
             ptr->a_weapon.name = to_add.name;
             ptr->a_weapon.type = to_add.type;
             ptr->a_weapon.damage = to_add.damage;
             //copy all the data
             
             ptr->next = ptr;
             //set the node to point
             //to itself
             
             return 1;
      }
      
      if(ptr == ptr->next)
      //Case 2: Having one existing node
      {
             temp = new queue_node;
             //create a new node
             
             temp->a_weapon.name = to_add.name;
             temp->a_weapon.type = to_add.type;
             temp->a_weapon.damage = to_add.damage;
             //copy all the data
             
             ptr->next = temp;
             //set the existing node to the new
             //node
             
             temp->next = ptr;
             //set the temp node to the front
             
             ptr = temp;
             //move the pointer to the rear
             return 1;
      }
      
      else
      {
             temp = ptr->next;
             //move pointer to the front of the queue
             ptr->next = new queue_node;
             //create a node at the end of the queue
             
                        
             ptr=ptr->next;
             //move the ptr to the newly created node
             
             ptr->a_weapon.name = to_add.name;
             ptr->a_weapon.type = to_add.type;
             ptr->a_weapon.damage = to_add.damage;
             //copy all the data
             
             ptr->next=temp;
             //point the rear to the front
             return 1;
      }
}           


int queue::display_queue(void)
//Function displays all nodes of the queue
//There are no arguments in this function
{
      queue_node * current = ptr;
      //create a temporary pointer
      //for traversing
      
      if(current == NULL)
      //List is empty
      {
             return 0;
      }
      if(current == current->next)
      //If one item in the list
      {
             cout<<"Name: ";
             cout<<current->a_weapon.name<<endl;
             cout<<"Type: ";
             cout<<current->a_weapon.type<<endl;
             cout<<"Damage: ";
             cout<<current->a_weapon.damage<<endl;
             cout<<endl;
             //Display the front of the queue
             
             return 1;       
      }
      else
      //this is for more two more more nodes
      {
             current = current->next; 
             //traverse to the front of the queue
                       
             cout<<"Name: ";
             cout<<current->a_weapon.name<<endl;
             cout<<"Type: ";
             cout<<current->a_weapon.type<<endl;
             cout<<"Damage: ";
             cout<<current->a_weapon.damage<<endl;
             cout<<endl;
             //display the front of the queue
             
             current = current->next;
             //traverse to the 2nd item
             
             while(current != ptr)
             //while this is not the last
             {
                   cout<<"Name: ";
                   cout<<current->a_weapon.name<<endl;
                   cout<<"Type: ";
                   cout<<current->a_weapon.type<<endl;
                   cout<<"Damage: ";
                   cout<<current->a_weapon.damage<<endl;
                   cout<<endl;
                   //display the data memebers
                   //except the last node
                   
                   current = current->next;
                   //traverse
             }
             
                        
             cout<<"Name: ";
             cout<<current->a_weapon.name<<endl;
             cout<<"Type: ";
             cout<<current->a_weapon.type<<endl;
             cout<<"Damage: ";
             cout<<current->a_weapon.damage<<endl;
             cout<<endl;
             //display the last node
             
             return 1;             
            
      }
                    
}  

int queue::dequeue(weapon & at_front)
//this function returns the front 
//and then removes it from the queue
//The arguments are a weapon struture 
//which is passed by reference.
{
      queue_node * current = ptr;
      //create a temporary and set it
      //equal to the rear
      
      if(current == NULL)
      //if the empty list
      {
             return 0;
      }
      
      if(current == current->next)
      //if the list has only one node
      {
             at_front.name = current->a_weapon.name;
             at_front.type = current->a_weapon.type;
             at_front.damage = current->a_weapon.damage;
             //copy the node
             
             delete current;
             //deallocate the current node
             
             return 1;
             
      }
      else
      //when there are more than one node
      {
             current = current->next;
             //traverse to the front
          
             at_front.name = current->a_weapon.name;
             at_front.type = current->a_weapon.type;
             at_front.damage = current->a_weapon.damage;
             //copy the front of the queue
             
             ptr->next = current->next;
             //point the rear to the front
             
             delete current;
             //delete the front node
             
             return 1;
             
      }
            
             
}

int queue::peek_queue(weapon & at_front)
//This function is used to peek at the front
//of the queue and return it.  The argument is 
//a weapons structure by reference.
{
      queue_node * current = ptr;
      //set a current pointer to the rear
      
      if(current == NULL)
      //Empty set
      {
            return 0;
      }
      
      if(current == current->next)
      //if only one node exists
      {
            at_front.name = current->a_weapon.name;
            at_front.type = current->a_weapon.type;
            at_front.damage = current->a_weapon.damage;
            //copy the front of the queue
            
            
            return 1;
      }
      else
      //if there are 2 or more nodes
      {
            current = current->next;
            //traverse to the front of queue
            
            at_front.name = current->a_weapon.name;
            at_front.type = current->a_weapon.type;
            at_front.damage = current->a_weapon.damage;
            //copy each member of the weapon from the
            //queue
      }
                       
      
}


