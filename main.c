#include <stdio.h>
#include <string.h>
#include "tree.h"

// ----------------------------------------------------------------------------
//
Node *createNode(const char *pStr)
{
  // TODO
  return 0;
}

bool addString(Node *pRoot, const char *pStr, Node **ppNode /* = 0 */)
{
  // TODO
  return false;
}

void traverseDF(const Node *pRoot, void(callBack)(const Node *))
{
  // TODO
}
// ----------------------------------------------------------------------------

// TODO: Define function printNode(...) with proper signature, so as to be
// callable by traverseDF()!

/* -------------------------------------
TESTING
=======
1. From the command line:
cat text2.txt | ./a.out
   _OR_
./a.out <<EOF
blahh
dah
blahh
EOF

2. From the debugger or command line, if not feeding a file, just type
   words and then ctrl-D for EOF to signal the end.
-------------------------------------  */

int main(int argc, const char *argv[])
{
  char buf[4096];
  while (fgets(buf, sizeof buf, stdin))
  {
    // If the line was NOT truncated - remove the trailing newline
    if (buf[strlen(buf) - 1] == '\n')
      buf[strlen(buf) - 1] = 0;

    printf(">>> %s\n", buf); // For testing/debugging

    // TODO: Insert strings into tree
  }

  // TODO: Print the sorted lines, with counts:
  // traverseDF(pRoot, printNode);

  return 0;
}
