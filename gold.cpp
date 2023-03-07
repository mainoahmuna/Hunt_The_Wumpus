/*******************************************************************
** Program: Hunt_the_Wumpus.cpp
** Author: Mainoah-Zander T Muna
** Date: 11/21/2022
** Description: This is a game that uses Object oriented 
** programming to recreate the old school hunt the wumpus game.
** Input: Player input for movement and actions.
** Output: If player wins or loses. 
*********************************************************************/
#include "gold.h"

using namespace std;

/*********************************************************************
** Function: Gold()
** Description: Initializes the Gold object and overwrites the near 
** message. 
** Parameters: none
** Pre-Conditions: Event object must be created. 
** Post-Conditions: 
*********************************************************************/ 
Gold::Gold() : Event("You see a glimmer nearby."){
    this->location_x = 0;
    this->location_y = 0;
    this->event_char = 'g';
}


/*********************************************************************
** Function: get_near_message()
** Description: returns the near message of the event.
** Parameters: none
** Pre-Conditions: Event object must be created. 
** Post-Conditions: 
*********************************************************************/
string Gold::get_near_message(){
    return this->near_message;
}


/*********************************************************************
** Function: set_location()
** Description: sets the location of the event form integer parameters.
** Parameters: int x, int y
** Pre-Conditions: Event object must be created. 
** Post-Conditions: 
*********************************************************************/
void Gold::set_location(int x, int y){
    this->location_x = x;
    this->location_y = y;
} 

/*********************************************************************
** Function: ~Gold()
** Description: Deletes gold event object
** Parameters: none
** Pre-Conditions: Event object must be out of scope. 
** Post-Conditions: 
*********************************************************************/
Gold::~Gold(){}