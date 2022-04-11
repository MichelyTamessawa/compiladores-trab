#include "arvore.hh"

declaracaoTipoVetor DeclaracaoTipoVetor(DeclaracaoTipo head, declaracaoTipoVetor tail)
{
    declaracaoTipoVetor *p = (declaracaoTipoVetor *)malloc(sizeof(declaracaoTipoVetor));
    (*p)->head = head;
    (*p)->tail = tail;
    return *p;
}
