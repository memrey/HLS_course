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
#ifndef __CCPP_TESTBENCH_EXERCISE_01_TB_H__
#define __CCPP_TESTBENCH_EXERCISE_01_TB_H__


void fourbit_adder(
		bool  a0,
		bool  a1,
		bool  a2,
		bool  a3,

		bool  b0,
		bool  b1,
		bool  b2,
		bool  b3,

		bool *s0,
		bool *s1,
		bool *s2,
		bool *s3,

		bool *c
		);

#endif //__CCPP_TESTBENCH_EXERCISE_01_TB_H__
