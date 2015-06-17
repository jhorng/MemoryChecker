#ifndef SafeMalloc_H
#define SafeMalloc_H

typedef struct{
  int paddingSize;
}padSpace;

padSpace *createPadding();

#endif // SafeMalloc_H
