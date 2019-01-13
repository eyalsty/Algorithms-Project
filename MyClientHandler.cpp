#include "MyClientHandler.h"

void MyClientHandler::ifError(ssize_t n, const char *errorType) {
    if (n < 0) {
        perror(errorType);
        exit(1);
    }
}

string MyClientHandler::getLineFromSocket(int sockNum) {
    ssize_t n;
    string line;
    char buffer[256] = {0};

    n = read(sockNum, buffer, 256);
    ifError(n, "ERROR reading from socket");

    line = buffer;

    // moving the EOL char so the line will be in the right format.
    if (line[line.length() - 1] == '\n') {
        line = line.substr(0, line.length() - 1);
    }
    return line;
}

void MyClientHandler::getMatrixFromClient(vector<string> &matrix, int socket) {
    string matrixLine = getLineFromSocket(socket);
    while (matrixLine != "end") {
        matrix.push_back(matrixLine);
        matrixLine = getLineFromSocket(socket);
    }
}

void MyClientHandler::handleClient(int socket) {
    ssize_t n;
    string answer;
    vector<string> matrix;

    getMatrixFromClient(matrix, socket);
    if (cm->isSolutionExists(matrix)) {
        answer = cm->getSolutionFor(matrix);
    } else {
        Searchable *maze = new MazeMatrix(matrix);
        vector<MyState *> states = solver->solve(maze);

        //stack<string> directions = fromStatesToStrings(states);
        //answer =
    }

    n = write(socket, answer.c_str(), answer.size());
    ifError(n, "ERROR writing to socket");

}