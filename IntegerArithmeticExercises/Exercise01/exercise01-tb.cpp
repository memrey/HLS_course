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

#include <ap_int.h>
#include <iostream>

typedef ap_int<7>   int7;
typedef ap_int<10>  int10;
typedef ap_uint<7>  uint7;
typedef ap_uint<10> uint10;



int main() {

	int status = 0;

	int7    a7 =-3;
	int10  a10 = a7;
	uint7   b7 =125;
	uint10 b10 = a7;


	std::cout << "a7 = " << a7.to_string() << std::endl;
	std::cout << "a10 = " << a10.to_string() << std::endl;
	std::cout << "b7 = " << b7.to_string() << std::endl;
	std::cout << "b10 = " << b10.to_string() << std::endl;


	return status;
}
