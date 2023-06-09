/*******************************************/
/*** DO NOT CHANGE ANYTHING IN THIS FILE ***/
/*******************************************/

#pragma once

#include <ge211.hxx>

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/// Represents the state of the board.
class Board
{
public:
    //
    // HELPFUL TYPE ALIASES
    //

    explicit Board(bool testing);

    int get_value(int r, int c) const;

    void set_value(int r, int c, int value);

    void spawn_tile();

    void double_tile(int r, int c);

    void print_board();
    int get_score() const;

private:
    //
    // PRIVATE DATA MEMBERS
    //

    int values_[4][4];

    int score_;

    bool testing_;
};