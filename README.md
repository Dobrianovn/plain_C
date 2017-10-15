# This branch
Simply illustrates how pointers and arrays are treated in `C`: memory layout, etc.

The short of it is that pointers and array indentifiers can be treated in a very similar way, so long as one follows "the standard rules" and types and their sizes are respected. Both array and pointer arithmetic work as expected.

# Program output
On a 64-bit Linux gcc build, where the pointer size is 8, this is the output:
```
strings1 = aa
sizeof strings1 = 3
Memory at strings1:
61 61 0

pStrings1 = aaAA
sizeof pStrings1 = 8
Memory at pStrings1:
61 61 41 41 0 6f 0 6f

strings2 =
[0] aaaaaaaa
[1] b
[2] cccXc
Memory at strings2:
61 61 61 61 61 61 61 61 0 0 62 0 0 0 0 0 0 0 0 0 63 63 63 58 63 0 0 0 0 0
sizeof strings2 = 30
sizeof *strings2 = 10
sizeof strings2[0] = 10
Pointer arithmetic: *(*(strings2 + 2) + 3) = 'X' = 58

pStrings2 =
[0] o
[1] oo
[2] oooYo
Memory at pStrings2:
4d a 40 0 0 0 0 0 4f a 40 0 0 0 0 0 52 a 40 0 0 0 0 0
sizeof pStrings2 = 24
sizeof *pStrings2 = 8
sizeof pStrings2[0] = 8
Pointer arithmetic: *(*(pStrings2 + 2) + 3) = 'Y' = 59

```
Enjoy interpreting the numbers!
