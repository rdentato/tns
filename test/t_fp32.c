#include "tns.h"


void test_fp32(void)
{
  // Test Case 1
  tns_fp32_t A1 = NULL; tns_new(A1, 1, 1);
  tns_fp32_t x1 = NULL; tns_new(x1, 1);
  tns_fp32_t r1 = NULL; tns_new(r1, 1);

  dbgmst(A1 != NULL);
  dbgmst(x1 != NULL);
  dbgmst(r1 != NULL);
 
  float   values1[] = {1.0};  tns_cpy(A1, values1);
  dbgchk(A1->values[0] == 1.0,"A[0] is %f",A1->values[0]);
  float x_values1[] = {2.0};  tns_cpy(x1, x_values1);
  dbgchk(x1->values[0] == 2.0,"x[0] is %f",x1->values[0]);
  tns_matmul_fp32_fp32(r1, A1, x1);
  dbgchk(!errno && r1->values[0] == 2.0, "Test Case 1 failed: expected 2.0, got %.2f (errno: %d)", r1->values[0],errno);
  tns_free(A1);
  tns_free(x1);
  tns_free(r1);

  // Test Case 2
  tns_fp32_t A2 = NULL;
  tns_new(A2, 2, 2);
  float values2[] = {1.0, 2.0, 3.0, 4.0};
  tns_cpy(A2, values2);
  tns_fp32_t x2 = NULL;
  tns_new(x2, 2);
  float x_values2[] = {5.0, 6.0};
  tns_cpy(x2, x_values2);
  tns_fp32_t r2 = NULL;
  tns_new(r2, 2);
  tns_matmul_fp32_fp32(r2, A2, x2);
  dbgchk(r2->values[0] == 17.0, "Test Case 2 failed: expected 17.0, got %.2f", r2->values[0]);
  dbgchk(r2->values[1] == 39.0, "Test Case 2 failed: expected 39.0, got %.2f", r2->values[1]);
  tns_free(A2);
  tns_free(x2);
  tns_free(r2);

    // Test Case 3
  tns_fp32_t A3 = NULL;
  tns_new(A3, 2, 3);
  float values3[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  tns_cpy(A3, values3);
  tns_fp32_t x3 = NULL;
  tns_new(x3, 3);
  float x_values3[] = {7.0, 8.0, 9.0};
  tns_cpy(x3, x_values3);
  tns_fp32_t r3 = NULL;
  tns_new(r3, 2);
  tns_matmul_fp32_fp32(r3, A3, x3);
  dbgchk(r3->values[0] == 50.0, "Test Case 3 failed: expected 50.0, got %.2f", r3->values[0]);
  dbgchk(r3->values[1] == 122.0, "Test Case 3 failed: expected 122.0, got %.2f", r3->values[1]);
  tns_free(A3);
  tns_free(x3);
  tns_free(r3);

  // Test Case 4
  tns_fp32_t A4 = NULL;
  tns_new(A4, 3, 2);
  float values4[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  tns_cpy(A4, values4);
  tns_fp32_t x4 = NULL;
  tns_new(x4, 2);
  float x_values4[] = {7.0, 8.0};
  tns_cpy(x4, x_values4);
  tns_fp32_t r4 = NULL;
  tns_new(r4, 3);
  tns_matmul_fp32_fp32(r4, A4, x4);
  dbgchk(r4->values[0] == 23.0, "Test Case 4 failed: expected 23.0, got %.2f", r4->values[0]);
  dbgchk(r4->values[1] == 53.0, "Test Case 4 failed: expected 53.0, got %.2f", r4->values[1]);
  dbgchk(r4->values[2] == 83.0, "Test Case 4 failed: expected 83.0, got %.2f", r4->values[2]);
  tns_free(A4);
  tns_free(x4);
  tns_free(r4);

  // Test Case 5
  tns_fp32_t A5 = NULL;
  tns_new(A5, 3, 3);
  float values5[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  tns_cpy(A5, values5);
  tns_fp32_t x5 = NULL;
  tns_new(x5, 3);
  float x_values5[] = {10.0, 11.0, 12.0};
  tns_cpy(x5, x_values5);
  tns_fp32_t r5 = NULL;
  tns_new(r5, 3);
  tns_matmul_fp32_fp32(r5, A5, x5);
  dbgchk(r5->values[0] == 68.0, "Test Case 5 failed: expected 68.0, got %.2f", r5->values[0]);
  dbgchk(r5->values[1] == 167.0, "Test Case 5 failed: expected 167.0, got %.2f", r5->values[1]);
  dbgchk(r5->values[2] == 266.0, "Test Case 5 failed: expected 266.0, got %.2f", r5->values[2]);
  tns_free(A5);
  tns_free(x5);
  tns_free(r5);

  // Test Case 6
  tns_fp32_t A6 = NULL;
  tns_new(A6, 4, 4);
  float values6[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
  tns_cpy(A6, values6);
  tns_fp32_t x6 = NULL;
  tns_new(x6, 4);
  float x_values6[] = {17.0, 18.0, 19.0, 20.0};
  tns_cpy(x6, x_values6);
  tns_fp32_t r6 = NULL;
  tns_new(r6, 4);
  tns_matmul_fp32_fp32(r6, A6, x6);
  dbgchk(r6->values[0] == 190.0, "Test Case 6 failed: expected 190.0, got %.2f", r6->values[0]);
  dbgchk(r6->values[1] == 486.0, "Test Case 6 failed: expected 486.0, got %.2f", r6->values[1]);
  dbgchk(r6->values[2] == 782.0, "Test Case 6 failed: expected 782.0, got %.2f", r6->values[2]);
  dbgchk(r6->values[3] == 1078.0, "Test Case 6 failed: expected 1078.0, got %.2f", r6->values[3]);
  tns_free(A6);
  tns_free(x6);
  tns_free(r6);

  // Test Case 7
  tns_fp32_t A7 = NULL;
  tns_new(A7, 1, 3);
  float values7[] = {1.0, 2.0, 3.0};
  tns_cpy(A7, values7);
  tns_fp32_t x7 = NULL;
  tns_new(x7, 3);
  float x_values7[] = {4.0, 5.0, 6.0};
  tns_cpy(x7, x_values7);
  tns_fp32_t r7 = NULL;
  tns_new(r7, 1);
  tns_matmul_fp32_fp32(r7, A7, x7);
  dbgchk(r7->values[0] == 32.0, "Test Case 7 failed: expected 32.0, got %.2f", r7->values[0]);
  tns_free(A7);
  tns_free(x7);
  tns_free(r7);

   // Test Case 8
  tns_fp32_t A8 = NULL; tns_new(A8, 3, 1);
  tns_fp32_t x8 = NULL; tns_new(x8, 1);
  tns_fp32_t r8 = NULL; tns_new(r8, 1);

  float values8[] = {1.0, 2.0, 3.0};   tns_cpy(A8, values8);
  float x_values8[] = {4.0};           tns_cpy(x8, x_values8); 

  tns_matmul_fp32_fp32(r8, A8, x8);

  dbgchk(errno == ERANGE, "Test Case 8 failed: expected error code ERANGE, got %d", errno);

  tns_free(A8);
  tns_free(x8);
  tns_free(r8);

  // Test Case 9
  tns_fp32_t A9 = NULL;
  tns_new(A9, 2, 2);
  float values9[] = {1.0, 2.0, 3.0, 4.0};
  tns_cpy(A9, values9);
  tns_fp32_t x9 = NULL;
  tns_new(x9, 3);
  float x_values9[] = {5.0, 6.0, 7.0};
  tns_cpy(x9, x_values9);
  tns_fp32_t r9 = NULL;
  tns_new(r9, 2);
  tns_matmul_fp32_fp32(r9, A9, x9);
  dbgchk(errno == ERANGE, "Test Case 9 failed: expected error code ERANGE, got %d", errno);
  tns_free(A9);
  tns_free(x9);
  tns_free(r9);

  // Test Case 10
  tns_fp32_t A10 = NULL;
  tns_new(A10, 3, 3);
  float values10[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  tns_cpy(A10, values10);
  tns_fp32_t x10 = NULL;
  tns_new(x10, 3);
  float x_values10[] = {0.0, 0.0, 0.0};
  tns_cpy(x10, x_values10);
  tns_fp32_t r10 = NULL;
  tns_new(r10, 3);
  tns_matmul_fp32_fp32(r10, A10, x10);
  dbgchk(r10->values[0] == 0.0, "Test Case 10 failed: expected 0.0, got %.2f", r10->values[0]);
  dbgchk(r10->values[1] == 0.0, "Test Case 10 failed: expected 0.0, got %.2f", r10->values[1]);
  dbgchk(r10->values[2] == 0.0, "Test Case 10 failed: expected 0.0, got %.2f", r10->values[2]);
  tns_free(A10);
  tns_free(x10);
  tns_free(r10);
}

int main(int argc, char *argv[])
{
  float n;
  tns_fp32_t fp32_tensor = NULL;
  tns_int8_t int8_tensor = NULL;

  tns_new(fp32_tensor, 10, 20, NULL);
  dbgchk(fp32_tensor && tns_type(fp32_tensor)==TNS_TYPE_FP32);

  n = tns_get(fp32_tensor,3,4);
  dbgchk(n==0);

  tns_set(fp32_tensor,4.25,1,7);
  n = tns_get(fp32_tensor,1,7);
  dbgchk(n==4.25);
  
  n = tns_get(fp32_tensor,32,12);
  dbgchk(isnan(n));

  tns_free(fp32_tensor);
  dbgchk(fp32_tensor == NULL);

  tns_new(fp32_tensor, 10, 20);
  tns_free(fp32_tensor);

  tns_new(fp32_tensor, 10);
  tns_free(fp32_tensor);

  tns_new(int8_tensor, 11, 21, 32);
  tns_free(int8_tensor);

  test_fp32();
}

