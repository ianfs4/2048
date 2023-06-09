#pragma once

#include <ge211.hxx>
#include "board.hxx"

class Model
{
public:
    Model(bool empty);

    void play_move(char);

    bool is_game_over() const;

    bool is_game_won() const;

    int get_score() const;

    void set_continued(bool);

    /// for testing
    int get_value(int r, int c) const
    { return board_.get_value(r,c); }

    void set_value(int r, int c, int value);

private:
    Board board_;

    bool continued_;

    void move_left_();

    void move_up_();

    void move_right_();

    void move_down_();

    bool compare_(Board board1);

    void rotate_(int);

    void reverse_();

    void compress_();

    void merge_();
};
