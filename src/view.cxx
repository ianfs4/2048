#include "view.hxx"

#include <math.h>

//variables
static int const grid_size = 130;
static int const screen_width = 1024;
static int const screen_height = 768;

View::View(Model const& model)
        : model_(model),
          margins_{73, 60, 45, 30, 17},
          gray_background_({screen_width, screen_height}, Color(128, 128, 128)),
          gray_square_({grid_size,grid_size}, Color(196, 196, 196)),
          game_over_overlay_({screen_width, screen_height}, Color(255,255,
                                                                  255,150)),
          two_({grid_size,grid_size}, Color(228, 224, 238)),
          four_({grid_size,grid_size}, Color(204, 196, 223)),
          eight_({grid_size,grid_size}, Color(164, 149, 195)),
          sixteen_({grid_size,grid_size}, Color(147, 128, 182)),
          thirtytwo_({grid_size,grid_size}, Color(131, 110, 170)),
          sixtyfour_({grid_size,grid_size}, Color(118, 93, 160)),
          onetwentyeight_({grid_size,grid_size}, Color(104, 76, 150)),
          twofiftysix_({grid_size,grid_size}, Color(91, 59, 140)),
          fivetwelve_({grid_size,grid_size}, Color(78, 42, 132)),
          onezerotwofour_({grid_size,grid_size}, Color(60, 32, 102)),
          twozerofoureight_({grid_size,grid_size}, Color(45, 24, 75)),
          fourzeroninesix_({grid_size,grid_size}, Color(33, 9, 64)),
          eightoneninetwo_({grid_size,grid_size}, Color(0, 0, 0)),
          onesixthreeeightfour_({grid_size,grid_size}, Color(255, 128, 255)),
          threetwosevensixeight_({grid_size,grid_size}, Color(255, 64, 255)),
          unknown_tile_({grid_size,grid_size}, Color(255, 0, 0)),

          two_text_(text_generate_(2, Color::black())),
          four_text_(text_generate_(4, Color::black())),
          eight_text_(text_generate_(8, Color::black())),
          sixteen_text_(text_generate_(16, Color::black())),
          thirtytwo_text_(text_generate_(32, Color::white())),
          sixtyfour_text_(text_generate_(64, Color::white())),
          onetwentyeight_text_(text_generate_(128, Color::white())),
          twofiftysix_text_(text_generate_(256, Color::white())),
          fivetwelve_text_(text_generate_(512, Color::white())),
          onezerotwofour_text_(text_generate_(1024, Color::white())),
          twozerofoureight_text_(text_generate_(2048, Color::white())),
          fourzeroninesix_text_(text_generate_(4096, Color::white())),
          eightoneninetwo_text_(text_generate_(8192, Color::white())),
          onesixthreeeightfour_text_(text_generate_(16384, Color::white())),
          threetwosevensixeight_text_(text_generate_(32768, Color::white())),
          unknown_tile_text_(string_text_generate_("?", Color(96, 0, 0),
                                                   100)),
          game_over_text_(string_text_generate_("GAME OVER", Color::black())),
          game_won_text_(string_text_generate_("YOU WIN!", Color(78, 42, 132))),
          quit_text_(string_text_generate_("Press 'q' to quit", Color::black
          (), 20)),
          continue_text_(string_text_generate_("Press 'c' to continue",
                                               Color::black(), 20)),
          score_text_(string_text_generate_("Score:", Color::black())),
          score_num_(string_text_generate_(std::to_string(model_.get_score()),
                                           Color::black()))

{}

void
View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(gray_background_,{0,0},0);
    for (int r = 0; r < 4; r++) {
        for (int c = 0;  c < 4; c++) {
            Posn screen_coords = {(grid_size + 10) * c + 22, (grid_size + 10)
                                  * r + 22};

            set.add_sprite(gray_square_, screen_coords,1);

            set.add_sprite(score_text_, {(screen_width / 3) + 270,
                                         (screen_height / 4) + 35}, 2);

            score_num_ = text_generate_(model_.get_score(),Color::black());

            set.add_sprite(score_num_, {(screen_width / 3) + 270,
                                        (screen_height / 4) + 85}, 2);

            int val = model_.get_value(r,c);

            if (val != 0) {
                int digits = (int) log10(val);

                // prevents memory error
                if (digits > 4) {
                    digits = 4;
                }

                Posn text_coords = {(grid_size + 10) * c + margins_[digits],
                                    (grid_size + 10) * r + 40};

                switch (val) {
                case 2:
                    set.add_sprite(two_, screen_coords, 2);
                    set.add_sprite(two_text_, text_coords, 3);
                    break;
                case 4:
                    set.add_sprite(four_, screen_coords, 2);
                    set.add_sprite(four_text_, text_coords, 3);
                    break;
                case 8:
                    set.add_sprite(eight_, screen_coords, 2);
                    set.add_sprite(eight_text_, text_coords, 3);
                    break;
                case 16:
                    set.add_sprite(sixteen_, screen_coords, 2);
                    set.add_sprite(sixteen_text_, text_coords, 3);
                    break;
                case 32:
                    set.add_sprite(thirtytwo_, screen_coords, 2);
                    set.add_sprite(thirtytwo_text_, text_coords, 3);
                    break;
                case 64:
                    set.add_sprite(sixtyfour_, screen_coords, 2);
                    set.add_sprite(sixtyfour_text_, text_coords, 3);
                    break;
                case 128:
                    set.add_sprite(onetwentyeight_, screen_coords, 2);
                    set.add_sprite(onetwentyeight_text_, text_coords, 3);
                    break;
                case 256:
                    set.add_sprite(twofiftysix_, screen_coords, 2);
                    set.add_sprite(twofiftysix_text_, text_coords, 3);
                    break;
                case 512:
                    set.add_sprite(fivetwelve_, screen_coords, 2);
                    set.add_sprite(fivetwelve_text_, text_coords, 3);
                    break;
                case 1024:
                    set.add_sprite(onezerotwofour_, screen_coords, 2);
                    set.add_sprite(onezerotwofour_text_,
                                   text_coords, 3);
                    break;
                case 2048:
                    set.add_sprite(twozerofoureight_, screen_coords, 2);
                    set.add_sprite(twozerofoureight_text_,
                                   text_coords, 3);
                    break;
                case 4096:
                    set.add_sprite(fourzeroninesix_, screen_coords, 2);
                    set.add_sprite(fourzeroninesix_text_,
                                   text_coords, 3);
                    break;
                case 8192:
                    set.add_sprite(eightoneninetwo_, screen_coords, 2);
                    set.add_sprite(eightoneninetwo_text_,
                                   text_coords, 3);
                    break;
                case 16384:
                    set.add_sprite(onesixthreeeightfour_, screen_coords, 2);
                    set.add_sprite(onesixthreeeightfour_text_,
                                   text_coords, 3);
                    break;
                case 32768:
                    set.add_sprite(threetwosevensixeight_, screen_coords, 2);
                    set.add_sprite(threetwosevensixeight_text_,
                                   text_coords, 3);
                    break;
                default:
                    text_coords = {(grid_size + 10) * c + 56,
                                   (grid_size + 10) * r};

                    set.add_sprite(unknown_tile_, screen_coords, 2);
                    set.add_sprite(unknown_tile_text_, text_coords, 3);
                }
            }
        }
    }

    if (model_.is_game_over() || model_.is_game_won()) {
        set.add_sprite(game_over_overlay_, {0,0}, 4);
        set.add_sprite(quit_text_, {642, 565}, 5);
    }

    if (model_.is_game_over()) {
        set.add_sprite(game_over_text_, {screen_width / 4,
                       screen_height / 3}, 5);
    }

    if (model_.is_game_won()) {
        set.add_sprite(game_won_text_, {screen_width / 4,
                       screen_height / 3}, 5);
        set.add_sprite(continue_text_, {20, 565}, 5);
    }
}


ge211::Text_sprite
View::text_generate_(int val, ge211::Color color)
{
    ge211::Text_sprite text_sprite;

    ge211::Font sans50{"sans.ttf",50};
    ge211::Text_sprite::Builder string_build(sans50);

    string_build.color(color) << val;
    text_sprite.reconfigure(string_build);

    return text_sprite;
}

ge211::Text_sprite
View::string_text_generate_(std::string val, ge211::Color color, int size)
{
    ge211::Text_sprite text_sprite;

    ge211::Font sans{"sans.ttf",size};
    ge211::Text_sprite::Builder string_build(sans);

    string_build.color(color) << val;
    text_sprite.reconfigure(string_build);

    return text_sprite;
}