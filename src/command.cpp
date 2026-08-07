#include "command.h"

void CommandHistory::push(Command cmd) {
    m_undoStack.push_back(cmd);
    m_redoStack.clear();
};

bool CommandHistory::undo(Scene& scene) {
    if (m_undoStack.empty()) return false;

    Command cmd = m_undoStack.back();
    m_undoStack.pop_back();

    applyInverse(cmd, scene);

    m_redoStack.push_back(cmd);
    return true;
}

bool CommandHistory::redo(Scene& scene) {
    if (m_redoStack.empty()) return false;

    Command cmd = m_redoStack.back();
    m_redoStack.pop_back();

    applyForward(cmd, scene);

    m_undoStack.push_back(cmd);
    return true;
}

bool CommandHistory::canRedo() const {
    return !m_redoStack.empty();
}

bool CommandHistory::canUndo() const {
    return !m_undoStack.empty();
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
                obj->x = cmd.beforeX;
                obj->y = cmd.beforeY;
            }
            break;
        }
        case CommandType::RESIZE: {
            SceneObject* obj = scene.getObject(cmd.objectId);
            if (obj) {
                obj->height = cmd.beforeHeight;
                obj->width = cmd.beforeWidth;
            }
            break;
        }
    }
}