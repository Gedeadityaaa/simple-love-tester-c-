#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono> // Untuk delay

// Fungsi untuk mencetak teks dengan delay
void printWithDelay(const std::string& text, int delayMs) {
    for (char c : text) {
        std::cout << c;
        std::cout.flush(); // Pastikan teks langsung muncul
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
    std::cout << std::endl;
}

int main() {
    std::string nama1, nama2;
    int matchPercentage;

    // Seed random number generator
    std::srand(std::time(0));

    // Input names
    std::cout << "Masukan nama pertama: ";
    std::getline(std::cin, nama1);
    std::cout << "masukan nama kedua: ";
    std::getline(std::cin, nama2);

    // Custom match percentage for specific names
    if ((nama1 == "Alice" && nama2 == "Bob") || (nama1 == "Bob" && nama2 == "Alice")) {
        matchPercentage = 95; // Predefined percentage
    } else {
        matchPercentage = std::rand() % 101; // Random percentage
    }

    // Determine description based on percentage
    std::string description;
    if (matchPercentage <= 5) {
        description = "Kurang cocok.";
    } else if (matchPercentage <= 30) {
        description = "Cocok sedikit.";
    } else if (matchPercentage <= 60) {
        description = "Cukup cocok.";
    } else if (matchPercentage <= 90) {
        description = "Sangat cocok.";
    } else {
        description = "Pasangan sempurna!";
    }

    // Output result with delay
    std::string result = "\nMenghitung persentase love...\n";
    printWithDelay(result, 50); // Animasi teks dengan delay 50ms

    std::string output = "Presentase kecocokan antara " + nama1 + " and " + nama2 + ": " 
                         + std::to_string(matchPercentage) + "% - " + description;
    printWithDelay(output, 50); // Hasil akhir dengan animasi

    // Hold CMD open
    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}
