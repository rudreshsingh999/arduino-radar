import serial
import numpy as np
import matplotlib.pyplot as plt
from visual import *
import math
print "step 0"
arduinoData =serial.Serial('com7',9600)
print "step 1"
while(arduinoData.inWaiting()==0):
    pass
print "step 2"

arduinoString = arduinoData.readline()
print arduinoString
dataArray = arduinoString.split(',')
rads = []
rs = []
for x in range(0,180):
    if(math.floor(float(dataArray[x])) <= 25):
        rs.append(float(dataArray[x]))
    else:
        rs.append(float(25))
    rads.append(0.0174*x)
fig = plt.figure();
ax = fig.add_subplot(1, 1, 1, projection='polar');
for x in range(1, 180):
    plt.plot([rads[x], rads[x-1]], [rs[x], rs[x-1]], color='r') 

plt.show()
