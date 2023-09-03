//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT

#include "tns.h"

float tns_fp32_get(tns_fp32_t tns,int row, int col)
{
 _dbginf("Getting from fp32 [%d,%d]",row,col);
  if (row < 0 || col < 0) { errno = ERANGE; return NAN; }
  if (row >= tns->nrows || col >= tns->ncols) { errno = ERANGE; return NAN; }
  return tns->values[row * tns->ncols + col];
}

void tns_fp32_set(tns_fp32_t tns, float x, int row, int col)
{
 _dbginf("Setting in fp32 [%d,%d] = %f",row,col,x);
  if (row < 0 || col < 0) { errno = ERANGE; return ; }
  if (row >= tns->nrows || col >= tns->ncols) { errno = ERANGE; return ; }
  tns->values[row * tns->ncols + col] = x;
}

float tns_fp32_get_by_ndx(tns_fp32_t tns,int ndx)
{ errno = 0;
  if (ndx >= tns->ncols * tns->nrows) {errno = ERANGE; return 0.0; }
  return tns->values[ndx];
}

float tns_int8_get_by_ndx(tns_int8_t tns,int ndx)
{errno = 0;
  if (ndx >= tns->ncols * tns->nrows) {errno = ERANGE; return 0.0; }
  return tns->values[ndx] * tns->scales[ndx / tns->gsize];
}

int8_t tns_int8_get_quant(tns_int8_t tns, int row, int col)
{
   return tns->values[row * tns->ncols +col];
}

float tns_int8_get_scale(tns_int8_t tns, int row, int col)
{
   return tns->scales[(row * tns->ncols +col)/tns->gsize];
}

float tns_int8_get(tns_int8_t tns,int row, int col)
{
 _dbginf("Getting from int8 [%d,%d]",row,col);
  if (row < 0 || col < 0) { errno = ERANGE; return NAN; }
  if (row >= tns->nrows || col >= tns->ncols) { errno = ERANGE; return NAN; }
  int ndx = row * tns->ncols + col;
  return tns->values[ndx] * tns->scales[ndx / tns->gsize];
}

// this might require re-quantize the entire group if the value x
// is outside the current group range.
void tns_int8_set(tns_int8_t tns, float x, int row, int col)
{

}
