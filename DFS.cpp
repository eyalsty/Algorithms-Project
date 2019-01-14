#include "DFS.h"

std::vector<MyState *> DFS::search(Searchable *graph) {
    stack.push(graph->getInitialState());

    while (!stack.empty()) {
        MyState *node = stack.top();
        stack.pop();
        if (graph->isGoalState(*node)) {
            //goal = node;
            return traceBack(node);
        }

        if (node->getColor() == white) {

            node->setColor(black);
            ++evaluatedNodes;

            auto adjNodes = graph->getAllPossibleStates(*node);
            auto it = adjNodes.begin();

            for (; it != adjNodes.end(); ++it) {

                if ((*it)->getColor() == white) {
                    (*it)->setCameFrom(node);
                    (*it)->setMinPath(node->getMinPath() +
                                      (*it)->getEdgeCost());
                    stack.push(*it);
                }
            }
        }
    }
}