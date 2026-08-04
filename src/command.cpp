#include "command.h"

void CommandHistory::push(Command cmd) {
    m_undoStack.push_back(cmd);
    m_redoStack.clear();
};

bool CommandHistory::undo(Scene& scene){}

bool CommandHistory::redo(Scene& scene){}

bool CommandHistory::canRedo() const {}

bool CommandHistory::canUndo() const {};

void CommandHistory::applyForward(const Command& cmd, Scene& scene){}

void CommandHistory::applyInverse(const Command& cmd, Scene& scene){}