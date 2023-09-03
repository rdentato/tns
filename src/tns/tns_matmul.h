//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT


void tns_fp32_matmul(tns_fp32_t r, tns_fp32_t A, tns_fp32_t x);
void tns_int8_matmul(tns_fp32_t r, tns_int8_t A, tns_int8_t x);


void tns_matmul_fp32_fp32(tns_fp32_t r, tns_fp32_t A, tns_fp32_t x);
void tns_matmul_fp32_int8(tns_fp32_t r, tns_fp32_t A, tns_int8_t x);
void tns_matmul_int8_fp32(tns_fp32_t r, tns_int8_t A, tns_fp32_t x);
void tns_matmul_int8_int8(tns_fp32_t r, tns_int8_t A, tns_int8_t x);
