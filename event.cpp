/*******************************************************************
** Program: Hunt_the_Wumpus.cpp
** Author: Mainoah-Zander T Muna
** Date: 11/21/2022
** Description: This is a game that uses Object oriented 
** programming to recreate the old school hunt the wumpus game.
** Input: Player input for movement and actions.
** Output: If player wins or loses. 
*********************************************************************/
#include "event.h"

using namespace std;

/*********************************************************************
** Function: Event()
** Description: Initializes the Event object. 
** Parameters: none
** Pre-Conditions: Event object must be created. 
** Post-Conditions: 
*********************************************************************/ 
Event::Event(){
    this->location_x = 0;
    this->location_y = 0;
    this->event_char = ' ';
}

/*********************************************************************
** Function: Event()
** Description: Initializes the Event object and overwrites the 
** near_message const. 
** Parameters: string 
** Pre-Conditions: Event object must be created. 
** Post-Conditions: 
*********************************************************************/ 
Event::Event(string m) : near_message(m){
    this->location_x = 0;
    this->location_y = 0;
    this->event_char = ' ';
}

/*********************************************************************
** Function: get_near_message()
** Description: returns the near message of the event.
** Parameters: none
** Pre-Conditions: Event object must be created. 
** Post-Conditions: 
*********************************************************************/
string Event::get_near_message() const{
    return this->near_message;
}

/*********************************************************************
** Function: get_event_char()
** Description: returns the event character of the event.
** Parameters: none
** Pre-Conditions: Event object must be created. 
** Post-Conditions: 
*********************************************************************/
char Event::get_event_char() const{
    return this->event_char;
}

/*********************************************************************
** Function: display_near_message()
** Description: prints the diplay messgae of the object to the screen. 
** Parameters: none
** Pre-Conditions: Event object must be created. 
** Post-Conditions: 
*********************************************************************/
void Event::display_near_message() const{
    cout << this->near_message << endl;
}

/*********************************************************************
** Function: display_event_char()
** Description: displays the character of the event. 
** Parameters: none
** Pre-Conditions: Event object must be created. 
** Post-Conditions: 
*********************************************************************/
void Event::display_event_char() const{
    cout << this->event_char;
}

/*********************************************************************
** Function: ~Event()
** Description: Deletes event object
** Parameters: none
** Pre-Conditions: Event object must be out of scope. 
** Post-Conditions: 
*********************************************************************/
Event::~Event(){}