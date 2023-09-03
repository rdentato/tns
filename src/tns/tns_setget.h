//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT

#define tns_nrows(t) ((t)->nrows)
#define tns_ncols(t) ((t)->ncols)
#define tns_type(t) ((t)->type)

// Get an element from the tensor

float tns_fp32_get(tns_fp32_t tns,int row, int col);
float tns_int8_get(tns_int8_t tns,int row, int col);

#define tns_get_(t,r,c)  _Generic((t),tns_fp32_t: tns_fp32_get, \
                                      tns_int8_t: tns_int8_get  \
                                 )(t,r,c)

#define tns_get(...) TNS_varargs(tns_get_,__VA_ARGS__)

#define tns_get_1(t)     tns_get_(t,0,0)
#define tns_get_2(t,r)   tns_get_(t,r,0)
#define tns_get_3(t,r,c) tns_get_(t,r,c)

#define tns_get_by_ndx(t,n)  _Generic((t),tns_fp32_t: tns_fp32_get_by_ndx, \
                                          tns_int8_t: tns_int8_get_by_ndx  \
                                     )((void *)t,n)


float tns_fp32_get_by_ndx(tns_fp32_t tns,int ndx);
float tns_int8_get_by_ndx(tns_int8_t tns,int ndx);

int8_t tns_int8_get_quant(tns_int8_t tns, int row, int col);
float tns_int8_get_scale(tns_int8_t tns, int row, int col);


void tns_fp32_set(tns_fp32_t tns, float x, int row, int col);
void tns_int8_set(tns_int8_t tns, float x, int row, int col);

#define tns_set_(t,x,r,c)  _Generic((t),tns_fp32_t: tns_fp32_set, \
                                        tns_int8_t: tns_int8_set  \
                                   )(t,x,r,c)

#define tns_set(...) TNS_varargs(tns_set_,__VA_ARGS__)

#define tns_set_1(t)       tns_set_(t,0.0,0,0)
#define tns_set_2(t,x)     tns_set_(t,x,0,0)
#define tns_set_3(t,x,r)   tns_set_(t,x,r,0)
#define tns_set_4(t,x,r,c) tns_set_(t,x,r,c)
