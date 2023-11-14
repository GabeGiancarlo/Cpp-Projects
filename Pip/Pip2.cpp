#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

int main() {
    double pi = 0.0;

    std::cout << std::fixed;
    std::cout << std::setprecision(DBL_DIG);

    for (int n = 2; n <= 1048576; n *= 2) {
        for (int k = 0; k <= n; k++) {
            double term = pow(-1.0, k) / (2.0 * k + 1);
            pi += term;
        }

        pi *= 4;

        std::cout << "PI (approx): " << pi << "; n: " << std::setw(7) << n << std::endl;
    }

    std::cout << "PI (actual): " << "3.141592653589793" << std::endl;

    return 0;
}
