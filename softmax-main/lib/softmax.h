#pragma once

#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <stdexcept>

class Softmax {
private: 
    double temperature = 1.0;
    std::vector<double> data_vector;
    double softmax_e(double value);
    double softmax_sum();
public:
    size_t size() ;
    Softmax(std::vector<double> input) ;
    std::vector<double> get_normalized_vector() ;
    double get_temperature() ;
    double set_temperature(double temperature) ;
    double increment_temperature(double increment) ;
    double decrement_temperature(double decrement);
};
