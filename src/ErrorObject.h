#ifndef ErrorObject_H
#define ErrorObject_H

typedef enum{
  ERR_USED_EXTRA_SPACE
} ErrorCode;

typedef struct{
  char *errorMsg;
  ErrorCode errorCode;
} ErrorObject;

void throwError(char *message, ErrorCode errCode);
void freeError(ErrorObject *errObj);

#endif // ErrorObject_H
