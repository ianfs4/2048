/*******************************************/
/*** DO NOT CHANGE ANYTHING IN THIS FILE ***/
/*******************************************/

#include <ge211.hxx>
#include "board.hxx"
#include <algorithm>

using namespace ge211;

Board::Board(bool testing)
        : score_(0),
          testing_(testing)
{
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            values_[r][c] = 0;
        }
    }

    spawn_tile();
    spawn_tile();
}

int
Board::get_value(int r, int c) const
{
    return values_[r][c];
}

void
Board::set_value(int r, int c, int value)
{
    values_[r][c] = value;
}

void
Board::spawn_tile()
{
    /// if testing is turned on, we want to control where the tiles
    /// are spawned
    if (testing_) {
        return;
    }

    int i = ge211::Random_source<int>(0,3).next();
    int j = ge211::Random_source<int>(0,3).next();
    int v = ge211::Random_source<int>(0, 99).next() < 90 ? 2 : 4;

    /// tiles should only spawn on an empty square
    while (values_[i][j] != 0) {
        i = ge211::Random_source<int>(0,3).next();
        j = ge211::Random_source<int>(0,3).next();
    }
    values_[i][j] = v;
}

// doubles left tile and sets right tile to zero
// score is incremented the new value of values_[r][c]
void
Board::double_tile(int r, int c)
{
    values_[r][c] *= 2;
    values_[r][c+1] = 0;

    score_ += values_[r][c];
}

void
Board::print_board()
{
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            std::cout << values_[r][c] << "|";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int
Board::get_score() const
{
    return score_;
}