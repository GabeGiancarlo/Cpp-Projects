#include <iostream>
#include <fstream>
#include <string>

class LazyCatererSequence {
private:
    int* mp_iNumbers;
    int m_nMax;
public:
    LazyCatererSequence();
    LazyCatererSequence(int nMax);
    ~LazyCatererSequence();
    void DisplaySequence();
    void SaveToFile(std::string fileName);
};

LazyCatererSequence::LazyCatererSequence() {
    m_nMax = 0;
    mp_iNumbers = new int[1];
    mp_iNumbers[0] = 1;
}

LazyCatererSequence::LazyCatererSequence(int nMax) {
    m_nMax = nMax;
    mp_iNumbers = new int[nMax + 1];
    for (int i = 0; i <= nMax; i++) {
        mp_iNumbers[i] = (i * i + i + 2) / 2;
    }
}

LazyCatererSequence::~LazyCatererSequence() {
    delete[] mp_iNumbers;
    std::cout << "Destructor called." << std::endl;
}

void LazyCatererSequence::DisplaySequence() {
    for (int i = 0; i <= m_nMax; i++) {
        std::cout << mp_iNumbers[i] << std::endl;
    }
}

void LazyCatererSequence::SaveToFile(std::string fileName) {
    std::ofstream outFile(fileName);
    for (int i = 0; i <= m_nMax; i++) {
        outFile << mp_iNumbers[i] << std::endl;
    }
    outFile.close();
}

int main() {
    LazyCatererSequence sequence(10);
    sequence.DisplaySequence();
    sequence.SaveToFile("lazy_caterer_sequence.txt");

    return 0;
}
