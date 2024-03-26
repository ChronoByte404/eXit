import os

# Startup

def printer(template):
    os.system(f"python3 ./Internal/printing/printer.py {template}.json")

def restart():
    os.system("clear")
    trapped_in_dungeon()

def question(text):
    print(f"\n{text}\n\n")

def game_over():
    question("Do you want to play again? [yes/no]")
    option = get_answer()
    if option.lower() in "yes":
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
    printer("dungeonbarrel")
    question("You're trapped in a dungeon with your friend. You see a barrel. You can move the barrel, or sit with your friend. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() in "move the barrel":
        secret_tunnel()
    else:
        hand_note()

def secret_tunnel():
    printer("tunnel")
    question("The barrel rolls aside and you find a secret tunnel. You can enter the tunnel, or sit with your friend. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() in "enter tunnel":
        escape_from_dungeon()
    else:
        hand_note()

def escape_from_dungeon():
    printer("friendnote1")
    question("You start to escape but your friend is too weak to go with you. They hand you a note. You can read the note, or leave. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() in "read note":
        read_note()
    else:
        beach()

def hand_note():
    printer("friendnote1")
    question("Your friend hands you a note. You can read the note, or leave. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() in "read note":
        read_note()
    else:
        beach()

def read_note():
    printer("handwithnote")
    question("It is too dark to read the note. You can leave, or light a match. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() in "leave":
        beach()
    else:
        light_match()

def light_match():
    printer("dlmh")
    d, l, mh = "Don't ", "leave ", "me here."
    dlmh = d+l+mh
    question(f"The note says {dlmh}. Do you stay with your friend or leave?")
    chosen_option = get_answer()
    if chosen_option.lower() in "leave":
        beach()
    else:
        loss()

def beach():
    printer("beach")
    question("You crawl through the tunnel and the tunnel leads you to a beach. Do you look or turn back?")
    chosen_option = get_answer()
    if chosen_option.lower() in "look":
        boat()
    else:
        escape_from_dungeon()

def boat():
    printer("boat")
    question("In the water you see a boat. You can get on the boat, or stay on the beach. What do you do?")
    chosen_option = get_answer()
    if chosen_option.lower() in "get on the boat":
        win()
    else:
        loss()

def win():
    printer("new_world")
    question("Congratulations, you're heading to a new world!")
    game_over()

def win2():
    printer("whiterose")
    question("Congratulations, you have decided to remain and therefore stopped Whiterose's machine!")
    game_over()

def loss():
    printer("starvation")
    question("The colony boat has left without you, and you and your friend have starved to death!")
    game_over()

if __name__ in "__main__":
    trapped_in_dungeon()
