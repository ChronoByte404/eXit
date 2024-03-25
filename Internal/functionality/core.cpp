#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

int printer(const std::string& templateFile) {
    std::string command = "python3 ./Internal/printing/printer.py " + templateFile;
    system(command.c_str());
    return 0;
}

int waiter() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}

int boot() {
    int first, wait, second;

    first = printer("ecorp.json");
    wait = waiter();
    second = printer("apple-boot.json");
    return 0;
}

int game() {
    int menu;
    menu = printer("./exitscreen.json");
    return 0;
}

int main() {
    int phil, sg;
    phil = boot();
    sg = game();
    return 0;
}
