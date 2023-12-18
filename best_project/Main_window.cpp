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

Radio_button encoder_radio_button(4);

textLabel encoder_enter_lable(400, 300,400, 50, "defoult_text");
textLabel encoder_exit_lable(400, 500, 400, 50, "defoult_text");
Button encoder_conver_button("img\\ConvertorCHAR.png", "img\\convertorActive.png");

void build_main_page(int page_id) {

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
        break;
    default:
        break;
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
            }
            /*------------------«¿œ»—‹ ƒ¿ÕÕ€’ ¬ À≈…¡À  ŒÕ¬≈–“Œ–¿ —»Ã¬ŒÀŒ¬---------------------*/
            if (page_id == 0) {
                encoder_enter_lable.writing_data(event);
                encoder_exit_lable.swap_postion();
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