# Data Logger (and using cool sensors!)

*A lab report by John Q. Student.*

## In The Report

Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**\
0-1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**
red is more powerful than others, needs more resistance

[See RBG LED Video](https://youtu.be/HxUzgDrZWlk)

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**\
lightly touching - 300-400
pressing - 900
full force - 1010

[See FSR Video] (https://youtu.be/-Ptw1uTUhtM)

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

[See FSR Controlling RBG LED Video](https://youtu.be/6nhOXofDmZg)

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

[See Photoresistor Video](https://youtu.be/P8UInswpBZA)
[See Flex Sensor Video](https://youtu.be/MxJ0pTu3t5w)
[See Soft Pot Video](https://youtu.be/Iri1fm8pl8g)

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

[See Accelerometer Video](https://youtu.be/uHOQc99nG_Q)
[See Accelerometer Controlling RGB LED Video](https://youtu.be/BDmlbut3kAY)
[See Accelerometer Readings on LCD Video](https://youtu.be/fuYh2QZAo4k)

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

[See Graphic Display Video](https://youtu.be/IzqdssEK25E)
[See A0 Readings on Graphic Display Video](https://youtu.be/boV_HuZNLkM)

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

[See EEPROM Analog Write/Read Video](https://youtu.be/kQPbyNzoZ_s)

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
