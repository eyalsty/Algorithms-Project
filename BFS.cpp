#include "BFS.h"

std::vector<MyState *> BFS::search(Searchable *searchable) {
    std::queue<MyState *> q;
    std::vector<MyState *> adj;
    MyState *s;
    s = searchable->getInitialState();
    s->setMinPath(0);
    s->setColor(grey);
    q.push(s);
    while (!q.empty()) {
        s = q.front();
        q.pop();
        adj = searchable->getAllPossibleStates(*s);
        for (auto &v : adj) {
            if (v->getColor() == white) {
                v->setColor(grey);
                v->setCameFrom(s);
                v->setMinPath(s->getMinPath() + v->getEdgeCost());
                q.push(v);
            }
        }
        s->setColor(black);
        evaluatedCounter++;
    }
//return the path to the goal
    return traceBack(searchable->getGoal());
}


int BFS::getEvaluatedCounter() {
    return this->evaluatedCounter;
}

std::vector<MyState *> BFS::traceBack(MyState *trg) {
    std::vector<MyState *> path;
    MyState *curr = trg;
    while (curr != nullptr) {
        path.push_back(curr);
        curr = curr->getCameFrom();
    }
    return path;
}