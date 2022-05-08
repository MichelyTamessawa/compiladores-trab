#include "symbol.hh"
#include "table.hh"
#include <stdio.h>
#include <string.h>

/* A tabela de símbolos é uma tabela hash baseada no S_symbol de alguma string*/

struct S_symbol_ {
  std::string name;
  S_symbol next;
};

static S_symbol mksymbol(std::string name, S_symbol next) {
  S_symbol s = (S_symbol)malloc(sizeof(*s));
  s->name = name;
  s->next = next;
  return s;
}

#define SIZE 109

static S_symbol hashtable[SIZE];

static unsigned int hash(const char *s0) {
  unsigned int h = 0;
  const char *s;
  for (s = s0; *s; s++)
    h = h * 65599 + *s;
  return h;
}

static int streq(std::string a, std::string b) {
  return !strcmp(a.c_str(), b.c_str());
}

S_symbol S_Symbol(std::string name) {
  int index = hash(name.c_str()) % SIZE;
  S_symbol syms = hashtable[index], sym;
  for (sym = syms; sym; sym = sym->next)
    if (streq(sym->name, name))
      return sym;
  sym = mksymbol(name, syms);
  hashtable[index] = sym;
  return sym;
}

S_table S_empty(void) { return TAB_empty(); }

void S_enter(S_table t, S_symbol sym, void *value) { TAB_enter(t, sym, value); }

void *S_look(S_table t, S_symbol sym) { return TAB_look(t, sym); }

static struct S_symbol_ marksym = {"<mark>", 0};
