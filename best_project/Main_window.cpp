#include"Header.h"
#define Win_width 1200
#define Win_height 800

int main(int argc,char*argv[]) {

    RenderWindow main_window(VideoMode(Win_width, Win_height), "new_project", Style::Close| Style::Titlebar);
    
    main_window.setVerticalSyncEnabled(true);

    while (main_window.isOpen())
    {
        Event event;
        while (main_window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                main_window.close();
        }

        main_window.clear(Color::White);

        main_window.display();

    }
    return 0;
}