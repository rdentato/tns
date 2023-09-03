#include "tns.h"

void test_tns_new_and_free_fp32() {
    // Test Case 1
    tns_fp32_t fp32_tensor1 = NULL;
    tns_new(fp32_tensor1, 5, 6);
    dbgchk(fp32_tensor1 != NULL,"Error creating the tensor");
    dbgchk(fp32_tensor1->nrows == 5 && fp32_tensor1->ncols ==6,"Wrong dimensions! Got: %d x %d",fp32_tensor1->nrows, fp32_tensor1->ncols);
    tns_free(fp32_tensor1);
    dbgchk(fp32_tensor1 == NULL, "Error freeing up the tensor");
    
    // Test Case 2
    tns_fp32_t fp32_tensor2 = NULL;
    tns_new(fp32_tensor2, 0, 4);
    dbgchk(fp32_tensor2 == NULL,"Creating tensor with zero rows should return NULL");
    tns_free(fp32_tensor2);
    
    // Test Case 3
    tns_fp32_t fp32_tensor3 = NULL;
    tns_new(fp32_tensor3, 3, 0);
    dbgchk(fp32_tensor3 == NULL,"Creating tensor with zero columns should return NULL");
    tns_free(fp32_tensor3);
    
    // Test Case 4
    tns_fp32_t fp32_tensor4 = NULL;
    tns_new(fp32_tensor4, -3, 4);
    dbgchk(fp32_tensor4 == NULL,"Creating tensor with negative rows should return NULL");
    tns_free(fp32_tensor4);
    
    // Test Case 5
    tns_fp32_t fp32_tensor5 = NULL;
    tns_new(fp32_tensor5, 3, -4);
    dbgchk(fp32_tensor5 == NULL,"Creating tensor with negative columns should return NULL");
    tns_free(fp32_tensor5);
}

void test_tns_new_and_free_int8() {
    // Test Case 1
    tns_int8_t int8_tensor1 = NULL;
    tns_new(int8_tensor1, 5, 6);
    dbgchk(int8_tensor1 != NULL,"Error creating the tensor");
    dbgchk(int8_tensor1->nrows == 5 && int8_tensor1->ncols ==6,"Wrong dimensions! Got: %d x %d",int8_tensor1->nrows, int8_tensor1->ncols);
    tns_free(int8_tensor1);
    dbgchk(int8_tensor1 == NULL, "Error freeing up the tensor");
    
    // Test Case 2
    tns_int8_t int8_tensor2 = NULL;
    tns_new(int8_tensor2, 0, 4);
    dbgchk(int8_tensor2 == NULL,"Creating tensor with zero rows should return NULL");
    tns_free(int8_tensor2);
    
    // Test Case 3
    tns_int8_t int8_tensor3 = NULL;
    tns_new(int8_tensor3, 3, 0);
    dbgchk(int8_tensor3 == NULL,"Creating tensor with zero columns should return NULL");
    tns_free(int8_tensor3);
    
    // Test Case 4
    tns_int8_t int8_tensor4 = NULL;
    tns_new(int8_tensor4, -3, 4);
    dbgchk(int8_tensor4 == NULL,"Creating tensor with negative rows should return NULL");
    tns_free(int8_tensor4);
    
    // Test Case 5
    tns_int8_t int8_tensor5 = NULL;
    tns_new(int8_tensor5, 3, -4);
    dbgchk(int8_tensor5 == NULL,"Creating tensor with negative columns should return NULL");
    tns_free(int8_tensor5);
}


int main(int argc, char *argv[])
{
 test_tns_new_and_free_fp32();
 test_tns_new_and_free_int8();
 
}