#pragma once
#include <SFML/Graphics.hpp>
#include "background.hh"
#include "menu.hh"
#include "cursor.hh"

class Window {
	public:
		Window(unsigned int width, unsigned int high);
		~Window();
		void launch();
	private:
		unsigned int width;
		unsigned int high;
};