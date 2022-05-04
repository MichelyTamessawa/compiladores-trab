#include "arvore.hh"
#include <stdio.h>
#include <iostream>

namespace AST {
Programa *ast_root;

declaracaoTipoVetor DeclaracaoTipoVetor(DeclaracaoTipo head,
                                        declaracaoTipoVetor tail) {
  declaracaoTipoVetor p = (declaracaoTipoVetor)malloc(sizeof(*p));
  std::cout << "Primeiro head " << head.identificador << std::endl;
  p->head = &head;
  std::cout << "P->head " << p->head->identificador << std::endl;

  p->tail = tail;

  return p;
}

declaracaoVarVetor DeclaracaoVarVetor(DeclaracaoVar head,
                                      declaracaoVarVetor tail) {
  declaracaoVarVetor p = (declaracaoVarVetor)malloc(sizeof(*p));

  p->head = &head;
  p->tail = tail;
  return p;
}

declaracaoFuncVetor DeclaracaoFuncVetor(AbstractDeclacaoFuncao head,
                                        declaracaoFuncVetor tail) {
  declaracaoFuncVetor p = (declaracaoFuncVetor)malloc(sizeof(*p));
  p->head = &head;
  p->tail = tail;
  return p;
}

comandosVetor ComandosVetor(Comando head, comandosVetor tail) {

  comandosVetor p = (comandosVetor)malloc(sizeof(*p));
  p->head = (Comando *)malloc(sizeof(Comando));

  p->head = &head;
  p->tail = tail;

  return p;
}

argRegistroVetor ArgRegistroVetor(ArgRegistro head, argRegistroVetor tail) {
  argRegistroVetor p = (argRegistroVetor)malloc(sizeof(*p));
  p->head = &head;
  p->tail = tail;
  return p;
}

exprVetor ExprVetor(NodeExpr head, exprVetor tail) {
  exprVetor p = (exprVetor)malloc(sizeof(*p));
  p->head = &head;
  p->tail = tail;
  return p;
}

tipoConstantes TipoConstantes(int head, tipoConstantes tail) {
  tipoConstantes p = (tipoConstantes)malloc(sizeof(*p));
  p->head = head;
  p->tail = tail;
  return p;
}

tipoCamposVetor TipoCamposVetor(TipoCampos head, tipoCamposVetor tail) {
  tipoCamposVetor p = (tipoCamposVetor)malloc(sizeof(*p));
  p->head = &head;
  p->tail = tail;
  return p;
}

argFuncVetor ArgFuncVetor(ArgFunc head, argFuncVetor tail) {
  argFuncVetor p = (argFuncVetor)malloc(sizeof(*p));
  p->head = &head;
  p->tail = tail;
  return p;
}

} // namespace AST
