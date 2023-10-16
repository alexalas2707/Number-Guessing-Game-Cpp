#include <iostream>

int main() {
    // Declare variables
    int low = 1;
    int high = 100;
    int guess;
    char feedback;
    int attempts = 0;

    // Introduction to the game
    std::cout << "Think of a number between 1 and 100 (inclusive) and I'll try to guess it!" << std::endl;
    std::cout << "Once you've thought of a number, press ENTER to continue...";
    std::cin.get();

    // Main loop
    while (true) {
        // Increase the attempts counter
        attempts++;

        // Compute the next guess by taking the middle of the current range (binary search algorithm)
        guess = (low + high) / 2;

        // Display the guess
        std::cout << "My guess is: " << guess << std::endl;
        std::cout << "Is my guess (l)ower, (h)igher, or (c)orrect? ";
        std::cin >> feedback;

        // Process feedback
        switch (feedback) {
        case 'l':
        case 'L':
            high = guess - 1; // Adjust the upper bound to just below the guess
            break;
        case 'h':
        case 'H':
            low = guess + 1;  // Adjust the lower bound to just above the guess
            break;
        case 'c':
        case 'C':
            std::cout << "Awesome! I guessed your number in " << attempts << " attempts!" << std::endl;
            return 0;
        default:
            std::cout << "Invalid input. Please use 'l', 'h', or 'c'." << std::endl;
        }
    }

    return 0;
}
