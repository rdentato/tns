# tns

tns is a small and lightweight C library designed to implement tensors for neural networks.
It only supports 1 and 2 dimensional tensors, but includes support for quantized representation (float32 and int8).

## Features

- Support for 1D and 2D tensors.
- Quantized representation (float32, int8) support.
- Clean polymorphic API

## Installation

Clone the repository to your local machine.

```
git clone https://github.com/yourusername/tns.git
```

Navigate to the project directory and compile the source code.

```
cd tns
make
```
you will get two files: `tns.c` and `tns.h` to include in your project.

Include the `tns.h` header file in your C program.

```c
#include "tns.h"
```

Compile `tns.c`

```bash
gcc -O3 -fopenmp -c tns.c
```
If your architecture does not support OpenMP, just remove the flag.

Link `tns.o` with your other objects to create the executable.

To run all the tests, go in the `test` directory and type:
```bash
make runtest
```
Only tests that failed are shown, if no test fails, nothing is printed.

## Creating a Tensor
Currently only floating point fp32 and quantized int8 tensors are supported.

```c
// Create a 2D float32 tensor
tns_fp32_t t1 = NULL;
tns_new(t1, 2, 5); // 2 rows, 5 columns

// Create a 1D column tensor
tns_fp32_t t2 = NULL;
tns_new(t2, 16); // 16 rows, 1 column

// Create a 1D column quantized tensor
tns_in8_t t3 = NULL;
tns_new(t3, 16, 1, 4); // 16 rows, 1 column, group size = 4

```

To free a tensor, use `tns_free()`.

```c
tns_free(t1); // will set t1 to NULL
tns_free(t2); // will set t1 to NULL
tns_free(t3); // will set t1 to NULL
```
To get the tension dimensions:
```c
tns_nrows(t1); // returns the number of rows
tns_ncols(t1); // returns the number of columns
```

## Setting and Getting Tensor Values

You can initialize a tensor by copying values into it:

```c

tns_fp32_t ft  = NULL;
tns_new(ft,4);

float v = {0.1, 1.2, 3.4, 5.6};
tns_cpy(ft,v);

```

You can also use `tns_cpy()` to copy values between tensors:
```c
tns_int8_t qt  = NULL; // A quantized tensor
tns_new(qt,4,1,2); // group size of 2

tns_cpy(qt,ft); // copy and quantize 

```

To set or get a value (that will always be a float) you can use `tns_set()` and `tns_get()`.

```c
float x;
x = tns_get(qt,2); // will de-quantize and return the third element in the vector `qt`

tns_set(ft,x,2); // put it in the `ft` tensor
```

## Contributing
Please note that this is just an initial version, many things need to be properly implemented and tested.

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
