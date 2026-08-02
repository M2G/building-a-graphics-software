#include "scene.h"
#include <algorithm>

int Scene::addObject(SceneObject obj) {
    obj.id = m_nextId++;
    m_objects.push_back(obj);
    return obj.id;
}

bool Scene::removeObject(int id) {

}

SceneObject* Scene::getObject(int id) {

}

const std::vector<SceneObject*>& Scene::getObjects() const {}

std::optional<int> hitTest(float x, float y) const {}