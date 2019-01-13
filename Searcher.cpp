#include "Searcher.h"

std::vector<MyState *> Searcher::traceBack(MyState *node) {
    std::vector<MyState *> trace;

    while (node->getCameFrom() != nullptr) {
        trace.push_back(node);
        node = node->getCameFrom();
    }
    trace.push_back(node);
    return trace;
}