/*******************************************************************
** Program: Hunt_the_Wumpus.cpp
** Author: Mainoah-Zander T Muna
** Date: 11/21/2022
** Description: This is a game that uses Object oriented 
** programming to recreate the old school hunt the wumpus game.
** Input: Player input for movement and actions.
** Output: If player wins or loses. 
*********************************************************************/
#include "room.h"

using namespace std;

/*********************************************************************
** Function:Room()
** Description: This is the default constructor for the room so it 
** sets the room_event pointer to NULL.
** Parameters: none
** Pre-Conditions: Needs to be called.
** Post-Conditions: Room object will be created.
*********************************************************************/ 
Room::Room(){
    this->room_event = NULL;
    srand (time(NULL));
};

/*********************************************************************
** Function: get_event_char()
** Description: returns the character of the event in the room.
** Parameters: none
** Pre-Conditions: Room must be constructed and in scope
** Post-Conditions: returns event character in room
*********************************************************************/ 
char Room::get_event_char() const{
    return this->room_event -> get_event_char();
};

/*********************************************************************
** Function: get_room_event()
** Description: returns the event pointer in the room.
** Parameters: none
** Pre-Conditions: Room must be constructed and in scope
** Post-Conditions: 
*********************************************************************/ 
Event* Room::get_room_event() const{
    return this->room_event;
}

/*********************************************************************
** Function: set_room_event()
** Description: sets the room event pointer point to a certain event 
** pointer.
** Parameters: Event pointer
** Pre-Conditions: Room must be constructed and in scope
** Post-Conditions: 
*********************************************************************/ 
void Room::set_room_event(Event* new_e){
    this->room_event = new_e;
}

/*********************************************************************
** Function: is_empty()
** Description: returns if the room is empty or not. 
** Parameters: none
** Pre-Conditions: Room must be constructed
** Post-Conditions: bool depending if room has an event
*********************************************************************/ 
bool Room::is_empty() const{
    if (this->room_event == NULL){
        return true;
    }
    else{
        return false;
    }
}

/*********************************************************************
** Function: display_room()
** Description: prints the room including the event character for 
** debug mode.
** Parameters: none
** Pre-Conditions: Room must be initialized and in scope.
** Post-Conditions: 
*********************************************************************/ 
void Room::display_room() const {
    if (is_empty()){
        cout << "|";
    }
    else {
        cout << "|";
        this->room_event -> display_event_char();
    }
}

/*********************************************************************
** Function: display_room()
** Description: prints the room not including the event character for 
** debug mode.
** Parameters: none
** Pre-Conditions: Room must be initialized and in scope.
** Post-Conditions: 
*********************************************************************/ 
void Room::display_normal_room() const{
    if (is_empty()){
        cout << "|";
    }
    else {
        cout << "|";
    }
}

/*********************************************************************
** Function: display_near_message()
** Description: prints the near message of the event in a room.
** Parameters: none
** Pre-Conditions: Room must be initialized and in scope.
** Post-Conditions: 
*********************************************************************/ 
void Room::display_near_message() const{
    cout << this->room_event -> get_near_message() << endl;
}

/*********************************************************************
** Function: ~Room()
** Description: Deletes the roomevent and sets it to NULL.
** Parameters: none
** Pre-Conditions: Room must be out of scope. 
** Post-Conditions: 
*********************************************************************/ 
Room::~Room(){
    delete this->room_event;
    this->room_event = NULL;
};