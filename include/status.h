#ifndef STATUS_H
#define STATUS_H

typedef enum{
    SUCCESS = 0,
    ERROR_ARGS = 1,
    ERROR_LUA = 2,
    ERROR_RUBY = 3,
}Status;

#endif
