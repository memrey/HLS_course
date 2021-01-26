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

void comparator(
		bool a0,
		bool a1,
		bool a2,
		bool a3,

		bool b0,
		bool b1,
		bool b2,
		bool b3,

		bool &M,
		bool &N,
		bool &P
		)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=a0
#pragma HLS INTERFACE ap_none port=a1
#pragma HLS INTERFACE ap_none port=a2
#pragma HLS INTERFACE ap_none port=a3


#pragma HLS INTERFACE ap_none port=b0
#pragma HLS INTERFACE ap_none port=b1
#pragma HLS INTERFACE ap_none port=b2
#pragma HLS INTERFACE ap_none port=b3

#pragma HLS INTERFACE ap_none port=M
#pragma HLS INTERFACE ap_none port=N
#pragma HLS INTERFACE ap_none port=P

	if (a3 == b3 ) {
		if (a2 == b2) {
			if (a1 == b1) {
				if (a0 == b0) {
					M=1;
					N=0;
					P=0;
				} else {
					if (a0 == 1) {
						M=0;
						N=1;
						P=0;
					} else {
						M=0;
						N=0;
						P=1;
					}
				}
			} else {
				if (a1 == 1) {
					M=0;
					N=1;
					P=0;
				} else {
					M=0;
					N=0;
					P=1;
				}
			}

		} else {
			if (a2 == 1) {
				M=0;
				N=1;
				P=0;
			} else {
				M=0;
				N=0;
				P=1;
			}
		}
	} else {
		if (a3 == 1) {
			M=0;
			N=1;
			P=0;
		} else {
			M=0;
			N=0;
			P=1;
		}
	}

}
