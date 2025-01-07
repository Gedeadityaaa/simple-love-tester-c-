#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono> 


void printWithDelay(const std::string& text, int delayMs) {
    for (char c : text) {
        std::cout << c;
        std::cout.flush(); 
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
    std::cout << std::endl;
}

int main() {
    std::string nama1, nama2;
    int matchPercentage;

    
    std::srand(std::time(0));

     // memasukan nama1 dan nama2 
    std::cout << "Masukan nama pertama: ";
    std::getline(std::cin, nama1);
    std::cout << "masukan nama kedua: ";
    std::getline(std::cin, nama2);

    // Ini adalah function yang bisa di ubah sesuka hati presentase love nya
    if ((nama1 == "Alice" && nama2 == "Bob") || (nama1 == "Bob" && nama2 == "Alice")) {
        matchPercentage = 95; 
    } else {
        matchPercentage = std::rand() % 101; 
    }

    // untuk kata2 di range presentase tertentu
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

    
    std::string result = "\nMenghitung persentase love...\n";
    printWithDelay(result, 50); 

    std::string output = "Presentase kecocokan antara " + nama1 + " and " + nama2 + ": " 
                         + std::to_string(matchPercentage) + "% - " + description;
    printWithDelay(output, 50); 

   
    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}
