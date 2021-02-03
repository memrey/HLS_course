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
#include "single_seven_segment-tb.h"
#include <iostream>

unsigned int seven_segment_code[10] =
{
		0b11000000,
		0b11111001,
		0b10100100,
		0b10110000,
		0b10011001,
		0b10010010,
		0b10000010,
		0b11111000,
		0b10000000,
		0b10010000
};

int main() {

	int status = 0;
	ap_uint<8> digit;
	ap_uint<8> code7segment;
	ap_uint<4>  anods;

	for (int i = 0; i < 10; i++) {
		single_seven_segment(i, &code7segment, &anods);
		std::cout << "i = " << i << " code7segment = " << code7segment << "  anods = "<< anods << std::endl;
		if (code7segment != seven_segment_code[i] || anods != 14) {
			status = -1;
			break;
		}
	}


	return status;

}
