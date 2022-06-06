## About

Python with Arduino.

## Set Up

Create a virutal enviroment:
python3 -m venv arduino_test

Activate Enviroment:
cd ./arduino_test/bin
source activate

Install libraries:
pip install pyserial

Arduino VS Code extension:
Arduino: initialize

## run_arduino_on_input.py

Steps:

- Upload the run_on_python_command sketch by using the VS Code extension.
- Run the python script.
  - python3 run_arduino_on_input.py
- Using the VS Code Arduino extension open the serial monitor.
  - cmd+shift+p Arduino Serial
