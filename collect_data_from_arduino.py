import serial
import os
import time
import matplotlib.pyplot as plt
import pandas as pd

dateString = time.strftime("%Y-%m-%d_%H%M")
filepath = "./" + dateString + ".csv"

arduinoData = serial.Serial('/dev/tty.usbserial-1310',115200)

"""
Run test for set amount of time, get data from Arduino and save to csv file.
HC-SR04 ultrasonic sensor, Arduino nano
"""
max_time = 5
start_time = time.time()
while ((time.time()-start_time) < max_time):
    data = float(arduinoData.readline().decode())
    time_stamp = time.ctime(time.time())
    with open(filepath, "a") as file:
        if os.stat(filepath).st_size == 0: #if empty file, write a nice header
            file.write("Time,Distance\n") 
        file.write("{},{}\n".format(time_stamp,data)) # log the data
    file.close()

"""
Use data from csv file to create scatter plot.
"""

# Load data
data = pd.read_csv(filepath)
print(data.head())
# print(data.columns)


# Setting the figure size
fig = plt.figure(figsize=(6.8, 4.2))
# x = data['Time']
# y = data['Distance']
x = range(len(data['Time']))
plt.scatter(x, data['Distance'])
plt.xticks(x, data['Time'],rotation=45)

plt.xlabel(data.columns[0]) 
plt.ylabel(data.columns[1]) 
# Give a title to the graph
plt.title(filepath[:-4])   

fig.savefig(filepath[:-4]+'.jpg', bbox_inches='tight', dpi=150)


