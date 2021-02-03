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
#include "four_digit_hex_7segments-tb.h"
#include <iostream>

void simple_calculator_sw(
		ap_uint<16> a,
		ap_uint<4>  push_buttons,
		ap_uint<8> *segment_data,
		ap_uint<4> *segment_ctrl,
		ap_uint<16> *led
	)
{
	ap_uint<16> r = a;
	*led = r;

	//----------------------------------------------------




	//-----------------------------------------------
	char d0, d1, d2, d3;


	d0 = r-16*(r/16);
	r = r/16;
	d1 = r-16*(r/16);
	r = r/16;
	d2 = r-16*(r/16);
	r = r/16;
	d3 = r-16*(r/16);
	//--------------------------------------------------

	ap_uint<8> segment_data_0 = seven_segment_code[d0];
	ap_uint<8> segment_data_1 = seven_segment_code[d1];
	ap_uint<8> segment_data_2 = seven_segment_code[d2];
	ap_uint<8> segment_data_3 = seven_segment_code[d3];

	if (push_buttons == 1) {
		*segment_data = segment_data_0;
		*segment_ctrl = 0b1110;
	} else if (push_buttons == 2) {
		*segment_data = segment_data_1;
		*segment_ctrl = 0b1101;
	} else if (push_buttons == 4) {
		*segment_data = segment_data_2;
		*segment_ctrl = 0b1011;
	} else if (push_buttons == 8) {
		*segment_data   = segment_data_3;
		*segment_ctrl = 0b0111;
	} else {
		*segment_data   = seven_segment_off;
		*segment_ctrl = 0b1111;
	}
}


int main() {

	int status = 0;

	ap_uint<16> a;




	ap_uint<8> segment_data_hw;
	ap_uint<4> segment_ctrl_hw;

	ap_uint<8> segment_data_sw;
	ap_uint<4> segment_ctrl_sw;

	ap_uint<16> led_hw;
	ap_uint<16> led_sw;


	for (int i = 0; i < 65536 && status == 0; i++) { // 2^16=65536
		for (int j = 0; j < 4 && status == 0; j++) {
		a = (ap_uint<16>)i;
		ap_uint<4> push_buttons =(ap_uint<4>) 1 << j;

		four_digit_hex_7segments(
				a,
				push_buttons,
				&segment_data_hw,
				&segment_ctrl_hw,
				&led_hw);

		simple_calculator_sw(
				a,
				push_buttons,
				&segment_data_sw,
				&segment_ctrl_sw,
				&led_sw );

		if ( 	(segment_data_hw != segment_data_sw) ||
				(segment_ctrl_hw != segment_ctrl_sw) ||
				(led_hw != led_sw) )
				{
					status = -1;

					std::cout << "Error at "<<
							     "    a = " << a.to_string() <<
								 "    push_buttons = " << push_buttons.to_string() <<
								 "-----------> segment_data_hw = " << segment_data_hw.to_string() <<
								 "    segment_data_sw = " << segment_data_sw.to_string() <<
								 "    segment_ctrl_hw = " << segment_ctrl_hw.to_string() <<
								 "    segment_ctrl_sw = " << segment_ctrl_sw.to_string() <<
								 std::endl;
				}

		}
	}

	if (status == 0) {
		std::cout << "Test Passed!" << std::endl;
	} else {
		std::cout << "Test Failed!" << std::endl;
	}

	return status;
}
