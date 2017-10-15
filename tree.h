#include <stdbool.h>

typedef struct Node Node;
struct Node
{
  char *pStr;
  int count;
  Node *pLeft, *pRight;
};

// Creates a Node with count = 1, pLeft and pRight = 0
Node *createNode(const char *pStrIn);

// Adds a string, unless the string is already in the tree.
// Keeps the tree SORTED by string value.
//
// Return:
//  - Return value is true if insertion took place, or false
//  - ppNode may be 0 (aka. "NULL"). If not null, it should return the
//    Node was found or freshly created.
bool addString(Node *pRoot, const char *pStrIn);

void printNode(Node *pNode);

// Traverse the tree depth-first and call callBack() for each node
void traverseInOrder(Node *pNode, void (callBack)(Node*));
