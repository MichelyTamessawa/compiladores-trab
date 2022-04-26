/*
 * table.c - Functions to manipulate generic tables.
 * Copyright (c) 1997 Andrew W. Appel.
 */

#include <stdio.h>
#include "table.hh"
#include <cstdlib>

#define TABSIZE 127

typedef struct binder_ *binder;
struct binder_
{
    void *key;
    void *value;
    binder next;
    void *prevtop;
};
struct TAB_table_
{
    binder table[TABSIZE];
    void *top;
};

static binder Binder(void *key, void *value, binder next, void *prevtop)
{
    binder b = (binder)malloc(sizeof(*b));
    b->key = key;
    b->value = value;
    b->next = next;
    b->prevtop = prevtop;
    return b;
}

TAB_table TAB_empty(void)
{
    TAB_table t = (TAB_table)malloc(sizeof(*t));
    int i;
    t->top = NULL;
    for (i = 0; i < TABSIZE; i++)
        t->table[i] = NULL;
    return t;
}

/* The cast from pointer to integer in the expression
 *   ((unsigned)key) % TABSIZE
 * may lead to a warning message.  However, the code is safe,
 * and will still operate correctly.  This line is just hashing
 * a pointer value into an integer value, and no matter how the
 * conversion is done, as long as it is done consistently, a
 * reasonable and repeatable index into the table will result.
 */

void TAB_enter(TAB_table t, void *key, void *value)
{
    int index;
    index = *((unsigned *)key) % TABSIZE;
    t->table[index] = Binder(key, value, t->table[index], t->top);
    t->top = key;
}

void *TAB_look(TAB_table t, void *key)
{
    int index;
    binder b;
    index = *((unsigned *)key) % TABSIZE;
    for (b = t->table[index]; b; b = b->next)
        if (b->key == key)
            return b->value;
    return NULL;
}

void *TAB_pop(TAB_table t)
{
    void *k;
    binder b;
    int index;
    k = t->top;
    index = *((unsigned *)k) % TABSIZE;
    b = t->table[index];
    t->table[index] = b->next;
    t->top = b->prevtop;
    return b->key;
}

void TAB_dump(TAB_table t, void (*show)(void *key, void *value))
{
    void *k = t->top;
    int index = *((unsigned *)k) % TABSIZE;
    binder b = t->table[index];
    if (b == NULL)
        return;
    t->table[index] = b->next;
    t->top = b->prevtop;
    show(b->key, b->value);
    TAB_dump(t, show);
    t->top = k;
    t->table[index] = b;
}
