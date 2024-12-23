#include <stdio.h>
#include <SDL3/SDL.h>

int main() {
    // declarations
    SDL_Window * window;
    SDL_Event event;
    int running = 1;

    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // create a window
    window = SDL_CreateWindow("SDL 3 Example", 800,600,0);

    // Main loop
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        }

    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
