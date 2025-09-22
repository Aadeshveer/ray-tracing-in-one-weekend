#include "interval.hpp"

interval::interval() {
    min = +infinity;
    max = -infinity;
}

interval::interval(double min, double max) {
    this->min = min;
    this->max = max;
}

double interval::size() const {
    return max-min;
}

bool interval::contains(double x) const {
    return (x >= min) && (x <= max);
}

bool interval::surrounds(double x) const {
    return min<x && max>x;
}