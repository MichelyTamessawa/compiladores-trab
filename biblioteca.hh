
#include "llvm/IR/Module.h"
#include <iostream>
#include <llvm-13/llvm/IR/IRBuilder.h>
#include <llvm-13/llvm/IR/LLVMContext.h>

namespace SimplesBiblioteca {
void imprimei(llvm::Value *value, std::shared_ptr<llvm::Module> TheModule,
              std::shared_ptr<llvm::LLVMContext> TheContext,
              std::shared_ptr<llvm::IRBuilder<>> builder);

void imprimei(int value, std::shared_ptr<llvm::Module> TheModule,
              std::shared_ptr<llvm::LLVMContext> TheContext,
              std::shared_ptr<llvm::IRBuilder<>> builder);
} // namespace SimplesBiblioteca