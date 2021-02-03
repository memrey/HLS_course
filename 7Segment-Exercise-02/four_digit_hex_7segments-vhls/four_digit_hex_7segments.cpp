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

#include "four_digit_hex_7segments.h"


ap_uint<8> seven_segment_digit_code (short int d) {

	ap_uint<8> segment_data;
	switch(d) {
	case 0:
		segment_data = seven_segment_code[0];
		break;
	case 1:
		segment_data = seven_segment_code[1];
		break;
	case 2:
		segment_data = seven_segment_code[2];
		break;
	case 3:
		segment_data = seven_segment_code[3];
		break;
	case 4:
		segment_data = seven_segment_code[4];
		break;
	case 5:
		segment_data = seven_segment_code[5];
		break;
	case 6:
		segment_data = seven_segment_code[6];
		break;
	case 7:
		segment_data = seven_segment_code[7];
		break;
	case 8:
		segment_data = seven_segment_code[8];
		break;
	case 9:
		segment_data = seven_segment_code[9];
		break;
	case 10:
		segment_data = seven_segment_code[10];
		break;
	case 11:
		segment_data = seven_segment_code[11];
		break;
	case 12:
		segment_data = seven_segment_code[12];
		break;
	case 13:
		segment_data = seven_segment_code[13];
		break;
	case 14:
		segment_data = seven_segment_code[14];
		break;
	case 15:
		segment_data = seven_segment_code[15];
		break;
	default:
		segment_data = seven_segment_off;
		break;
	}


	return segment_data;
}


void four_digit_hex_7segments(
		ap_uint<16> a,
		ap_uint<4>  push_buttons,
		ap_uint<8> *segment_data,
		ap_uint<4> *segment_ctrl,
		ap_uint<16> *led) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=a
#pragma HLS INTERFACE ap_none port=push_buttons
#pragma HLS INTERFACE ap_none port=segment_data
#pragma HLS INTERFACE ap_none port=segment_ctrl
#pragma HLS INTERFACE ap_none port=led



	*led = a;
	ap_uint<4> digit_1 = a(3, 0);
	ap_uint<4> digit_2 = a(7, 4);
	ap_uint<4> digit_3 = a(11, 8);
	ap_uint<4> digit_4 = a(15, 12);

	ap_uint<8> segment_data_0 = seven_segment_digit_code(digit_1);
	ap_uint<8> segment_data_1 = seven_segment_digit_code(digit_2);
	ap_uint<8> segment_data_2 = seven_segment_digit_code(digit_3);
	ap_uint<8> segment_data_3 = seven_segment_digit_code(digit_4);



	if (push_buttons == 0b0001) {
		*segment_data = segment_data_0;
		*segment_ctrl = 0b1110;
	} else if (push_buttons == 0b0010) {
		*segment_data = segment_data_1;
		*segment_ctrl = 0b1101;
	} else if (push_buttons == 0b0100) {
		*segment_data = segment_data_2;
		*segment_ctrl = 0b1011;
	} else if (push_buttons == 0b1000) {
		*segment_data   = segment_data_3;
		*segment_ctrl = 0b0111;
	} else {
		*segment_data   = seven_segment_off;
		*segment_ctrl = 0b1111;
	}


}

