#include "scene.h"
#include <cstdio>

#include "command.h"

int main() {
    Scene scene;
    CommandHistory history;

    SceneObject rect;
    rect.type = ObjectType::RECT;
    rect.x = 10; rect.y = 10; rect.width = 100; rect.height = 50;
    rect.color = 0xFF0000FF;

    int id = scene.addObject(rect);
    Command addCmd;
    addCmd.type = CommandType::ADD;
    addCmd.objectId = id;
    addCmd.objectSnapshot = *scene.getObject(id);
    history.push(addCmd);

    printf("Apres ajout: %zu objet(s) dans la scene\n", scene.getObjects().size());

    // Test undo : le rectangle doit disparaitre
    history.undo(scene);
    printf("Apres undo: %zu objet(s) dans la scene\n", scene.getObjects().size());

    // Test redo : le rectangle doit revenir, avec le meme id
    history.redo(scene);
    printf("Apres redo: %zu objet(s) dans la scene\n", scene.getObjects().size());

    SceneObject* restored = scene.getObject(id);
    if (restored) {
        printf("Objet restaure avec id=%d, x=%.1f, y=%.1f\n",
               restored->id, restored->x, restored->y);
    } else {
        printf("ERREUR: objet non retrouve apres redo\n");
    }

    return 0;
}
