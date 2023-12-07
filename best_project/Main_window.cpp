#include"Header.h"

int main(int argc,char*argv[]) {
    RenderWindow main_window(VideoMode(1200, 800), L"new_project");

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