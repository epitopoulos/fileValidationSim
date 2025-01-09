import tkinter as tk
from tkinter import Toplevel
import subprocess
import threading

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

        self.is_executing = False

    def on_successful_execution_clicked(self):
        
        if self.is_executing:
            return
        
        if not self.code_file_input.get():
            self.execution_status_label.config(text="Please enter the code file name.")
            return

        self.is_executing = True

        execution_thread = threading.Thread(target=self.check_code_file)
        execution_thread.start()

    def check_code_file(self):
        self.successful_execution_button.config(state="disabled")

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
        finally:
            self.is_executing = False
            self.successful_execution_button.config(state="normal")

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

        self.test_status_label = tk.Label(new_window, text="")
        self.test_status_label.pack(pady=5)

        self.execute_test_button = tk.Button(new_window, text="Execute Test", command=lambda: self.on_execute_test_clicked(input1_entry, input2_entry))
        self.execute_test_button.pack(pady=10)
    
    def on_execute_test_clicked(self, input1, input2):
        if self.is_executing:
            return

        if not self.code_file_input.get():
            self.test_status_label.config(text="Please enter the code file name in main menu.")
            return
        
        if not input1.get() or not input2.get():
            self.test_status_label.config(text="Please fill both inputs.")
            return

        self.is_executing = True

        execution_thread = threading.Thread(target=self.execute_test, args=(input1.get(), input2.get()))
        execution_thread.start()

    def execute_test(self, input1, input2):
        self.execute_test_button.config(state="disabled")

        test_filename = self.code_file_input.get()
        self.test_status_label.config(text="Running test and comparing files...")
        self.root.update_idletasks()  # Update the GUI to show the message immediately

        print(f"Executing test with Input 1: {input1} and Input 2: {input2}")
        try :
            result = subprocess.run(["./validationSim", "compareFiles", input1, input2, test_filename], check=True, capture_output=True, text=True)
            self.test_status_label.config(text=result.stdout)
        finally :
            self.is_executing = False
            self.execute_test_button.config(state="normal")


if __name__ == "__main__":
    root = tk.Tk()
    gui = GuiHandler(root)
    root.mainloop()