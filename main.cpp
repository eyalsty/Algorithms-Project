#include "StringReverser.h"

int main() {
    Solver<string,string>* ss = new StringReverser;
    string s("Hello, World!");
    std::cout << ss->solve(s) << std::endl;
    delete ss;
    return 0;
}