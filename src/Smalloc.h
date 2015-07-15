#ifndef Smalloc_H
#define Smalloc_H

#define DATA_SIZE   100
#define HEADER_SIZE 21
#define FOOTER_SIZE 21  //HEADER_SIZE AND FOOTER_SIZE MUST BE THE SAME!!

#define safeMalloc(size) _safeMalloc(size,__LINE__,__FILE__)


typedef struct {
  int headerSize;
  int footerSize;
  int size;
} Space;


void *_safeMalloc(int size,int lineNumber, char *fileName);
Space *createMemorySpace();
void patternRepeat( int timesToCopy,char *pattern, char *pointer);

#endif // Smalloc_H
