#include "MusicalNoteApi.h"
#include <iostream>
#include <iomanip>
#include <cmath>

const double speedOfSound = 34500.0;  // Speed of sound in centimeters per second

int main() {
    const double fR = 16.35;  // Reference Frequency in Hz

    for (int nu = 0; nu <= k_nOctaves; ++nu) {
        for (int k = 0; k < k_nHalfTones; ++k) {
            // Calculate frequency (f)
            double f = computeFrequency(nu, k);

            // Calculate wavelength (dWavelengthCentimeters)
            double dWavelengthCentimeters = computeWavelengthInCm(nu, k);

            // Select name for note (e.g., "C#0") from array
            std::string strNote = getNoteName(nu, k);

            // Print the details
            std::cout << std::setw(5) << "Note: " << std::setw(4) << strNote
                      << "; nu: " << std::setw(2) << nu << "; k: " << std::setw(2) << k
                      << "; frequency: " << std::setw(10) << f << " Hz; wavelength: "
                      << std::setw(10) << dWavelengthCentimeters << " cm" << std::endl;
        }
    }

    // Test the functions with erroneous input
    int nu = -1;
    int k = 20;

    // Call functions and assign return values to variables
    double erroneousFrequency = computeFrequency(nu, k);
    double erroneousWavelength = computeWavelengthInCm(nu, k);
    std::string erroneousNote = getNoteName(nu, k);

    // Print results
    std::cout << "Erroneous Frequency: " << erroneousFrequency << " Hz" << std::endl;
    std::cout << "Erroneous Wavelength: " << erroneousWavelength << " cm" << std::endl;
    std::cout << "Erroneous Note: " << erroneousNote << std::endl;

    return 0;
}

// Implementation of computeFrequency
double computeFrequency(int nu, int k, double fR) {
    // Preconditions check
    if (!(nu >= 0 && nu <= k_nOctaves && k >= 0 && k < k_nHalfTones)) {
        std::cerr << "Error: Invalid input values for computeFrequency." << std::endl;
        // Return an appropriate value indicating an error
        return -1.0;
    }

    // Calculate frequency in Hertz
    return fR * std::pow(2.0, static_cast<double>(nu) + k / 12.0);
}

// Implementation of computeWavelengthInCm
double computeWavelengthInCm(int nu, int k) {
    // Preconditions check
    if (!(nu >= 0 && nu <= k_nOctaves && k >= 0 && k < k_nHalfTones)) {
        std::cerr << "Error: Invalid input values for computeWavelengthInCm." << std::endl;
        // Return an appropriate value indicating an error
        return -1.0;
    }

    // Calculate wavelength in centimeters
    double frequency = computeFrequency(nu, k);
    return speedOfSound / frequency;
}

// Implementation of getNoteName
std::string getNoteName(int nu, int k) {
    // Preconditions check
    if (!(nu >= 0 && nu <= k_nOctaves && k >= 0 && k < k_nHalfTones)) {
        std::cerr << "Error: Invalid input values for getNoteName." << std::endl;
        // Return an appropriate string indicating an error
        return "UNK";
    }

    // Select name for note from array
    return a_strNotes[nu * k_nHalfTones + k];
}
