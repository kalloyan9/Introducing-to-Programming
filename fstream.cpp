#include <iostream>
#include <fstream>
#include <string>

int reading_fstream_string()
{
    std::string fileName;
    std::cout << "input file name: ";
    std::cin >> fileName;

    std::fstream file(fileName, std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    std::string line;
    while (getline(file, line)) {
        std::cout << line << "\n";
    }
    file.close();

    return 0;
}

int writting_fstream_string()
{
    std::string fileName;
    std::cout << "output file name: ";
    std::cin >> fileName;

    std::fstream file(fileName, std::ios::out);
    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    std::string line;
    std::cout << "Enter lines, type 'quit' to finish:\n";
    while (std::getline(std::cin, line)) {
        if (line == "quit")
            break;
        file << line << "\n";
    }
    file.close();

    return 0;
}

int reading_fstream_int()
{
    std::string fileName;
    std::cout << "input file name: ";
    std::cin >> fileName;

    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    int num;
    while (file >> num) {
        std::cout << num << "\n";
    }
    file.close();

    return 0;
}

int writting_fstream_int()
{
    std::string fileName;
    std::cout << "output file name: ";
    std::cin >> fileName;

    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    int num;
    std::cout << "Enter integers, type '-1' to finish:\n";
    while (std::cin >> num) {
        if (num == -1)
            break;
        file << num << "\n";
    }
    file.close();

    return 0;
}

int main ()
{
    reading_fstream_string();
    writting_fstream_string();
    reading_fstream_int();
    writting_fstream_int();

    return 0;
}
