import os
import json
from colorama import init, Back, Fore, Style

# Initialize colorama
init(autoreset=True)

output_list = os.listdir("./outputfiles/")

for filename in output_list:
    count = 0
    with open(f"./outputfiles/{filename}", "r") as file:
        data = json.load(file)

        for line in data:
            count += 1
            # Print with white background and black text
            
            if count >= 53:
                print(Back.WHITE + "")
            else:
                print(Back.WHITE + Fore.BLACK + line)
