
#include "llvm/IR/Module.h"
#include <iostream>
#include <llvm-13/llvm/IR/IRBuilder.h>
#include <llvm-13/llvm/IR/LLVMContext.h>

// Biblioteca padrão da linguagem Simples
// Atualmente contém apenas a função "imprimei"

namespace SimplesBiblioteca {

// Quando queremos imprimir um Value*
void imprimei(llvm::Value *value, std::shared_ptr<llvm::Module> TheModule,
              std::shared_ptr<llvm::LLVMContext> TheContext,
              std::shared_ptr<llvm::IRBuilder<>> builder);

// Quando queremos imprimir um int
void imprimei(int value, std::shared_ptr<llvm::Module> TheModule,
              std::shared_ptr<llvm::LLVMContext> TheContext,
              std::shared_ptr<llvm::IRBuilder<>> builder);

// Quando queremos imprimir um real
void imprimer(float value, std::shared_ptr<llvm::Module> TheModule,
              std::shared_ptr<llvm::LLVMContext> TheContext,
              std::shared_ptr<llvm::IRBuilder<>> builder);

// Quando queremos imprimir um real
llvm::Value *gere_inteiro(std::shared_ptr<llvm::Module> TheModule,
                          std::shared_ptr<llvm::IRBuilder<>> builder);
} // namespace SimplesBiblioteca