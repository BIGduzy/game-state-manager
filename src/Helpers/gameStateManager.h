#ifndef GSM_GAMESTATEMANAGER_H
#define GSM_GAMESTATEMANAGER_H

#include <memory>
#include <vector>
#include "../States/State.h"


class GameStateManager {
private:
    // Disallow creating an instance of this object
    GameStateManager();

private:
    static std::vector<std::shared_ptr<State>> states;
public:
    static std::shared_ptr<State> getCurrentState();

    static void popState();
    static void pushState(std::shared_ptr<State> state);
};

#endif //GSM_GAMESTATEMANAGER_H
