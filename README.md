# Data Logger (and using cool sensors!)

*A lab report by Meera Nanda.*

## In The Report

Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**\
0-1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**\
10 bits.

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**\
I used this as an indicator of success or failure in a Whack-A-Mole game. This required one resistor connected to each pin of the RGB LED (except the common anode), and then each RGB pin in turn connected to pins 9, 10 and 11 of the Arduino. I then programmed the Arduino to send values to each pin to turn it red or green depending on whether the user was successful or not. Below is a video of the Whack-A-Mole game running with the RGB LED, and a video of the LED running through all colors.

[See Whack-A-Mole Video](https://youtu.be/2LdZr8o1ReI)\
[See RBG LED Video](https://youtu.be/HxUzgDrZWlk)

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**\
The range I saw went from 0 to approximately 1000. 

Lightly touching ~ 300-400\
Pressing ~ 900\
Full force ~ 1000

[See FSR Video](https://youtu.be/-Ptw1uTUhtM)

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**\
The voltage appears to have a logarithmic relationship to the force applied. As the force increases, the resistance decreases and therefore the voltage increases. Below is a graph describing this relationship (sourced from the FSR datasheet).

![FSR Voltage by Force Graph](/images/FSRGraph.png)

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**\
If we want to change only the brightness of the LED, then the code needs to include a map function to take in the FSR reading and translate it to a value between 0-255, as seen below:
```c
brightnessValue = map(fsrValue, 0, 1000, 0, 255);
```
If we want to use the FSR to control the colors of the RGB LED, then the mapping needs to translate the FSR reading to a value between 0-765 (255 * 3) in order to write a range of 0-255 per RGB pin, as shown below:
```c
rgbValue = map(fsrValue, 0, 1000, 0, 765);
```
Then the values from 0-255, 256-510 and 511-765 will be written to the pins for red, green and blue respectively.

[See complete code here](/code/FSR_Controlling_RGB.ino)\
[See FSR Controlling RBG LED Video](https://youtu.be/6nhOXofDmZg)

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**\
Around 10k ohms in series for each sensor allows for a reasonable range of voltages. This was referenced from the datasheets for each sensor.

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**\
Photoresistor - logarithmic: as light increases, resistance decreases.
Flex sensor - linear: as the bending angle increases, the resistance increases.
Soft pot - linear: resistance increases/decreases depending on the direction you move the position in.

[See Photoresistor Video](https://youtu.be/P8UInswpBZA)\
[See Flex Sensor Video](https://youtu.be/MxJ0pTu3t5w)\
[See Soft Pot Video](https://youtu.be/Iri1fm8pl8g)

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**\
[Accelerometer Read-Out Code](/code/Accelerometer_ReadOutCode.ino)

[See Accelerometer Video](https://youtu.be/uHOQc99nG_Q)\
[See Accelerometer Controlling RGB LED Video](https://youtu.be/BDmlbut3kAY)\
[See Accelerometer Readings on LCD Video](https://youtu.be/fuYh2QZAo4k)

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**\
Below is an image of the reading from an FSR on the Graphic Display.
![Working Screen](/images/GraphicDisplay.png)

[See Graphic Display Video](https://youtu.be/IzqdssEK25E)\
[See A0 Readings on Graphic Display Video](https://youtu.be/boV_HuZNLkM)

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**\
In this example it does because you need to keep track of when you are reading, writing and clearing the EEPROM. If, for instance, you clear something that has been written to the EEPROM before it is read, then your code will not function as planned.

**b. Why is the code here all in the setup() functions and not in the loop() functions?**\
Because we want to perform each action once and not loop through it continuously.

**c. How many byte-sized data samples can you store on the Atmega328?**\
1024 bytes.

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**\
Analog data from the Arduino analog pins are 10 bits, so in order for it to be byte sized we will need to divide by 4, or use a mapping function to translate the value to a number between 0-255. I2C devices already send only 8 bits (1 byte) of data at a time.

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**\
You could store the data at different addresses in the EEPROM by seperating it into byte sized groups.

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**\

[Updated EEPROM Code]()\

[See EEPROM Analog Write/Read Video](https://youtu.be/kQPbyNzoZ_s)

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
