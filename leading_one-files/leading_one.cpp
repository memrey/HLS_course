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
#include "leading_one.h"

ap_int<5> leading_one(ap_uint<9> a) {
#pragma HLS INTERFACE ap_none port=a
#pragma HLS INTERFACE ap_ctrl_none port=return



	ap_int<5> index;

	if (a[8] == 1) {
		index = 8;
	} else if (a[7] == 1) {
		index = 7;
	} else	if (a[6] == 1) {
		index = 6;
	} else	if (a[5] == 1) {
		index = 5;
	} else	if (a[4] == 1) {
		index = 4;
	} else	if (a[3] == 1) {
		index = 3;
	} else	if (a[2] == 1) {
		index = 2;
	} else	if (a[1] == 1) {
		index = 1;
	} else	if (a[0] == 1) {
		index = 0;
	} else {
		index = -1;
	}



	return index;
}
