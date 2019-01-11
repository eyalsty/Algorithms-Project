#ifndef SECONDPART_STATE_H
#define SECONDPART_STATE_H


#define INFINITY -1

typedef enum {
    white, grey, black
} Color;

template<class T>
class State {
    T stateId;
    double edgeCost;
    double minPath;
    State<T> *cameFrom;
    Color color;
public:
    State(const T &_stateId, double _cost) :
            stateId(_stateId), edgeCost(_cost) {
        cameFrom = nullptr;
        minPath = INFINITY;
        color = white;
    }

    T getStateId() const {
        return stateId;
    }

    double getEdgeCost() {
        return edgeCost;
    }

    void setEdgeCost(double _cost) {
        edgeCost = _cost;
    }

    void setMinPath(double _minPath) {
        minPath = _minPath;
    }

    double getMinPath() {
        return minPath;
    }


    State<T> *getCameFrom() {
        return cameFrom;
    }

    void setCameFrom(State<T> *_cameFrom) {
        cameFrom = _cameFrom;
    }

    bool isEqual(const State<T> &other) {
        return this->stateId == other.stateId;
    }

    void setColor(int _color) {
        color = (Color) _color;
    }

    Color getColor() {
        return color;
    }
};

#endif