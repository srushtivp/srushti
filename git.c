def read_numbers(file_path):
    try:
        with open(file_path, 'r') as file:
            numbers = file.readlines()
        return [int(num.strip()) for num in numbers]
    except ValueError:
        print("Error: File contains non-integer values.")
        return []
    except FileNotFoundError:
        print(f"Error: File not found - {file_path}")
        return []
    except IOError:
        print(f"Error: An IOError occurred while reading the file - {file_path}")
        return []

def calculate_sum(numbers):
    return sum(numbers)

def calculate_average(numbers):
    if len(numbers) == 0:
        print("Error: Cannot calculate average of an empty list.")
        return None
    return calculate_sum(numbers) / len(numbers)

def write_results(file_path, total, average):
    try:
        with open(file_path, 'w') as file:
            file.write(f"Sum: {total}\n")
            if average is not None:
                file.write(f"Average: {average}\n")
    except IOError:
        print(f"Error: An IOError occurred while writing to the file - {file_path}")

def main():
    input_file = input("Enter the input file path: ")
    output_file = input("Enter the output file path: ")

    numbers = read_numbers(input_file)
    if numbers:
        total = calculate_sum(numbers)
        average = calculate_average(numbers)
        write_results(output_file, total, average)
    else:
        print("No numbers to process.")

if __name__ == "__main__":
    main()
