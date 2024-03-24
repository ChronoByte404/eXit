import json

def read_file_and_save_to_json(input_file, output_file):
    lines = []

    with open(input_file, 'r') as file:
        for line in file:
            lines.append(line.strip())

    # Save lines to a JSON file
    with open(output_file, 'w') as json_file:
        json.dump(lines, json_file, indent=4)

if __name__ == "__main__":
    input_file = input("Enter the path of the input text file: ")
    output_file = input("Enter the path of the output JSON file: ")

    read_file_and_save_to_json(input_file, output_file)
