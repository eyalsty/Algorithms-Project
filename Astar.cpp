#include "Astar.h"

std::vector<MyState *> Astar::search(Searchable *searchable) {
    this->searchable = searchable;
    openMyPriorityQueue q;
    std::vector<MyState *> adj;
    MyState *s = searchable->getInitialState();
    MyState *trg = searchable->getGoal();
    s->setMinPath(0);
    s->setColor(grey);
    q.push(std::pair<MyState *, double>(s, calcF(s)));
    while (!q.empty()) {
        s = q.top().first;
        q.pop();
        if (s == trg) {
            break;
        }
        adj = searchable->getAllPossibleStates(*s);
        for (auto &v : adj) {
            if (v->getColor() == white) {
                v->setMinPath(s->getMinPath() + v->getEdgeCost());
                v->setColor(grey);
                v->setCameFrom(s);
                q.push(std::pair<MyState *, double>(v, calcF(v)));
            } else if (v->getColor() == grey) { //already visited
                //relax
                if (v->getMinPath() > s->getMinPath() + v->getEdgeCost()) {
                    v->setMinPath(s->getMinPath() + v->getEdgeCost());
                    v->setCameFrom(s);
                    q = addAndUpdate(q, v);
                }
            }
        }
        s->setColor(black);
        ++evaluatedNodes;
    }
    return traceBack(searchable->getGoal());
}


double Astar::getHuristic(MyState *curr) {
    MyState *trg = this->searchable->getGoal();
    return sqrt(pow(curr->getStateId().row - trg->getStateId().row, 2) +
                pow(curr->getStateId().col - trg->getStateId().col, 2));
}

double Astar::calcF(MyState *s) {
    double goalH = getHuristic(s);
    return s->getMinPath() + goalH;
}

openMyPriorityQueue Astar::addAndUpdate(openMyPriorityQueue old, MyState *toAdd) {
    openMyPriorityQueue newQueue;
    while (!old.empty()) {
        if (old.top().first->getStateId() == toAdd->getStateId()) {
            newQueue.push(std::pair<MyState *, double>(toAdd, calcF(toAdd)));
            old.pop();
        } else {
            newQueue.push(old.top());
            old.pop();
        }
    }
    return newQueue;
}