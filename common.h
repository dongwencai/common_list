#ifndef __COMMON_H__
#define __COMMON_H__
#include <stdint.h>
#define SWAP(a,b)   {   \
    typeof(a) c;        \
    c = a;              \
    a = b;              \
    b = c;              \
    }

#ifndef NULL
#if defined(__cplusplus)
#define NULL (0)
#else
#define NULL ((void *)0)
#endif
#endif

#define MAX(a,b)    (a > b ? a : b)

#define MIN(a,b)    (a < b ? a : b)

#define offsetof(TYPE, MEMBER) ((uint32_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
    const typeof(((type *)0)->member) * __mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

struct list_head {
        struct list_head *next, *prev;
};

struct hlist_head {
        struct hlist_node *first;
};

struct hlist_node {
        struct hlist_node *next, **pprev;
};

#endif
