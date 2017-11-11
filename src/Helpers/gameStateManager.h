#ifndef GSM_GAMESTATEMANAGER_H
#define GSM_GAMESTATEMANAGER_H

#include <vector>
#include "../States/State.h"


class GameStateManager {
private:
    // Disallow creating an instance of this object
    GameStateManager();

private:
    static std::vector<State*> states;
public:
    static State* getCurrentState();

    static void popState();
    static void pushState(State* state);
};

#endif //GSM_GAMESTATEMANAGER_H
