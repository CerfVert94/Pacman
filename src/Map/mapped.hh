#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "./Graphics/image.hh"

class Mapped {
public:
	Mapped(Image &image) : _image(image) {}
	virtual ~Mapped() {}
	virtual void set_map_coordinate(sf::Vector2i map_coordinate);
	virtual void set_map_coordinate(int x, int y);
	virtual void set_map_coordinate_x(int x);
	virtual void set_map_coordinate_y(int y);

	virtual void set_screen_coordinate(sf::Vector2i screen_coordinate);
	virtual void set_screen_coordinate(int x, int y);
	virtual void set_screen_coordinate_x(int x);
	virtual void set_screen_coordinate_y(int y);
	virtual void set_offset(sf::Vector2i screen_coordinate);
	virtual void set_offset(int x, int y);

	void set_scale(sf::Vector2f scale);
	void set_scale(float h_scale, float v_scale);
	
	
	sf::Vector2i get_map_coordinate() const {return _map_coordinate;}
	int get_map_coordinate_x() const {return _map_coordinate.x;}
	int get_map_coordinate_y() const {return _map_coordinate.y;}
	sf::Vector2i get_screen_coordinate() const {return _image.get_position();}
	int get_screen_coordinate_x() const {return _image.get_x();}
	int get_screen_coordinate_y() const {return _image.get_y();}
	

	sf::Vector2f get_scale() const {return _image.get_scale();}
	sf::Vector2i get_size() const {return _image.get_size();}
	
protected:
	Image &_image;
	sf::Vector2i _map_coordinate;
	sf::Vector2i _screen_coordinate;


};