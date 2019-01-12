#ifndef SECONDPART_BFS_H
#define SECONDPART_BFS_H


#include <queue>
#include <algorithm>
#include "Searchable.h"
#include "Searcher.h"

class BFS : public Searcher {
private:
    int evaluatedCounter = 0;
public:
    std::vector<MyState *> search(Searchable *searchable) override {
        std::queue<MyState *> q;
        std::vector<MyState *> adj;
        MyState *s, *v;
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



    int getEvaluatedCounter() override {
        return this->evaluatedCounter;
    }

    std::vector<MyState *> traceBack(MyState *trg) override {
        std::vector<MyState *> path;
        MyState *curr = trg;
        while (curr != nullptr) {
            path.push_back(curr);
            curr = curr->getCameFrom();
        }
        return path;
    }


};


#endif