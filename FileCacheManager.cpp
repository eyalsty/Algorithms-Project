#include "FileCacheManager.h"

void FileCacheManager::terminateEOL(string &line) {
    if (line[line.length() - 1] == '\r') {
        line = line.substr(0, line.length() - 1);
    }
}

bool FileCacheManager::loadData(const char *fileName) {
    string line, solution;
    ifstream file(fileName);
    vector<string> problem;

    if (!file) {
        std::cout << ERR_LOAD << fileName << std::endl;
        return false;
    }

    while (getline(file, line)) {
        terminateEOL(line);
        if (line == "$") {
            getline(file, solution);
            terminateEOL(solution);
            probsAndSols.insert(pair<vector<string>,
                    string>(problem, solution));
            problem.clear();
            continue;
        }
        problem.push_back(line);
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
        vector<string> data = it->first;
        auto matLine = data.begin();
        for (; matLine != data.end(); ++matLine) {
            // saves each line of the vector.
            file << *matLine << EOL;
        }
        // saves the separate char with new line, and than the solution.
        file << SEPARATE_CHAR << EOL << it->second << EOL;
    }
    return true;
}

bool FileCacheManager::isSolutionExists(const vector<string> &problem) {
    auto it = probsAndSols.find(problem);
    return it != probsAndSols.end();
}

string FileCacheManager::getSolutionFor(const vector<string> &problem) {
    auto it = probsAndSols.find(problem);
    return isSolutionExists(problem) ? it->second : nullptr;
}

void FileCacheManager::saveSolution(const vector<string> &problem,
                                    const string &solution) {
    probsAndSols.insert(pair<vector<string>, string>(problem, solution));
}