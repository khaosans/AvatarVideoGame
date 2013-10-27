//Souriya Khaosanga
//CS163 HW2
//stack.cpp

#include "table.h"

//This is where all the stack functions
//are implemented.  Functions will be
//disscussed as well as arguments.

stack::stack(void)  //This is the constructor
//no arguments
{
      head = NULL; //Initialize the head
                   //pointer to null
      
}

stack::~stack(void) //This is the destructor
//It merely deletes the head.
{
      delete head; //Delete the head pointer
}

int stack::push(const avatar & to_add) //This is the 
//stack function, the arguments are the avatar node.
//The argument is just a avatar struct.  It is inputted
//from the application.  It is passed by reference.
{
    stack_node * temp;  //create a temporary pointer
    
    if (head == NULL)
    //If there is nothing in head
    {
         head = new stack_node;
         //create a new node
         
         
         head->a_avatar.name = to_add.name;
         head->a_avatar.ranking = to_add.ranking;
         //create a copy of the data from the passed
         //struct
         
         head->next = NULL;
         //set the next pinter to null
         
         return 1;
        
    }
    else //this adds to the top of the stack
    {
        temp = new stack_node;
        //create a new temporary node 
        
        temp->a_avatar.name = to_add.name;
        temp->a_avatar.ranking = to_add.ranking;
        //copy that data from the structure
        
        temp->next = head; 
        //link up the temporary
        
        head = temp;
        //move the head to the front
        
        return 1;
        
    }
    
}

int stack::peek(avatar & at_top)
//This is a peek function that looks at
//the top of the stack.  The argument is the
//avatar structure which is passed by reference.
{

    if (head == NULL)
    //nothing to do
    {
        return 0;
    }
    else
    {
        at_top.name = head->a_avatar.name;
        at_top.ranking = head->a_avatar.ranking;
        //make that copy of the head onto
        //the at_top struct
        
        return 1;
        //return that structure
        
    }

}



int stack::pop(avatar & at_top)
//This function returns the top 
//and deletes it off the top of the
//stack.
//Argument is the avatar structure.

{
    stack_node * current = head; 
    //create a current pointer 
    //set it equal to head.
            
    if (current == NULL)
    //nothing to do
    {
        return 0;
    }
    else
    {
        at_top.name = current->a_avatar.name;
        at_top.ranking = current->a_avatar.ranking;
        //make that copy of the head onto
        //the at_top struct
        
        head = head->next;
        //traverse head to the next 
        //node
        
        delete current;
        //delete the node that head was
        //previously pointing to.
        
        return 1;
        //return that structure
        
    }
           
            
        
    
}



int stack::display_all(void)
//This function has no arguments.
//It displays all the data in the stack
{
    stack_node * current = head;
    //create the current pointer so it doesn't
    //delete the head pointer.
    //Use it to display the stack.
    
    if (current == NULL)
    {
        return 0;
        //Nothing to do
    }
    else
    {
        while (current!=NULL)
        //Something is in the list 
        {
              cout<<"Name: ";      
              cout<<current->a_avatar.name<<endl;
              cout<<"Rank: ";
              cout<<current->a_avatar.ranking<<endl;
              cout<<endl;
              //display the struct entries
              
              current = current->next;
              //traverse
        }
        
        return 1;
        //return success
    }
   
}


