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

#include "bcd2binary_rdd-tb.h"


void binary2bcd_software(uint16 in_binary, uint16 *packed_bcd) {

	int packed_bcd_tmp;
	int in_binary_tmp = in_binary;


	int r = in_binary_tmp%10;
	packed_bcd_tmp = r;
	in_binary_tmp = in_binary_tmp/10;

	r = in_binary_tmp%10;
	packed_bcd_tmp = (r << 4) + packed_bcd_tmp;
	in_binary_tmp = in_binary_tmp/10;

	r = in_binary_tmp%10;
	packed_bcd_tmp = (r << 8) + packed_bcd_tmp;
	in_binary_tmp = in_binary_tmp/10;

	r = in_binary_tmp%10;
	packed_bcd_tmp = (r << 12) + packed_bcd_tmp;

	*packed_bcd = packed_bcd_tmp;
}

int main() {
	int status = 0;




	uint16 binary_original = 9999;
	uint16 packed_bcd;
	uint16 binary_hw;

	for (int i = 0; i < 9999; i++) {
		binary_original = (uint16)i;

		binary2bcd_software(binary_original, &packed_bcd);

		binary2bcd_rdd(packed_bcd, &binary_hw);


		if (binary_original !=binary_hw) {
			status = -1;
			std::cout << "Error at " << i
					  << " binary_original = " << binary_original.to_string()
					  << " packed_bcd = " << packed_bcd.to_string()
					  << " binary_hw = " << binary_hw.to_string()
					  << std::endl;
			break;
		}
	}



	if (status == 0) {
		std::cout << " Test Passed!" << std::endl;
	} else {
		std::cout << " Test Failed!" << std::endl;
	}

	return status;

}
