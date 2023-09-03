//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT


void tns_fp32_softmax(tns_fp32_t dst, tns_fp32_t tns);

#define tns_softmax(o,t) tns_fp32_softmax(o,t)
