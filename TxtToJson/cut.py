import json
import os

def read_file_and_save_to_json(input_file):
    lines = []

    try:
        with open(input_file, 'r') as file:
            for line in file:
                lines.append(line.strip())
    except FileNotFoundError:
        print(f"File '{input_file}' not found.")
        return
    
    if input_file.endswith(".txt"):
        new_filename = input_file.replace(".txt", ".json")
    else:
        new_filename = input_file + ".json"
    
    new_filename = new_filename.replace("./inputfiles/", "")
    new_filename = f"./outputfiles/{new_filename}"

    # Save lines to a JSON file
    with open(new_filename, 'w+') as json_file:
        json.dump(lines, json_file, indent=4)

if __name__ == "__main__":
    list_of_inputs = os.listdir("./inputfiles")
    for file in list_of_inputs:
        full_path = os.path.join("./inputfiles", file)
        read_file_and_save_to_json(full_path)
        os.remove(full_path)
