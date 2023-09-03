//  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
//  SPDX-License-Identifier: MIT


#include "tns.h"

// Multply a Matrix and a vector:  r = A x
void tns_matmul_fp32_fp32(tns_fp32_t r, tns_fp32_t A, tns_fp32_t x)
{
  // Check if the matrices can be multiplied
  _dbginf("r(%d) = A(%dx%d) * x(%d)",r->nrows,A->nrows,A->ncols,x->nrows);
  if (A->ncols != x->nrows || x->ncols != 1 || r->nrows != A->nrows || r->ncols != 1) { 
    errno = ERANGE;
    return; 
  }
  errno = 0;
  for (int i = 0; i < A->nrows; i++) {
    r->values[i] = 0.0;
    for (int j = 0; j < A->ncols; j++) {
      r->values[i] += tns_get(A,i,j) * tns_get(x,j);
    }
  }
}

// Multply a Matrix and a vector:  r = A x
void tns_matmul_int8_int8(tns_fp32_t r, tns_int8_t A, tns_int8_t x)
{
  // Check if the matrices can be multiplied
  if (A->ncols != x->nrows || x->ncols != 1 || r->nrows != A->nrows || r->ncols != 1 || A->gsize != x->gsize) { 
    errno = ERANGE;
    return; 
  }
  errno = 0;

  for (int i = 0; i < A->nrows; i++) {
    r->values[i] = 0.0;
    for (int j = 0; j < A->ncols; j++) {
      r->values[i] += tns_get(A,i,j) * tns_get(x,j);
    }
  }
}

