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

#include "even_parity_of_even_bits-tb.h"
#include <iostream>


bool even_parity_of_even_bits_software(ap_uint<N> a) {

	bool p = 0;

	for (int i = 0; i < N/2; i++) {
		bool bit = a%2;  //extract even bit
		a =  a/2;
		p = p ^ bit;
		a =  a/2;   //skip the odd bit
	}

	return p;
}


int main() {

	int status = 0;

	bool p_hw;
	bool p_sw;

	for ( int l = 0; l < 2000; l++) {
		ap_uint<N> a = 0;

		int d = rand()%N;

		for (int j = 0; j < d; j++) {
			int k = rand()%N;
			a[k] = 1;
		}

		p_hw = even_parity_of_even_bits(a);
		p_sw = even_parity_of_even_bits_software(a);

		if (p_hw != p_sw) {
			status = -1;

			std::cout << " Error at " <<  " a = " << a.to_string() << " p_hw = " << p_hw << " p_sw = " << p_sw << std::endl;

			break;
		}
	}
	if (status == 0) {
		std::cout << "Test Passed!" << std::endl;
	} else {
		std::cout << "Test Failed!" << std::endl;
	}

	return status;
}






