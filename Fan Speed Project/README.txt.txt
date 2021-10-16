This Project is a simple fan speed controller project using atmega32.

components:
1 atmega32
1 lcd 16*2
1 LM35 "temperature sensor"
1 L293D H-Bridge Motor driver
1 DC-Motor to drive the fan
1 12V DC Source to drive the motor

The components should be connected according to the schematic 
attached to the project.

The lcd is used to display the status of the fan and the current 
temperature read from the LM35 sensor,the fan is either on or off
depending on the temperature.
if the temperature is lower than 30 C then the fan will be off, if
the temperature is between 30 C and 60 C then the fan will be on with
25% of it's max speed,between 60 C and 90 C the fan will be on with
50% of it's max speed,between 90 C and 120 C the fan wwill be on with 
75% of it's max speed and above 120 C then the fan will be on with 
100% of it's max speed.
The microcontroller will get the reading of the sensor through the ADC
connection and converts it into celsius and then display it on the lcd
and determine whether the fan is off or on with specific speed and then
output that speed with pwm to the motor driver.