#include <softmax.h>

#include <vector>
#include <iostream>
#include <iomanip>

int main(){
    std::vector<double> data { 6.0, -5.0, 4.0, 1.5, 9.9, -2.3, 4.0};

    Softmax s(data);
    s.set_temperature(7.0);

    auto result = s.get_normalized_vector();

    std::cout << std::setprecision(2) << std::fixed;
    for (auto &r: result) {
        std::cout << r << ' ';
    }

    std::cout << '\n';

    return 0;
}
