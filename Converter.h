#ifndef SECONDPART_CONVERTER_H
#define SECONDPART_CONVERTER_H

#include "Searchable.h"
#include <stack>


std::stack<std::string> fromStatesToStrings(std::vector<MyState *> &path) {
    std::stack<std::string> directions;
    for (auto &curr : path) {
        if (curr->getCameFrom() == nullptr) {
            break;
        }
        if (curr->getStateId().row == curr->getCameFrom()->getStateId().row) { // parent is LEFT/RIGHT
            if (curr->getStateId().col > curr->getCameFrom()->getStateId().col)
                directions.push("Right"); //parent if from the LEFT
            else
                directions.push("Left"); //parent is from the RIGHT
        } else { //parent is UP/RIGHT
            if (curr->getStateId().row > curr->getCameFrom()->getStateId().row)
                directions.push("Down"); //parent if from UPPER state
            else
                directions.push("Up");
        }

    }
    return directions;
}


#endif //SECONDPART_CONVERTER_H
