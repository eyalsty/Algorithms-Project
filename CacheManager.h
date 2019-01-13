#ifndef SECONDPART_CACHEMANAGER_H
#define SECONDPART_CACHEMANAGER_H

#include <string>
#include <vector>

using namespace std;

class CacheManager {
public:
    virtual bool isSolutionExists(const vector<string> &problem) = 0;

    virtual string getSolutionFor(const vector<string> &problem) = 0;

    virtual void saveSolution(const vector<string> &problem,
                              const string &solution) = 0;

    virtual ~CacheManager() {}
};
#endif