//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT

enum TNS_type {
    TNS_TYPE_FP32 = 1,
    TNS_TYPE_FP16,
    TNS_TYPE_INT8,
    TNS_TYPE_COUNT,
};

// -----------------------------------
// Generic tensor (just to get the number of rows and columns)
typedef struct tns_s  {
  uint16_t type;
  uint16_t aux;
  int    nrows;
  int    ncols;
} *tns_t;

typedef struct tns_fp32_s  {
  uint16_t type;
  uint16_t aux;
  int    nrows;
  int    ncols;
  float *values;
} *tns_fp32_t;

typedef struct tns_fp16_s  {
  uint16_t type;
  uint16_t aux;
  int      nrows;
  int      ncols;
  uint32_t *values;
} *tns_fp16_t;

typedef struct tns_int8_s  {
  uint16_t type;
  uint16_t gsize;
  int      nrows;
  int      ncols;
  int8_t  *values;
  float   *scales;
} *tns_int8_t;

