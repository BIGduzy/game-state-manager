#ifndef GSM_GAMESTATEMANAGER_H
#define GSM_GAMESTATEMANAGER_H

#include <vector>
#include "../States/State.h"


class GameStateManager {
private:
    // Disallow creating an instance of this object
    GameStateManager();

private:
    static std::vector<std::unique_ptr<State>> states;
public:
    static std::unique_ptr<State>& getCurrentState();

    static void popState();
    static void pushState(std::unique_ptr<State> state);
};

#endif //GSM_GAMESTATEMANAGER_H
