import json

with open("Output.json", "r") as file:
    ASCII = json.load(file)

for line in ASCII:
    print(line)
