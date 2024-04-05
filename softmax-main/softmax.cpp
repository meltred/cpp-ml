#include "lib/softmax.h"

#include "utility"
#include "vector"

double Softmax::softmax_e(double value)  {
    return std::exp(value / this->temperature);
}

double Softmax::softmax_sum()  {
    double result = 0.0;
    for (auto &data: this->data_vector) {
        result += this->softmax_e(data);
    }

    return result;
}

size_t Softmax::size()  {
    return this->data_vector.size();
}

Softmax::Softmax(std::vector<double> input)  {
    this->data_vector = input;
}

std::vector<double> Softmax::get_normalized_vector()  {
    std::vector<double> result;
    result.reserve(this->size());

    double sum = this->softmax_sum();

    for (auto val: this->data_vector) {
        result.push_back(softmax_e(val) / sum);
    }

    return result;
}

double Softmax::get_temperature()  {
    return this->temperature;
}

double Softmax::set_temperature(double temperature)  {
    return (this->temperature = temperature);
}

double Softmax::increment_temperature(double increment = 0.1)  {
    return (this->temperature = this->temperature + increment);
}

double Softmax::decrement_temperature(double decrement = 0.1) {
    double new_temperature = std::max<double>(this->temperature - decrement, 0);

    if (new_temperature < 0) {
        throw std::invalid_argument("Decrementing temperature makes it negative, which is not allowed");
    }

    return (this->temperature = new_temperature);
}
