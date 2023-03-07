/*******************************************************************
** Program: Hunt_the_Wumpus.cpp
** Author: Mainoah-Zander T Muna
** Date: 11/21/2022
** Description: This is a game that uses Object oriented 
** programming to recreate the old school hunt the wumpus game.
** Input: Player input for movement and actions.
** Output: If player wins or loses. 
*********************************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include "event.h"

using namespace std;

class Wumpus : public Event{
private:
    bool alive;
public:
    //constructor
    Wumpus();

    //getters
    string get_near_message();

    //setters
    void set_location(int, int);

    //deoconstructor
    ~Wumpus();
};

#endif