#include "scene.h"
#include <cstdio>

int main() {
    // Tester le add/undo/redo/restore
    Scene scene;

    SceneObject rect;
    rect.type = ObjectType::RECT;
    rect.x = 10; rect.y = 10; rect.width = 100; rect.height = 50;
    rect.color = 0xFF0000FF;

    int rectId = scene.addObject(rect);
    printf("Rectangle ajoute avec id=%d\n", rectId);

    auto hit = scene.hitTest(50, 30);
    if (hit.has_value()) {
        printf("Hit sur objet id=%d\n", hit.value());
    } else {
        printf("Aucun object sous ce point\n");
    }

    auto miss = scene.hitTest(200, 200);
    printf("Point hors forme -> hit=%d\n", miss.has_value());

    return 0;
}