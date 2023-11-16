#if !defined(MUSICAL_NOTE_API_H)
#define MUSICAL_NOTE_API_H // Sentinel

/// @brief Musical Notes Application Programming Interface (API) Header File
/// CPSC-298-6 Programming in C++ Project Musical Note Frequencies with Functions
/// @author giancarlo.student@chapman.edu

#include <string>

const int k_nOctaves = 9;      // Number of octaves to consider
const int k_nHalfTones = 12;   // Number of Half-tones in an octave

std::string a_strNotes[] = {
    // ... (same as in the provided code)
};

/**
 * @brief Compute the frequency of a musical note.
 *
 * This function takes the octave number (nu) and the halftone index (k)
 * and calculates the frequency in Hertz (Hz).
 *
 * @param nu The octave number.
 * @param k The halftone index.
 * @return The frequency of the note in Hertz.
 * @pre nu >= 0 && nu <= k_nOctaves && k >= 0 && k < k_nHalfTones
 */
double computeFrequency(int nu, int k);

/**
 * @brief Compute the wavelength of a musical note.
 *
 * This function takes the octave number (nu) and the halftone index (k)
 * and calculates the wavelength in centimeters.
 *
 * @param nu The octave number.
 * @param k The halftone index.
 * @return The wavelength of the note in centimeters.
 * @pre nu >= 0 && nu <= k_nOctaves && k >= 0 && k < k_nHalfTones
 */
double computeWavelengthInCm(int nu, int k);

/**
 * @brief Get the name of a musical note.
 *
 * This function takes the octave number (nu) and the halftone index (k)
 * and returns the name of the note as a string.
 *
 * @param nu The octave number.
 * @param k The halftone index.
 * @return The name of the note.
 * @pre nu >= 0 && nu <= k_nOctaves && k >= 0 && k < k_nHalfTones
 */
std::string getNoteName(int nu, int k);

#endif
