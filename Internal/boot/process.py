import os
import json
import time
from colorama import init, Back, Fore, Style

init(autoreset=True)

path = "./Internal/assets/"
images = [path+"ecorp.json", path+"apple-boot.json"]

def open_json(file):
    os.system("clear")
    with open(file, "r+") as file:
        data = json.load(file)
        for item in data:
            print(item)
        time.sleep(20)

if __name__ == "__main__":
    for ipath in images:
        open_json(ipath)