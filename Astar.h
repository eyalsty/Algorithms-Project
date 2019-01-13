#ifndef SECONDPART_A_H
#define SECONDPART_A_H

#include <queue>
#include <cmath>
#include "Searcher.h"

struct AstarComparator {
    bool operator()(std::pair<MyState *, double> l, std::pair<MyState *, double> r) {
        return l.second > r.second;
    }
};

typedef std::priority_queue<std::pair<MyState *, double>, std::vector<std::pair<MyState *, double>>, AstarComparator>
        openMyPriorityQueue;


class Astar : public Searcher {
private:
    Searchable *searchable; //being Initialized in "search" function
public:

    std::vector<MyState *> search(Searchable *searchable) override;

    double getHuristic(MyState *curr);

    double calcF(MyState *s);

    openMyPriorityQueue addAndUpdate(openMyPriorityQueue old, MyState *toAdd);

};


#endif //SECONDPART_A_H
