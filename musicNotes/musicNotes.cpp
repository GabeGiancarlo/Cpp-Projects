#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    // Constants
    const double referenceFrequency = 16.35; // Reference frequency for C0
    const double twelfthRootOfTwo = 1.059463094359;
    const double speedOfSound = 345.0; // Speed of sound in air at room temperature (m/s)

    // Output reference frequency and speed of sound
    std::cout << "Reference Frequency (fR): " << referenceFrequency << " Hz" << std::endl;
    std::cout << "Speed of Sound (c): " << speedOfSound << " m/s" << std::endl;

    // Table header
    std::cout << std::left << std::setw(5) << "Note" << std::setw(5) << "Octave" << std::setw(5) << "Half-tone" << std::setw(15) << "Frequency (Hz)" << std::setw(15) << "Wavelength (cm)" << std::endl;

    // Define the notes to calculate
    struct Note {
        std::string name;
        int octave;
        int halfTone;
    };

    Note notes[] = {
        {"C0", 0, 0},
        {"C#0", 0, 1},
        {"D0", 0, 2},
        {"C4", 4, 0},
        {"D#7", 7, 3},
        {"C8", 8, 0}
    };

    for (const auto& note : notes) {
        // Calculate frequency
        double frequency = referenceFrequency * std::pow(2.0, note.octave) * std::pow(twelfthRootOfTwo, note.halfTone);
        // Calculate wavelength
        double wavelength = speedOfSound / frequency;

        // Display the results
        std::cout << std::left << std::setw(5) << note.name << std::setw(5) << note.octave << std::setw(5) << note.halfTone;
        std::cout << std::fixed << std::setprecision(2) << std::setw(15) << frequency << std::setw(15) << wavelength * 100 << std::endl; // Convert meters to centimeters
    }

    return 0;
}
