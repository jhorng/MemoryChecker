#ifndef Smalloc_H
#define Smalloc_H

typedef struct {
  int headerSize;
  int footerSize;
  int size;
} Space;

Space *createMemorySpace();

#endif // Smalloc_H
