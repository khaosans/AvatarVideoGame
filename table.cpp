//Souriya Khaosanga
//

#include "table.h"




table::table(void)
{
      head = new table_node*[MAX];
      //create an array of pointers
      //of size max
      
      table_node ** array;
      //pointer to a pointer
      
      for (int i = 0; i < MAX-1 ; i++)
      {
          head[i] = NULL;
          //set each pointer in the 
          //array to null.  Each pointer 
          //is a head pointer to a linked list
      }
                  
 
                          
}

table::~table()
{
      
      for ( int i = 0; i < MAX-1 ; i++)
      {
          if (head[i] != NULL)
          {
               table_node * previous = NULL;
               //create a pointer named previous
               
               
               table_node * entry = head[i]->next;
               //traverse to the next entry
               
               delete head[i];
               //deallocate the head pointer of each 
               //has table index
               
               head[i] = NULL;
               //set the pointer to NULL
                           
               while (entry != NULL)
               //if the pointer is pointing to anything
               //other than null
                     {
                           previous = entry;
                           //set the previous pointer
                           //to the head of the linked list
                           entry = entry->next;
                           //Traverse the entry to the next
                           
                           delete previous;
                           //delete the previous
                           
                           previous = NULL;
                           //set the previous to null
                     }

          }
      }          
}

int table::add(const avatar & avatar_index, 
     const weapon & weapon_index, char * comm, 
     const command_info & info, int & x, int & y)
//This function is used to add a certain table
{
    
    int hash;
    int count;
    
	for (int i=0;i<strlen(comm);i++)
	{
		count = comm[i];
		hash = count % MAX;   	
	}
	//this loop is used to determine the 
	//hash index of the data
	
    if (head[hash] == NULL)
       {
          head[hash] = new table_node;
          //create a new table when the index is empty
          
          head[hash]->table_avatar.name = avatar_index.name;
          head[hash]->table_avatar.ranking = avatar_index.ranking;
          
          head[hash]->table_weapon.name = weapon_index.name;
          head[hash]->table_weapon.type = weapon_index.type;
          head[hash]->table_weapon.damage = weapon_index.damage;
          
          
          head[hash]->user_comm = comm;
          head[hash]->function = info.function;
          head[hash]->state = info.state;
          head[hash]->rules = info.rules;
          head[hash]->others = info.others;
          
          //copy the infromation
          
          head[hash]->x_coord = x;
          head[hash]->y_coord = y;
          
          
          head[hash]->next = NULL;
          //set the next pointer to null
          
          return 1;
       }
    else{
         table_node * current = head[hash];
         //set current to the head of the index
         
         table_node * temp = new table_node;
         //create a new node
         
         temp->table_avatar.name = avatar_index.name;
         temp->table_avatar.ranking = avatar_index.ranking;
         
         temp->table_weapon.name = weapon_index.name;
         temp->table_weapon.type = weapon_index.type;
         temp->table_weapon.damage = weapon_index.damage;
         
         temp->x_coord = x;
         temp->y_coord = y;
         
         temp->user_comm = comm;
         temp->function = info.function;
         temp->state = info.state;
         temp->rules = info.rules;
         temp->others = info.others;
         //copy the data onto the hash table
         
         head[hash] = temp;
         //point head to the temp
         temp->next = current;
         //set the temp next to the current
         
         while(current->next != NULL)
         {
               current = current->next;
         }
               current->next = NULL;              
         //traverse to the node in the index
         //and set that to null
                       
         return 1;
    }


}

int table::display_all()
{
    int counter = 0;
    //store the total number of null
    //pointers
    int i = 0;
    
    while( i < MAX-1)
    //for ever index in the hash table
    {
     
          if (head[i] != NULL)
          //if the head of the index list is not
          //empty
          {
    
                table_node * current = head[i];
                //create a current pointer and 
                //set it equal to the head of index
                
                while(current!= NULL)
                //while the current is not null
                {
                      cout<<"Hash index: ";
                      cout<<i<<endl;
                      cout<<"Table data "<<endl;
                      
                      cout<<"Avatar Name: ";
                      cout<<current->table_avatar.name<<endl;
                      cout<<"Avatar Ranking: ";
                      cout<<current->table_avatar.ranking<<endl;
                      
                      cout<<"Weapon Name: ";
                      cout<<current->table_weapon.name<<endl;
                      cout<<"Weapon Type: ";
                      cout<<current->table_weapon.type<<endl;
                      cout<<"Weapon Damage: ";
                      cout<<current->table_weapon.damage<<endl;
                      
                      cout<<"Command: ";
                      cout<<current->user_comm<<endl;
                      cout<<"Function: ";
                      cout<<current->function<<endl;
                      cout<<"State: ";
                      cout<<current->state<<endl;
                      cout<<"Rules ";
                      cout<<current->rules<<endl;
                      cout<<"Others: ";
                      cout<<current->others<<endl;
                      
                      cout<<"X Coordinate: ";
                      cout<<current->x_coord<<endl;
                      cout<<"Y coordinate: ";
                      cout<<current->y_coord<<endl;
                      
                      //display the data information
                      
                      cout<<endl;
                      
                      current = current->next;
                      //traverse chain of nodes in the 
                      //has table
                } 
          
          
          }
          
    i++;
    //increment the index up 
       
    }      
    
    return 1;
    
}

int table::get(const avatar & avatar_index, 
     const weapon & weapon_index, char * command, int & x, int & y)
{
    int hash;
    //store the hash index
    int count;
    //store the number for the ascii table
    
    int number_matches = 0;
    //store how many times matches exist
    
	for (int i=0; i<strlen(command) ;i++)
	{
		count = command[i];
		hash = count % MAX;   	
	}
	//this loop is used to determine the 
	//hash index of the hash table
	
    table_node * temp = head[hash];
    //set the temporary pointer
    //to the hash index being searched
    
    while(temp != NULL)
    //Go until there is nothing left to search
    {
               if (avatar_index.name == temp->table_avatar.name
                    && weapon_index.name == temp->table_weapon.name
                    && x == temp->x_coord && y == temp->y_coord)
               //match has been found
               {
                      cout<<"Match number: ";
                      cout<<++number_matches<<endl; 
                      cout<< avatar_index.name<<endl;
                      cout<< weapon_index.name<<endl;
                      cout<<"X Coordinate: ";
                      cout<<temp->x_coord<<endl;
                      cout<<"Y Coordinate: ";
                      cout<<temp->y_coord<<endl;
                      //display the matches
                      
                      
               }
               
               temp = temp->next;
               //traverse to the next
    }
    
    return 1;
    
    if( number_matches == 0)
    {
        cout<<"No matches exist";
        return 0;
        //no matches exist
    }
    //no match has been found
}

/*   
int table::remove(const avatar & avatar_index, 
     const weapon & weapon_index, char * comm, 
     int & x, int & y)
{
    int hash;
    int count;
    
	for (int i=0;i<strlen(comm);i++)
	{
		count = comm[i];
		hash = count % MAX;   	
	}
	
	
    table_node * previous;
    
    table_node * current = head[hash_index];
    if(current == NULL)
    {
       return 0;
    }
    
    while(current != NULL)
    {
               
               if( num_to_remove == current->number)
               {
                   table_node * temp = current; 
                   //create a temporary
                   current = current->next;
                   //traverse
                   
                   previous->next = current;
                   //connect up
                   
                   delete temp;
                   return 1;
                   
               }  
               
               previous = current;
               //drag a previous pointer to the last
               current = current->next;
               //traverse      
    }
    
    return 0;
    
}        


                     
  */                          
           
      
               
      
