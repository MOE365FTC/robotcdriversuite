#pragma config(Sensor, S1,     NXTSERVO,            sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindensors-servo-test1.c 133 2013-03-10 15:15:38Z xander $
 */

/**
 * mindensors-servo.h provides an API for the Mindsensors NXTServo Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER. 

 * Xander Soldaat (xander_at_botbench.com)
 * 28 November 2009
 * version 0.2
 */

#include "mindensors-servo.h"

task main () {
  int voltage = 0;

  nxtDisplayCenteredTextLine(0, "Mindsensors");
  nxtDisplayCenteredBigTextLine(1, "NXTServo");
  nxtDisplayCenteredTextLine(3, "Demo prog");
  nxtDisplayCenteredTextLine(5, "Connect NXServo");
  nxtDisplayCenteredTextLine(6, "to S1 and servo");
  nxtDisplayCenteredTextLine(7, "to connector 1");
  wait1Msec(2000);

  eraseDisplay();
  while (true) {

    // read the current voltage of the power supply for the
    // sevos
    voltage = NXTServoReadVoltage(NXTSERVO);
    nxtDisplayCenteredBigTextLine(1, "%dmV", voltage);

    // Move the servo to position "500" with max speed (0)
	  NXTServoSetPos(NXTSERVO, 1, 500, 0);
	  wait1Msec(1000);

	  // Move the servo to position "2500" with speed 30
	  NXTServoSetPos(NXTSERVO, 1, 2500, 30);

	  wait1Msec(1000);
  }
}


/*
 * $Id: mindensors-servo-test1.c 133 2013-03-10 15:15:38Z xander $
 */
