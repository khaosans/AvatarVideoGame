//Souriya Khaosanga
//HW #3

//functions.cpp

#include "table.h"


int command(int input, char * & move, command_info & info)
{
    if (input == 1)
    {  
       move = "move forward";
       info.function ="function 1";
       info.state ="state 1";
       info.rules ="rules 1";
       info.others ="other 1";
       
       return 1;
    }
    
    if (input == 2)
    {  
        
       move = "move backward";
       info.function ="function 2";
       info.state ="state 2";
       info.rules ="rules 2";
       info.others ="other 2";
         
       return 2;
       }
    
    if (input == 3 )
       { 
 
       move = "move up/jump";
       info.function ="function 3";
       info.state ="state 3";
       info.rules ="rules 3";
       info.others ="other 3";
          
       return 3;
       }
    if (input == 4)
    {      

       move = "move down/dig";
       info.function ="function 4";
       info.state ="state 4";
       info.rules ="rules 4";
       info.others ="other 4";
       
       return 4;
    }     
    
    if (input == 5)
       {      
  
       move = "stab";
       info.function ="function 5";
       info.state ="state 5";
       info.rules ="rules 5";
       info.others ="other 5";
            
       return 5;
       }     
    
    if (input == 6)
    {      
 
       move = "use magic";
       info.function ="function 6";
       info.state ="state 6";
       info.rules ="rules 6";
       info.others ="other 6";
       
       return 6;
       
       }   
    if (input == 7)
    {      

       move = "sleep";
       info.function ="function 7";
       info.state ="state 7";
       info.rules ="rules 7";
       info.others ="other 7";
       
       return 7;
       
       }  
    if (input == 8)
    {    

       move = "wake up";
       info.function ="function 8";
       info.state ="state 8";
       info.rules ="rules 8";
       info.others ="other 8";
       return 8;
       }     
       
    if (input == 9) 
    {    

       move = "heal";
       info.function ="function 9";
       info.state ="state 9";
       info.rules ="rules 9";
       info.others ="other 9";
       return 9;   
       }    
}             

