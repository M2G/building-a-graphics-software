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
        case CommandType::ADD:
            break;
        case CommandType::DELETE:
            break;
        case CommandType::MOVE:
            break;
        case CommandType::RESIZE:
            break;
    }
}

void CommandHistory::applyInverse(const Command& cmd, Scene& scene) {
    switch (cmd.type) {
        case CommandType::ADD:
            break;
        case CommandType::DELETE:
            break;
        case CommandType::MOVE:
            break;
        case CommandType::RESIZE:
            break;
    }
}