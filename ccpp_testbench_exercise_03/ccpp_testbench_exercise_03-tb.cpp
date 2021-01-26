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
		);

void comparator_sw( int a, int b, bool &m_sw, bool &n_sw, bool &p_sw) {
	if (a == b) {
		m_sw = 1;
		n_sw = 0;
		p_sw = 0;
	}

	if (a > b) {
		m_sw = 0;
		n_sw = 1;
		p_sw = 0;
	}


	if (a < b) {
		m_sw = 0;
		n_sw = 0;
		p_sw = 1;
	}

}
int main() {

	int status = 0;

	int a;
	int b;

	bool a0, a1, a2, a3;
	bool b0, b1, b2, b3;

	bool m_hw, n_hw, p_hw;
	bool m_sw, n_sw, p_sw;

	for (int i = 0; (i < 16) && (status == 0) ; i++) {
		for (int j = 0; (j < 16) && (status == 0); j++) {
			a = i;
			b = j;
			split_bits(a, a0, a1, a2, a3);
			split_bits(b, b0, b1, b2, b3);

			comparator( a0, a1, a2, a3, b0, b1, b2, b3, m_hw, n_hw, p_hw);
			comparator_sw( a, b, m_sw, n_sw, p_sw);

			if ( (m_hw != m_sw) || (n_hw != n_sw) || (p_hw != p_sw) ){
				status = -1;
				std::cout << " Errot at "
						  << " a = " << a
						  << " b = " << b
						  << " m_hw = " << m_hw << "m_sw = " << m_sw
						  << " n_hw = " << n_hw << "n_sw = " << n_sw
						  << " p_hw = " << p_hw << "p_sw = " << p_sw
						  << std::endl;
			}

		}
	}


	if (status == 0 ) {
		std::cout << "OK " << std::endl;
	} else {
		std::cout << "Error " << std::endl;
	}

	return status;
}
