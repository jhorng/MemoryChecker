#ifndef ErrorObject_H
#define ErrorObject_H

typedef enum{
  ERR_EXCEED_DATA_SIZE,
  ERR_FREE_INVALID_LOCATION,
  ERR_FAIL_TO_CREATE_ALLOCATION_POOL
} ErrorCode;

typedef struct{
  char *errorMsg;
  ErrorCode errorCode;
} ErrorObject;

void throwError(ErrorCode errCode, char *msg, ...);
void freeError(ErrorObject *errObj);

#endif // ErrorObject_H
