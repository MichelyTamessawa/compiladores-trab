#include "semantic.hh"
#include <string.h>

using namespace AST;
namespace semantic
{
    bool Inicializar(Programa root)
    {
        declaracaoTipoVetor aux = root.declaracoes.declaracoesTipo->tail;
        printf("AI CALICA %s\n", root.declaracoes.declaracoesTipo->head.identificador.c_str());

        while (aux != NULL)
        {

            printf("AI CALICA %s\n", aux->head.identificador.c_str());
            // aux->head.validar();
            aux = aux->tail;
        }

        printf("HAHA DEU BOM\n");
        return false;
    }

}