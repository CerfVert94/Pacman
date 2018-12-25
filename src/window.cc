#include "window.hh"    
#include <iostream>
// background texture size : 420x460
#define BG_WIDTH Background::bg_width
#define BG_HEIGHT Background::bg_height
Window::Window(unsigned int width, unsigned int height) 
{
	_width = width;
	_height = height;
    _scale = ((_width < BG_WIDTH * 2 || _height < BG_HEIGHT * 2) ? SMALL_SCALE : MEDIUM_SCALE);
    std::cout << "scale:"<<_scale;
    _background = new Background(_width, _height, _scale);
    _cursor = new Cursor(_width, _height, _scale, 0, 0, 4);
    _map = new Map(_default_path + "/Map/Map.txt", width, height, _scale);
    _mode = DrawMode::Bg;
}

Window::~Window() 
{
    delete _background;
    delete _cursor;
    delete _map;
}

void Window::launch() {
	// Init
	sf::RenderWindow window(sf::VideoMode(_width, _height), "Pacman !", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    key_pressed(window, event.key.code); 
                    break;
                default:
                    break;
            }   
            draw(window); //WinEvents.cc
        }
    }
}
