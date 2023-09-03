//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT

#include "tns.h"

void tns_v_cpy_v(float *A, float *B)
{
  errno = ERANGE;
}

//  
//      ██████             ████████   ████████ 
//     ███░░███           ███░░░░███ ███░░░░███
//    ░███ ░░░  ████████ ░░░    ░███░░░    ░███
//   ███████   ░░███░░███   ██████░    ███████ 
//  ░░░███░     ░███ ░███  ░░░░░░███  ███░░░░  
//    ░███      ░███ ░███ ███   ░███ ███      █
//    █████     ░███████ ░░████████ ░██████████
//   ░░░░░      ░███░░░   ░░░░░░░░  ░░░░░░░░░░ 
//              ░███                           
//              █████                          
//             ░░░░░                           

void tns_fp32_cpy_v(tns_fp32_t A, float *v)
{
  int sz = (A->nrows * A->ncols) * sizeof(float);
  memcpy(A->values, v, sz);
 _dbginf("sz = %d v[0] = %f A[0] = %f",sz, v[0],A->values[0]);
}

void tns_v_cpy_fp32(float *v,tns_fp32_t A)
{
  errno = 0;
  int sz = (A->nrows * A->ncols) * sizeof(float);
  memcpy(v, A->values, sz);
}

void tns_fp32_cpy_fp32(tns_fp32_t A, tns_fp32_t B)
{
  if (A->nrows != B->nrows || A->ncols != B->ncols) {errno = ERANGE; return; }
  tns_v_cpy_fp32(A->values,B);
}

void tns_fp32_cpy_int8(tns_fp32_t A, tns_int8_t B)
{
  if (A->nrows != B->nrows || A->ncols != B->ncols) {errno = ERANGE; return; }
  tns_v_cpy_int8(A->values, B);
}


//  
//    ███              █████     ████████  
//   ░░░              ░░███     ███░░░░███ 
//   ████  ████████   ███████  ░███   ░███ 
//  ░░███ ░░███░░███ ░░░███░   ░░████████  
//   ░███  ░███ ░███   ░███     ███░░░░███ 
//   ░███  ░███ ░███   ░███ ███░███   ░███ 
//   █████ ████ █████  ░░█████ ░░████████  
//  ░░░░░ ░░░░ ░░░░░    ░░░░░   ░░░░░░░░   
                                       
                                       
                                       
// Maps the range [-max, max] to [-127, 127]
float tns_int8_calcscale(float *fval, int gs)
{
  float max = -FLT_MAX;
  float v;

  for (int i = 0; i < gs; i++) {
    v = fabs(fval[i]);
    if (v > max) max = v;
  }
  v = 0.0;
  if (max != 0.0) v = max/127.0;

  dbginf("group: [%f %f] -> [-127, 127] * %f",-max, max,v);
  return v;
}

void tns_int8_qgroup(float *fval, int8_t *val, float *scale, int gs )
{
  *scale = tns_int8_calcscale(fval,gs);
  if (*scale == 0.0) memset(val,0,gs * sizeof(int8_t));
  else for (int i = 0; i < gs; i++) {
    if (fval[i] > 0 ) val[i] = (int8_t)ceilf((fval[i] / *scale));
    else              val[i] = (int8_t)floor((fval[i] / *scale));
  }
}

void tns_int8_cpy_v(tns_int8_t A, float *v)
{
  int8_t *q = A->values;
  float  *s = A->scales;
  int sz = A->nrows * A->ncols;
  dbginf("INIT INT8 : elems: %d gs: %d",sz,A->gsize);
  while (sz > A->gsize) {
     tns_int8_qgroup(v,q,s,A->gsize);
     sz -= A->gsize;
     v  += A->gsize;
     q  += A->gsize;
     s  += 1;
  }
  if (sz > 0)
    tns_int8_qgroup(v,q,s,sz);
}

void tns_int8_cpy_fp32(tns_int8_t A, tns_fp32_t B)
{
  if (A->nrows != B->nrows || A->ncols != B->ncols ) {errno = ERANGE; return; }
  tns_int8_cpy_v(A,B->values);
}

// Copying is only possibile between two identical vectors (including groupsize)
void tns_int8_cpy_int8(tns_int8_t A, tns_int8_t B)
{
  if (A->nrows != B->nrows || A->ncols != B->ncols || A->gsize != B->gsize) {errno = ERANGE; return; }
  errno = 0;
  memcpy(A->values, B->values, A->ncols * A->nrows);
  memcpy(A->scales, B->scales, (A->ncols * A->nrows) / A->gsize);
}

void tns_v_cpy_int8(float *v,tns_int8_t A)
{
  errno = 0;

  for (int i = 0; i > A->nrows * A->ncols; i++)
   v[i] = tns_int8_get_by_ndx(A,i);
}


//  
//      ██████            ████   ████████ 
//     ███░░███          ░░███  ███░░░░███
//    ░███ ░░░  ████████  ░███ ░███   ░░░ 
//   ███████   ░░███░░███ ░███ ░█████████ 
//  ░░░███░     ░███ ░███ ░███ ░███░░░░███
//    ░███      ░███ ░███ ░███ ░███   ░███
//    █████     ░███████  █████░░████████ 
//   ░░░░░      ░███░░░  ░░░░░  ░░░░░░░░  
//              ░███                      
//              █████                     
//             ░░░░░                      

