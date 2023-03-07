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
#include <iomanip>
#include <vector>
#include "room.h"
#include "event.h"
#include "bats.h"
#include "pit.h"
#include "wumpus.h"
#include "gold.h"

using namespace std;

class Game {
private:
    vector <vector<Room> > map;
    int map_size, arrows, num_gold;
    int wumpus_x, wumpus_y;
    int player_start_x, player_start_y, player_position_x, player_position_y, player_action;
    char movement;
    bool game_over, wumpus_alive, win;
public:
    Game();
    Game(int);

    //getters
    char get_movement_char() const;
    bool get_win() const;
    int get_player_arrows() const;
    int get_map_size();

    //setters
    void set_map_size(int);
    void set_starting_position();
    void set_player_action(int);
    void set_movement();

    //deconstructor
    ~Game();

    //game functionalities 
    void create_map();
    void print_map() const; 
    void print_debug_map() const;   
    void get_player_action();
    void move_player();
    void set_event_locations(); 
    bool in_cave(int, int) const;
    void shoot_arrow();
    void move_wumpus();
    void check_event();
    void check_nearby() const;
    void start_game_normal();
    void start_game_debug();
    int win_loss_play_again() const;
    void check_win();
    void reset_wumpus();
    int debug_normal();


};