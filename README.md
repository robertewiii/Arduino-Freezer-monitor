# Arduino-Freezer-monitor
uses a Seeed grove system to monitor the temperature in a freezer with a color changing display to quickly indicate status
Note: All temperatures are displayed in farenheit with a +/- 2.7 degree precision.


The grove system was chosen in order to rapidly prototype and implement this project and to standardize parts to be sourced by a reputable hardware vendor who maintains a reliable supply chain. Note that Seeed now sells and warehouses some inventory through Amazon (eligible for Prime shipping) as well as through direct shipping from Hong Kong. This project takes under 30 minutes to fully set up and provides an accurate way to dial freezer temperature to an ideal level for long term food storage. The display will change color based on temperature range according to the following values:
Color - R,G,B; Temperature; status message
Red - 255,0,0; temperature > 32F; "Freezer Thawing!"
Magenta - 128,0,128; 0F < temp <= 32; "Freezer Warm" 
blue - 0,0,128; -10F < temp <= 0; "Freezer Frozen" (note that the ideal temperature for a deep freezer is between -10F and -20F)
green - 0,255,0; -10F >= tempf >= -20F; "Stat: ideal temp"
white - 128,128,128; "Freezer too cold"

Parts list with links to Seeed wiki:
Note: all parts are standard in Grove Starter Kit
1x Arduino Uno or equivalent
1x base shield V2 http://wiki.seeed.cc/Base_Shield_V2/
1x grove temperature sensor V1.2 (thermistor type) http://wiki.seeed.cc/Grove-Temperature_Sensor_V1.2/
1x Grove-LCD RGB Backlight V4.0 (or eqivalent version) http://wiki.seeed.cc/Grove-LCD_RGB_Backlight/

total cost (not including shipping or Arduino) estimated to be $24 USD direct from Hong Kong

Instructions:
setup
1. Place shield on Uno board
2. Use included grove connector cables to secure display to one of the 12C ports
3. Connect the temperature sensor to the A0 pin
installation
4. secure the main board and display OUTSIDE of freezer be careful to mount to the door or lid in such a way that the unit will not
tug on the power connection cable
5. tape the temperature sensor inside the freezer and ensure the sensor does not contact the freezer wall in order to ensure accurate temperature readings of the ambient air.
6. Power over USB or 9V 
6b. Optionally, use a large capacity power bank (10,000 mAh+) that allows pass through charging to easily power the unit over USB so that, in the event of a power outage, you can track the temperature of the unit. 

