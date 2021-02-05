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

uint10 div10(uint10 r) {
#pragma HLS INLINE off

	return (r/10);
}

void extract_digits(
		bool  hex_dec,
		int10 result,
		short int &d0,
		short int &d1,
		short int &d2,
		short int &d3) {


	short int sign = 0;
	uint10 r = result;
	if (result < 0) {
		sign = 1;
		r = -result;
	} else {
		sign = 0;
		r = result;
	}

	d0 = 0;
	d1 = 0;
	d2 = 0;
	d3 = 0;

	if (hex_dec == 0) {
		//first decimal digit
		d0 = r-10*div10(r);

		r = r/10;
		//second decimal digit
		d1 = r-10*div10(r);

		r = r/10;
		//third decimal digit
		d2 = r-10*div10(r);
	} else {
		//first decimal digit
		d0 = r(3, 0);
		//second decimal digit
		d1 = r(7, 4);
		//third decimal digit
		d2 = r(9, 8);
	}

	d3 = sign;
}

