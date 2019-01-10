#ifndef SECONDPART_FILECACHEMANAGER_H
#define SECONDPART_FILECACHEMANAGER_H

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>

#include "CacheManager.h"

#define ERR_LOAD "ERROR Loading From Cache File: "
#define ERR_SAVE "ERROR saving to Cache File: "
#define FILE_NAME "cache.txt"
#define SEPARATE_CHAR '$'
#define EOL '\n'

class FileCacheManager : public CacheManager {
    unordered_map<string, string> probsAndSols;

    /* Private Helper methods. */
    bool loadData(const char *fileName);

    bool saveData(const char *fileName);

public:
    FileCacheManager() {
        this->loadData(FILE_NAME);
    }

    bool isSolutionExists(const string &problem);

    string getSolutionFor(const string &problem);

    void saveSolution(const string &problem,
                      const string &solution);

    ~FileCacheManager() {
        this->saveData(FILE_NAME);
    }
};
#endif