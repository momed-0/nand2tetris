
# Project 2: [Implementation of Hack ALU](https://github.com/momed-0/nand2tetris/tree/main/Project%201)

## Project Overview

The goal of this project is to implement the following components: 
1. Half Adder
2. Full Adder
3. Add16
4. Inc16
5. ALU

These components will allow you to perform addition, increment, and various arithmetic and logical operations on 16-bit binary numbers.

## Project Files

The project folder includes the following files:
- `README.md`: This file provides an overview of the project and its requirements.
- `HalfAdder.hdl`: Hardware Description Language file for the Half Adder component.
- `FullAdder.hdl`: Hardware Description Language file for the Full Adder component.
- `Add16.hdl`: Hardware Description Language file for the Add16 component.
- `Inc16.hdl`: Hardware Description Language file for the Inc16 component.
- `ALU.hdl`: Hardware Description Language file for the Arithmetic Logic Unit component.
- `Test` folder: This folder contains the test scripts for each component.
  - `HalfAdder.tst`: Test script for the Half Adder component.
  - `FullAdder.tst`: Test script for the Full Adder component.
  - `Add16.tst`: Test script for the Add16 component.
  - `Inc16.tst`: Test script for the Inc16 component.
  - `ALU.tst`: Test script for the ALU component.
- `tools` folder: This folder contains the hardware simulator and other tools necessary for testing the components.
  - `HardwareSimulator.bat` (Windows) / `HardwareSimulator.sh` (Unix): Executable files for running the hardware simulator.
  - `CPUEmulator.bat` (Windows) / `CPUEmulator.sh` (Unix): Executable files for running the CPU emulator.

## Component Descriptions

Here is a brief overview of each component you will be implementing:

1. **Half Adder**: A combinational circuit that adds two single-bit inputs and produces a sum and a carry output.
2. **Full Adder**: A combinational circuit that adds three single-bit inputs (two data bits and a carry-in) and produces a sum and a carry output.
3. **Add16**: A sequential circuit that adds two 16-bit inputs and produces a 16-bit sum output.
4. **Inc16**: A sequential circuit that increments a 16-bit input by 1 and produces a 16-bit output.
5. **ALU**: The Arithmetic Logic Unit that performs various arithmetic and logical operations on two 16-bit inputs, based on a control input. It produces a 16-bit output and several status flags.

## Getting Started

To get started with the project, follow these steps:

1. Clone or download the project repository to your local machine.
2. Open the HDL files (`HalfAdder.hdl`, `FullAdder.hdl`, `Add16.hdl`, `Inc16.hdl`, `ALU.hdl`) in a text editor or HDL development environment of your choice.
3. Implement the logic for each component according to their respective specifications.
4. Open the hardware simulator (`HardwareSimulator.bat` for Windows or `HardwareSimulator.sh` for Unix) and load the HDL files and test scripts.
5. Run the test