// gcc -g -std=c99 main.c
#include <stdio.h>
#include <string.h>

#define prnsz(xx) printf("sizeof " #xx " = %ld\n", sizeof(xx))

#define memAt(xx)                               \
  printf("Memory at " #xx ":\n");               \
  for (ii = 0; ii < sizeof xx; ++ii)            \
  {                                             \
    printf("%x ", *((unsigned char *)xx + ii)); \
  }                                             \
  printf("\n")

#define prnArr(xx)                                \
  printf(#xx " =\n");             \
  for (ii = 0; ii < sizeof xx / sizeof *xx; ++ii) \
  {                                               \
    printf("[%d] %s\n", ii, xx[ii]);               \
  }

#define ptrArith(xx, ii, jj) \
  printf("Pointer arithmetic: *(*(" #xx " + " #ii ") + " #jj ") = '%c' = %x\n", \
  *(*(xx + ii) + jj), *(*(xx + ii) + jj));

int main(int argc, const char *argv[])
{
  int ii;

  const char strings1[] = "aa";
  const char *pStrings1 = "aaAA";
  const char strings2[3][10] = {"aaaaaaaa", "b", "cccXc"};
  const char *pStrings2[3] = {"o", "oo", "oooYo"};

  printf("strings1 = %s\n", strings1);
  prnsz(strings1);
  memAt(strings1);

  printf("\n");
  printf("pStrings1 = %s\n", pStrings1);
  prnsz(pStrings1);
  memAt(pStrings1);

  printf("\n");
  prnArr(strings2);
  memAt(strings2);
  prnsz(strings2);
  prnsz(*strings2);
  prnsz(strings2[0]);
  ptrArith(strings2, 2, 3);

  printf("\n");
  prnArr(pStrings2);
  memAt(pStrings2);
  prnsz(pStrings2);
  prnsz(*pStrings2);
  prnsz(pStrings2[0]);
  ptrArith(pStrings2, 2, 3);

  return 0;
}
