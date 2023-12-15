#include"Header.h"
#include"menu_bar.h"
#define Win_width 1200
#define Win_height 800

int main(int argc,char*argv[]) {

    RenderWindow main_window(VideoMode(Win_width, Win_height), "new_project", Style::Close| Style::Titlebar);
    
    main_window.setVerticalSyncEnabled(true);

    Menu menu_bar(300, Win_height, 70);
    menu_bar.set_button_zone(100);
    menu_bar.set_buttons_settings(70, 50, 0);
    menu_bar.set_button_text_settings(25, 10);

    while (main_window.isOpen())
    {
        Event event;
        while (main_window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                main_window.close();
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu_bar.getButton(0)->is_hover(&main_window)) {
                    menu_bar.set_active(0);
                }
                if (menu_bar.getButton(1)->is_hover(&main_window)) {
                    menu_bar.set_active(1);
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
            }
        }

        main_window.clear(Color::White);


        if (menu_bar.is_hover(&main_window)) {
            menu_bar.expand();
        }
        else {
            menu_bar.collaps();
        }

        menu_bar.render(&main_window);

        main_window.display();
    }
    return 0;
}