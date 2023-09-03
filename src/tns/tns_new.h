//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT

// Create a new tensor

tns_fp32_t tns_fp32_new(int nrows, int ncols, float *values);
tns_int8_t tns_int8_new(int nrows, int ncols, int gsize, int8_t *values, float  *scales);

// Call the right `new` function depending on the type of `t`
#define tns_new(t, ...)  do { tns_fp32_t(*_fp32_new)() = tns_fp32_new; \
                              tns_int8_t(*_int8_new)() = tns_int8_new; \
                              t = _Generic((t), tns_fp32_t : tns_fp32_new_(__VA_ARGS__), \
                                                tns_int8_t : tns_int8_new_(__VA_ARGS__) ); \
                            } while(0)

#define tns_fp32_new_(...)         TNS_varargs(tns_fp32_new_,__VA_ARGS__)
#define tns_int8_new_(...)         TNS_varargs(tns_int8_new_,__VA_ARGS__)

#define tns_fp32_new_1(r)          _fp32_new(r, 1, NULL)
#define tns_fp32_new_2(r,c)        _fp32_new(r, c, NULL)
#define tns_fp32_new_3(r,c,v)      _fp32_new(r, c, v)

#define tns_int8_new_1(r)          _int8_new(r, 1, 64, NULL, NULL)
#define tns_int8_new_2(r,c)        _int8_new(r, c, 64, NULL, NULL)
#define tns_int8_new_3(r,c,g)      _int8_new(r, c, g,  NULL, NULL)
#define tns_int8_new_4(r,c,g,v)    _int8_new(r, c, g,  v, NULL)
#define tns_int8_new_5(r,c,g,v,s)  _int8_new(r, c, g,  v, s)

// Free Tensor
#define tns_free(t) (free(t), t = NULL)

