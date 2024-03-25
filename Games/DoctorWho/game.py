import os

# Startup

def restart():
    os.system("./Internal/functionality/core.out")

def question(text):
    print(f"\n{text}\n\n")

def game_over():
    question("Would you like to play again? [yes/no]")
    option = get_answer()
    if option.lower() == "yes":
        restart()
    else:
        os.system("clear")
        print("See you next time!")
        quit()

def printer(template):
    os.system(f"python3 ./Internal/printing/printer.py {template}.json")

def get_answer():
    os.system("./Internal/functionality/get_input")
    with open("./temp/memory/input.txt", "r") as f:
        chosen_option = f.read()
    return chosen_option

def dinosaur_era():
    printer("dinosaurs")
    question("The Police Box has taken you to the Dinosaur era. Do you stay or leave?")
    chosen_option = get_answer()
    if chosen_option.lower() in "stay":
        dinosaur_attack()
    else:
        dalek_parliament()

def dinosaur_attack():
    printer("dinosaur_attack")
    question("The dinosaurs have found you and eaten you! Game over.")
    game_over()

def earth_explode():
    printer("apocalypse")
    question("The Daleks activated the reality bomb and destroyed Earth! Game over.")
    game_over()

def dalek_parliament():
    printer("dalek_parliament")
    question("The Police Box has landed in the Dalek spaceship. They are planning to destroy the Earth. Do you stay or leave?")
    option = get_answer()
    if option.lower() in "stay":
        dalek_controls()
    else:
        earth_explode()

def dalek_controls():
    printer("dalek-control-panel")
    question("You walk to the Dalek control panel. You can either (A) blow up the Daleks and save Earth, or (B) blow up Earth and save yourself.")
    option = get_answer()
    if option.lower() == "a":
        dalek_explode()
    else:
        earth_explode()

def dalek_explode():
    printer("daleks-exploding")
    win()

def tardis():
    printer("TARDIS1")
    question("")
    question("A blue Police Box has landed in front of you. What do you do? [Enter or Walk Away]")
    chosen_option = get_answer()
    if chosen_option.lower() in "enter":
        dinosaur_era()
    elif chosen_option.lower() in "walk away":
        game_over()

def win():
    question("Congratulations, you have blown up the Daleks and saved Earth!")
    game_over()

if __name__ == "__main__":
    tardis()