#pragma once
#include "types.h"
#include <vector>
#include <optional>
#include <string>

class Scene {
public:
    int addObject(SceneObject obj);

    bool removeObject(int id);

    SceneObject* getObject(int id);

    const std::vector<SceneObject>& getObjects() const;

    std::optional<int> hitTest(float x, float y) const;

private:
    std::vector<SceneObject> m_objects;
    int m_nextId = 1;
};