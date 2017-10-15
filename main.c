#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

/*
createNode is a method that returns a node pointer and returns a pointer with count 1 and
input string as it's value and two null nodes left and right of it.
*/
Node *createNode(const char *pStrIn)
{
  Node *pTemp = (Node*)malloc(sizeof(Node));
  pTemp->count = 1;
  pTemp->pStr = (char*)malloc(sizeof(char)*(strlen(pStrIn) + 1));
  strcpy(pTemp->pStr, pStrIn);
  pTemp->pLeft = NULL;
  pTemp->pRight = NULL;
  return pTemp;
}

/*
addString adds an input string to the search tree. The strings are in a BST with a lexographical
value comparison, with words lexographically first to the left and no duplicates but increasing
the count on repeat entry (returns false on fail).
*/
bool addString(Node *pRoot, const char *pStrIn)
{
  Node *pTemp = pRoot;
  Node *previous;
  while(pTemp != NULL){
    if(strncmp(pStrIn, pTemp->pStr, 4096) < 0){
      previous = pTemp;
      pTemp = pTemp->pLeft;
    } else if(strncmp(pStrIn, pTemp->pStr, 4096) > 0){
      previous = pTemp;
      pTemp = pTemp->pRight;
    } else {
      pTemp->count += 1;
      return false;
    }
  }
  if(strncmp(pStrIn, previous->pStr, 4096) < 0){
    pTemp = createNode(pStrIn);
    previous->pLeft = pTemp;
  } else {
    pTemp = createNode(pStrIn);
    previous->pRight = pTemp;
  }
  return true;
}

//printNode is a method to print the string at a given node pointer
void printNode(Node *pNode){
  printf("%s : %d\n", pNode->pStr, pNode->count);
}

/*
traverseInOrder prints to the console in depth first in order format the string values
at each node.
*/
void traverseInOrder(Node *pNode, void (callBack)(Node*)){
  if(pNode == NULL){
    return;
  } 
  traverseInOrder(pNode->pLeft, callBack);
  callBack(pNode);
  traverseInOrder(pNode->pRight, callBack);
}
/*-------------------------------------- 
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
  Node *searchTree = NULL;
  while (fgets(buf, sizeof buf, stdin))
  {
    // If the line was NOT truncated - remove the trailing newline
    if (buf[strlen(buf) - 1] == '\n')
      buf[strlen(buf) - 1] = 0;
    // printf(">>> %s\n", buf); // For testing/debugging
    if(!searchTree){
      searchTree = createNode(buf);
      continue;
    }
    addString(searchTree, buf);
  }
  traverseInOrder(searchTree, printNode);
  // TODO: Print the sorted lines, with counts:
  // traverseDF(pRoot, printNode);
  return 0;
}
