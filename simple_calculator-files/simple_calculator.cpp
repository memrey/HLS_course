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
#include "simple_calculator.h"




void simple_calculator(
		int5 a,
		int5 b,

		bool hex_dec,
		uint4 code,

		uint4 select_digit,

		uint16 *leds,

		uint8 *segment_data,
		uint4 *segment_enable
	) {

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=a
#pragma HLS INTERFACE ap_none port=b
#pragma HLS INTERFACE ap_none port=hex_dec
#pragma HLS INTERFACE ap_none port=code
#pragma HLS INTERFACE ap_none port=select_digit
#pragma HLS INTERFACE ap_none port=segment_data
#pragma HLS INTERFACE ap_none port=segment_enable
#pragma HLS INTERFACE ap_none port=leds



	int10 result=0;


	result = operations(a, b, code);

	short int d0 = 0, d1 = 0, d2 = 0, d3 = 0;
	extract_digits(hex_dec, result, d0, d1, d2, d3);
	display_digits( d0, d1, d2, d3, select_digit, segment_data, segment_enable);


	*leds = (code, hex_dec, (ap_uint<1>)0b0, b, a);




}
