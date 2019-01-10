#include "FileCacheManager.h"

bool FileCacheManager::loadData(const char *fileName) {
    string token, p, s;
    stringstream ss;
    ifstream file(fileName);

    if (!file) {
        std::cout << ERR_LOAD << fileName << std::endl;
        return false;
    }

    while (getline(file, token, SEPARATE_CHAR)) {
        // to ignore endOfLine.
        while (token[0] == EOL) {
            token = token.substr(1, token.length() - 1);
        }
        if (!token.empty()) {
            p = token;
            getline(file, token, EOL);
            s = token;
            probsAndSols.insert(pair<string, string>(p, s));
        }
    }
    file.close();
    return true;
}

bool FileCacheManager::saveData(const char *fileName) {
    auto it = probsAndSols.begin();

    ofstream file(fileName);
    if (!file) {
        std::cout << ERR_SAVE << fileName << std::endl;
        return false;
    }

    for (; it != probsAndSols.end(); ++it) {
        // saving problems and solutions in the right format.
        file << it->first << SEPARATE_CHAR << it->second << "\n";
    }
    return true;
}

bool FileCacheManager::isSolutionExists(const string &problem) {
    auto it = probsAndSols.find(problem);
    return it != probsAndSols.end();
}

string FileCacheManager::getSolutionFor(const string &problem) {
    auto it = probsAndSols.find(problem);
    return isSolutionExists(problem) ? it->second : nullptr;
}

void FileCacheManager::saveSolution(const string &problem,
                                    const string &solution) {
    probsAndSols.insert(pair<string, string>(problem, solution));
}
