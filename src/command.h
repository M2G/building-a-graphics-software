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

class CommandHistory {
public:
    void push(Command command);
    bool undo(Scene& scene);
    bool redo(Scene& scene);
    bool canUndo() const; // not sure
    bool canRedo() const; // not sure

private:
    std::vector<Command> m_undoStack;
    std::vector<Command> m_redoStack;
    void applyInverse(const Command& cmd, Scene& scene); // not sure
    void applyForward(const Command& cmd, Scene& scene); // not sure
};