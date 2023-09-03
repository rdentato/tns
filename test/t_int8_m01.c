#include "tns.h"

void test_tns_matmul_int8_int8() 
{
    // Test 1: Regular case, all dimensions compatible
    {
        tns_fp32_t r = NULL;
        tns_int8_t A = NULL, x = NULL;

        tns_new(r, 3, 1);
        tns_new(A, 3, 3,2);
        tns_new(x, 3, 1,2);
        
        float A_values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        float x_values[] = {1, 1, 1};
        
        tns_cpy(A, A_values);

        for (int i=0; i<3; i++)
          for (int j=0; j<3; j++) {
            dbgchk(fabs(tns_get(A,i,j) - A_values[i *3+j]) < 6E-2,
                   "Expected: %f got: %f (%d * %f) err: %f", A_values[i *3+j], tns_get(A,i,j), tns_int8_get_quant(A,i,j), tns_int8_get_scale(A,i,j), fabs(tns_get(A,i,j) - A_values[i *3+j]));
          }

        tns_cpy(x, x_values);
        
        for (int i=0; i<3; i++) {
            dbgchk(fabs(tns_get(x,i,0) - x_values[i]) < 6E-2,
                   "Expected: %f got: %f (%d * %f) err: %f", x_values[i], tns_get(x,i,0), tns_int8_get_quant(x,i,0), tns_int8_get_scale(x,i,0), fabs(tns_get(x,i,0) - x_values[i]));
          }

        tns_matmul_int8_int8(r, A, x);
        
        dbgchk(errno == 0, "Error: errno should be 0 but got %d\n", errno);
        
        float expected[] = {6, 15, 24};
        for (int i = 0; i < 3; i++) {
            dbgchk(fabs(tns_get(x,i,0) - x_values[i]) < 6E-2,
                   "Expected: %f got: %f err: %f", expected[i], tns_get(r,i), fabs(tns_get(r,i) - expected[i]));
        }

        tns_free(r);
        tns_free(A);
        tns_free(x);
    }
    
}
int main() {
    test_tns_matmul_int8_int8();
    return 0;
}
