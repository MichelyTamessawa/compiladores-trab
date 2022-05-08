#include <string>

typedef struct S_symbol_ *S_symbol;

/* Criação de um símbolo unico de acordo com uma string */
S_symbol S_Symbol(std::string);

/* Tabela que mapeia um S_symbol para qualquer valor (inteiro, Value*...) */
typedef struct TAB_table_ *S_table;

/* Cria uma tabela vazia */
S_table S_empty(void);

/* Insere um símbolo na tabela com seu determinado valor*/
/* Caso um símbolo já exista, irá apenas substituir o valor */
void S_enter(S_table t, S_symbol sym, void *value);

/* Procura na tabela pelo símbolo especificado*/
void *S_look(S_table t, S_symbol sym);
