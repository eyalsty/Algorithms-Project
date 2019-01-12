#include "DFS.h"

std::vector<MyState *> DFS::search(Searchable *graph) {
    MyState *goal = nullptr;
    stack.push(graph->getInitialState());

    while (!stack.empty()) {
        MyState *node = stack.top();
        stack.pop();
        if (graph->isGoalState(*node)) {
            goal = node;
        }

        if (node->getColor() == white) {

            node->setColor(black);
            ++evaluatedNodes;

            auto adjNodes = graph->getAllPossibleStates(*node);
            auto it = adjNodes.begin();

            for (; it != adjNodes.end(); ++it) {

                if ((*it)->getColor() == white) {
                    (*it)->setCameFrom(node);
                    stack.push(*it);
                }
            }
        }
    }
    return traceBack(goal);
}

std::vector<MyState *> DFS::traceBack(MyState *node) {
    std::vector<MyState *> trace;

    while (node->getCameFrom() != nullptr) {
        trace.push_back(node);
        node = node->getCameFrom();
    }
    trace.push_back(node);
    return trace;
}