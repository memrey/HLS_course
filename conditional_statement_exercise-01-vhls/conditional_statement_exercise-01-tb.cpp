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
#include "conditional_statement_exercise-01-tb.h"
#include <iostream>






int main() {

	int status = 0;


	bool led1_hw, led2_hw;
	bool led1_sw, led2_sw;

	for (int i = 0; i < 256; i++) {
		ap_uint<8> a = (ap_uint<8>)i;

		odd_even(a, led1_hw, led2_hw);

		if (i%2 == 0) {
			led1_sw = 1;
			led2_sw = 0;
		} else {
			led1_sw = 0;
			led2_sw = 1;
		}

		if (led1_hw != led1_sw || led2_hw != led2_sw) {
			status = -1;
			std::cout << " Error at " << i << " led1_hw = " << led1_hw
					  << " led1_sw = " << led1_sw
					  << " led2_hw = " << led2_hw
					  << " led2_sw = " << led2_sw
					  << std::endl;
			break;
		}


	}


	if (status == 0) {
		std::cout << "Test passed!" << std::endl;
	} else {
		std::cout << "Test failed!" << std::endl;
	}




	return status;

}
