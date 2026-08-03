#include "scene.h"
#include <algorithm>

int Scene::addObject(SceneObject obj) {
    obj.id = m_nextId++;
    m_objects.push_back(obj);
    return obj.id;
}

bool Scene::removeObject(int id) {
    auto it = std::find_if(m_objects.begin(), m_objects.end(),
        [id](const SceneObject& obj) { return obj.id == id; });
    if (it == m_objects.end()) {
        return false;
    }
    m_objects.erase(it);
    return true;
}

SceneObject* Scene::getObject(int id) {
    auto it = std::find_if(m_objects.begin(), m_objects.end(),
        [id](const SceneObject& obj) { return obj.id == id; });
    return (it != m_objects.end()) ? &(*it) : nullptr;
}

const std::vector<SceneObject>& Scene::getAllObjects() const {
    return m_objects;
}

std::optional<int> Scene::hitTest(float x, float y) const {
    for (auto it = m_objects.rbegin(); it != m_objects.rend(); ++it) {
        const SceneObject& obj = *it;

        switch (obj.type) {
            case ObjectType::RECT: {
                // https://en.wikipedia.org/wiki/Hit-testing
                bool inside = (x >= obj.x && x <= obj.x + obj.width &&
                    y >= obj.y && y <= obj.y + obj.height);
                if (inside) return obj.id;
                break;
            }
            case ObjectType::ELLIPSE: {
                // https://www.geeksforgeeks.org/dsa/check-if-a-point-is-inside-outside-or-on-the-ellipse/
                // // Équation normalisée de l'ellipse : ((x-cx)/rx)^2 + ((y-cy)/ry)^2 <= 1
                float cx = (obj.x + obj.width) / 2.0f;
                float cy = (obj.y + obj.height) / 2.0f;
                float rx = obj.width / 2.0f;
                float ry = obj.height / 2.0f;
                // ...
            }
            case ObjectType::LINE:
            case ObjectType::STROKE:
                break;

        }
    }
    return std::nullopt;
}