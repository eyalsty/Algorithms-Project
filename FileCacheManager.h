#ifndef SECONDPART_FILECACHEMANAGER_H
#define SECONDPART_FILECACHEMANAGER_H

#include <map>
#include <vector>
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
    map<vector<string>, string> probsAndSols;

    /* Private Helper methods. */
    void terminateEOL(string& line);

    bool loadData(const char *fileName);

    bool saveData(const char *fileName);
public:
    FileCacheManager() {
        this->loadData(FILE_NAME);
    }

    bool isSolutionExists(const vector<string> &problem) override;

    string getSolutionFor(const vector<string> &problem) override;

    void saveSolution(const vector<string> &problem,
                      const string &solution) override;

    ~FileCacheManager() {
        this->saveData(FILE_NAME);
    }
};

#endif