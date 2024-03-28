#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>

typedef float    f32;
typedef double   f64;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef size_t   usize;

typedef struct v2_s { f32 x, y; } v2;

#define WIDTH 1280
#define HEIGHT 720

struct {
    SDL_Window* window;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    u32 pixels[WIDTH * HEIGHT];

    bool quit;

    v2 pos, dir, plane;
} state;

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("ERR: Failed to initialize SDL: %s\n", SDL_GetError());
        return -1;
    }

    state.window = SDL_CreateWindow("WINDOW", WIDTH, HEIGHT, 0);
    if (!state.window) {
        printf("ERR: Failed to create a window: %s\n", SDL_GetError());
        return -1;
    }

    state.renderer = SDL_CreateRenderer(state.window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!state.renderer) {
        printf("ERR: Failed to create a renderer: %s\n", SDL_GetError());
        return -1;
    }

    state.texture = SDL_CreateTexture(state.renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
    if (!state.texture) {
        printf("ERR: Failed to create a texture: %s\n", SDL_GetError());
        return -1;
    }

    while (!state.quit) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    state.quit = true;
                    break;
            }
        }
    }

    return 0;
}