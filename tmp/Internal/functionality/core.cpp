#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <cstdio>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int printer(const std::string& templateFile) {
    std::string command = "./Internal/printing/printer " + templateFile;
    system(command.c_str());
    return 0;
}

int waiter() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}

int boot() {
    int first, wait, second;

    second = printer("apple-boot.json");
    return 0;
}

int game() {
    int menu;
    menu = printer("./exitscreen.json");
    return 0;
}

std::string menu_interface() {
    char option[256];
    printf("\nWhich eXit game would you like to play? [DoctorWho, MrRobot]\n\nGame: ");
    scanf("%s", option);
    return std::string(option);
}

int start_game(const std::string& option) {
    std::string path = "./Games/" + option + "/";
    // Check if the directory exists
    if (fs::is_directory(path)) {
        // Directory exists, do something
        std::cout << "Directory exists: " << path << std::endl;
        // You can list files in the directory or perform other operations here
    } else {
        std::cerr << "Directory does not exist: " << path << std::endl;
        return 1; // Return an error code indicating directory not found
    }

    // Construct the command string
    std::string command = path + "game.out";
    
    // Execute the command
    std::cout << "Executing command: " << command << std::endl;
    int result = system(command.c_str());

    if (result != 0) {
        std::cerr << "Failed to execute command: " << command << std::endl;
        return 1; // Return an error code indicating command execution failure
    }

    return 0;
}

int main() {
    int phil, sg;
    std::string option;
    phil = boot();
    sg = game();
    option = menu_interface();
    start_game(option);
    return 0;
}
