#ifndef __CONFIG_H__
#define __CONFIG_H__

#define BUILTIN_LED          13
#define BUTTON_PIN           32  // Button on the eTextile Teensy shield
#define BAUD_RATE            230400
#define COLS                 16
#define ROWS                 16
#define SCALE                4
#define MAX_BLOBS            8  // Set the maximum blob number

#define ROW_FRAME            (COLS * ROWS)
#define NEW_COLS             (COLS * SCALE)
#define NEW_ROWS             (ROWS * SCALE)
#define NEW_FRAME            (NEW_COLS * NEW_ROWS)
#define INC                  (1.0 / SCALE)
#define CYCLES               4     // Set the calibration cycles
#define THRESHOLD            15    // Set the threshold that determine toutch sensitivity (10 is low 30 is high)
#define MAX_NODES            40    // Set the maximum blob number
#define MIN_BLOB_PIX         4     // Set the minimum blob pixels
#define MAX_BLOB_PIX         1500  // Set the minimum blob pixels
#define A0_PIN               A0    // The output of multiplexerA (SIG pin) is connected to Analog pin 0

#define DEBUG_INPUT          false
#define DEBUG_INTERP         false
#define DEBUG_BITMAP         false
#define DEBUG_LIST           false
#define DEBUG_BLOB           false
#define DEBUG_OSC            true

#endif /*__CONFIG_H__*/
