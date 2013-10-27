//Souriya Khaosanga
//CS163 HW2
//player.cpp

//This is where the player class functions
//are implemented in the program.  Function 
//and arguments will be discuessed here.

#include "table.h"


player::player(void)
//Constructor
//This function has no arguments
//as it is the constructor.
{
    a_player.name = NULL;
    a_player.ranking = NULL;  
    //initialize the pointers       
    
}
player::~player(void)
//Destructor
//This function has no arguments as 
//it is the destructor.
{
    a_player.name = NULL;
    a_player.ranking = NULL;
    
    delete a_player.name;
    delete a_player.ranking;
    //de allocate the pointer
                 
}

int player::pick(const avatar & to_pick)
//Function allows the user to pick an 
//avatar to play.  It takes an avatar as the
//argument.  
{
    a_player.name = to_pick.name;
    a_player.ranking = to_pick.ranking; 
    //copies the information into the user
    //information
    
    return 1;               
}
      

int player::add_weapon(const weapon & to_add)
//Function allows a player to add a weapon
//from the bag
{
    bag.enqueue(to_add);
    //put the weapon into the bag
    return 1;
}

int player::equip_weapon(weapon & to_equip)
//Function allows the user to equip the first 
//weapon in the bag using the dequeue function.
//It takes the weapon structure as an arguement.
{
    
    bag.dequeue(to_equip);
    //Takes the weapon of the top of the 
    //user bag queue and equips the
    //user
    
    a_weapon.name = to_equip.name;
    a_weapon.type = to_equip.type;
    a_weapon.damage = to_equip.damage;
    //take the first weapon out
    //of the bag and equip
    
    return 1;
}

int player::display_player(void)
//Displays the user's current
//avatar being played.  The function
//has no arugments.
{
    cout<<"Currently playing as:"<<endl;
    cout<<"Name: ";     
    cout<<a_player.name<<endl;
    cout<<"Ranking: ";
    cout<<a_player.ranking<<endl;
    cout<<endl;
    //display the user and the 
    //weapon they are currently equipped
    
    return 1;
    
}

int player::display_weapon(void)
//Function is used to display
//the players weapons equipped.
//This function takes no arguments.
{
    cout<<"Currently equipped with: "<<endl;
    cout<<"Name: ";   
    cout<<a_weapon.name<<endl;
    cout<<"Type: ";
    cout<<a_weapon.type<<endl;
    cout<<"Damage: ";
    cout<<a_weapon.damage<<endl;
    //this displays the weapons
    
    return 1;
}    

int player::display_bag(void)
//Function displays all the items in
//the bag of the users current 
//avatar.
{
    cout<<"Your bag has: "<<endl;
    bag.display_queue();
    //this displays all the 
    //items in the bag
    
    return 1;
}

int player::player_get(avatar & avatar_peek, weapon & weapon_peek)
//Function looks and returns the avatar information & weapon
//data.  It takes the avatar_peek and weapon_peek by reference
//because it copies to those structures.
{
    avatar_peek.name = a_player.name ;
    avatar_peek.ranking = a_player.ranking ;
    //copy the avatar data
    
    weapon_peek.name = a_weapon.name;
    weapon_peek.type = a_weapon.type;
    weapon_peek.damage = a_weapon.damage;
    //copy the weapon data 
    
    return 1;
} 


   

