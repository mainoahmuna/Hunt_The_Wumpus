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
#include "game.h"

using namespace std;

/*********************************************************************
** Function: Game()
** Description: Initializes the Game object. 
** Parameters: none
** Pre-Conditions: Game object must be created. 
** Post-Conditions: 
*********************************************************************/ 
Game::Game(){
    this->map_size = 0;
    this->arrows = 3;
    this->num_gold = 0;
    this->player_action = 0;
    this->player_start_x = this->player_start_y = 0;
    this->player_position_x = this->player_position_y = 0;
    this->movement = 'n';
    this->game_over = false;
    this->win = false;
    this->wumpus_alive = true;
    this->wumpus_x = 0;
    this->wumpus_y = 0;

}

/*********************************************************************
** Function: ~Game()
** Description: Deletes game object
** Parameters: none
** Pre-Conditions: Game object must be out of scope. 
** Post-Conditions: 
*********************************************************************/
Game::~Game(){}

/*********************************************************************
** Function: get_win()
** Description: returns the win bool
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
bool Game::get_win() const{
    return this->win;
}

/*********************************************************************
** Function: get_movement_char()
** Description: returns the movement character that the game object 
** stored.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
char Game::get_movement_char() const{
    return this->movement;
}

/*********************************************************************
** Function: get_player_arrows()
** Description: returns the number of arrows the player has.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
int Game::get_player_arrows() const{
    return this->arrows;
}

/*********************************************************************
** Function: get_map_size()
** Description: gets the player input and returns the map size that 
** is going to be used to create the map. 
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
int Game::get_map_size(){
    int size = 5;
    cout << "Enter map size? ";
    cin >> size;
    while(size < 5){
        cout << "Error map not big enough..." << endl;
        cin >> size;
    }
    set_map_size(size);
    return size;
}

/*********************************************************************
** Function: get_player_action()
** Description: gets the player input that determines if the player 
** wants to shoot an arrow or move. 
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::get_player_action(){
    int option;
    cout << "Would you like to move (1) or fire an arrow(2): " << endl;
    cin >> option;
    while(option != 1 && option !=2){
        cout << "Error not an option please pick again... " << endl;
        cin >> option;
    }
    set_player_action(option);
}

/*********************************************************************
** Function: set_movement()
** Description: Gets the user input for movement and sets the movement 
** character for that movement.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::set_movement(){
    cout << "Move using WASD" << endl;
    cin >> this->movement;
}

/*********************************************************************
** Function: set_map_size()
** Description: Sets the map size.
** Parameters: integer
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::set_map_size(int size){
    this->map_size = size;
}

/*********************************************************************
** Function: set_starting_position()
** Description: puts the player into a random room.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::set_starting_position(){
    int rand_i = -1, rand_j = -1;

    do{
        rand_i = rand() % this->map_size;
        rand_j = rand() % this->map_size;        
    }while(!map[rand_i][rand_j].is_empty());

    this->player_position_x = rand_i;
    this->player_start_x = rand_i;    
    this->player_position_y = rand_j;
    this->player_start_y = rand_j;
}

/*********************************************************************
** Function: set_player_action()
** Description: sets the player action integer.
** Parameters: integer
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::set_player_action(int option){
    this->player_action = option;
}

/*********************************************************************
** Function: create_map()
** Description: Creates the map which is a 2d vector of Rooms
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::create_map(){
    for(int i = 0; i < this->map_size; i++){
        vector<Room> row_vec;
        for(int j = 0; j < this->map_size; j++){
            row_vec.push_back(Room());
        }
        this->map.push_back(row_vec);
    }
}

/*********************************************************************
** Function: print_map()
** Description: prints the map to the users screen without showing 
** where each event is at.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::print_map() const{
    for (int i = 0; i <this->map_size; i++){
        cout << setfill('-') << setw(this->map_size * 4) << "-" << endl;
        for (int j = 0; j < this->map_size; j++){
            cout << "  ";
            this->map[i][j].display_normal_room();
            if(i == this->player_position_x && j == this->player_position_y){
                cout << "*";
            }
        }
        cout << "  |" << endl;
    }
    cout << setfill('-') << setw(this->map_size * 4 ) << "-" << endl;
}

/*********************************************************************
** Function: print_debug_map()
** Description: prints the map to the users screen and shows where 
** each event is.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::print_debug_map() const{
    for (int i = 0; i <this->map_size; i++){
        cout << setfill('-') << setw(this->map_size * 4) << "-" << endl;
        for (int j = 0; j < this->map_size; j++){
            cout << "  ";
            this->map[i][j].display_room();
            if(i == this->player_position_x && j == this->player_position_y){
                cout << "*";
            }
        }
        cout << "  |" << endl;
    }
    cout << setfill('-') << setw(this->map_size * 4 ) << "-" << endl;    
}

/*********************************************************************
** Function: move_player()
** Description: moves the player depending on what the movement input 
** was.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::move_player(){

    set_movement();
    char move = get_movement_char();
    if (move == 'w'){
        if (in_cave(this->player_position_x-1, this->player_position_y) == true)
        {
            this->player_position_x--;
        }   
    }
    else if(move == 'a'){
         if (in_cave(this->player_position_x, this->player_position_y-1) == true)
        {
            this->player_position_y--;
        }
    }
    else if(move == 's'){
         if (in_cave(this->player_position_x+1, this->player_position_y) == true)
        {
            this->player_position_x++;
        }
    }
    else if(move == 'd'){
         if (in_cave(this->player_position_x, this->player_position_y+1) == true)
        {
            this->player_position_y++;
        }
    }
    else{
        cout << "Error not valid move..." << endl;
    }
}

/*********************************************************************
** Function: set_event_locations()
** Description: initializes the 2d array with 1 gold spot, 2 pits, 
** 2 bats, and 1 wumpus in random spots.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::set_event_locations(){  
    srand(time(NULL));
    vector<Event*> events(6);

    events.push_back(new Wumpus());
    events.push_back(new Pit());
    events.push_back(new Pit());
    events.push_back(new Bats());
    events.push_back(new Bats());
    events.push_back(new Gold());

    int rand_i = -1, rand_j = -1;

    for (int i = 0; i < 6; i++){
        do{
            rand_i = rand() % this->map_size;
            rand_j = rand() % this->map_size;
        }while (!this->map[rand_i][rand_j].is_empty());
        this->map[rand_i][rand_j].set_room_event(events.back());
        events.pop_back();
    }
}

/*********************************************************************
** Function: in_cave()
** Description: checks if a position is inside the map
** Parameters: 2 integers
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
bool Game::in_cave(int position_x, int position_y) const{
    if (position_x < 0 || position_x > this->map_size-1 || position_y < 0 || position_y > this->map_size-1){
        return false;
    }
    else{
        return true;
    }
}

/*********************************************************************
** Function: shoot_arrow()
** Description: shoots an arrow across three roooms or until it hits a 
** wall. Also determines if wumpus is killed.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::shoot_arrow(){
    int arrow_pos_x = this->player_position_x;
    int arrow_pos_y = this->player_position_y;
    int direction = -1;

    cout << "Which direction would you like to shoot?" << endl;
    cout << "(1)Up (2)Down (3)Left (4)Right " << endl;
    cin >> direction;

    if(this->arrows != 0){
        cout << "Arrow has been fired!!" << endl;
        if (direction == 1){
            this->arrows--;
            for (int i = 0; i < 3; i++){
                arrow_pos_x--;
                if (in_cave(arrow_pos_x, arrow_pos_y) == true){ 
                    if (!this->map[arrow_pos_x][arrow_pos_y].is_empty()){
                        if(this->map[arrow_pos_x][arrow_pos_y].get_event_char() == 'w'){
                            this->wumpus_alive = false;
                            this->map[arrow_pos_x][arrow_pos_y] = Room();
                            cout << "You killed the Wumpus" << endl;
                            break;
                        }
                    }
                } 
            }
            if (this->wumpus_alive == true){
                cout << "You did not hit anything" << endl;
                move_wumpus();
            }
        } 

        if (direction == 2){
            this->arrows--; 
            for (int i = 0; i < 3; i++){
                arrow_pos_x++;
                if (in_cave(arrow_pos_x, arrow_pos_y) == true){ 
                    if (!this->map[arrow_pos_x][arrow_pos_y].is_empty()){
                        if(this->map[arrow_pos_x][arrow_pos_y].get_event_char() == 'w'){
                            this->wumpus_alive = false;
                            this->map[arrow_pos_x][arrow_pos_y] = Room();
                            cout << "You killed the Wumpus" << endl;
                            break;
                        }
                    }
                }
            }
            if (this->wumpus_alive == true){
                cout << "You did not hit anything" << endl;
                move_wumpus();
            }
        } 

        if (direction == 3){
            this->arrows--;
            for (int i = 0; i < 3; i++){
                arrow_pos_y--;
                if (in_cave(arrow_pos_x, arrow_pos_y) == true){ 
                    if (!this->map[arrow_pos_x][arrow_pos_y].is_empty()){
                        if(this->map[arrow_pos_x][arrow_pos_y].get_event_char() == 'w'){
                            this->wumpus_alive = false;
                            this->map[arrow_pos_x][arrow_pos_y] = Room();
                            cout << "You killed the Wumpus" << endl;
                            break;
                        }
                    }
                }
            }
            if (this->wumpus_alive == true){
                cout << "You did not hit anything" << endl;
                move_wumpus();
            }
        }

        if (direction == 4){
            this->arrows--;
            for (int i = 0; i < 3; i++){
                arrow_pos_y++; 
                if (in_cave(arrow_pos_x, arrow_pos_y) == true){ 
                    if (!this->map[arrow_pos_x][arrow_pos_y].is_empty()){
                        if(this->map[arrow_pos_x][arrow_pos_y].get_event_char() == 'w'){
                            this->wumpus_alive = false;
                            this->map[arrow_pos_x][arrow_pos_y] = Room();
                            cout << "You killed the Wumpus" << endl;
                            break;
                        }
                    }
                }
            }
            if (this->wumpus_alive == true){
                cout << "You did not hit anything" << endl;
                move_wumpus();
            }
        }
    }
    else{
        cout << "You are out of arrows" << endl;
    }
}

/*********************************************************************
** Function: move_wumpus()
** Description: moves wumpus 75% of the time if arrow hits nothing.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::move_wumpus(){
    srand(time(NULL));
    vector <Event*> new_wump;

    new_wump.push_back(new Wumpus());
    
    char room_event;
    int new_i = -1;
    int new_j = -1;
    int will_move = rand() % 4;
    if (will_move != 4){
        cout << "You hear the Wumpus move" << endl;
        
        //gets new wumpus position;
        do{
            new_i = rand() % this->map_size;
            new_j = rand() % this->map_size;
        }while (!this->map[new_i][new_j].is_empty());
        
        //finds current wumpus and deletes it
        for (int i = 0; i < this->map_size; i++){
            for(int j = 0; j < this->map_size; j++){
                if(!this->map[i][j].is_empty()){
                    room_event = this->map[i][j].get_event_char();
                }
                if(room_event == 'w'){
                    this->wumpus_x = i;
                    this->wumpus_y = j;
                    this->map[i][j] = Room();
                    break;
                }
            }
        }

        //puts wumpus in new room
        this->map[new_i][new_j].set_room_event(new_wump.back());
        new_wump.pop_back();

    }
}

/*********************************************************************
** Function: reset_wumpus()
** Description: moves wumpus back to its orignal spot.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::reset_wumpus(){
    char room_event;

    for (int i = 0; i < this->map_size; i++){
        for(int j = 0; j < this->map_size; j++){
            if(!this->map[i][j].is_empty()){
                room_event = this->map[i][j].get_event_char();
            }
            if(room_event == 'w'){
                this->wumpus_x = i;
                this->wumpus_y = j;
                this->map[i][j] = Room();
                break;
            }
        }
    }


    vector <Event*> new_wump;

    new_wump.push_back(new Wumpus());

    this->map[this->wumpus_x][this->wumpus_y].set_room_event(new_wump.back());
    new_wump.pop_back();
}

/*********************************************************************
** Function: check_even()
** Description: checks if the room the player is in contains an event.
** it also executes the event. 
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::check_event(){
    char room_event;
    int rand_y = -1;
    int rand_x = -1;
    if (!this->map[this->player_position_x][this->player_position_y].is_empty()){
        room_event = this->map[this->player_position_x][this->player_position_y].get_event_char();
        if (room_event == 'w'){
            this->win = false;
            this->game_over = true;
            cout << "The wumpus just ate you...Game Over" << endl;
        }
        else if(room_event == 'p'){
            this->win = false;
            this->game_over = true;
            cout << "You just fell down a bottomeless pit you have died... Game Over" << endl;
        }
        else if(room_event == 'g'){
            this->num_gold++;
            this->map[this->player_position_x][this->player_position_y] = Room();
            cout << "Congrats you found the gold" << endl;
        }
        else if (room_event == 'b'){
            do{
                rand_x = rand() % this->map_size;
                rand_y = rand() % this->map_size;
            }while (!this->map[rand_x][rand_y].is_empty());
            this->player_position_x = rand_x;
            this->player_position_y = rand_y;
            cout << "The superbats just dropped you to a new room" << endl;
        }
    }
}

/*********************************************************************
** Function: check_nearby()
** Description: checks if a room adjacent to the players position has 
** an event and prints the near message to the screen. 
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::check_nearby() const{
    srand(time(NULL));
    int up_x = this->player_position_x+1;
    int down_x = this->player_position_x-1;
    int up_y = this->player_position_y+1;
    int down_y = this->player_position_y-1;

    if (in_cave(up_x, this->player_position_y)){
        if (!this->map[up_x][this->player_position_y].is_empty()){
            this->map[up_x][this->player_position_y].display_near_message();
        }
    }
    if (in_cave(down_x, this->player_position_y)){
        if (!this->map[down_x][this->player_position_y].is_empty()){
            this->map[down_x][this->player_position_y].display_near_message();
        }
    }
    if (in_cave(this->player_position_x, up_y)){
        if(!this->map[this->player_position_x][up_y].is_empty()){
            this->map[this->player_position_x][up_y].display_near_message();
        }
    }
    if (in_cave(this->player_position_x, down_y)){
        if(!this->map[this->player_position_x][down_y].is_empty()){
            this->map[this->player_position_x][down_y].display_near_message();
        }
    }
}

/*********************************************************************
** Function: win_loss_play_again()
** Description: prints game over message and asks user if they want to 
** play again.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
int Game::win_loss_play_again() const{
    if (this->win == false){
        cout << "Game Over... tough Loss :(" << endl;
    }
    if (this->win == true){
        cout << "Congrats you won!!" << endl;
    }

    int option;
    cout << "Would you like to play again" << endl;
    cout << "(1)yes (2)no" << endl;
    cin >> option;

    return option;
}

/*********************************************************************
** Function: start_game_normal()
** Description: starts the game in normal mode where the player cannot 
** see where the events are ar. 
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::start_game_normal(){
    int again = -1;
    get_map_size();
    create_map();
    set_event_locations();
    set_starting_position();

    do{
        print_map();
        get_player_action();
        if(this->player_action == 1){
            system("stty -echo");
            system("stty cbreak");
            move_player();
            system("stty -echo");
            system("stty cbreak");
            check_event();
            check_nearby();
        }
        if (this->player_action == 2){
            shoot_arrow();
            check_event();
        }
        check_win();
        if (this->game_over == true){
            again = win_loss_play_again();
            if (again == 1){
                reset_wumpus();
                this->game_over = false;
                this->num_gold = 0;
                this->player_position_x = this->player_start_x;
                this->player_position_y = this->player_start_y;
            }
        }
    }while(this->game_over == false);
    
}

/*********************************************************************
** Function: debug_normal()
** Description: asks player if they want to play in normal or debug mode.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
int Game::debug_normal(){
    int option;
    cout << "Would you like to play in normal mode or debug mode." << endl;
    cout << "(1)Normal (2)debug: ";
    cin >> option;
    while (option > 2 || option <= 0){
        cout << "Error not an option...";
        cin >> option;
    }
    return option;
}

/*********************************************************************
** Function: start_game_debug()
** Description: starts the game where player can see where 
all the events are.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game::start_game_debug(){
    int again = -1;
    get_map_size();
    create_map();
    set_event_locations();
    set_starting_position();

    do{
        print_debug_map();
        get_player_action();

        if(this->player_action == 1){
            system("stty -echo");
            system("stty cbreak");
            move_player();
            system("stty -echo");
            system("stty cbreak");
            check_event();
            check_nearby();
        }

        if (this->player_action == 2){
            shoot_arrow();
            check_event();
        }

        check_win();

        if (this->game_over == true){
            again = win_loss_play_again();
            if (again == 1){
                reset_wumpus();
                this->game_over = false;
                this->num_gold = 0;
                this->player_position_x = this->player_start_x;
                this->player_position_y = this->player_start_y;
            }
        }
    }while(this->game_over == false);
    
}

/*********************************************************************
** Function: check_win()
** Description: checks if player meets the requirements to win the game.
** Parameters: none
** Pre-Conditions: Game object must be in scope and initialized. 
** Post-Conditions: 
*********************************************************************/
void Game:: check_win(){
    if(this->num_gold >= 1 && this->wumpus_alive == false && this->player_position_x == this->player_start_x && this->player_position_y == this->player_start_y){
        this->win = true;
        this->game_over = true;
    }
    else{
        this->win = false;
    }
}