//Souriya Khaosanga
//main.cpp
//This is where the main body of the 
//program lives.

#include "table.h"




int command(int input, char * & move, command_info & info);

int main()
{
    char * user_command = NULL;
    command_info info;
    //use for a temporary storage of the 
    //command name
    
    srand (time(NULL));
    //used to generate random numbers
    
    int moves[TEST];
    //create an array of size test
    //used to store the integers for
    //testing the hash table
    
    for (int i = 0 ; i <TEST-1 ; i++)
    {
        moves[i] = rand() %9 +1;;
        
    }
    //generate and store the random numbers
    //used in testing the hash table
    

    int x_map = 0;
    int y_map = 0;
    //these are the coordinates used by
    //the avatar in the game
   
    table a_table;
    //create the user hash table
    //which will keep track of all
    //all the moves a user chooses
    
    player user;
    //create a player that can play the game
    
    stack a_stack;
    //create a stack to transfer to the player
    
    avatar an_avatar;
    //create an avatar that will be copied
    //to the top of the stack
    
    avatar avatar_get;
    weapon weapon_get;
    //create an avatar and weapon object 
    //to use peek function in player to copy to
    
    weapon free_weapon;
    //create a free_weapon object
    //which will be used on the hash table
    //for testing
    
    free_weapon.name = "Wooden Knife";
    free_weapon.type = "off hand";
    free_weapon.damage = "0";
    //Create a weapon given to the user
    //for initial use
    
    
    avatar to_play;
    //used to copy the avatar that will be
    //played throughout the game
    
    an_avatar.name = "User #1";
    an_avatar.ranking = "Level 1";
    //sets the name and ranking of the avatar
    //the user will be playing
    
    a_stack.push(an_avatar);
    //push that avatar to the top of the
    //stack
    
    a_stack.pop(to_play);
    user.pick(to_play);
    //user.display_player();
    //take the avatar off the top of the stack
    //that will be used in the game and assign
    //that to the user
    
    user.equip_weapon(free_weapon);
    //user.display_weapon();
    //give the user a free weapon
    
    user.player_get(avatar_get, weapon_get);
    //looks at the avatar and weapon info that
    
    cout<<"We will now enter test data into ";
    cout<<"our hash table for user #1."<<endl;
    cout<<"Press ENTER to continue";
    cin.get();
    for (int j = 1 ; j < TEST-1 ; j++)
    {
        command(moves[j], user_command, info);
        //convert the random number into
        //an avatar move listed in the function
        //chart
        a_table.add(avatar_get, weapon_get, user_command, 
        info, x_map, y_map);
        //store each of the commands with the
        //approprate data into the hash table
        //using the class function
      
    }
    //This for loops generates nodes which are stored
    //onto the hash table. It is primarily used for
    //user 1 test information.
    
    
    an_avatar.name = "User #2";
    an_avatar.ranking = "Level 2";
    //sets the name and ranking of the avatar
    //the user will be playing
    
    a_stack.push(an_avatar);
    //push that avatar to the top of the
    //stack
    
    a_stack.pop(to_play);
    user.pick(to_play);
    //user.display_player();
    //take the avatar off the top of the stack
    //that will be used in the game and assign
    //that to the user
    
    free_weapon.name = "Weapon 2";
    free_weapon.type = "Dagger";
    free_weapon.damage = "2";
    //create a new weapon for user 2 to use
    //in the video game
    
    user.equip_weapon(free_weapon);
    //user.display_weapon();
    //give the user a free weapon
    
    user.player_get(avatar_get, weapon_get);
    //looks at the avatar and weapon info that
    
    cout<<"We will now enter test data into ";
    cout<<"our hash table for user #2."<<endl;
    cout<<"Press ENTER to continue";
    cin.get();
    
    for (int k = 1 ; k < TEST-1 ; k++)
    {
        command(moves[k], user_command, info);
        //convert the random number into
        //an avatar move listed in the function
        //chart
        a_table.add(avatar_get, weapon_get, user_command, 
        info, x_map, y_map);
        //store each of the commands with the
        //approprate data into the hash table
        //using the class function
    }
    //This is used for testing the second user input
    
       
    cout<<"Now we will display all the tables of the ";
    cout<<"hash table: "<<endl;
    cout<<"Press ENTER to continue";
    cin.get();
    a_table.display_all();
    
    
    cout<<"This displays nodes User 2 moving forward" <<endl;
    cout<<"Press ENTER to continue";
    cin.get();
    a_table.get(avatar_get, weapon_get, "move forward",x_map ,y_map);
 
    cout<<"This displays nodes User 2 using magic" <<endl;
    cout<<"Press ENTER to continue";
    cin.get();
    a_table.get(avatar_get, weapon_get, "use magic",x_map ,y_map);
    
    
    
   
    
    cin.get();
    return 0;
}
    
