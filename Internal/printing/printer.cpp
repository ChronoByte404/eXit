#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <json_file_path>" << std::endl;
        return 1;
    }

    std::string json_path = argv[1];
    std::string command = "python3 ./Internal/printing/printer.py " + json_path;
    system(command.c_str());

    return 0;
}
