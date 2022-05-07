
#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "arvore.hh"

namespace semantic {
bool Inicializar(AST::Programa *root, std::string filename,
                 bool imprimeIntermediario);
}

#endif