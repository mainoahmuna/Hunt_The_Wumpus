/*******************************************************************
** Program: Hunt_the_Wumpus.cpp
** Author: Mainoah-Zander T Muna
** Date: 11/21/2022
** Description: This is a game that uses Object oriented 
** programming to recreate the old school hunt the wumpus game.
** Input: Player input for movement and actions.
** Output: If player wins or loses. 
*********************************************************************/
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "bats.h"
#include "pit.h"

using namespace std;

class Room {
private:
    Event *room_event; //event in each room
public:
    Room();
    
    //getters
    char get_event_char() const;
    Event* get_room_event() const;

    //setters
    void set_room_event(Event*);
    void set_event_char(char);

    bool is_empty() const;

    void display_room() const;

    void display_normal_room() const;

    void display_near_message() const;

    //destructor
    ~Room();

};


#endif