#ifndef SECONDPART_BESTFIRSTSEARCH_H
#define SECONDPART_BESTFIRSTSEARCH_H

#include <queue>
#include <set>

#include "Searchable.h"
#include "Searcher.h"

struct comparator {
    bool operator()(MyState *l, MyState *r) {
        return l->getMinPath() > r->getMinPath();
    }
};

typedef std::priority_queue<MyState *, std::vector<MyState *>, comparator>
        My_priority_queue;

class BestFirstSearch : public Searcher {
    int evaluatedCounter;
public:
    BestFirstSearch() : evaluatedCounter(0) {}

    std::vector<MyState *> search(Searchable *searchable) override {
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
            ++evaluatedCounter;

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

    std::vector<MyState *> traceBack(MyState *node) override {
        std::vector<MyState *> trace;

        while (node->getCameFrom() != nullptr) {
            trace.push_back(node);
            node = node->getCameFrom();
        }
        trace.push_back(node);
        return trace;
    }

    int getEvaluatedCounter() override {
        return evaluatedCounter;
    }

    My_priority_queue updateQueue(My_priority_queue open) {
        My_priority_queue temp = open;
        while (!open.empty()) {
            temp.push(open.top());
            open.pop();
        }
        return temp;
    }
};


#endif