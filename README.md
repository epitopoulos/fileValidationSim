# HERMES 3rd Project

## Description
This program simulates a **verification software for an exoskeleton**, designed to ensure that control code for the exoskeleton executes correctly and produces the expected results. Here’s how it functions:

1. **Flash Simulation**: It allows the user to select a Python file (representing control code for the exoskeleton) and simulates **flashing** the code to the exoskeleton's system memory (in real-world scenarios, this would be loading the code into non-volatile memory). In this case, the flashing is simply file selection, as no real hardware is used.

2. **Test Execution**: Once the Python file is selected (simulated as the code for controlling the exoskeleton), the user can run tests to ensure it works as expected. The tests are:
   - **Successful Execution**: This test checks whether the Python script (the exoskeleton’s control code) runs correctly without errors, ensuring it would execute properly in a real system.
   - **Output Comparison**: This test compares the actual output of the Python script to a **desired output** (which simulates the correct responses of the exoskeleton). If the two outputs match, the script is validated; if not, the program reports the differences.

3. **User Interface**: The program can be operated via a **Graphical User Interface (GUI)** created with Python's `tkinter` library. The GUI simplifies the process of selecting files, executing tests, and receiving feedback. The GUI communicates with the main C++ program through pipes.

4. **C++ Core Implementation**: The program's logic is built using various C++ classes:
   - **InputHandler**: Handles user input and displays menus (or communicates with the GUI).
   - **FlashModule**: Manages the selection of the Python file to be tested (simulating flashing of code to the exoskeleton).
   - **TestModule**: Runs the Python script and compares its output with the predefined expected output, ensuring the control code performs correctly.
   - **ReportingModule**: Reports whether the script passed or failed the test, displaying the results either in the GUI.

In summary, this program ensures that the control code intended for an exoskeleton executes without errors and behaves as expected, simulating real-world flashing, execution, and output validation.

## Prerequisites
- GCC compiler
- POSIX-compliant operating system (e.g., Linux)

## Running the Project
To run the program, open a terminal in the project folder and run the following command:

    python gui.py
