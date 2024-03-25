import os
import json
import time
import sys
from colorama import init, Back, Fore, Style

init(autoreset=True)

path = "./Internal/assets/"

def print_json(json_path):
    linecount = 0
    os.system("clear")
    with open(json_path, "r+") as file:
        data = json.load(file)
        for item in data:
            linecount += 1
            if linecount >= 50:
                pass
            else:
                print(Back.WHITE + Fore.BLACK + item)
            
        time.sleep(2)

if __name__ == "__main__":
    json_path = sys.argv[1]
    print_json(path + json_path)
