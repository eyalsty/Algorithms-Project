#ifndef SECONDPART_SEARCHER_H
#define SECONDPART_SEARCHER_H


#include "Searchable.h"

class Searcher {
public:
    virtual std::vector<MyState> search(Searchable *searchable) =0;

    virtual ~Searcher() {}


};


#endif