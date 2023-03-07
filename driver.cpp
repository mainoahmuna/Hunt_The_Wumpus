/*******************************************************************
** Program: Hunt_the_Wumpus.cpp
** Author: Mainoah-Zander T Muna
** Date: 11/21/2022
** Description: This is a game that uses Object oriented 
** programming to recreate the old school hunt the wumpus game.
** Input: Player input for movement and actions.
** Output: If player wins or loses. 
*********************************************************************/
#include <iostream>
#include "bats.h"
#include "wumpus.h"
#include "pit.h"
#include "gold.h"
#include "game.h"

using namespace std;

int main(){

    Game g;

    int option = -1;

    option = g.debug_normal();

    if(option == 1){
        g.start_game_normal();
    }
    if (option == 2){
        g.start_game_debug();
    }

    return 0;
}