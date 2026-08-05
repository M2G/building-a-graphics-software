#include "command.h"

void CommandHistory::push(Command cmd) {
    m_undoStack.push_back(cmd);
    m_redoStack.clear();
};

bool CommandHistory::undo(Scene& scene) {
    // m_undoStack.pop_back();
}

bool CommandHistory::redo(Scene& scene) {

}

bool CommandHistory::canRedo() const {
    !m_redoStack.empty();
}

bool CommandHistory::canUndo() const {
    !m_undoStack.empty();
};

void CommandHistory::applyForward(const Command& cmd, Scene& scene) {
    switch (cmd.type) {
        case CommandType::ADD: {
            scene.addObject(cmd.objectSnapshot);
            break;
        }
        case CommandType::DELETE: {
            scene.removeObject(cmd.objectId);
            break;
        }
        case CommandType::MOVE: {
            SceneObject* obj = scene.getObject(cmd.objectId);
            if (obj) {
                obj->x = cmd.afterX;
                obj->y = cmd.afterY;
            }
            break;
        }
        case CommandType::RESIZE: {
            SceneObject* obj = scene.getObject(cmd.objectId);
            if (obj) {
                obj->height = cmd.afterHeight;
                obj->width = cmd.afterWidth;
            }
            break;
        }
    }
}
// la même mais, l'inverse point de vu logique
void CommandHistory::applyInverse(const Command& cmd, Scene& scene) {
    switch (cmd.type) {
        case CommandType::ADD: {
            scene.removeObject(cmd.objectId);
            break;
        }
        case CommandType::DELETE: {
            scene.restoreObject(cmd.objectSnapshot);
            break;
        }
        case CommandType::MOVE: {
            SceneObject* obj = scene.getObject(cmd.objectId);
            if (obj) {
                obj->x = cmd.afterX;
                obj->y = cmd.afterY;
            }
            break;
        }
        case CommandType::RESIZE: {
            SceneObject* obj = scene.getObject(cmd.objectId);
            if (obj) {
                obj->height = cmd.afterHeight;
                obj->width = cmd.afterWidth;
            }
            break;
        }
    }
}