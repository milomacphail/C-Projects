# Questions

## What's `stdint.h`?

Stdint.h is a header file from the C Standard Library, meaning it is available in all C code.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To ensure that memory allocation is optimized for the numbers returned in this function and set boundaries on the input and output numbers.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

8, 32, 32 and 16 bytes respectively.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM

## What's the difference between `bfSize` and `biSize`?

bfSize is the size, in bytes, of the bmp file. biSize is the number of bytes required by the structure itself, in a bitmap file. bfSize is about the file CONTAINING a DIB. biSize is about the size of the DIB itself, not including the file packaging.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the image's origin is in the lower-left corner. These DIBs are referred to as top-down DIBs. Top-down DIBs cannot be compressed and their biCompression must be either BI_RGB or BI_BITFIELDS.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitcount.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

`fopen` will return `NULL` if either the input file or output file cannot be opened for reading or writing respectively.

## Why is the third argument to `fread` always `1` in our code?

Because we are reading and writing 1 pixel at a time.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

1.

## What does `fseek` do?

Generally, `fseek` sets the file position of a stream to a given offset value. In this situation, `fseek` checks for any padding in the bmp file and skips over it, so as not to distort the image.

## What is `SEEK_CUR`?

`SEEK_CUR` is an `fseek` function constant which moves the file pointer position to a custom given location within a file.

## Whodunit?

TODO
