#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

struct SDLState {
	SDL_Window* window;
	SDL_Renderer* renderer;
};

void cleanup(SDLState &state);

int main(int argc, char *argv[])
{
	SDLState state;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error initializing SDL3", nullptr);
		return 1;	
	}
	
	// create window
	int width = 800;
	int height = 600;
	state.window = SDL_CreateWindow("SDL3 Demo", width, height, 0);
	if (!state.window) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating window", nullptr);
		cleanup(state);
		return 1;
	}

	// create renderer
	state.renderer = SDL_CreateRenderer(state.window, nullptr);
	if (!state.renderer) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating renderer", nullptr);
		cleanup(state);
		return 1;
	}

	// load game assets
	SDL_Texture* idleTexture = IMG_LoadTexture(state.renderer, "SDL3-Game/src/assets/school_girl_idle.png");
	SDL_SetTextureScaleMode(idleTexture, SDL_SCALEMODE_NEAREST);

	// start game loop
	bool running = true;
	while (running) {
		SDL_Event event{ 0 };
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_EVENT_QUIT:
				running = false;
				break;
			}
		}

		// perform drawing commands
		SDL_SetRenderDrawColor(state.renderer, 20, 10, 30, 255);
		SDL_RenderClear(state.renderer);

		SDL_FRect src{
			.x = 0,
			.y = 0,
			.w = 32,
			.h = 80
		};

		SDL_FRect dst{
			.x = 0,
			.y = 0,
			.w = 32,
			.h = 80
		};
		
		SDL_RenderTexture(state.renderer, idleTexture, &src, &dst);

		// swap buffers and presents
		SDL_RenderPresent(state.renderer);
	}
	
	SDL_DestroyTexture(idleTexture);
	cleanup(state);
	return 0;
}

void cleanup(SDLState &state) {
	SDL_DestroyRenderer(state.renderer);
	SDL_DestroyWindow(state.window);
	SDL_Quit();
}

