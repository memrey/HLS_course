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

#include "ascii_on_7segment-tb.h"

void ascii_on_7segment_software(
		ap_uint<8> a,
		ap_uint<8> *segment_data,
		ap_uint<4> *segment_ctrl,
		ap_uint<8> *led) {


	*led = a;

	int index = a - 96;

	*segment_data = seven_segment_code[index];
	*segment_ctrl = 0b1110;
}

int main() {

	int status = 0;

	ap_uint<8> a;

	ap_uint<8> segment_data_hw;
	ap_uint<4> segment_ctrl_hw;
	ap_uint<8> led_hw;

	ap_uint<8> segment_data_sw;
	ap_uint<4> segment_ctrl_sw;
	ap_uint<8> led_sw;

	for (int i = 97; i < 104 && status == 0; i++) {
		a = (ap_uint<8>)i;
		ascii_on_7segment( a, &segment_data_hw, &segment_ctrl_hw, &led_hw );
		ascii_on_7segment_software( a, &segment_data_sw, &segment_ctrl_sw, &led_sw );


		if ( 	(segment_data_hw != segment_data_sw) ||
				(segment_ctrl_hw != segment_ctrl_sw) ||
				(led_hw != led_sw) )
				{
					status = -1;

					std::cout << "Error at "<<
							     "    a = " << a.to_string() <<
								 "-----------> segment_data_hw = " << segment_data_hw.to_string() <<
								 "    segment_data_sw = " << segment_data_sw.to_string() <<
								 "    segment_ctrl_hw = " << segment_ctrl_hw.to_string() <<
								 "    segment_ctrl_sw = " << segment_ctrl_sw.to_string() <<
								 std::endl;
				}
	}



	if (status == 0) {
		std::cout << "Test Passed!" << std::endl;
	} else {
		std::cout << "Test Failed!" << std::endl;
	}

	return status;
}
