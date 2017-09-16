#ifndef __ETEXTILE_MATRIX_SENSOR_BLOB_H__
#define __ETEXTILE_MATRIX_SENSOR_BLOB_H__

#include <arm_math.h>
#include <PacketSerial.h>
#include "blob.h" // Part of the OpenMV project : https://github.com/openmv/openmv

// PacketSerial serial;
/*
  PACKET SERIAL : Copyright (c) 2012-2014 Christopher Baker <http://christopherbaker.net>
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

// Control pins to send values to the 8-BITs shift registers used on the E-256 PCB
// shiftOut using SPI library : https://forum.arduino.cc/index.php?topic=52383.0
// Arduino UNO - SPI PINS
// DATA_PIN -> SPI:MOSI -> D11 // Pin connected to Data in (DS) of the firdt 74HC595 8-BIT shift register
// CLOCK_PIN -> SPI:SCK -> D13 // Pin connected to clock pin (SH_CP) of the first 74HC595 8-BIT shift register
// LATCH_PIN -> SPI:SS -> D10  // Pin connected to latch pin (ST_CP) of the first 74HC595 8-BIT shift register

// Teensy - SPI PINS https://www.pjrc.com/teensy/td_libs_SPI.html

#define  BUILTIN_LED          13
#define  BUTTON_PIN           32  // Button on the eTextile Teensy shield
#define  BAUD_RATE            230400
#define  COLS                 16
#define  ROWS                 16
#define  SCALE                4
#define  INC                  ((float)(1.0 / SCALE))
#define  ROW_FRAME            ((uint16_t)(COLS * ROWS))
#define  NEW_FRAME            ((uint16_t)(COLS * ROWS * SCALE))
#define  CALIBRATION_CYCLES   4
#define  MIN_BLOB_PIX         4   // Only blobs that with more pixels than 4
#define  A0_PIN               A0  // The output of multiplexerA (SIG pin) is connected to Arduino Analog pin 0

// Digital pins array
// See the attached home made PCB (Eagle file) to understand the Digital and Analog pin mapping
const int rowPins[ROWS] = {
  27, 26, 25, 24, 12, 11, 10, 9, 8, 7, 6, 5, 33, 2, 1, 0
};

// Analog pins array
const int columnPins[COLS] = {
  A17, A18, A19, A0, A20, A1, A2, A3, A4, A5, A6, A7, A11, A8, A10, A9
};

uint16_t minVals[ROW_FRAME] = {0};         // Array to store smallest values
// q7_t frameValues[ROW_FRAME] = {0};      // Array to store ofset input values
uint16_t frameValues[ROW_FRAME] = {0};      // Array to store ofset input values
uint8_t bilinIntOutput[NEW_FRAME] = {0};   // Bilinear interpolation Output buffer
uint8_t myPacket[ROW_FRAME] = {0};         // Array to store values to transmit

arm_bilinear_interp_instance_q7 S;
image_t       frame;
list_t        BlobOut;
rectangle_t   Roi;
thresholds_t  Thresholds;

void onPacket(const uint8_t *buffer, size_t size);
void calibrate(const uint16_t *sumArray, uint16_t id, uint16_t val);
void pushButton();
void bootBlink(int flash);

boolean scan = true;
boolean calibration = true;

#endif // __ETEXTILE_MATRIX_SENSOR_BLOB_H__