import serial
import os
import time

dateString = time.strftime("%Y-%m-%d_%H%M")
filepath = "./" + dateString + ".csv"

arduinoData = serial.Serial('/dev/tty.usbserial-1310',115200)

while (True):
    data = arduinoData.readline().decode()
    timestamp = time.ctime(time.time())
    idx = 0
    # Write results to a file
    with open(filepath, "a") as file:
        if os.stat(filepath).st_size == 0: #if empty file, write a nice header
            file.write("Measurement Index Timestamp Distance\n") 
        file.write("{},{},{}\n".format(idx, timestamp,data)) # log the data
        idx+=1
    file.close()