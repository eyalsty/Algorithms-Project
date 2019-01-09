#ifndef SECONDPART_SOLVER_H
#define SECONDPART_SOLVER_H

template<class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(const Problem &p) = 0;
    virtual ~Solver(){};
};
#endif