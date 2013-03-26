#pragma config(Sensor, S3,     LEGOLS,              sensorLightInactive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: lego-light-test2.c 133 2013-03-10 15:15:38Z xander $
 */

/**
 * lego-light.h provides an API for the Lego Light Sensor.  This program
 * demonstrates how to use that API to calibrate the sensor.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER. 

 * Xander Soldaat (xander_at_botbench.com)
 * 25 November 2009
 * version 0.2
 */

#include "lego-light.h"

task main () {
  int raw = 0;
  int nrm = 0;
  // Get control over the buttons
  nNxtButtonTask  = -2;

  LSsetActive(LEGOLS);
  eraseDisplay();
  nxtDisplayTextLine(0, "Light Sensor Cal.");
  nxtDisplayTextLine(2, "Left:  set black");
  nxtDisplayTextLine(3, "Right: set white");
  nxtDisplayTextLine(7, "Grey:  exit");

  while (true) {
    switch(nNxtButtonPressed) {
      // if the left button is pressed calibrate the black value for the sensor
      case kLeftButton:
                        LScalLow(LEGOLS);
                        PlaySound(soundBeepBeep);
                        while(bSoundActive) EndTimeSlice();
                        break;

      // if the left button is pressed calibrate the white value for the sensor
      case kRightButton:
                        LScalHigh(LEGOLS);
                        PlaySound(soundBeepBeep);
                        while(bSoundActive) EndTimeSlice();
                        break;
    }

    nxtDisplayClearTextLine(5);
    nxtDisplayClearTextLine(6);

    // Read the raw value of the sensor
    raw = LSvalRaw(LEGOLS);

    // Read the normalised value of the sensor
    nrm = LSvalNorm(LEGOLS);

    // Display the raw and normalised values
    nxtDisplayTextLine(5, "R: %4d N: %4d", raw, nrm);

    // Display the values for black and white
    nxtDisplayTextLine(6, "B: %4d W: %4d", lslow[LEGOLS * 4], lshigh[LEGOLS * 4]);
    wait1Msec(50);
  }
}

/*
 * $Id: lego-light-test2.c 133 2013-03-10 15:15:38Z xander $
 */
