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
#ifndef __HOME_ALARM_SYSTEM_H__
#define __HOME_ALARM_SYSTEM_H__


#include <ap_int.h>

const ap_uint<8> svn_sg_code [] = {
	0b11000000,   // 0 or O----- > index 0
	0b11111001,   // 1---------- > index 1
	0b10100100,   // 2---------- > index 2
	0b10110000,   // 3---------- > index 3
	0b10011001,   // 4---------- > index 4
	0b10010010,   // 5---------- > index 5
	0b10000010,   // 6---------- > index 6
	0b11111000,   // 7---------- > index 7
	0b10000000,   // 8---------- > index 8
	0b10010000,   // 9---------- > index 9

	0b10001000,   // A---------- > index 10
	0b10000011,   // b---------- > index 11
	0b11000110,   // C---------- > index 12
	0b10100001,   // d---------- > index 13
	0b10000110,   // E---------- > index 14
	0b10001110    // F---------- > index 15

};


void security_breach(
		ap_uint<3>  window_sensors,
		ap_uint<2>  motion_detectors,
		ap_uint<5>  show_fault,

		ap_uint<8> &sg_data,
		ap_uint<4> &sg_enable);


#endif //__HOME_ALARM_SYSTEM_H__
