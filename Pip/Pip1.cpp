#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

int main() {
    int n;
    double pi = 0.0;
    std::cout << "Enter the upper bound (n) for the Leibnitz formula: ";
    std::cin >> n;

    for (int k = 0; k <= n; k++) {
        double term = pow(-1.0, k) / (2.0 * k + 1);
        pi += term;
    }

    pi *= 4;

    std::cout << std::fixed;
    std::cout << std::setprecision(DBL_DIG);
    std::cout << "PI (approx): " << pi << "; n: " << std::setw(7) << n << std::endl;
    std::cout << "PI (actual): " << "3.141592653589793" << std::endl;

    double next_representable = std::nextafter(3.141592653589793, 3.14);
    std::cout << "Next representable number from 3.141592653589793: " << next_representable << std::endl;

    return 0;
}
