//Souriya Khaosanga
//HW#3
//

#include "player.h"

struct command_info
{
      char * function;
      char * state;
      char * rules;
      char * others;
}; 
//used to make a copy of the data
//which will used to transfer the copy
//onto the adt

struct table_node
{
      int x_coord;
      int y_coord;
      //used to store the location
      //of the avatar on a x y plane
      
      avatar table_avatar;
      weapon table_weapon;
      //store a copy of the avatar data
      //and weapon data
      
      char * user_comm;
      char * function;
      char * state;
      char * rules;
      char * others;

      //these pointers represent the
      //rules information for each
      //command
      
      table_node * next;
      //create a pointer to the next
      //data set
      
}; 

class table
{
      public:
             table();
             //this is the contructor
             ~table();
             //this is the destructor
             int add(const avatar & avatar_index, 
                  const weapon & weapon_index, char * command,
                  const command_info & info, int & x_coord, 
                  int & y_coord);
             //this function is used to add to the hash
             //table of the chain
             int get(const avatar & avatar_index, 
                  const weapon & weapon_index, char * command, 
                  int & x_coord, int & y_coord);
             //this returns the command of the avatar
             int table::remove(const avatar & avatar_index, 
             const weapon & weapon_index, char * comm, 
             int & x, int & y);
             //this removes the command of the avatar
             int display_all(void);
             //This function displays all non empty hash 
             //tables and indexes
             
      private:
              table_node ** head;
};    

          
      
