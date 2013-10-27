//Souriya Khaosanga
//CS163 HW2
//player.h

#include "queue.h"
//The purpose of this file is to 
//player specifications.

class player
//This class is essentially the 
//user of the game.  The player is
//allowed to have one avatar and 
//one weapon in hand.  This class also
//allows them to carry a bag of weapons
//used in the game
{
      public:
             player(void);
             //constructor
             ~player(void);
             //destructor
             int pick(const avatar & to_pick);
             //allows the user to chose which 
             //avatar to play
             int add_weapon(const weapon & to_add);
             //allows the user to add a weapon 
             //from the game into the bag
             int equip_weapon(weapon & to_equip);
             //allows the user to equip the first
             //item in their bag.
             int display_player(void);
             //shows the user which avatar they 
             //are currently playing
             int display_weapon(void);
             //displays what weapon the user is
             //currently equipped with
             int display_bag(void);
             //displays all the weapons the user
             //has picked up
             int player_get(avatar & avatar_peek, weapon & weapon_peek); 
             //looks and returns the avatar and weapon
             
             
      private:
             avatar a_player;
             //this is the users avatar being
             //played
             weapon a_weapon;
             //weapon the user is equipped
             queue bag;
             //this is the bag queue
};



