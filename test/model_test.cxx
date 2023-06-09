#include "model.hxx"
#include <catch.hxx>


//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate your functional requirements.
//



TEST_CASE("Initialize 4x4 board, 2 tiles, check tile gen,  (1, 3, 10)")
{
    Model m(false);
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (m.get_value(i, j) != 0){
                //increments count if tile is not empty
                count++;
            }
        }
    }
    CHECK(count == 2); //checks two initial tiles

    m.play_move('w');  // moves once

    int move_count = 0;
    int score = m.get_score();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (m.get_value(i, j) != 0){
                move_count++; //counts post move tiles
            }
        }
    }

    //after additional move,
    // either 3 pieces or (no merge)
    // 2 pieces with non-zero score (merged)
    if (move_count == 2) {
        CHECK(score > 0); //2 tiles mean merge happened, score should be > 0
    } else {
        CHECK(move_count == 3); // 3 tiles, no merge, move_count should be 3
    }

}

TEST_CASE("Tile movement and Merging, (4, 6)")
{
    Model m(true);
    //left col, top 2 rows have '2' in them
    m.set_value(0, 0, 2);
    m.set_value(1, 0, 2);
    //moves down, bottom right should be '4'
    m.play_move('s');
    CHECK(m.get_value(0, 0) == 0);
    CHECK(m.get_value(1, 0) == 0);
    CHECK(m.get_value(2, 0) == 0);
    CHECK(m.get_value(3, 0) == 4);
}

TEST_CASE("Win Condition (8)")
{
    Model m(true);
    //there is a piece on the board that is '512' (win condition)
    m.set_value(0, 0, 512);
    CHECK(m.is_game_won() == true);
}

TEST_CASE("Lose Condition (9)")
{
    Model m(true);
    //TL;DR, alternates board with 2 and 4 so no moves possible
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i % 2 == 0) { // row index is even
                if (j % 2 == 0) { // col index is even
                    m.set_value(i, j, 2);
                } else { // col index is odd
                    m.set_value(i, j, 4);
                }
            } else { // row index is odd
                if (j % 2 == 0) { // if column index is even
                    m.set_value(i, j, 4);
                } else { // col index is odd
                    m.set_value(i, j, 2);
                }
            }
        }
    }
    // verify all cells not empty
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            CHECK(m.get_value(i, j) != 0);
        }
    }
    //checks if game is over
    CHECK(m.is_game_over() == true);
}

TEST_CASE("Score tracking (7)")
{
    Model m(true);
    CHECK(m.get_score() == 0);
    //merges two tiles with value '2'
    m.set_value(0, 0, 2);
    m.set_value(1, 0, 2);
    //should be one tile with value '4' now, thus also increasing score by 4
    m.play_move('s');
    //check if the score is 4
    CHECK(m.get_score() == 4);
}