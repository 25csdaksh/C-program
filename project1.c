#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

// Utility function to print a timestamp
std::string currentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    return std::ctime(&t); // returns a formatted string
}

int main() {
    // Greeting
    std::cout << "=============================\n";
    std::cout << "   🚀 Advanced Hello World   \n";
    std::cout << "=============================\n\n";

    // Print message
    std::string message = "Hello, World!";
    std::cout << message << std::endl;

    // Show timestamp
    std::cout << "\nProgram executed at: " << currentTime() << std::endl;

    // Exit gracefully
    std::cout << "✨ Program finished successfully ✨" << std::endl;
    return 0;
}
