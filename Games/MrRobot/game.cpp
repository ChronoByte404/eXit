#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function declarations
void printer(const char* templateName);
void restart();
void question(const char* text);
void game_over();
std::string get_answer();
void trapped_in_dungeon();
void secret_tunnel();
void escape_from_dungeon();
void hand_note();
void read_note();
void light_match();
void beach();
void boat();
void win();
void win2();
void loss();

// Function implementations
void printer(const char* templateName) {
    char command[100];
    sprintf(command, "python3 ./Internal/printing/printer.py %s.json", templateName);
    system(command);
}

void restart() {
    system("clear");
    trapped_in_dungeon();
}

void question(const char* text) {
    std::cout << std::endl << text << std::endl << std::endl;
}

void game_over() {
    question("Do you want to play again? [yes/no]");
    std::string option = get_answer();
    if (option == "yes") {
        restart();
    } else {
        system("clear");
        std::cout << "Return to home page." << std::endl;
        exit(0);
    }
}

std::string get_answer() {
    system("./Internal/functionality/get_input");
    FILE* file = fopen("./temp/memory/input.txt", "r");
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);
    return std::string(buffer);
}

void trapped_in_dungeon() {
    printer("dungeonbarrel");
    question("You're trapped in a dungeon with your friend. You see a barrel. You can move the barrel, or sit with your friend. What do you do?");
    std::string chosen_option = get_answer();
    if (chosen_option == "move the barrel") {
        secret_tunnel();
    } else {
        hand_note();
    }
}

void secret_tunnel() {
    printer("tunnel");
    question("The barrel rolls aside and you find a secret tunnel. You can enter the tunnel, or sit with your friend. What do you do?");
    std::string chosen_option = get_answer();
    if (chosen_option == "enter the tunnel") {
        escape_from_dungeon();
    } else {
        hand_note();
    }
}

void escape_from_dungeon() {
    printer("friendnote1");
    question("You start to escape but your friend is too weak to go with you. They hand you a note. You can read the note, or leave. What do you do?");
    std::string chosen_option = get_answer();
    if (chosen_option == "read the note") {
        read_note();
    } else {
        beach();
    }
}

void hand_note() {
    printer("friendnote1");
    question("Your friend hands you a note. You can read the note, or leave. What do you do?");
    std::string chosen_option = get_answer();
    if (chosen_option == "read the note") {
        read_note();
    } else {
        beach();
    }
}

void read_note() {
    printer("handwithnote");
    question("It is too dark to read the note. You can leave, or light a match. What do you do?");
    std::string chosen_option = get_answer();
    if (chosen_option == "leave") {
        beach();
    } else {
        light_match();
    }
}

void light_match() {
    printer("dlmh");
    std::string d = "Don't ", l = "leave ", mh = "me here.";
    std::string dlmh = d + l + mh;
    question("The note says 'Don't leave me here.' Do you stay with your friend or leave?");
    std::string chosen_option = get_answer();
    if (chosen_option == "leave") {
        beach();
    } else {
        loss();
    }
}

void beach() {
    printer("beach");
    question("You crawl through the tunnel and the tunnel leads you to a beach. Do you look or turn back?");
    std::string chosen_option = get_answer();
    if (chosen_option == "look") {
        boat();
    } else {
        escape_from_dungeon();
    }
}

void boat() {
    printer("boat");
    question("In the water you see a boat. You can get on the boat, or stay on the beach. What do you do?");
    std::string chosen_option = get_answer();
    if (chosen_option == "get on the boat") {
        win();
    } else {
        loss();
    }
}

void win() {
    printer("new_world");
    question("Congratulations, you're heading to a new world!");
    game_over();
}

void win2() {
    printer("whiterose");
    question("Congratulations, you have decided to remain and therefore stopped Whiterose's machine!");
    game_over();
}

void loss() {
    printer("starvation");
    question("The colony boat has left without you, and you and your friend have starved to death!");
    game_over();
}

int main() {
    trapped_in_dungeon();
    return 0;
}

