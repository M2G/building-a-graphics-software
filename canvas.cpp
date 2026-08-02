#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cstdio>
const int WIDTH = 400;
static const int HEIGHT = 400;
static const int CHANNELS = 4; // RGBA

static uint8_t* g_buffer = nullptr;

#ifdef __EMSCRIPTEN__
   #include <emscripten/emscripten.h>
#else
   #define EMSCRIPTEN_KEEPALIVE
#endif

extern "C" {
EMSCRIPTEN_KEEPALIVE
   void init_canvas() {
      size_t size = WIDTH * HEIGHT * CHANNELS;
      g_buffer = static_cast<uint8_t*>(malloc(size));

   printf("Canvas initialized with size: %zu bytes\n", size);

      for (size_t i = 0; i < size; i += CHANNELS) {
         g_buffer[i + 0] = 220;
         g_buffer[i + 1] = 220;
         g_buffer[i + 2] = 220;
         g_buffer[i + 3] = 255;
      }
   }
EMSCRIPTEN_KEEPALIVE
uint8_t* get_buffer_ptr() {
   return g_buffer;
}

EMSCRIPTEN_KEEPALIVE
int get_width() {
   return WIDTH;
}

EMSCRIPTEN_KEEPALIVE
int get_height() {
   return HEIGHT;
}
}