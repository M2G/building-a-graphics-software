#pragma once
#include "types.h"
#include "scene.h"
#include <vector>
#include <memory>

enum class CommandType {
    ADD,
    DELETE,
    MOVE,
    RESIZE
};