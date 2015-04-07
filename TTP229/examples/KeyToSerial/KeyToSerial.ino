/*********************************** LICENCE **********************************\
| Copyright (c) 2014, A.E. TEC                                                 |
| All rights reserved.                                                         |
|                                                                              |
| Redistribution and use in source and binary forms, with or without           |
| modification, are permitted provided that the following conditions are met:  |
|                                                                              |
| * Redistributions of source code must retain the above copyright notice,     |
|   this list of conditions and the following disclaimer.                      |
| * Redistributions in binary form must reproduce the above copyright notice,  |
|   this list of conditions and the following disclaimer in the documentation  |
|   and/or other materials provided with the distribution.                     |
|                                                                              |
| THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  |
| AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    |
| IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   |
| ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE    |
| LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR          |
| CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         |
| SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS     |
| INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      |
| CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      |
| ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   |
| POSSIBILITY OF SUCH DAMAGE.                                                  |
\******************************************************************************/
/************************************ USES ************************************\
| This sketch demonstrates the use of TTP229 Module, in 16 Buttons Mode.       |
| It displays the pressed number on the Terminal                               |
|                                                                              |
| It works with a TTP229 (16-Channel Digital Touch Capacitive Switch Sensor)   |
| using the 2-wires serial interface protocol - only 2 arduino pins.           |
\******************************************************************************/
/*********************************** CIRCUIT **********************************\
| 16 Buttons Mode:                                                             |
|	* TTP229 VCC to pin VCC                                                    |
|	* TTP229 GND to pin GND                                                    |
|	* TTP229 SCL to pin 2                                                      |
|	* TTP229 SDO to pin 3                                                      |
|	* TTP229 TP2 to GND via 1 Megohm resistor!                                 |
|	# See TTP229_Modes.jpg for help...                                         |
|                                                                              |
| Important:                                                                   |
|	* Must reconnect the TTP229 power so the mode changes will take effect     |
|	* The 1 Megohm resistors already exist on some TTP229 modules              |
\******************************************************************************/

#include <TTP229.h>

const int SCL_PIN = 2;  // The pin number of the clock pin.
const int SDO_PIN = 3;  // The pin number of the data pin.

TTP229 ttp229(SCL_PIN, SDO_PIN); // TTP229(sclPin, sdoPin)

void setup()
{
	Serial.begin(115200);
	Serial.println("Start Touching One Key At a Time!");
}

void loop()
{
	uint8_t key = ttp229.ReadKey16(); // Blocking
	if (key) Serial.println(key);

//	uint8_t key = ttp229.GetKey16(); // Non Blocking
//	Serial.println(key);
}


