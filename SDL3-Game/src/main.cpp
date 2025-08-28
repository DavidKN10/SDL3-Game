#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

int main(int argc, char *argv[])
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "Could Not Load" << std::endl;
		return -1;	
	}
	else {	
		std::cout << "Loaded Successfully!" << std::endl;
		SDL_Quit();
		return 0;	
	}	
}
