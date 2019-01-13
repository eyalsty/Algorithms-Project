#ifndef SECONDPART_MYCLIENTHANDLER_H
#define SECONDPART_MYCLIENTHANDLER_H

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <strings.h>
#include <string>
#include <cstring>
#include <iostream>

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include "MazeMatrix.h"
#include "Converter.h"

class MyClientHandler : public ClientHandler {
    Solver<Searchable *, vector<MyState *> > *solver;
    CacheManager *cm;
public:
    MyClientHandler(Solver<Searchable *, vector<MyState *> > *_solver,
                    CacheManager *_cm) : solver(_solver), cm(_cm) {}

    void ifError(ssize_t n, const char *errorType);

    string getLineFromSocket(int sockNum);

    void getMatrixFromClient(vector<string> &matrix, int socket);

    void handleClient(int socket) override;

    ~MyClientHandler() {
        // .......
    }
};


#endif