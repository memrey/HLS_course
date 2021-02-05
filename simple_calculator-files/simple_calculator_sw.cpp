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
#include <iostream>
#include "simple_calculator-tb.h"


void simple_calculator_sw(
		int5 a,
		int5 b,

		bool hex_dec,
		uint4 code,

		uint4 select_digit,

		uint16 *leds,

		uint8 *segment_data,
		uint4 *segment_enable
	)
{

	*leds = (code, hex_dec, (ap_uint<1>)0b0, b, a);

	//----------------------------------------------------
	int10 result;

	if (code == 0) {
		result = a+b;
	} else if (code == 1) {
		result = a-b;
	} else if (code == 2) {
		result = a&b;
	} else if (code == 3) {
		result = a|b;
	} else if (code == 4) {
		result = ~(a&b);
	} else if (code == 5) {
		result = a^b;
	} else if (code == 6) {
		result = ~a;
	} else  {
		result = -a;
	}


	//-----------------------------------------------
	char d0, d1, d2, d3;

	int10 r;

	if (result < 0) {
		d3 = 1;
		r = -result;
	} else {
		d3 = 0;
		r = result;
	}

	if (hex_dec == 0) {
		d0 = r-10*(r/10);
		r = r/10;
		d1 = r-10*(r/10);
		r = r/10;
		d2 = r-10*(r/10);
	} else {
		d0 = r-16*(r/16);
		r = r/16;
		d1 = r-16*(r/16);
		r = r/16;
		d2 = r-16*(r/16);
	}
	//--------------------------------------------------

	uint8 segment_data_0 = seven_segment_code[d0];
	uint8 segment_data_1 = seven_segment_code[d1];
	uint8 segment_data_2 = seven_segment_code[d2];
	uint8 segment_data_3;
	if (d3 == 0)
		segment_data_3 = seven_segment_off;
	else
		segment_data_3 = seven_segment_negative;



	if (select_digit == 1) {
		*segment_data = segment_data_0;
		*segment_enable = 0b1110;
	} else if (select_digit == 2) {
		*segment_data = segment_data_1;
		*segment_enable = 0b1101;
	} else if (select_digit == 4) {
		*segment_data = segment_data_2;
		*segment_enable = 0b1011;
	} else if (select_digit == 8) {
		*segment_data   = segment_data_3;
		*segment_enable = 0b0111;
	} else {
		*segment_data   = seven_segment_off;
		*segment_enable = 0b1111;
	}
}

