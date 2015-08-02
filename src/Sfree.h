#ifndef Sfree_H
#define Sfree_H
#include "AllocationPool.h"
#include "LinkedList.h"
#include "Smalloc.h"

#include "ErrorObject.h"
#define safeFree(dataAddress) _safeFree(dataAddress,__LINE__,__FILE__)

#endif // Sfree_H
