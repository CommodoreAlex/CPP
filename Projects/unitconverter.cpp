#include <iostream>

using namespace std;

// Conversion functions
float celsiusToFahrenheit(float c) {
    return (c * 9 / 5) + 32;
}

float fahrenheitToCelsius(float f) {
    return (f - 32) * 5 / 9;
}

float kmToMiles(float km) {
    return km * 0.621371;
}

float milesToKm(float mi) {
    return mi / 0.621371;
}

float kgToPounds(float kg) {
    return kg * 2.20462;
}

float poundsToKg(float lb) {
    return lb / 2.20462;
}

int main() {
    int choice, direction;
    float input, result;
    char again;

    do {
        cout << "=== Unit Converter ===\n";
        cout << "1. Temperature (Celsius <-> Fahrenheit)\n";
        cout << "2. Distance (Kilometers <-> Miles)\n";
        cout << "3. Weight (Kilograms <-> Pounds)\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "1. Celsius to Fahrenheit\n";
                cout << "2. Fahrenheit to Celsius\n";
                cout << "Choose direction: ";
                cin >> direction;
                cout << "Enter value: ";
                cin >> input;
                if (direction == 1)
                    result = celsiusToFahrenheit(input);
                else
                    result = fahrenheitToCelsius(input);
                cout << "Result: " << result << endl;
                break;

            case 2:
                cout << "1. Kilometers to Miles\n";
                cout << "2. Miles to Kilometers\n";
                cout << "Choose direction: ";
                cin >> direction;
                cout << "Enter value: ";
                cin >> input;
                if (direction == 1)
                    result = kmToMiles(input);
                else
                    result = milesToKm(input);
                cout << "Result: " << result << endl;
                break;

            case 3:
                cout << "1. Kilograms to Pounds\n";
                cout << "2. Pounds to Kilograms\n";
                cout << "Choose direction: ";
                cin >> direction;
                cout << "Enter value: ";
                cin >> input;
                if (direction == 1)
                    result = kgToPounds(input);
                else
                    result = poundsToKg(input);
                cout << "Result: " << result << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "\nDo you want to convert another unit? (y/n): ";
        cin >> again;
        cout << endl;

    } while (again == 'y' || again == 'Y');

    cout << "Goodbye!" << endl;
    return 0;
}
