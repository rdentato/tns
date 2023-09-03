//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT


# include "tns.h"

tns_fp32_t tns_fp32_new(int nrows, int ncols, float *values)
{
 _dbginf("fp32_new r: %d c: %d (from: %p)",nrows, ncols, (void *)values);
  tns_fp32_t tns = NULL;
  int32_t num_elements;
  num_elements = nrows * ncols;

  if (nrows <= 0 || ncols <= 0) return NULL;

  if (values != NULL) {
    tns = calloc(1, sizeof(struct tns_fp32_s));
  }
  else {
    tns = calloc(1, sizeof(struct tns_fp32_s) + num_elements * sizeof(float));
    if (tns) values = (float *)(((int8_t *)tns) + sizeof(struct tns_fp32_s));
  }
  if (tns)  {
    tns->type = TNS_TYPE_FP32;
    tns->ncols = ncols;
    tns->nrows = nrows;
    tns->values = values;
  }

  return tns;
}

tns_int8_t tns_int8_new(int nrows, int ncols, int gsize, int8_t *values, float  *scales)
{
 _dbginf("int8_new  r: %d c: %d gsize: %d (from: %p,%p)",nrows, ncols, gsize, (void *)values, (void *)scales);
  tns_int8_t tns = NULL;
  int32_t num_elements;

  if (nrows <= 0 || ncols <= 0 || gsize < 2) return NULL;

  num_elements = nrows * ncols;
  if (values != NULL) {
    tns = calloc(1, sizeof(struct tns_int8_s));
    if (!scales) scales = (float *) (values + num_elements * sizeof(int8_t));
  }
  else {
    tns = calloc(1, sizeof(struct tns_int8_s) +
                    (num_elements) * ( sizeof(int8_t)) +
                   ((num_elements) * sizeof(float)) / gsize +
                    sizeof(float) ); // this is for cases when the last group has less than gs elements.
    if (tns) {
      values = (int8_t *)tns + sizeof(struct tns_int8_s);
      scales = (float *)(values + (num_elements * sizeof(int8_t)));
    }
  }
  if (tns)  {
    tns->type = TNS_TYPE_INT8;
    tns->ncols = ncols;
    tns->nrows = nrows;
    tns->values = values;
    tns->scales = scales;
    tns->gsize = gsize;
  }

  return tns;
}
