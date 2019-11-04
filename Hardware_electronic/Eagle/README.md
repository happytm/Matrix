# eTextile matrix sensor / Eagle PCB

### Transforming textiles into an intuitive way to interact with computers. This project is part of an electronic textiles research on HCI gesture interaction that was started in 2005.

- Author/developer: Maurin Donneaud <maurin@etextile.org> - Industrial designer
- Repository: https://github.com/eTextile/resistiveMatrix/tree/master
- Project web page: www.eTextile.org
- License: CC-BY-SA (see the License file)

![alt tag](http://wiki.datapaulette.org/lib/exe/fetch.php/atelier/projets/matrice_capteurs_textiles_05.jpg)

This PCB is adapted to an eTextile bus solution that allows the connection betwin the textile matrix conductive strips and the microcontroller I/O pins.
The E256 branch of this project present a new PCB design based on etching conductive fabric replacing this eTextile bus solution.

## Partslist

| Part        |    Value                     |     Device              |          Package     |
|-------------|:-----------------------------|:------------------------|:---------------------|
ANALOG_INPUT  | 3.3V                         | PINHD-1X16/90           | 1X16/90              |
ANALOG_INPUT1 | 3.3V                         | PINHD-1X16              | 1X16                 |
C1            | 4.7uF                        | CAP0805                 | 0805                 |
C2            | 4.7uF                        | CAP0805                 | 0805                 |
C3            | 10uf                         | CPOL-EUE1.8-4           | E1,8-4               |
D1            | RED                          | LED1206                 | LED-1206             |
D11           | RED                          | LED1206                 | LED-1206             |
DIGITAL_OUT   |                              | PINHD-1X16/90           | 1X16/90              |
DIGITAL_OUT1  | 3.3V                         | PINHD-1X16/90           | 1X16/90              |
JP7           | LiPo Battery                 | M02-JST-2MM-SMT         | JST-2-SMD            |
R1            | 2K                           | RESISTOR0805-RES        | 0805                 |
R2            | 330                          | RESISTOR0805-RES        | 0805                 |
R3            | 330                          | RESISTOR0805-RES        | 0805                 |
RN1           | 3.3V                         | G08R                    | SIL9                 |
RN2           | 3.3V                         | G08R                    | SIL9                 |
S1            | SWITCH                       | SWITCH-SPSTSMD          | AYZ0202              |
SWITCH1       | SWITCH-MOMENTARY-2           | SWITCH-MOMENTARY-2      | TACTILE_SWITCH_TALL  |
U$1           | TEENSY_3.1_ALL_PINS_AND_PADS | TEENSY_3.1_ALL_PINS_AND_PADS | TEENSY_3.1_ALLPINS   |
U1            | MCP73831                     | MCP73831                     | SOT23-5              |
U3            |                              | AUDIO-JACKSMD2               | AUDIO-JACK-3.5MM-SMD |

## TODO
- Replace the Teensy With an other chip
  - keep compatibility with the Teensy audo lib : http://www.pjrc.com/teensy/td_libs_Audio.html
- Make the design with Upverter
