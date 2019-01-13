#include "BestFirstSearch.h"

std::vector<MyState *> BestFirstSearch::search(Searchable *searchable) {
    My_priority_queue open;
    MyState *init = searchable->getInitialState();
    init->setColor(grey);
    init->setMinPath(0);
    open.push(init);

    std::set<MyState *> closed;
    while (!open.empty()) {
        MyState *node = open.top();
        open.pop();

        node->setColor(black);
        closed.insert(node);
        ++evaluatedNodes;

        if (searchable->isGoalState(*node)) {
            return traceBack(node);
        }
        std::vector<MyState *> adj = searchable->getAllPossibleStates(*node);
        auto it = adj.begin();
        for (; it != adj.end(); ++it) {
            if ((*it)->getColor() == white) {
                (*it)->setCameFrom(node);
                (*it)->setMinPath(node->getMinPath() + (*it)->getEdgeCost());
                (*it)->setColor(grey);
                open.push(*it);
            } else if ((*it)->getColor() == grey) {
                if ((*it)->getMinPath() >
                    node->getMinPath() + (*it)->getEdgeCost()) {

                    (*it)->setMinPath(node->getMinPath() + (*it)->getEdgeCost());
                    (*it)->setCameFrom(node);
                    open = updateQueue(open);
                }
            }
        }
    }
//IF NO VALID PATH
}


My_priority_queue BestFirstSearch::updateQueue(My_priority_queue open) {
    My_priority_queue temp = open;
    while (!open.empty()) {
        temp.push(open.top());
        open.pop();
    }
    return temp;
}