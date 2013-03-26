#pragma config(Sensor, S1,     MSANG,               sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindsensors-angle-test2.c 133 2013-03-10 15:15:38Z xander $
 */

/**
 * mindsensors-angle.h provides an API for the Mindsensors Angle Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER. 

 * Xander Soldaat (xander_at_botbench.com)
 * date 31 November 2012
 * version 0.1
 */

#define debounce() while (nNxtButtonPressed != kNoButton) EndTimeSlice()

#include "mindsensors-angle.h"

// This is the value when I calibrated it, yours may vary
float gramsPerUnit = 1.084507;


// Get the current weight of the object
int weighObject()
{
  return max2(0, round(MSANGreadRaw(MSANG) * gramsPerUnit));
}

// Allow the user to calibrate the scales
void calibrateScales()
{
  int calibrateWeight = 0;

  eraseDisplay();
  nxtDisplayCenteredTextLine(0, "GlideWheel-AS");
  nxtDisplayCenteredTextLine(2, "Place the object");
  nxtDisplayCenteredTextLine(3, "on the scales");
  nxtDisplayCenteredTextLine(4, "and press");
  nxtDisplayCenteredTextLine(5, "[enter]");
  nxtDisplayCenteredTextLine(6, "to calibrate");
  while (nNxtButtonPressed != kEnterButton) EndTimeSlice();
  debounce();
  eraseDisplay();
  calibrateWeight = weighObject();
  nxtDisplayCenteredTextLine(0, "GlideWheel-AS");
  nxtDisplayCenteredTextLine(2, "Enter the weight");
  nxtDisplayCenteredTextLine(3, "in grams");
  nxtDisplayCenteredTextLine(7, "-     OK     +");
  while (true)
  {
    nxtDisplayCenteredBigTextLine(5, "%d", calibrateWeight);
    switch(nNxtButtonPressed)
    {
      case kLeftButton: PlayTone(500,10); calibrateWeight--; calibrateWeight = max2(0, calibrateWeight); break;
      case kRightButton: PlayTone(1000,10); calibrateWeight++; break;
      case kEnterButton: PlayTone(1500,10);gramsPerUnit = (float)calibrateWeight / (float)MSANGreadRaw(MSANG); eraseDisplay(); return;
    }
    wait1Msec(20);
    debounce();
  }
}


task main () {
  nNxtButtonTask  = -2;
  nxtDisplayCenteredTextLine(0, "Mindsensors");
  nxtDisplayCenteredBigTextLine(1, "Angle");
  nxtDisplayCenteredTextLine(3, "Test 2");
  nxtDisplayCenteredTextLine(5, "Connect sensor");
  nxtDisplayCenteredTextLine(6, "to S1");
  MSANGresetAngle(MSANG);
  wait1Msec(2000);

  eraseDisplay();

  while (true) {
    // Reset the angle to 0
    if (nNxtButtonPressed == kEnterButton)
    {
      debounce();
      calibrateScales();
      debounce();
    }
    nxtDisplayCenteredTextLine(0, "GlideWheel-AS");
    nxtDisplayCenteredTextLine(1, "Weighing scale");
		nxtDisplayTextLine(7, "[enter] to calib.");

    nxtDisplayCenteredBigTextLine(4, "%d g", weighObject());

    wait1Msec(20);
  }
}


/*
 * $Id: mindsensors-angle-test2.c 133 2013-03-10 15:15:38Z xander $
 */
