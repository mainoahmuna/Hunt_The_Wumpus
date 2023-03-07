/*******************************************************************
** Program: Hunt_the_Wumpus.cpp
** Author: Mainoah-Zander T Muna
** Date: 11/21/2022
** Description: This is a game that uses Object oriented 
** programming to recreate the old school hunt the wumpus game.
** Input: Player input for movement and actions.
** Output: If player wins or loses. 
*********************************************************************/
#ifndef EVENT_H
#define EVENT_H

#include <iostream>

using namespace std;

class Event{
protected:
    int location_x;
    int location_y;
    const string near_message;
    char event_char;
public:
    //constructors
    Event();
    Event(string);

    //getters
    string get_near_message() const;
    string get_action_message() const;
    char get_event_char() const;

    //setters
    virtual void set_location(int, int) = 0;
    
    virtual void display_near_message() const;
    
    void display_event_char() const;

    //deconstructor
    virtual ~Event();
};

#endif