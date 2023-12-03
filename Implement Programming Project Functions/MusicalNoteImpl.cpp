#include "MusicalNoteApi.h"
#include <cmath>
#include <iostream> // Add include for std::cerr

double computeFrequency(int nu, int k)
{
    double f = -1.0; // computed frequency in Hertz (Hz)

    // Preconditions:
    // k >= 0
    // k < Number of Halftones (12)
    // n >= 0
    if ((k >= 0) && (k < k_nHalfTonesInOctave) && (nu >= 0))
    {
        // Calculate the frequency in Hz based on the value of nu and k.
        // Use the pow function and supply it with a fractional exponent. Use the reference frequency constant,
        // k_dFrequencyRef, defined in the header file.
        f = k_dFrequencyRef * pow(2.0, static_cast<double>(nu) + static_cast<double>(k) / k_nHalfTonesInOctave);
    }
    else
    {
        std::cerr << "ERROR: computeFrequency preconditions not satisfied; nu (" << nu << ") or k (" << k << ") invalid" << std::endl;
    }
    return f;
}

double computeWavelengthInCm(double dFrequencyHz)
{
    double dWavelengthCm = -1.0; // Computed wavelength in centimeters returned by computeWavelengthInCm

    // Preconditions:
    // dFrequencyHz > 0.0
    // dFrequencyHz must be finite (i.e. not positive or negative infinity, or a signaling or quiet Not-a-Number).
    // Infinite frequency makes no sense (not even Jimi Hendrix can do that) and is treated as
    // an error.
    // The expressions below check the negation of the preconditions and report an error.
    // Report an error if dFrequencyHz < 0.0
    // Report an error if dFrequencyHz is not finite (a NaN or positive or negative infinity)
    // Report an error if dFrequencyHz is exactly 0 (including either positive or negative zero).
    // A frequency of zero produces no wave at all and thus has no wavelength at all; zero
    // frequency makes no sense for this
    // function and is treated as an error.
    if ((dFrequencyHz <= 0.0) || (!std::isfinite(dFrequencyHz)) || (FP_ZERO == std::fpclassify(dFrequencyHz)))
    {
        dWavelengthCm = -1.0; // Indicate Error
        std::cerr << "ERROR: computeWavelengthInCm preconditions not satisfied; dFrequencyHz invalid: " << dFrequencyHz << std::endl;
    }
    else
    {
        // Input satisfies all preconditions; perform computation
        // Calculate the wavelength in centimeters and assign the value to the double precision
        // variable dWavelengthCm. Use one of the constants defined in the header file.
        dWavelengthCm = k_dSpeedOfSoundCmPerSecond / dFrequencyHz;
    }
    return dWavelengthCm;
}

const std::string getNoteName(int nu, int k)
{
    const static std::string a_strNotePrefix[] = {
        "C", "C#", "D","D#", "E", "F", "F#", "G", "G#", "A", "A#", "B",
    };
    std::string strNote = "UNK";

    // Preconditions:
    // k >= 0
    // k < Number of Halftones (12)
    // n >= 0
    if ((k >= 0) && (k < k_nHalfTonesInOctave) && (nu >= 0))
    {
        // Express strNote in terms of an element of a_strNotePrefix and the stringized form of
        // the integer nu.
        //
        // Use std::to_string to covert integer nu to a string.
        //
        // Concatenate the prefix with the string representation
        // of nu to form the note name. For example, "C#0" = "C#" + "0"
        strNote = a_strNotePrefix[k] + std::to_string(nu);
    }
    return strNote;
}

int main()
{
    int nOctaves = 11; // Number of octaves over which to compute frequencies.

    // Compute for Octaves 0 through 10 (previously you computed only zero through 8)
    for (int nu = 0; nu < nOctaves; nu++)
    {
        for (int k = 0; k < k_nHalfTonesInOctave; k++)
        {
            // Call your function to compute the frequency in Hertz of the note corresponding to
            // octave nu and half-tone k and assign it to a variable named f of the appropriate type.
            double f = computeFrequency(nu, k);

            // Call your function to compute the wavelength of the note given its frequency in Hertz
            // and assign it to a variable named dWavelengthCentimeters of the appropriate type.
            double dWavelengthCentimeters = computeWavelengthInCm(f);

            // Call function getNoteName to obtain the name of the note as a string variable and
            // assign it to a variable named strNote of the appropriate type.
            std::string strNote = getNoteName(nu, k);

            // Print the results
            std::cout << "Note: " << strNote << "; nu: " << nu << "; k: " << k << "; frequency: " << f << " Hz; wavelength: " << dWavelengthCentimeters << " cm" << std::endl;
        }
    }

    // Check error handling
    std::cout << std::endl << std::endl;
    std::cout << "------------------------------------------------ CHECK ERROR HANDLING ---------------------------------------------------------------" << std::endl;

    // Call your function to compute the frequency in Hertz of the note corresponding to
    // octave nu and half-tone k and assign it to a variable named f of the appropriate type.
    // Pass -1 as the value for argument nu and -1 for the value for argument k.
    double fError = computeFrequency(-1, -1);

    // Call your function to compute the wavelength of the note given its frequency in Hertz
    // and assign it to a variable named dWavelengthCentimeters of the appropriate type.
    // Pass -16.35 as the value for the argument dFrequencyHz.
    double dWavelengthError = computeWavelengthInCm(-16.35);

    // Call function getNoteName to obtain the name of the note as a string variable and
    // assign it to a variable named strNote of the appropriate type.
    // Pass -1 as the value for argument nu and -1 for the value for argument k.
    std::string strNoteError = getNoteName(-1, -1);

    // Print the results
    std::cout << "Note: " << strNoteError << "; nu: -1; k: -1; frequency: " << fError << " Hz; wavelength: " << dWavelengthError << " cm" << std::endl;

    return 0;
}

