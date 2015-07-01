#ifndef Smalloc_H
#define Smalloc_H

typedef struct Space_t Space;
struct Space_t{
  int headerSize;
  int footerSize;
  int size;
};

Space *memorySpace();

#endif // Smalloc_H
