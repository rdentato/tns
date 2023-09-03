//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT

#include "tns.h"

void tns_fp32_softmax(tns_fp32_t dst, tns_fp32_t tns)
{
  // find max value (for numerical stability)
  float max_val;
  int size;

  max_val = tns_get_by_ndx(tns,0);
  size = tns_ncols(tns) * tns_nrows(tns);

  float x;
  for (int i = 1; i < size ; i++) {
    x = tns_get(tns,i);
    if (x > max_val) max_val = x;
  }

  // exp and sum
  float sum = 0.0f;
  for (int i = 0; i < size; i++) {
    dst->values[i] = expf(tns->values[i] - max_val);
    sum += dst->values[i];
  }

  // normalize
  for (int i = 0; i < size; i++) {
    dst->values[i] /= sum;
  }
}

