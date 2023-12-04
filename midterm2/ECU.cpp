#include <iostream>

class EngineControlUnit {
private:
    bool autoJacksActivated;
    bool gripTiresActivated;
    bool infraredLightsActivated;

    void actuateHydraulicJacks() {
        autoJacksActivated = !autoJacksActivated;
        std::cout << "Hydraulic Jacks ";
        if (autoJacksActivated) {
            std::cout << "activated" << std::endl;
        } else {
            std::cout << "deactivated" << std::endl;
        }
    }

    void activateGripTires() {
        if (autoJacksActivated) {
            std::cout << "Cannot activate Grip Tires while Auto-Jacks are activated" << std::endl;
        } else {
            gripTiresActivated = !gripTiresActivated;
            std::cout << "Grip Tires ";
            if (gripTiresActivated) {
                std::cout << "activated" << std::endl;
            } else {
                std::cout << "deactivated" << std::endl;
            }
        }
    }

    void activateInfraredLights() {
        infraredLightsActivated = !infraredLightsActivated;
        std::cout << "Infrared Lights ";
        if (infraredLightsActivated) {
            std::cout << "activated" << std::endl;
        } else {
            std::cout << "deactivated" << std::endl;
        }
    }

public:
    EngineControlUnit() {
        autoJacksActivated = false;
        gripTiresActivated = false;
        infraredLightsActivated = false;
    }

    ~EngineControlUnit() {}

    void handleCommand(char button) {
        switch(button) {
            case 'A':
                actuateHydraulicJacks();
                break;
            case 'B':
                activateGripTires();
                break;
            case 'E':
                activateInfraredLights();
                break;
            default:
                std::cout << "Invalid button" << std::endl;
        }
    }
};

int main() {
    EngineControlUnit ecu;

    char button;
    do {
        std::cout << "Enter button (A, B, E) or X to turn off ignition: ";
        std::cin >> button;

        if (button != 'X') {
            ecu.handleCommand(button);
        }
    } while (button != 'X');

    return 0;
}
