# tns

tns is a small and lightweight C library designed to implement tensors for neural networks.
It only supports 1 and 2 dimensional tensors, but includes support for quantized representation (float32, float16, and int8).

## Features

- Support for 1D and 2D tensors.
- Quantized representation (float32, float16, int8) support.

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

## Usage

Include the `tns.h` header file in your C program.

```c
#include "tns.h"
```

### Creating a Tensor

```c
// Create a 1D tensor
tns* t1 = tensor_create(1, 5);

// Create a 2D tensor
Tensor* t2 = tensor_create(2, 3, 4);
```

### Setting and Getting Tensor Values

```c
// Set values for 1D tensor
tensor_set(t1, 2, 3.0);

// Set values for 2D tensor
tensor_set(t2, 1, 2, 4.0);

// Get values for 1D tensor
float value1 = tensor_get(t1, 2);

// Get values for 2D tensor
float value2 = tensor_get(t2, 1, 2);
```

### Quantization and Dequantization

```c
// Quantize a tensor to float16
Tensor* t1_quantized = tensor_quantize(t1, FLOAT16);

// Dequantize a tensor to float32
Tensor* t1_dequantized = tensor_dequantize(t1_quantized, FLOAT32);
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
