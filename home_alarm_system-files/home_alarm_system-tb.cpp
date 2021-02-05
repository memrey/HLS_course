/************************************************
Copyright (c) 2020, Mohammad Hosseinabady
All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. // Copyright (c) 2020, Mohammad Hosseinabady.
************************************************/
#include "home_alarm_system-tb.h"
#include <iostream>


void home_alarm_system_sw(
		ap_uint<16> slide_switches,
		ap_uint<5>  push_buttons,

		ap_uint<16> &leds,
		ap_uint<8>  &sg_data,
		ap_uint<4>  &sg_enable
		)
{



	leds = slide_switches;
	if (slide_switches.range(15, 12) == 0b1011) { // home alarm system is ON
		if (   slide_switches.range(2, 0) == 0b000  // All windows are closed
		    && slide_switches.range(7, 6) == 0b00)  // No motion is detected
		{
			sg_data = 0b10001000;
			sg_enable = 0b0000;
		}  else {				// security breach
			sg_data = 0b10000110;
			sg_enable = 0b0000;

			if (push_buttons[0] == 1) {
				if (slide_switches[0] == 1) {
					sg_data = 0b11111001;
					sg_enable = 0b1110;
				}
			}

			if (push_buttons[1] == 1) {
				if (slide_switches[1] == 1) {
					sg_data = 0b10100100;
					sg_enable = 0b1110;
				}
			}

			if (push_buttons[2] == 1) {
				if (slide_switches[2] == 1) {
					sg_data = 0b10110000;
					sg_enable = 0b1110;
				}
			}

			if (push_buttons[3] == 1) {
				if (slide_switches[6] == 1) {
					sg_data = 0b11111001;
					sg_enable = 0b1101;
				}
			}

			if (push_buttons[4] == 1) {
				if (slide_switches[7] == 1) {
					sg_data = 0b10100100;
					sg_enable = 0b1101;
				}
			}


		}



	} else {                //home alarm system is OFF
		sg_data = 0b11000000;
		sg_enable = 0b0000;
	}


}


int main() {

	int status = 0;



	ap_uint<3> window_sensors;
	ap_uint<2> motion_sensors;
	ap_uint<4> on_pattern;

	ap_uint<16> slide_switches;
	ap_uint<5>  push_buttons;

	ap_uint<16> leds_hw;
	ap_uint<8>  sg_data_hw;
	ap_uint<4>  sg_enable_hw;

	ap_uint<16> leds_sw;
	ap_uint<8>  sg_data_sw;
	ap_uint<4>  sg_enable_sw;




	for (int i = 0; (i < 8) && (status==0); i++) {
		for (int j = 0; (j < 4) && (status==0); j++) {
			for (int k = 0; (k < 16) && (status==0); k++) {
				push_buttons = (ap_uint<5>)0b00001;
				for (int l = 0; (l < 32) && (status==0); l++) {
					window_sensors = i;
					motion_sensors = j;
					on_pattern = k;
					push_buttons = push_buttons << 1;
					slide_switches = (push_buttons, (ap_int<4>)0, motion_sensors, (ap_int<3>)0, window_sensors);


					home_alarm_system(
							slide_switches,
							push_buttons,

							leds_hw,
							sg_data_hw,
							sg_enable_hw
					);

					home_alarm_system_sw(
							slide_switches,
							push_buttons,

							leds_sw,
							sg_data_sw,
							sg_enable_sw
					);


					if (   leds_hw != leds_sw
						|| sg_data_hw != sg_data_sw
						|| sg_enable_hw != sg_enable_sw) {

						status = -1;
						std::cout << "leds_hw = " << leds_hw.to_string() << "?" << "leds_sw = " << leds_sw.to_string() << std::endl;
						std::cout << "sg_data_hw = " << sg_data_hw.to_string() << "?" << "sg_data_sw = " << sg_data_sw.to_string() << std::endl;
						std::cout << "sg_enable_hw = " << sg_enable_hw.to_string() << "?" << "sg_enable_sw = " << sg_enable_sw.to_string() << std::endl;
						break;
					}
				}
			}
		}
	}





	if (status == 0) {
		std::cout << " Test passed!" << std::endl;
	} else {
		std::cout << " Test failed!" << std::endl;
	}

	return status;
}
