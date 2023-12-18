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

Font font;
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

void build_main_page(int page_id) {

    font.loadFromFile("arialmt.ttf");

    switch (page_id)
    {   
    case 0:
       
       cout<< background.loadFromFile("img\\Rectangle 1.png");
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

        convertor_BIN.clear_all();
        convertor_OCT.clear_all();
        convertor_DEC.clear_all();
        convertor_HEX.clear_all();

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
    default:
        break;
    }
}

void scale_of_nation_logic() {
    if (convertor_BIN.has_data()&& !convertor_DEC.has_data()&& !convertor_OCT.has_data()&& !convertor_HEX.has_data()) {  // BIN
        convertor_OCT.set_data(converter_to_scale_of_nation(convertor_BIN.get_data(), 2));
        convertor_DEC.set_data(converter_to_scale_of_nation(convertor_DEC.get_data(), 3));
        convertor_HEX.set_data(converter_to_scale_of_nation(convertor_HEX.get_data(), 4));
    }
    else if (!convertor_BIN.has_data() && convertor_DEC.has_data() && !convertor_OCT.has_data() && !convertor_HEX.has_data()) {  //OCT
        convertor_BIN.set_data(converter_to_scale_of_nation(convertor_BIN.get_data(), 1));
        convertor_OCT.set_data(converter_to_scale_of_nation(convertor_OCT.get_data(), 2));
        convertor_HEX.set_data(converter_to_scale_of_nation(convertor_HEX.get_data(), 4));
    }
    else if (!convertor_BIN.has_data() && !convertor_DEC.has_data() && convertor_OCT.has_data() && !convertor_HEX.has_data()) {  //DEC
        convertor_BIN.set_data(converter_to_scale_of_nation(convertor_BIN.get_data(), 1));
        convertor_DEC.set_data(converter_to_scale_of_nation(convertor_DEC.get_data(), 3));
        convertor_HEX.set_data(converter_to_scale_of_nation(convertor_HEX.get_data(), 4));
    }
    else if (!convertor_BIN.has_data() && !convertor_DEC.has_data() && !convertor_OCT.has_data() && convertor_HEX.has_data()) {  //HEX
        convertor_BIN.set_data(converter_to_scale_of_nation(convertor_BIN.get_data(), 1));
        convertor_OCT.set_data(converter_to_scale_of_nation(convertor_OCT.get_data(), 2));
        convertor_DEC.set_data(converter_to_scale_of_nation(convertor_DEC.get_data(), 3));
    }
    else {      //ERROR
        cout << "------------error messege----------" << endl;
    }
}

int main(int argc,char*argv[]) {
    
    RenderWindow main_window(VideoMode(Win_width, Win_height), "new_project", Style::Close | Style::Titlebar);

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
                }
                if (menu_bar.getButton(3)->is_hover(&main_window)) {
                    menu_bar.set_active(3);
                }
                if (menu_bar.getButton(4)->is_hover(&main_window)) {
                    menu_bar.set_active(4);
                }
                if (menu_bar.getButton(5)->is_hover(&main_window)) {
                    menu_bar.set_active(5);
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
            }
            /*------------------«¿œ»—‹ ƒ¿ÕÕ€’ ¬ À≈…¡À  ŒÕ¬≈–“Œ–¿ —»Ã¬ŒÀŒ¬---------------------*/
            if (page_id == 0) {
                encoder_enter_lable.writing_data(event);
                encoder_exit_lable.swap_postion();
            }
            else if (page_id == 1) {
                convertor_BIN.writing_data(event);
                convertor_DEC.writing_data(event);
                convertor_OCT.writing_data(event);
                convertor_HEX.writing_data(event);
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