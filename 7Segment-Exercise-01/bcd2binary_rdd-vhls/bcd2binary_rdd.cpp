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
#include "bcd2binary_rdd.h"


uint32 reverse_double_dabble(uint32 scp) {
      uint32 s;
      s = scp;
      s = scp >> 1;
      if (s(19, 16) > 7)
        s(19, 16) = s(19, 16) - 3;
      if (s(23, 20) > 7)
        s(23, 20) = s(23, 20) - 3;
      if (s(27, 24) > 7)
        s(27, 24) = s(27, 24) - 3;


      return s;
    }




void binary2bcd_rdd(uint16 packed_bcd, uint16 *in_binary) {
#pragma HLS INTERFACE ap_none port=in_binary
#pragma HLS INTERFACE ap_none port=packed_bcd
#pragma HLS INTERFACE ap_ctrl_none port=return

	uint32 scratch_pad = 0;
    scratch_pad(31, 16) = packed_bcd;

    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = reverse_double_dabble(scratch_pad);

    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = reverse_double_dabble(scratch_pad);

    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = reverse_double_dabble(scratch_pad);

    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = reverse_double_dabble(scratch_pad);
    scratch_pad = scratch_pad >> 1;

    *in_binary   = scratch_pad(15, 0);
}
