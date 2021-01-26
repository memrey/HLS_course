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
#include "ccpp_testbench_exercise_02-tb.h"
#include <iostream>

void split_bits(int a, bool &a0, bool &a1, bool &a2, bool &a3) {

	a0 = a%2;
	a = a/2;

	a1 = a%2;
	a = a/2;

	a2 = a%2;
	a = a/2;

	a3 = a%2;
}


void adder_software(int a, int b, bool &s0, bool &s1, bool &s2, bool &s3, bool &c) {
	int sum = a+b;
	if (sum < 16) {
		c=0;
	} else {
		sum = sum-16;
		c = 1;
	}
	split_bits(sum, s0, s1, s2, s3);

}



int main () {
	int status = 0;


	bool a0, a1, a2, a3;
	bool b0, b1, b2, b3;
	int a, b;

	bool s0_hw, s1_hw, s2_hw, s3_hw;
	bool s0_sw, s1_sw, s2_sw, s3_sw;

	bool c_hw, c_sw;



	for (int a = 0; a < 16 && status == 0; a++) {
		for (int b = 0; b < 16 && status == 0; b++) {

			split_bits(a, a0, a1, a2, a3);
			split_bits(b, b0, b1, b2, b3);

			fourbit_adder(a0, a1, a2, a3, b0, b1, b2, b3, &s0_hw, &s1_hw, &s2_hw, &s3_hw, &c_hw);
			adder_software(a, b, s0_sw, s1_sw, s2_sw, s3_sw, c_sw);

			if (s0_hw != s0_sw
			  ||s1_hw != s1_sw
			  ||s2_hw != s2_sw
			  ||s3_hw != s3_sw
			  ||c_hw != c_sw
			  )
			{
				status = -1;
				std::cout << "Error at " << "a = " << a << " b = " << b
						  << " a = " << a3 << a2 << a1 << a0
						  << " b = " << b3 << b2 << b1 << b0
						  << " s_hw = " << s3_hw << s2_hw << s1_hw << s0_hw
						  << " s_sw = " << s3_sw << s2_sw << s1_sw << s0_sw
						  << " c_hw = " << c_hw
						  << " c_sw = " << c_sw
						  << std::endl;
			}

		}
	}



	if (status == 0) {
		std::cout << "Test Passed" << std::endl;
	} else {
		std::cout << "Test Failed" << std::endl;
	}


	return status;
}
