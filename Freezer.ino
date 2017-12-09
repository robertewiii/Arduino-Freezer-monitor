//freezer temperature probe
//v0.0.1
//Robertewiii 7/20/17
//uses Seeed temperature sensor, RGB LCD backlight, and main hub connector to monitor the temperature of a freezer to see if it stays within the correct ranges
//ideal freezer temp is -20 to -10 F and is indicated by a green light, adequate temp is -10 to 0 F and is indicated by a blue light, high temp (but still frozen) is anything from 0 to 32 F and is indicated by a purple light, anything above 32 F is thawing and is 
//indicated by a red light
//connect main hub to an arduino uno, then connect an RGB LCD unit to one of the 12C ports and connect a temperature sensor to port A0. Power unit either over USB or 9V

#include <math.h>
#include <Wire.h>
#include <rgb_lcd.h>

//LCD display stuff
rgb_lcd lcd;
const int colorR = 255;
const int colorG = 255;
const int colorB = 255;


//temperature sensor stuff and setup values
const int B = 4275; //thermistor B value
const int R0 = 100000; //R0 = 100k
const int pinTempSensor = A0; //grove - temp sensor connect A0


void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2); //set up LCD columns and rows
lcd.setRGB(colorR, colorG, colorB); //sets color of display
delay(500); //keep the arduino from running too fast
}

void loop() {
  // put your main code here, to run repeatedly:
int a = analogRead(pinTempSensor);

float R = 1023.0/a-1.0;
R = R0*R;

float temperatureC = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
float tempF = ((9 * temperatureC)/(5))+32; //convert the temp to F

int colorRShift, colorGShift, colorBShift; //LCD colors that shift based on temperature ranges, range from 0-255

//print the temp in F
//lcd rows and columns count from 0
lcd.setCursor(0, 0); //set cursor top row far left (0 column, 0 row)
lcd.print(tempF); //print temperature in F to LCD, 4 SF
lcd.setCursor(5, 0); //set cursor top row column 6
lcd.print(" F +/-2.7 F"); //print the temperature units and accuracy, include the space between temperature and degree markation in order to clear any excess characters


if (tempF > 32.0)
{
  //change the LCD color to bright red indicate freezer thawing
  colorRShift = 255;
  colorGShift = 0;
  colorBShift = 0;
  lcd.setRGB(colorRShift, colorGShift, colorBShift);
  
  lcd.setCursor(0, 1); //set the cursor to bottom row left column (column, row)
  lcd.print("Freezer Thawing!"); //warn that the freezer is not frozen
}

else if (tempF <= 32 && tempF > 0)
{
  //change the LCD color to dark purple to indicate freezer is frozen but warm
  colorRShift = 128;
  colorGShift = 0;
  colorBShift = 128;
  lcd.setRGB(colorRShift, colorGShift, colorBShift);

  lcd.setCursor(0, 1); //set the cursor to bottom row left column (column, row)
  lcd.print("Freezer Warm    "); //additional spaces are used to clear LCD display 
}

else if (tempF <= 0 && tempF > -10)
{
  //change the LCD color to dark blue to indicate freezer is properly frozen but not at the ideal temp
  colorRShift = 0;
  colorGShift = 0;
  colorBShift = 128;
  lcd.setRGB(colorRShift, colorGShift, colorBShift);
  
  lcd.setCursor(0, 1); //set the cursor to bottom row left column (column, row)
  lcd.print("Freezer Frozen  "); //indicates freezer is frozen adequately
}

else if (tempF <= -10 && tempF >= -20)
{
  //change the LCD color to green to indicate freezer is properly frozen and at the ideal temp
  colorRShift = 0;
  colorGShift = 255;
  colorBShift = 0;
  lcd.setRGB(colorRShift, colorGShift, colorBShift);
  
  lcd.setCursor(0, 1); //set the cursor to bottom row left column (column, row)
  lcd.print("Stat: ideal temp"); //indicates freezer frozen at ideal temp 
}

else
{
  //indicates freezer is too cold, trailing else
  //change LED to dim white / 1/2 gray
  colorRShift = 128;
  colorGShift = 128;
  colorBShift = 128;
  lcd.setRGB(colorRShift, colorGShift, colorBShift);
  
  lcd.setCursor(0, 1); //set the cursor to bottom row left column (column, row)
  lcd.print("Freezer too cold");
}

delay(100); //delay 100 ms to keep the sensor from being overloaded
}

