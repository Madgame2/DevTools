#include"Header.h"
#include"menu_bar.h"
#include"Button.h"
#include"Radio_button.h"
#include"text_label.h"

#define Win_width 1200.0
#define Win_height 800.0

int page_id = 0;

Sprite background_sprite;
Texture background;
Font font;

/*-----------encoder-------------*/
Radio_button encoder_radio_button(4);

textLabel encoder_enter_lable(400, 300,400, 50, "defoult_text");
textLabel encoder_exit_lable(400, 500, 400, 50, "defoult_text");
Button encoder_conver_button("img\\ConvertorCHAR.png", "img\\convertorActive.png");

/*-----------convertor to scale of nation-------------*/
textLabel convertor_BIN(400, 220, 400, 50, "defoult_text");
textLabel convertor_OCT(400, 330, 400, 50, "defoult_text");
textLabel convertor_DEC(400, 440, 400, 50, "defoult_text");
textLabel convertor_HEX(400, 550, 400, 50, "defoult_text");


Text BIN_text(L"ƒ‚ÓË˜Ì‡ˇ", font, 30);
Text OCT_text(L"¬ÓÒ¸ÏÂË˜Ì‡ˇ", font, 30);
Text DEC_text(L"ƒÂÒˇÚË˜Ì‡ˇ", font, 30);
Text HEX_text(L"ÿÂÒÚÌ‡‰ˆ‡ÚËË˜Ì‡ˇ", font, 30);

Button convertor_scale_of_nation_button("img\\ConvertorCHAR.png", "img\\convertorActive.png");

Button BIN_copy_button("img\\copy.png", "img\\copyActive.png");
Button OCT_copy_button("img\\copy.png", "img\\copyActive.png");
Button DEC_copy_button("img\\copy.png", "img\\copyActive.png");
Button HEX_copy_button("img\\copy.png", "img\\copyActive.png");

Button encode_scale_of_nation_reset_button("img\\ArrowClockwise.png","img\\ArrowClockwiseActive.png");

/*-----------convertor to scale of nation-------------*/
textLabel math_sytem_lable_BIT(250,250,300,40,"");
textLabel math_sytem_lable_BYTE(650, 250, 300, 40, "");
textLabel math_sytem_lable_KBYTE(250, 350, 300, 40, "");
textLabel math_sytem_lable_MBYTE(650, 350, 300, 40, "");
textLabel math_sytem_lable_GBYTE(250, 450, 300, 40, "");
textLabel math_sytem_lable_TBYTE(650, 450, 300, 40, "");

Text BIT_text(L"¡ËÚ", font, 30);
Text BYTE_text(L"¡‡ÈÚ", font, 30);
Text KBYTE_text(L" ËÎÓ·‡ÈÚ", font, 30);
Text MBYTE_text(L"ÃÂ„‡·‡ÈÚ", font, 30);
Text GBYTE_text(L"√Ë„‡·‡ÈÚ", font, 30);
Text TBYTE_text(L"“Â‡·‡ÈÚ", font, 30);

Button   BIT_copy_button("img\\copy.png", "img\\copyActive.png");
Button  BYTE_copy_button("img\\copy.png", "img\\copyActive.png");
Button KBYTE_copy_button("img\\copy.png", "img\\copyActive.png");
Button MBYTE_copy_button("img\\copy.png", "img\\copyActive.png");
Button GBYTE_copy_button("img\\copy.png", "img\\copyActive.png");
Button TBYTE_copy_button("img\\copy.png", "img\\copyActive.png");

Button math_system_convert_button("img\\ConvertorCHAR.png", "img\\convertorActive.png");

Button math_system_RESET_button("img\\ArrowClockwise.png", "img\\ArrowClockwiseActive.png");

/*-----------convertor to machine code-------------*/
textLabel Dec_code    (240, 280, 300, 60, "");
textLabel reverse_code(660, 280, 300, 60, "");
textLabel Simple_code (240, 440, 300, 60, "");
textLabel extra_code  (660, 440, 300, 60, "");

Text dec_text(L"ƒÂÒˇÚË˜Ì˚È",font,30);
Text simple_text(L"œˇÏÓÈ ÍÓ‰", font, 30);
Text reverse_text(L"Œ·‡Ì˚È ÍÓ‰", font, 30);
Text extra_text(L"ƒÓÔ. ÍÓ‰", font, 30);

Button copy_button_dec("img\\copy.png", "img\\copyActive.png");
Button copy_button_simple("img\\copy.png", "img\\copyActive.png");
Button copy_button_reverse("img\\copy.png", "img\\copyActive.png");
Button copy_button_extra("img\\copy.png", "img\\copyActive.png");

Button machine_code_convert_button("img\\ConvertorCHAR.png", "img\\convertorActive.png");

Button machine_code_RESET_button("img\\ArrowClockwise.png", "img\\ArrowClockwiseActive.png");

/*-----------convertor to machine code-------------*/

textLabel first_label_atithm_operations(200, 280, 300, 60," ");
textLabel second_label_arithm_operations(200, 400, 300, 60, " ");
textLabel result_lable_arithm_operaations(700, 340, 300, 60, " ");

Button plus_button("img\\BtnPlus.png","img\\BtnPlusActive.png");
Button minus_button("img\\BtnMINUS.png", "img\\BtnMinusActive.png");
Button multiplication_button("img\\BtnUmnoz.png", "img\\BtnActiveUmnoz.png");
Button division_button("img\\BtnDel.png", "img\\btnActiveDel.png");

Button convert_button_arithmetic("img\\Button.png", "img\\ArithmetiqActive.png");
Button RESET_button_arithmetic("img\\ArrowClockwise.png", "img\\ArrowClockwiseActive.png");

Text first_lable_arithmetic(L"First", font, 15);
Text second_lable_arithmetic(L"Second", font, 15);
Text result_lable_arithmetic(L"Result", font, 15);

void build_main_page(int page_id) {

    font.loadFromFile("arialmt.ttf");

    switch (page_id)
    {   
    case 0:
       
       background.loadFromFile("img\\Rectangle 1.png");
       background.setSmooth(true);

       background_sprite.setTexture(background);
       background_sprite.setOrigin(0, 0);
       background_sprite.setPosition(0, 0);
       background_sprite.setScale(
           Win_width/background_sprite.getTexture()->getSize().x,
           Win_height/background_sprite.getTexture()->getSize().y
           );

       encoder_radio_button.set_buttons_size(24, 24);
       encoder_radio_button.get_button(0)->set_position(390, 235.5);
       encoder_radio_button.get_button(1)->set_position(500, 235.5);
       encoder_radio_button.get_button(2)->set_position(595, 235.5);
       encoder_radio_button.get_button(3)->set_position(685, 235.5);

       encoder_radio_button.set_button_active(0);

       encoder_conver_button.set_position(500, 400);
       encoder_conver_button.set_size(200, 60);

       encoder_enter_lable.clear_all();
       encoder_exit_lable.clear_all();

        break;
    case 1:
        background.loadFromFile("img\\back.png");
        background.setSmooth(true);

        background_sprite.setTexture(background);
        background_sprite.setOrigin(0, 0);
        background_sprite.setPosition(0, 0);
        background_sprite.setScale(
                                    Win_width / background_sprite.getTexture()->getSize().x,
                                    Win_height / background_sprite.getTexture()->getSize().y
                                  );
        
        BIN_text.setFillColor(Color(128, 128, 128));
        OCT_text.setFillColor(Color(128, 128, 128));
        DEC_text.setFillColor(Color(128, 128, 128));
        HEX_text.setFillColor(Color(128, 128, 128));

        BIN_text.setPosition(520, 170);
        OCT_text.setPosition(490, 280);
        DEC_text.setPosition(510, 390);
        HEX_text.setPosition(460, 500);

        convertor_scale_of_nation_button.set_position(500, 620);
        convertor_scale_of_nation_button.set_size(200, 60);

        BIN_copy_button.set_position(820, 225);
        OCT_copy_button.set_position(820, 335);
        DEC_copy_button.set_position(820, 445);
        HEX_copy_button.set_position(820, 555);

        BIN_copy_button.set_size(55, 35);
        OCT_copy_button.set_size(55, 35);
        DEC_copy_button.set_size(55, 35);
        HEX_copy_button.set_size(55, 35);

        encode_scale_of_nation_reset_button.set_position(720,625);
        encode_scale_of_nation_reset_button.set_size(50,50);

        convertor_BIN.set_symbols_limit(32);
        convertor_OCT.set_symbols_limit(32);
        convertor_DEC.set_symbols_limit(32);
        convertor_HEX.set_symbols_limit(32);

        convertor_BIN.clear_all();
        convertor_OCT.clear_all();
        convertor_DEC.clear_all();
        convertor_HEX.clear_all();

        break;
    case 2:
        background.loadFromFile("img\\back_bytes.png");
        background.setSmooth(true);

        background_sprite.setTexture(background);
        background_sprite.setOrigin(0, 0);
        background_sprite.setPosition(0, 0);
        background_sprite.setScale(
            Win_width / background_sprite.getTexture()->getSize().x,
            Win_height / background_sprite.getTexture()->getSize().y
        );

        math_sytem_lable_BIT.set_font_size(25);
        math_sytem_lable_BYTE.set_font_size(25);
        math_sytem_lable_KBYTE.set_font_size(25);
        math_sytem_lable_MBYTE.set_font_size(25);
        math_sytem_lable_GBYTE.set_font_size(25);
        math_sytem_lable_TBYTE.set_font_size(25);

        math_sytem_lable_BIT.set_symbols_limit(16);
        math_sytem_lable_BYTE.set_symbols_limit(16);
        math_sytem_lable_KBYTE.set_symbols_limit(16);
        math_sytem_lable_MBYTE.set_symbols_limit(16);
        math_sytem_lable_GBYTE.set_symbols_limit(16);
        math_sytem_lable_TBYTE.set_symbols_limit(16);


        BIT_text.setFillColor(Color(128, 128, 128));
        BYTE_text.setFillColor(Color(128, 128, 128));
        KBYTE_text.setFillColor(Color(128, 128, 128));
        MBYTE_text.setFillColor(Color(128, 128, 128));
        GBYTE_text.setFillColor(Color(128, 128, 128));
        TBYTE_text.setFillColor(Color(128, 128, 128));

        BIT_text.setPosition(360, 210);
        BYTE_text.setPosition(760, 210);
        KBYTE_text.setPosition(330, 310);
        MBYTE_text.setPosition(730, 310);
        GBYTE_text.setPosition(330, 410);
        TBYTE_text.setPosition(730, 410);

        BIT_copy_button.set_size(55, 35);
        BYTE_copy_button.set_size(55, 35);
        KBYTE_copy_button.set_size(55, 35);
        MBYTE_copy_button.set_size(55, 35);
        GBYTE_copy_button.set_size(55, 35);
        TBYTE_copy_button.set_size(55, 35);

        BIT_copy_button.set_position(560,252);
        BYTE_copy_button.set_position(960, 252);
        KBYTE_copy_button.set_position(560, 352);
        MBYTE_copy_button.set_position(960, 352);
        GBYTE_copy_button.set_position(560, 452);
        TBYTE_copy_button.set_position(960, 452);

        math_system_convert_button.set_size(200, 55);
        math_system_convert_button.set_position(480, 580);

        math_system_RESET_button.set_size(50, 50);
        math_system_RESET_button.set_position(690, 582);

        math_sytem_lable_BIT.clear_all();
        math_sytem_lable_BYTE.clear_all();
        math_sytem_lable_KBYTE.clear_all();
        math_sytem_lable_MBYTE.clear_all();
        math_sytem_lable_GBYTE.clear_all();
        math_sytem_lable_TBYTE.clear_all();
        break;

    case 3:
        background.loadFromFile("img\\back_arithm.png");
        background.setSmooth(true);

        background_sprite.setTexture(background);
        background_sprite.setOrigin(0, 0);
        background_sprite.setPosition(0, 0);
        background_sprite.setScale(
            Win_width / background_sprite.getTexture()->getSize().x,
            Win_height / background_sprite.getTexture()->getSize().y
        );

        plus_button.set_position(550,250);
        minus_button.set_position(550,320);
        multiplication_button.set_position(550,390);
        division_button.set_position(550,460);

        plus_button.set_swictch_mode(true);
        minus_button.set_swictch_mode(true);
        multiplication_button.set_swictch_mode(true);
        division_button.set_swictch_mode(true);

        plus_button.set_disactive();
        minus_button.set_disactive();
        multiplication_button.set_disactive();
        division_button.set_disactive();

        convert_button_arithmetic.set_position(445, 580);
        convert_button_arithmetic.set_size(265, 70);

        RESET_button_arithmetic.set_position(720, 585);
        RESET_button_arithmetic.set_size(60, 60);

        first_lable_arithmetic.setFillColor(Color(128, 128, 128));
        second_lable_arithmetic.setFillColor(Color(128, 128, 128));
        result_lable_arithmetic.setFillColor(Color(128, 128, 128));

        first_lable_arithmetic.setPosition(210,260);
        second_lable_arithmetic.setPosition(210,380);
        result_lable_arithmetic.setPosition(710,320);

        first_label_atithm_operations.set_symbols_limit(16);
        second_label_arithm_operations.set_symbols_limit(16);

        first_label_atithm_operations.clear_all();
        second_label_arithm_operations.clear_all();
        result_lable_arithm_operaations.clear_all();
        break;

    case 4:
        background.loadFromFile("img\\back_code.png");
        background.setSmooth(true);

        background_sprite.setTexture(background);
        background_sprite.setOrigin(0, 0);
        background_sprite.setPosition(0, 0);
        background_sprite.setScale(
            Win_width / background_sprite.getTexture()->getSize().x,
            Win_height / background_sprite.getTexture()->getSize().y
        );

        dec_text.setPosition(250, 240);
        simple_text.setPosition(250,400);
        reverse_text.setPosition(670,240);
        extra_text.setPosition(670, 400);

        dec_text.setFillColor(Color(128, 128, 128));
        simple_text.setFillColor(Color(128, 128, 128));
        reverse_text.setFillColor(Color(128, 128, 128));
        extra_text.setFillColor(Color(128, 128, 128));

        dec_text.setCharacterSize(30);
        simple_text.setCharacterSize(30);
        reverse_text.setCharacterSize(30);
        extra_text.setCharacterSize(30);

        copy_button_dec.set_position(545, 290);
        copy_button_simple.set_position(545, 450);
        copy_button_reverse.set_position(965, 290);
        copy_button_extra.set_position(965, 450);

        machine_code_convert_button.set_position(480, 560);
        machine_code_convert_button.set_size(200, 55);

        machine_code_RESET_button.set_position(690, 562.5);
        machine_code_RESET_button.set_size(50, 50);

        Dec_code.set_symbols_limit(16);

        Dec_code.clear_all();
        Simple_code.clear_all();
        reverse_code.clear_all();
        extra_code.clear_all();
        break;
    default:
        break;
    }
}

void render_main_page(int page_id, RenderWindow *Window) {
    switch (page_id)
    {
    case 0:

        Window->draw(background_sprite);
        encoder_radio_button.render_all(Window);
        encoder_enter_lable.render(Window);
        encoder_exit_lable.render(Window);
        encoder_conver_button.render(Window);
        break;
    case 1:
        Window->draw(background_sprite);

        convertor_BIN.render(Window);
        convertor_OCT.render(Window);
        convertor_DEC.render(Window);
        convertor_HEX.render(Window);

        Window->draw(BIN_text);
        Window->draw(OCT_text);
        Window->draw(DEC_text);
        Window->draw(HEX_text);

        convertor_scale_of_nation_button.render(Window);
  
        BIN_copy_button.render(Window);
        OCT_copy_button.render(Window);
        DEC_copy_button.render(Window);
        HEX_copy_button.render(Window);

        encode_scale_of_nation_reset_button.render(Window);
        break;
    case 2:
        Window->draw(background_sprite);

        math_sytem_lable_BIT.render(Window);
        math_sytem_lable_BYTE.render(Window);
        math_sytem_lable_KBYTE.render(Window);
        math_sytem_lable_MBYTE.render(Window);
        math_sytem_lable_GBYTE.render(Window);
        math_sytem_lable_TBYTE.render(Window);

        Window->draw(BIT_text);
        Window->draw(BYTE_text);
        Window->draw(KBYTE_text);
        Window->draw(MBYTE_text);
        Window->draw(GBYTE_text);
        Window->draw(TBYTE_text);

        BIT_copy_button.render(Window);
        BYTE_copy_button.render(Window);
        KBYTE_copy_button.render(Window);
        MBYTE_copy_button.render(Window);
        GBYTE_copy_button.render(Window);
        TBYTE_copy_button.render(Window);

        math_system_convert_button.render(Window);

        math_system_RESET_button.render(Window);

        break;
    case 3:
        Window->draw(background_sprite);

        first_label_atithm_operations.render(Window);
        second_label_arithm_operations.render(Window);
        result_lable_arithm_operaations.render(Window);
        
        plus_button.render(Window);
        minus_button.render(Window);
        multiplication_button.render(Window);
        division_button.render(Window);

        convert_button_arithmetic.render(Window);
        RESET_button_arithmetic.render(Window);


        Window->draw(first_lable_arithmetic);
        Window->draw(second_lable_arithmetic);
        Window->draw(result_lable_arithmetic);
        break;
    case 4:
        Window->draw(background_sprite);

        Dec_code.render(Window);
        Simple_code.render(Window);
        reverse_code.render(Window);
        extra_code.render(Window);

        Window->draw(dec_text);
        Window->draw(simple_text);
        Window->draw(reverse_text);
        Window->draw(extra_text);

        copy_button_dec.render(Window);
        copy_button_simple.render(Window);
        copy_button_reverse.render(Window);
        copy_button_extra.render(Window);

        machine_code_convert_button.render(Window);

        machine_code_RESET_button.render(Window);
        break;
    default:
        break;
    }
}

void scale_of_nation_logic() {
    if (convertor_BIN.has_data()&& !convertor_DEC.has_data()&& !convertor_OCT.has_data()&& !convertor_HEX.has_data()) {  // BIN
        convertor_OCT.set_data(converter_to_scale_of_nation(convertor_BIN.get_data(), 2, 1));
        convertor_DEC.set_data(converter_to_scale_of_nation(convertor_BIN.get_data(), 3, 1));
        convertor_HEX.set_data(converter_to_scale_of_nation(convertor_BIN.get_data(), 4, 1));
    }

    else if (!convertor_BIN.has_data() && !convertor_DEC.has_data() && convertor_OCT.has_data() && !convertor_HEX.has_data()) {  //OCT
        convertor_BIN.set_data(converter_to_scale_of_nation(convertor_OCT.get_data(), 1, 2));
        convertor_DEC.set_data(converter_to_scale_of_nation(convertor_OCT.get_data(), 3, 2));
        convertor_HEX.set_data(converter_to_scale_of_nation(convertor_OCT.get_data(), 4, 2));
    }
    else if (!convertor_BIN.has_data() && convertor_DEC.has_data() && !convertor_OCT.has_data() && !convertor_HEX.has_data()) {  //DEC
        convertor_BIN.set_data(converter_to_scale_of_nation(convertor_DEC.get_data(), 1, 3));
        convertor_OCT.set_data(converter_to_scale_of_nation(convertor_DEC.get_data(), 2, 3));
        convertor_HEX.set_data(converter_to_scale_of_nation(convertor_DEC.get_data(), 4, 3));
    }
    else if (!convertor_BIN.has_data() && !convertor_DEC.has_data() && !convertor_OCT.has_data() && convertor_HEX.has_data()) {  //HEX
        convertor_BIN.set_data(converter_to_scale_of_nation(convertor_HEX.get_data(), 1, 4));
        convertor_OCT.set_data(converter_to_scale_of_nation(convertor_HEX.get_data(), 2, 4));
        convertor_DEC.set_data(converter_to_scale_of_nation(convertor_HEX.get_data(), 3, 4));
    }
    else {      //ERROR
        cout << "------------error messege----------" << endl;
    }
}

void conver_to_math_system_logic() {
    if (math_sytem_lable_BIT.has_data() && !math_sytem_lable_BYTE.has_data() &&       //BIT
        !math_sytem_lable_KBYTE.has_data() && !math_sytem_lable_MBYTE.has_data() &&
        !math_sytem_lable_GBYTE.has_data() && !math_sytem_lable_TBYTE.has_data()) 
    {
        math_sytem_lable_BYTE.set_data(converter_to_mathematical_system(math_sytem_lable_BIT.get_data(), 2, 1));
        math_sytem_lable_KBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_BIT.get_data(), 3, 1));
        math_sytem_lable_MBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_BIT.get_data(), 4, 1));
        math_sytem_lable_GBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_BIT.get_data(), 5, 1));
        math_sytem_lable_TBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_BIT.get_data(), 6, 1));
    }
    else if (!math_sytem_lable_BIT.has_data() && math_sytem_lable_BYTE.has_data() &&       //BYTE
             !math_sytem_lable_KBYTE.has_data() && !math_sytem_lable_MBYTE.has_data() &&
             !math_sytem_lable_GBYTE.has_data() && !math_sytem_lable_TBYTE.has_data()) 
    {
        math_sytem_lable_BIT.set_data(converter_to_mathematical_system(math_sytem_lable_BYTE.get_data(), 1, 2));
        math_sytem_lable_KBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_BYTE.get_data(), 3, 2));
        math_sytem_lable_MBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_BYTE.get_data(), 4, 2));
        math_sytem_lable_GBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_BYTE.get_data(), 5, 2));
        math_sytem_lable_TBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_BYTE.get_data(), 6, 2));
    }
    else if (!math_sytem_lable_BIT.has_data() && !math_sytem_lable_BYTE.has_data() &&       //KBYTE
              math_sytem_lable_KBYTE.has_data() && !math_sytem_lable_MBYTE.has_data() &&
             !math_sytem_lable_GBYTE.has_data() && !math_sytem_lable_TBYTE.has_data()) 
    {
        math_sytem_lable_BIT.set_data(converter_to_mathematical_system(math_sytem_lable_KBYTE.get_data(), 1, 3));
        math_sytem_lable_BYTE.set_data(converter_to_mathematical_system(math_sytem_lable_KBYTE.get_data(), 2, 3));
        math_sytem_lable_MBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_KBYTE.get_data(), 4, 3));
        math_sytem_lable_GBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_KBYTE.get_data(), 5, 3));
        math_sytem_lable_TBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_KBYTE.get_data(), 6, 3));
    }
    else if (!math_sytem_lable_BIT.has_data() && !math_sytem_lable_BYTE.has_data() &&       //MBYTE
             !math_sytem_lable_KBYTE.has_data() &&  math_sytem_lable_MBYTE.has_data() &&
             !math_sytem_lable_GBYTE.has_data() && !math_sytem_lable_TBYTE.has_data())
    {
        math_sytem_lable_BIT.set_data(converter_to_mathematical_system(math_sytem_lable_MBYTE.get_data(), 1, 4));
        math_sytem_lable_BYTE.set_data(converter_to_mathematical_system(math_sytem_lable_MBYTE.get_data(), 2, 4));
        math_sytem_lable_KBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_MBYTE.get_data(), 3, 4));
        math_sytem_lable_GBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_MBYTE.get_data(), 5, 4));
        math_sytem_lable_TBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_MBYTE.get_data(), 6, 4));
    }
    else if (!math_sytem_lable_BIT.has_data() && !math_sytem_lable_BYTE.has_data() &&       //GBYTE
             !math_sytem_lable_KBYTE.has_data() && !math_sytem_lable_MBYTE.has_data() &&
              math_sytem_lable_GBYTE.has_data() && !math_sytem_lable_TBYTE.has_data())
    {
        math_sytem_lable_BIT.set_data(converter_to_mathematical_system(math_sytem_lable_GBYTE.get_data(), 1, 5));
        math_sytem_lable_BYTE.set_data(converter_to_mathematical_system(math_sytem_lable_GBYTE.get_data(), 2, 5));
        math_sytem_lable_KBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_GBYTE.get_data(), 3, 5));
        math_sytem_lable_MBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_GBYTE.get_data(), 4, 5));
        math_sytem_lable_TBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_GBYTE.get_data(), 6, 5));
    }
    else if (!math_sytem_lable_BIT.has_data() && !math_sytem_lable_BYTE.has_data() &&       //TBYTE
             !math_sytem_lable_KBYTE.has_data() && !math_sytem_lable_MBYTE.has_data() &&
             !math_sytem_lable_GBYTE.has_data() &&  math_sytem_lable_TBYTE.has_data())
    {
        math_sytem_lable_BIT.set_data(converter_to_mathematical_system(math_sytem_lable_TBYTE.get_data(), 1, 6));
        math_sytem_lable_BYTE.set_data(converter_to_mathematical_system(math_sytem_lable_TBYTE.get_data(), 2, 6));
        math_sytem_lable_KBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_TBYTE.get_data(), 3, 6));
        math_sytem_lable_MBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_TBYTE.get_data(), 4, 6));
        math_sytem_lable_GBYTE.set_data(converter_to_mathematical_system(math_sytem_lable_TBYTE.get_data(), 5, 6));
    }
    else
    {    //ERROR
        cout << "------------error messege----------" << endl;
    }
}

void convert_to_machine_code_logic() {
    Simple_code.set_data(convertor_to_machine_code(Dec_code.get_data(), 1));
    reverse_code.set_data(convertor_to_machine_code(Dec_code.get_data(), 2));
    extra_code.set_data(convertor_to_machine_code(Dec_code.get_data(), 3));
}

void arithmetic_logic() {
    if (plus_button.isActive()) {
        result_lable_arithm_operaations.set_data(arithmetic_operations(first_label_atithm_operations.get_data(), second_label_arithm_operations.get_data(), 1));
    }
    else if (minus_button.isActive()) {
        result_lable_arithm_operaations.set_data(arithmetic_operations(first_label_atithm_operations.get_data(), second_label_arithm_operations.get_data(), 2));
    }
    else if (multiplication_button.isActive()) {
        result_lable_arithm_operaations.set_data(arithmetic_operations(first_label_atithm_operations.get_data(), second_label_arithm_operations.get_data(), 3));
    }
    else if (division_button.isActive()) {
        result_lable_arithm_operaations.set_data(arithmetic_operations(first_label_atithm_operations.get_data(), second_label_arithm_operations.get_data(), 4));
    }
}

int main(int argc,char*argv[]) {
    
    RenderWindow main_window(VideoMode(Win_width, Win_height), "DevTools", Style::Close | Style::Titlebar);

    main_window.setVerticalSyncEnabled(true);
    build_main_page(0);

    Menu menu_bar(360, Win_height, 70);
    menu_bar.set_button_zone(100);
    menu_bar.set_buttons_settings(70, 50, 0);
    menu_bar.set_button_text_settings(17, 0);
    menu_bar.set_active(0);

    while (main_window.isOpen())
    {
        Event event;
        while (main_window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                main_window.close();
            if (Mouse::isButtonPressed(Mouse::Left)) {

                /*------------------Õ¿∆¿“»≈ Õ¿  ÕŒœ » Ã≈Õﬁ---------------------*/
                if (menu_bar.getButton(0)->is_hover(&main_window)) {
                    menu_bar.set_active(0);
                    build_main_page(0);
                    page_id = 0;
                }
                if (menu_bar.getButton(1)->is_hover(&main_window)) {
                    menu_bar.set_active(1);
                    build_main_page(1);
                    page_id = 1;
                }
                if (menu_bar.getButton(2)->is_hover(&main_window)) {
                    menu_bar.set_active(2);
                    build_main_page(2);
                    page_id = 2;
                }
                if (menu_bar.getButton(3)->is_hover(&main_window)) {
                    menu_bar.set_active(3);
                    build_main_page(3);
                    page_id = 3;
                }
                if (menu_bar.getButton(4)->is_hover(&main_window)) {
                    menu_bar.set_active(4);
                    build_main_page(4);
                    page_id = 4;
                }
                if (menu_bar.getButton(5)->is_hover(&main_window)) {
                    menu_bar.set_active(5);
                    build_main_page(5);
                    page_id = 5;
                }

                if (page_id == 0) {

                    /*------------------Õ¿∆¿“»≈ Õ¿ –¿ƒ»Œ  ÕŒœ »---------------------*/
                    if (encoder_radio_button.get_button(0)->is_hover(&main_window)) {
                        encoder_radio_button.set_button_active(0);
                    }
                    if (encoder_radio_button.get_button(1)->is_hover(&main_window)) {
                        encoder_radio_button.set_button_active(1);
                    }
                    if (encoder_radio_button.get_button(2)->is_hover(&main_window)) {
                        encoder_radio_button.set_button_active(2);
                    }
                    if (encoder_radio_button.get_button(3)->is_hover(&main_window)) {
                        encoder_radio_button.set_button_active(3);
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿ À≈…¡À ¬¬Œƒ¿ ƒ¿ÕÕ€’---------------------*/
                    if (encoder_enter_lable.is_hover(&main_window)) {
                        encoder_enter_lable.set_active();
                    }
                    else
                    {
                        encoder_enter_lable.set_disactive();
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿  ÕŒœ ”  ŒÕ¬≈–“¿÷»»---------------------*/
                    if (encoder_conver_button.is_hover(&main_window)) {
                        encoder_conver_button.set_active();
                        encoder_exit_lable.set_data(encoder(encoder_enter_lable.get_data(),encoder_radio_button.get_active_button()));
                    } 
                    else
                    {
                        encoder_conver_button.set_disactive();
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿ À≈…¡À –≈«”À‹“¿“¿---------------------*/
                    if (encoder_exit_lable.is_hover(&main_window)) {
                        encoder_exit_lable.set_active();
                    }
                    else
                    {
                        encoder_exit_lable.set_disactive();
                    }
                }
                else if (page_id == 1) {

                    /*------------------Õ¿∆¿“»≈ Õ¿ À≈…¡À —»—“≈Ã »—◊»—À≈Õ»ﬂ---------------------*/
                    if (convertor_BIN.is_hover(&main_window)) {
                        convertor_BIN.set_active();
                    }
                    else
                    {
                        convertor_BIN.set_disactive();
                    }
                    if (convertor_OCT.is_hover(&main_window)) {
                        convertor_OCT.set_active();
                    }
                    else
                    {
                        convertor_OCT.set_disactive();
                    }
                    if (convertor_DEC.is_hover(&main_window)) {
                        convertor_DEC.set_active();
                    }
                    else
                    {
                        convertor_DEC.set_disactive();
                    }
                    if (convertor_HEX.is_hover(&main_window)) {
                        convertor_HEX.set_active();
                    }
                    else
                    {
                        convertor_HEX.set_disactive();
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿  ÕŒœ ”  ŒÕ¬≈–“»–Œ¬¿“‹---------------------*/
                    if (convertor_scale_of_nation_button.is_hover(&main_window)) {
                        convertor_scale_of_nation_button.set_active();
                        scale_of_nation_logic();
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿  ÕŒœ ” RESET---------------------*/
                    if (encode_scale_of_nation_reset_button.is_hover(&main_window)) {
                        encode_scale_of_nation_reset_button.set_active();
                        convertor_BIN.clear_all();
                        convertor_OCT.clear_all();
                        convertor_DEC.clear_all();
                        convertor_HEX.clear_all();
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿  ÕŒœ ”  Œœ»–Œ¬¿“‹---------------------*/
                    if (BIN_copy_button.is_hover(&main_window)) {
                        BIN_copy_button.set_active();
                    }
                    if (OCT_copy_button.is_hover(&main_window)) {
                        OCT_copy_button.set_active();
                    }
                    if (DEC_copy_button.is_hover(&main_window)) {
                        DEC_copy_button.set_active();
                    }
                    if (HEX_copy_button.is_hover(&main_window)) {
                        HEX_copy_button.set_active();
                    }
                }
                else if (page_id == 2) {
                /*------------------Õ¿∆¿“»≈ Õ¿ À≈…¡À ¡»“Œ¬, ¡¿…“Œ¬ “.ƒ---------------------*/
                    if (math_sytem_lable_BIT.is_hover(&main_window)) {
                        math_sytem_lable_BIT.set_active();
                    }
                    else {
                        math_sytem_lable_BIT.set_disactive();
                    }
                    if (math_sytem_lable_BYTE.is_hover(&main_window)) {
                        math_sytem_lable_BYTE.set_active();
                    }
                    else {
                        math_sytem_lable_BYTE.set_disactive();
                    }
                    if (math_sytem_lable_KBYTE.is_hover(&main_window)) {
                        math_sytem_lable_KBYTE.set_active();
                    }
                    else {
                        math_sytem_lable_KBYTE.set_disactive();
                    }
                    if (math_sytem_lable_MBYTE.is_hover(&main_window)) {
                        math_sytem_lable_MBYTE.set_active();
                    }
                    else {
                        math_sytem_lable_MBYTE.set_disactive();
                    }
                    if (math_sytem_lable_GBYTE.is_hover(&main_window)) {
                        math_sytem_lable_GBYTE.set_active();
                    }
                    else {
                        math_sytem_lable_GBYTE.set_disactive();
                    }
                    if (math_sytem_lable_TBYTE.is_hover(&main_window)) {
                        math_sytem_lable_TBYTE.set_active();
                    }
                    else {
                        math_sytem_lable_TBYTE.set_disactive();
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿  ÕŒœ ”  Œœ»–Œ¬¿“‹---------------------*/
                    if (BIT_copy_button.is_hover(&main_window)) {
                        BIT_copy_button.set_active();
                    }
                    if (BYTE_copy_button.is_hover(&main_window)) {
                        BYTE_copy_button.set_active();
                    }
                    if (KBYTE_copy_button.is_hover(&main_window)) {
                        KBYTE_copy_button.set_active();
                    }
                    if (MBYTE_copy_button.is_hover(&main_window)) {
                        MBYTE_copy_button.set_active();
                    }
                    if (GBYTE_copy_button.is_hover(&main_window)) {
                        GBYTE_copy_button.set_active();
                    }
                    if (TBYTE_copy_button.is_hover(&main_window)) {
                        TBYTE_copy_button.set_active();
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿  ÕŒœ ”  ŒÕ¬≈–“¿÷»»---------------------*/
                    if (math_system_convert_button.is_hover(&main_window)) {
                        math_system_convert_button.set_active();
                        conver_to_math_system_logic();
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿  ÕŒœ ” —¡–Œ—¿---------------------*/
                    if (math_system_RESET_button.is_hover(&main_window)) {
                        math_system_RESET_button.set_active();
                        math_sytem_lable_BIT.clear_all();
                        math_sytem_lable_BYTE.clear_all();
                        math_sytem_lable_KBYTE.clear_all();
                        math_sytem_lable_MBYTE.clear_all();
                        math_sytem_lable_GBYTE.clear_all();
                        math_sytem_lable_TBYTE.clear_all();
                    }
                }
                else if (page_id == 3) 
                {
                    if (first_label_atithm_operations.is_hover(&main_window)) {
                        first_label_atithm_operations.set_active();
                    }
                    else {
                        first_label_atithm_operations.set_disactive();
                    }
                    if (second_label_arithm_operations.is_hover(&main_window)) {
                        second_label_arithm_operations.set_active();
                    }
                    else {
                        second_label_arithm_operations.set_disactive();
                    }
                    if (result_lable_arithm_operaations.is_hover(&main_window)) {
                        result_lable_arithm_operaations.set_active();
                    }
                    else {
                        result_lable_arithm_operaations.set_disactive();
                    }

                    if (plus_button.is_hover(&main_window)) {
                        plus_button.set_active();
                        minus_button.set_disactive();
                        multiplication_button.set_disactive();
                        division_button.set_disactive();
                    }
                    else if (minus_button.is_hover(&main_window)) {
                        plus_button.set_disactive();
                        minus_button.set_active();
                        multiplication_button.set_disactive();
                        division_button.set_disactive();
                    }
                    else if (multiplication_button.is_hover(&main_window)) {
                        plus_button.set_disactive();
                        minus_button.set_disactive();
                        multiplication_button.set_active();
                        division_button.set_disactive();
                    }
                    else if (division_button.is_hover(&main_window)) {
                        plus_button.set_disactive();
                        minus_button.set_disactive();
                        multiplication_button.set_disactive();
                        division_button.set_active();
                    }

                    if (convert_button_arithmetic.is_hover(&main_window)) {
                        convert_button_arithmetic.set_active();

                        arithmetic_logic();
                    }

                    if (RESET_button_arithmetic.is_hover(&main_window)) {
                        RESET_button_arithmetic.set_active();

                        first_label_atithm_operations.clear_all();
                        second_label_arithm_operations.clear_all();
                        result_lable_arithm_operaations.clear_all();
                    }
                }
                else if (page_id == 4) {

                /*------------------Õ¿∆¿“»≈ Õ¿ À≈…¡À œ /Œ /ƒ ---------------------*/
                    if (Dec_code.is_hover(&main_window)) {
                        Dec_code.set_active();
                    }
                    else
                    {
                        Dec_code.set_disactive();
                    }
                    if (Simple_code.is_hover(&main_window)) {
                        Simple_code.set_active();
                    }
                    else
                    {
                        Simple_code.set_disactive();
                    }
                    if (reverse_code.is_hover(&main_window)) {
                        reverse_code.set_active();
                    }
                    else
                    {
                        reverse_code.set_disactive();
                    }
                    if (extra_code.is_hover(&main_window)) {
                        extra_code.set_active();
                    }
                    else
                    {
                        extra_code.set_disactive();
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿  ÕŒœ ” COPY---------------------*/
                    if (copy_button_dec.is_hover(&main_window)) {
                        copy_button_dec.set_active();
                    }
                    if (copy_button_simple.is_hover(&main_window)) {
                        copy_button_simple.set_active();
                    }
                    if (copy_button_reverse.is_hover(&main_window)) {
                        copy_button_reverse.set_active();
                    }
                    if (copy_button_extra.is_hover(&main_window)) {
                        copy_button_extra.set_active();
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿  ÕŒœ ”  ŒÕ¬≈–“¿÷»»---------------------*/
                    if (machine_code_convert_button.is_hover(&main_window)) {
                        machine_code_convert_button.set_active();
                        convert_to_machine_code_logic();
                    }

                    /*------------------Õ¿∆¿“»≈ Õ¿  ÕŒœ ” RESET---------------------*/
                    if (machine_code_RESET_button.is_hover(&main_window)) {
                        machine_code_RESET_button.set_active();
                        Dec_code.clear_all();
                        Simple_code.clear_all();
                        reverse_code.clear_all();
                        extra_code.clear_all();
                    }
                }
            }
            /*------------------«¿œ»—‹ ƒ¿ÕÕ€’ ¬ À≈…¡À  ŒÕ¬≈–“Œ–¿ —»Ã¬ŒÀŒ¬---------------------*/
            if (page_id == 0) {
                encoder_enter_lable.writing_data(event);
                encoder_exit_lable.swap_postion();
            }
            /*------------------«¿œ»—‹ ƒ¿ÕÕ€’ ¬ À≈…¡À  ŒÕ¬≈–“Œ–¿ —»—“≈Ã —◊»—À≈Õ»ﬂ---------------------*/
            else if (page_id == 1) {
                convertor_BIN.writing_data(event);
                convertor_DEC.writing_data(event);
                convertor_OCT.writing_data(event);
                convertor_HEX.writing_data(event);
            }
            /*------------------«¿œ»—‹ ƒ¿ÕÕ€’ ¬ À≈…¡À ¡»“Œ¬ ¡¿…“Œ¬ » “.ƒ---------------------*/
            else if (page_id == 2) {
                math_sytem_lable_BIT.writing_data(event);
                math_sytem_lable_BYTE.writing_data(event);
                math_sytem_lable_KBYTE.writing_data(event);
                math_sytem_lable_MBYTE.writing_data(event);
                math_sytem_lable_GBYTE.writing_data(event);
                math_sytem_lable_TBYTE.writing_data(event);
            }
            else if (page_id == 3) {
                first_label_atithm_operations.writing_data(event);
                second_label_arithm_operations.writing_data(event);
                result_lable_arithm_operaations.swap_postion();
            }
            else if (page_id == 4) {
                Dec_code.writing_data(event);
            }
        }

        main_window.clear(Color::White);


        if (menu_bar.is_hover(&main_window)) {
            menu_bar.expand();
        }
        else {
            menu_bar.collaps();
        }

        render_main_page(page_id, &main_window);
        menu_bar.render(&main_window);

        main_window.display();
    }
    return 0;
}