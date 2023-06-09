#include "model.hxx"

Model::Model(bool empty)
        : board_(empty),
          continued_(false)
{}

void
Model::play_move(char direction)
{
    Board copy = board_;

    switch(direction) {
    case 'w':
        move_up_();
        break;
    case 'a':
        move_left_();
        break;
    case 's':
        move_down_();
        break;
    case 'd':
        move_right_();
        break;
    default:
        return;
    }

    if(!compare_(copy)) {
        board_.spawn_tile();
    }

    board_.print_board();
}

/// tells you whether the board is full
bool
Model::is_game_over() const
{
    // empty cells, game not over
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(board_.get_value(i, j) == 0) {
                return false;
            }
        }
    }

    // any side by side cells, game not over
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            if(board_.get_value(i, j) == board_.get_value(i, j + 1) ||
               board_.get_value(j, i) == board_.get_value(j + 1, i)) {
                return false;
            }
        }
    }

    // none empty, no moves, game over is true
    return true;
}

bool
Model::is_game_won() const
{
    if(!continued_) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board_.get_value(i, j) == 2048) {
                    return true;
                }
            }
        }
    }
    return false;
}

/// Score getter
int
Model::get_score() const
{
    return board_.get_score();
}

/// Changes value of continued_
void
Model::set_continued(bool continued)
{
    continued_ = continued;
}

void
Model::move_left_()
{
    compress_();
    merge_();
}

void
Model::move_up_()
{
    rotate_(3);

    move_left_();

    rotate_(1);
}

void
Model::move_right_()
{
    reverse_();

    move_left_();

    reverse_();
}

void
Model::move_down_()
{
    rotate_(1);

    move_left_();

    rotate_(3);
}


bool
Model::compare_(Board board1)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board_.get_value(i,j) != board1.get_value(i,j)) {
                return false;
            }
        }
    }

    return true;
}

void
Model::rotate_(int count)
{
    Board board = board_;

    for (int i = 0; i < count; i++) {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                board_.set_value(row, col, board.get_value(3-col, row));
            }
        }

        board = board_;
    }
}

void
Model::reverse_()
{
    Board board = board_;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            board_.set_value(r,c,board.get_value(r,3-c));
        }
    }
}

void
Model::compress_()
{
    Board board = board_;
    for (int r = 0; r < 4; r++) {
        int pos = 0;
        for (int c = 0; c < 4; c++) {
            if(board.get_value(r,c) != 0) {
                // first non-zero value is moved to the first position
                board_.set_value(r,pos,board_.get_value(r,c));

                // empties original position
                if (c != pos) {
                    board_.set_value(r, c, 0);
                }

                pos++;
            }
        }
    }
}

void
Model::merge_()
{
    Board board = board_;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 3; c++) {
            if (board_.get_value(r,c) != 0 && board_.get_value(r,c) == board_
                    .get_value(r,c+1)) {
                board_.double_tile(r,c);
            }
        }
    }

    // std::cout << "BEFORE MERGE\n";
    // board.print_board();
    // std::cout << "AFTER MERGE\n";
    // board_.print_board();

    // if any tiles were merged, we must compress again
    if (!compare_(board)) {
        compress_();
    }

}

void
Model::set_value(int r, int c, int value)
{
    board_.set_value(r, c, value);
}