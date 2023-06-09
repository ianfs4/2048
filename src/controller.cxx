#include "controller.hxx"

Controller::Controller()
        : model_(false),
          view_(model_)
{ }

void
Controller::on_key(ge211::Key key)
{
    char code = key.code();
    if(code == 'q') {
        quit();
    }
    // player continues after getting 2048
    if(code == 'c') {
        if(model_.is_game_won()) {
            model_.set_continued(true);
        }
    }
    if (!model_.is_game_over() && !model_.is_game_won()){
        if (key == ge211::Key::up() || code =='w') {
            model_.play_move('w');
        } else if (key == ge211::Key::left() || code =='a') {
            model_.play_move('a');
        } else if (key == ge211::Key::down() || code =='s') {
            model_.play_move('s');
        } else if (key == ge211::Key::right() || code =='d') {
            model_.play_move('d');
        }
    }
}

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}
