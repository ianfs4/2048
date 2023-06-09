#pragma once

#include "model.hxx"

class View
{
public:

    using Posn = ge211::Posn<int>;

    using Color = ge211::Color;

    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

private:
    Model const& model_;

    int const margins_[5];

    ge211::Rectangle_sprite const gray_background_;
    ge211::Rectangle_sprite const gray_square_;
    ge211::Rectangle_sprite const game_over_overlay_;
    ge211::Rectangle_sprite const two_;
    ge211::Rectangle_sprite const four_;
    ge211::Rectangle_sprite const eight_;
    ge211::Rectangle_sprite const sixteen_;
    ge211::Rectangle_sprite const thirtytwo_;
    ge211::Rectangle_sprite const sixtyfour_;
    ge211::Rectangle_sprite const onetwentyeight_;
    ge211::Rectangle_sprite const twofiftysix_;
    ge211::Rectangle_sprite const fivetwelve_;
    ge211::Rectangle_sprite const onezerotwofour_;
    ge211::Rectangle_sprite const twozerofoureight_;
    ge211::Rectangle_sprite const fourzeroninesix_;
    ge211::Rectangle_sprite const eightoneninetwo_;
    ge211::Rectangle_sprite const onesixthreeeightfour_;
    ge211::Rectangle_sprite const threetwosevensixeight_;
    ge211::Rectangle_sprite const unknown_tile_;

    ge211::Text_sprite two_text_;
    ge211::Text_sprite four_text_;
    ge211::Text_sprite eight_text_;
    ge211::Text_sprite sixteen_text_;
    ge211::Text_sprite thirtytwo_text_;
    ge211::Text_sprite sixtyfour_text_;
    ge211::Text_sprite onetwentyeight_text_;
    ge211::Text_sprite twofiftysix_text_;
    ge211::Text_sprite fivetwelve_text_;
    ge211::Text_sprite onezerotwofour_text_;
    ge211::Text_sprite twozerofoureight_text_;
    ge211::Text_sprite fourzeroninesix_text_;
    ge211::Text_sprite eightoneninetwo_text_;
    ge211::Text_sprite onesixthreeeightfour_text_;
    ge211::Text_sprite threetwosevensixeight_text_;
    ge211::Text_sprite unknown_tile_text_;

    ge211::Text_sprite game_over_text_;
    ge211::Text_sprite game_won_text_;
    ge211::Text_sprite quit_text_;
    ge211::Text_sprite continue_text_;

    ge211::Text_sprite score_text_;
    ge211::Text_sprite score_num_;



    ge211::Text_sprite text_generate_(int, Color);
    ge211::Text_sprite string_text_generate_(std::string, Color, int size=50);
};
