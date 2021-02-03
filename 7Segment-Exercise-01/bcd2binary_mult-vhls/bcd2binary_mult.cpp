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
#include "bcd2binary_mult.h"



void bcd2binary_mult(uint16 packed_bcd, uint14 *output_bcd) {
#pragma HLS INTERFACE ap_none port=packed_bcd
#pragma HLS INTERFACE ap_none port=output_bcd
#pragma HLS INTERFACE ap_ctrl_none port=return


	uint14 bcd = 0;

	uint4 digit_1 = packed_bcd(3, 0);
	uint4 digit_2 = packed_bcd(7, 4);
	uint4 digit_3 = packed_bcd(11, 8);
	uint4 digit_4 = packed_bcd(15, 12);



	bcd = bcd + digit_1 * 1;
	bcd = bcd + digit_2 * 10;
	bcd = bcd + digit_3 * 100;
	bcd = bcd + digit_4 * 1000;

	*output_bcd = bcd;
}
