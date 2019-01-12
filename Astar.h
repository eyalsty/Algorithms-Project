#ifndef SECONDPART_A_H
#define SECONDPART_A_H

#include <queue>
#include <cmath>
#include "Searcher.h"

struct AstarComparator {
    bool operator()(std::pair<MyState *, double> *l, std::pair<MyState *, double> *r) {
        return l->second > r->second;
    }
};

typedef std::priority_queue<std::pair<MyState *, double>, std::vector<std::pair<MyState *, double>>, AstarComparator>
        openMyPriorityQueue;


class Astar : public Searcher {
private:
    int evaluatedCounter = 0;
    Searchable *searchable;
public:

    std::vector<MyState *> search(Searchable *searchable) override {
        openMyPriorityQueue q;
        q.push(std::pair<searchable->getInitialState(),getHuristic(std::pair<searchable->getInitialState(), ) );


    }
};


double getHuristic(MyState *curr, MyState *trg) {
    return sqrt(pow(curr->getStateId().row - trg->getStateId().row, 2) +
                pow(curr->getStateId().col - trg->getStateId().col, 2));
}

double calcF(MyState* s) {
    return pair<
}


#endif //SECONDPART_A_H
