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

struct Command {
    CommandType type;
    int objectId;

    SceneObject objectSnapshot;

    float beforeX = 0, beforeY = 0, beforeWidth = 0, beforeHeight = 0;
    float afterX = 0, afterY = 0, afterWidth = 0, afterHeight = 0;
};