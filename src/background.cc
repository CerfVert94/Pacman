#include "background.hh"

Background::Background(unsigned int width, unsigned int height, Woption option):
AutoPosImage(_default_path + _bg_image_paths[bMENU], // image_path
			 width, height, // Size of screen.
			 bg_width, bg_height, // Size of background sprite.
			 0, 0, // offset of image pos.
			 (option != MEDIUM ? DEFAULT_SCALE : MEDIUM_SCALE)) // scale.
{
	load_sound(_default_path + _sound_paths[sCHOICE]);
	token = bMENU;
	play();
}

Background::~Background() {}

background_option Background::get_token() const {
	return token;
}

void Background::set_sprite(background_option option) {
	std::string image_path;
	load_image(_default_path + _bg_image_paths[option]);
	token = option;
}