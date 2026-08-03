#pragma once
#include <vector>
#include <cstdint>

enum class ObjectType {
    RECT,
    ELLIPSE,
    LINE,
    STROKE
};

struct Point {
    float x;
    float y;
};

struct SceneObject {
    ObjectType type;
    int id;

    float x = 0.0f;
    float y = 0.0f;
    float width = 0.0f;
    float height = 0.0f;

    std::vector<Point> points;
    uint32_t color = 0xFFFFFFFF;
};