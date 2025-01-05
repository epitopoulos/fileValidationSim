import time

# Function to print 3 numbers in a sequence
def print_numbers(file):
    for i in range(3):
        numbers = [i+1, i+2, i+3]  # Generate the sequence of 3 numbers
        print(*numbers, file=file)  # Print the numbers separated by spaces
        time.sleep(3)  # Wait for 3 seconds

if __name__ == "__main__":
    with open("test_output.txt", "w") as file:
        print("Starting to generate sequences of numbers...")
        print_numbers(file)
        print("Done!")
