#ifndef SECONDPART_CACHEMANAGER_H
#define SECONDPART_CACHEMANAGER_H

#include <string>

using namespace std;

class CacheManager {
public:
    virtual bool isSolutionExists(const string &problem) = 0;

    virtual string getSolutionFor(const string &problem) = 0;

    virtual void saveSolution(const string &problem,
                              const string &solution) = 0;

    virtual ~CacheManager() {}
};
#endif