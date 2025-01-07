import tkinter as tk
from tkinter import Toplevel
import subprocess

class GuiHandler:
    def __init__(self, root):
        self.root = root
        self.root.title("Code Tester")

        self.code_file_label = tk.Label(root, text="Enter the code file name:")
        self.code_file_label.pack(pady=5)
        self.code_file_input = tk.Entry(root, width=50)
        self.code_file_input.pack(pady=10)

        self.execution_status_label = tk.Label(root, text="")
        self.execution_status_label.pack(pady=5)

        self.successful_execution_button = tk.Button(root, text="Successful Execution", command=self.on_successful_execution_clicked)
        self.successful_execution_button.pack(pady=5)

        self.choose_test_output_button = tk.Button(root, text="Choose Test Output", command=self.on_choose_test_output_clicked)
        self.choose_test_output_button.pack(pady=5)

    def on_successful_execution_clicked(self):
        test_filename = self.code_file_input.get()        
        self.execution_status_label.config(text="Executing test...")
        self.root.update_idletasks()  # Update the GUI to show the message immediately
        print(f"Executing test with code file: {test_filename}")
    
        try:
            # Set the execution filename
            subprocess.run(["./validationSim", "setExecFilename", test_filename], check=True)
        
            # Run the test
            subprocess.run(["./validationSim", "runTest", test_filename], check=True)
        
            # Read the result from the file
            with open("/tmp/reportResult.txt", "r") as result_file:
                result = result_file.read()
                self.execution_status_label.config(text=result)
        except subprocess.CalledProcessError as e:
            self.execution_status_label.config(text=f"Error: {e.stderr}")
        except FileNotFoundError:
            self.execution_status_label.config(text="Result file not found.")

    def on_choose_test_output_clicked(self):
        self.open_test_output_menu()

    def open_test_output_menu(self):
        new_window = Toplevel(self.root)
        new_window.title("Test Output Menu")

        input1_label = tk.Label(new_window, text="Expected Output File:")
        input1_label.pack(pady=5)
        input1_entry = tk.Entry(new_window, width=50)
        input1_entry.pack(pady=5)

        input2_label = tk.Label(new_window, text="Test Output File:")
        input2_label.pack(pady=5)
        input2_entry = tk.Entry(new_window, width=50)
        input2_entry.pack(pady=5)

        execute_test_button = tk.Button(new_window, text="Execute Test", command=lambda: self.execute_test(input1_entry.get(), input2_entry.get()))
        execute_test_button.pack(pady=10)

    def execute_test(self, input1, input2):
        # Implement the logic to execute the test with the provided inputs
        print(f"Executing test with Input 1: {input1} and Input 2: {input2}")
        # Example subprocess call (modify as needed)
        subprocess.run(["./main", "runTest", input1, input2])

if __name__ == "__main__":
    root = tk.Tk()
    gui = GuiHandler(root)
    root.mainloop()