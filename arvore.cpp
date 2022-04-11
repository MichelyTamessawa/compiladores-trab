#include "arvore.hh"

declaracaoTipoVetor DeclaracaoTipoVetor(DeclaracaoTipo head, declaracaoTipoVetor tail)
{
    declaracaoTipoVetor *p = (declaracaoTipoVetor *)malloc(sizeof(declaracaoTipoVetor));
    (*p)->head = head;
    (*p)->tail = tail;
    return *p;
}

declaracaoVarVetor DeclaracaoVarVetor(DeclaracaoVar head, declaracaoVarVetor tail)
{
    declaracaoVarVetor *p = (declaracaoVarVetor *)malloc(sizeof(declaracaoVarVetor));
    (*p)->head = head;
    (*p)->tail = tail;
    return *p;
}

declaracaoFuncVetor DeclaracaoFuncVetor(AbstractDeclacaoFuncao head, declaracaoFuncVetor tail)
{
    declaracaoFuncVetor *p = (declaracaoFuncVetor *)malloc(sizeof(declaracaoFuncVetor));
    (*p)->head = head;
    (*p)->tail = tail;
    return *p;
}

comandosVetor ComandosVetor(Comando head, comandosVetor tail)
{
    comandosVetor *p = (comandosVetor *)malloc(sizeof(comandosVetor));
    (*p)->head = head;
    (*p)->tail = tail;
    return *p;
}

argRegistroVetor ArgRegistroVetor(ArgRegistro head, argRegistroVetor tail)
{
    argRegistroVetor *p = (argRegistroVetor *)malloc(sizeof(argRegistroVetor));
    (*p)->head = head;
    (*p)->tail = tail;
    return *p;
}

exprVetor ExprVetor(NodeExpr head, exprVetor tail)
{
    exprVetor *p = (exprVetor *)malloc(sizeof(exprVetor));
    (*p)->head = head;
    (*p)->tail = tail;
    return *p;
}

tipoConstantes TipoConstantes(int head, tipoConstantes tail)
{
    tipoConstantes *p = (tipoConstantes *)malloc(sizeof(tipoConstantes));
    (*p)->head = head;
    (*p)->tail = tail;
    return *p;
}