#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <emscripten/emscripten.h>

const int WIDTH = 400;
static const int HEIGHT = 400;
static const int CHANNELS = 4; // RGBA

static uint8_t* g_buffer = nullptr;

extern "C" {}