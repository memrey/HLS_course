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
#include "single_seven_segment.h"




void single_seven_segment(ap_uint<8> digit, ap_uint<8> *code7segment, ap_uint<4> *anods) {
#pragma HLS INTERFACE ap_none port=anods
#pragma HLS INTERFACE ap_none port=code7segment
#pragma HLS INTERFACE ap_none port=digit
#pragma HLS INTERFACE ap_ctrl_none port=return


	switch(digit) {
	case 0:
		*code7segment = 0b11000000;
		break;
	case 1:
		*code7segment = 0b11111001;
		break;
	case 2:
		*code7segment = 0b10100100;
		break;
	case 3:
		*code7segment = 0b10110000;
		break;
	case 4:
		*code7segment = 0b10011001;
		break;
	case 5:
		*code7segment = 0b10010010;
		break;
	case 6:
		*code7segment = 0b10000010;
		break;
	case 7:
		*code7segment = 0b11111000;
		break;
	case 8:
		*code7segment = 0b10000000;
		break;
	case 9:
		*code7segment = 0b10010000;
		break;
	default:
		*code7segment = 0b11111111;
	}

	*anods = 0b1110;


}
