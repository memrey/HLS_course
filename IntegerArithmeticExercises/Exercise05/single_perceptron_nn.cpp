#include "single_perceptron_nn.h"


void single_perceptron_nn (
		ap_int<8> x1,
		ap_int<8> x2,
		ap_int<8> x3,

		float w1,
		float w2,
		float w3,

		float b,

		bool &y) {
#pragma HLS INTERFACE ap_ctrl_none port=return

#pragma HLS INTERFACE ap_none port=x1
#pragma HLS INTERFACE ap_none port=x2
#pragma HLS INTERFACE ap_none port=x3

#pragma HLS INTERFACE ap_none port=w1
#pragma HLS INTERFACE ap_none port=w2
#pragma HLS INTERFACE ap_none port=w3

#pragma HLS INTERFACE ap_none port=b

#pragma HLS INTERFACE ap_none port=y




	float s = w1*x1 + w2*x2 + w3*x3 + b;

	if (b >= 0) {
		y = 1;
	} else {
		y = 0;
	}


}
