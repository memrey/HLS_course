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

#include "conditional_statement_exercise-02-tb.h"
#include <iostream>


bool find_pattern_sw(int a) {
	int b;
	bool p=0;
	if (a == 27) {
		std::cout << " ";
	}
	for (int i = 0; i < 6; i++) {
		b = a;
		b = b >> i;
		b = b & 0b1111;
		p = p || (b == 0b1011);
	}

	return p;
}



int main() {
	int status = 0;
	bool p_hw;
	bool p_sw;

	for (int i = 0; i <  512; i++) {// 2^9 = 512
		ap_uint<9> a = (ap_uint<9>)i;

		p_hw = find_pattern(a);
		p_sw = find_pattern_sw(i);


		std::cout << " Data at " << i <<  " a = " << a.to_string() << " p_hw = " << p_hw << " p_sw = " << p_sw << std::endl;

		if (p_hw != p_sw) {
			status = -1;

			std::cout << " Error at " << i <<  " a = " << a.to_string() << " p_hw = " << p_hw << " p_sw = " << p_sw << std::endl;

			break;
		}


	}
	if (status == 0) {
		std::cout << "Test Passed" << std::endl;
	} else {
		std::cout << "Test Failed" << std::endl;
	}


	return status;
}
