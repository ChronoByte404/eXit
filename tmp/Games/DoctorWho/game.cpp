#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function declarations
void restart();
void question(const char* text);
void game_over();
void printer(const char* templateName);
std::string get_answer();
void dinosaur_era();
void dinosaur_attack();
void earth_explode();
void dalek_parliament();
void dalek_controls();
void dalek_explode();
void tardis();
void win();

// Function implementations
void restart() {
    system("./Internal/functionality/core.out");
}

void question(const char* text) {
    std::cout << std::endl << text << std::endl << std::endl;
}

void game_over() {
    question("Would you like to play again? [yes/no]");
    std::string option = get_answer();
    if (option == "yes") {
        restart();
    } else {
        system("clear");
        std::cout << "See you next time!" << std::endl;
        exit(0);
    }
}

void printer(const char* templateName) {
    char command[100];
    sprintf(command, "python3 ./Internal/printing/printer.py %s.json", templateName);
    system(command);
}

std::string get_answer() {
    system("./Internal/functionality/get_input");
    FILE* file = fopen("./temp/memory/input.txt", "r");
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);
    return std::string(buffer);
}

void dinosaur_era() {
    printer("dinosaurs");
    question("The Police Box has taken you to the Dinosaur era. Do you stay or leave?");
    std::string chosen_option = get_answer();
    if (chosen_option == "stay") {
        dinosaur_attack();
    } else {
        dalek_parliament();
    }
}

void dinosaur_attack() {
    printer("dinosaur_attack");
    question("The dinosaurs have found you and eaten you! Game over.");
    game_over();
}

void earth_explode() {
    printer("apocalypse");
    question("The Daleks activated the reality bomb and destroyed Earth! Game over.");
    game_over();
}

void dalek_parliament() {
    printer("dalek_parliament");
    question("The Police Box has landed in the Dalek spaceship. They are planning to destroy the Earth. Do you stay or leave?");
    std::string option = get_answer();
    if (option == "stay") {
        dalek_controls();
    } else {
        earth_explode();
    }
}

void dalek_controls() {
    printer("dalek-control-panel");
    question("You walk to the Dalek control panel. You can either (A) blow up the Daleks and save Earth, or (B) blow up Earth and save yourself.");
    std::string option = get_answer();
    if (option == "a") {
        dalek_explode();
    } else {
        earth_explode();
    }
}

void dalek_explode() {
    printer("daleks-exploding");
    win();
}

void tardis() {
    printer("TARDIS1");
    question("A blue Police Box has landed in front of you. What do you do? [Enter or Walk Away]");
    std::string chosen_option = get_answer();
    if (chosen_option == "enter") {
        dinosaur_era();
    } else if (chosen_option == "walk away") {
        game_over();
    }
}

void win() {
    question("Congratulations, you have blown up the Daleks and saved Earth!");
    game_over();
}

int main() {
    tardis();
    return 0;
}
