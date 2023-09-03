//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT

void tns_fp32_cpy_v(tns_fp32_t A, float *v);
void tns_int8_cpy_v(tns_int8_t A, float *v);

void tns_v_cpy_fp32(float *v,tns_fp32_t A);
void tns_v_cpy_int8(float *v,tns_int8_t A);

void tns_fp32_cpy_fp32(tns_fp32_t A, tns_fp32_t B);
void tns_fp32_cpy_int8(tns_fp32_t A, tns_int8_t B);

void tns_int8_cpy_fp32(tns_int8_t A, tns_fp32_t B);
void tns_int8_cpy_int8(tns_int8_t A, tns_int8_t B);

void tns_v_cpy_v(float *A, float *B);

#define tns_cpy(t,v) _Generic((t),    float *: _Generic((v),    float *: tns_v_cpy_v,\
                                                             tns_fp32_t: tns_v_cpy_fp32, \
                                                             tns_int8_t: tns_v_cpy_int8  \
                                                       ), \
                                   tns_fp32_t: _Generic((v),    float *: tns_fp32_cpy_v, \
                                                             tns_fp32_t: tns_fp32_cpy_fp32, \
                                                             tns_int8_t: tns_fp32_cpy_int8  \
                                                       ), \
                                   tns_int8_t: _Generic((v),    float *: tns_int8_cpy_v, \
                                                             tns_fp32_t: tns_int8_cpy_fp32, \
                                                             tns_int8_t: tns_int8_cpy_int8  \
                                                       ) \
                              )((void *)t,(void *)v)



