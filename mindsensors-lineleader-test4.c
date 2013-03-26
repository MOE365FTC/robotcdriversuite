#pragma config(Sensor, S1,     LLEADER,             sensorI2CCustomFastSkipStates9V)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindsensors-lineleader-test4.c 133 2013-03-10 15:15:38Z xander $
 */

 /** \file mindsensors-lineleader.c
 * \brief Mindsensors LineLeader Sensor demo program
 *
 * MSLL-test3.c is a demo program for the Mindsensors LineLeader Sensor.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where its due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER. 

 * Xander Soldaat (xander_at_botbench.com)
 * 28 November 2009
 * version 0.2
 */

#include "mindsensors-lineleader.h"

task main {
  tIntArray signalstr;

  while (true) {
    // Fetch the data from the sensor.  These are the 16 bit raw AD values.
    LLreadSensorUncalibrated(LLEADER, signalstr);

    // Display the actual signal strength for each sensor
    for (int i = 0; i < 7; i++) {
      nxtDisplayTextLine(i, "S[%d]: %5d", i, signalstr[i]);
    }
    wait1Msec(50);
  }
}

/*
 * $Id: mindsensors-lineleader-test4.c 133 2013-03-10 15:15:38Z xander $
 */
