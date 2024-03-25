import os

# Startup

def restart():
    os.system("clear")
    trapped_in_dungeon()

def question(text):
    print(f"\n{text}\n\n")

def game_over():
    question("Do you want to play again? [yes/no]")
    option = get_answer()
    if option.lower() == "yes":
        restart()
    else:
        os.system("clear")
        print("Return to home page.")

def get_answer():
    os.system("./Internal/functionality/get_input")
    with open("./temp/memory/input.txt", "r") as f:
        chosen_option = f.read()
    return chosen_option

def trapped_in_dungeon():
    question("You're trapped in a dungeon with your friend. You see a barrel. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() == "move the barrel":
        secret_tunnel()
    else:
        game_over()

def secret_tunnel():
    question("The barrel rolls aside and you find a secret tunnel. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() == "enter tunnel":
        escape_from_dungeon()
    else:
        game_over()

def escape_from_dungeon():
    question("You start to escape but your friend is too weak to go with you. They hand you a note. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() == "read note":
        read_note()
    else:
        game_over()

def read_note():
    question("It is too dark to read the note. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() == "leave":
        beach()
    else:
        game_over()

def beach():
    question("You crawl through the tunnel and the tunnel leads you to a beach. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() == "look":
        boat()
    else:
        game_over()

def boat():
    question("In the water you see a boat. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() == "get on the boat":
        win()
    else:
        game_over()

def win():
    question("Congratulations, you're heading to a new world!")
    game_over()

if __name__ == "__main__":
    trapped_in_dungeon()
