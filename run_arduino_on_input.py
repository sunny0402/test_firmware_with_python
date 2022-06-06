import serial

arduinoData = serial.Serial('/dev/tty.usbserial-1310',115200)

while (True):
    myCmd = input("Measure distance 'Measure' or 'OFF ")
    myCmd = myCmd+'\r'
    arduinoData.write(myCmd.encode())
