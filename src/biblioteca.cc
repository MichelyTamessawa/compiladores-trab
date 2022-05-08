#include "biblioteca.hh"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/Optional.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include <iostream>
#include <llvm-13/llvm/IR/Constant.h>
#include <llvm-13/llvm/IR/GlobalValue.h>

using namespace llvm;

namespace SimplesBiblioteca {
void imprimei(int valor, std::shared_ptr<Module> TheModule,
              std::shared_ptr<LLVMContext> TheContext,
              std::shared_ptr<IRBuilder<>> builder) {

  // Recupera a função "imprimei" declarada lá no início do programa
  Function *function = TheModule->getFunction("imprimei");
  if (!function) {
    std::cout << "Função desconhecida." << std::endl;
    return;
  }

  // Cria um Value* a partir do valor
  Value *v = ConstantInt::get(*TheContext, APInt(32, valor, true));
  std::vector<Value *> args;
  args.push_back(v);

  // Realiza a chamada para a função "imprimei"
  builder->CreateCall(function, args);
}

void imprimei(Value *valor, std::shared_ptr<Module> TheModule,
              std::shared_ptr<LLVMContext> TheContext,
              std::shared_ptr<IRBuilder<>> builder) {

  // Recupera a função "imprimei" declarada lá no início do programa
  Function *function = TheModule->getFunction("imprimei");

  if (!function) {
    std::cout << "Função desconhecida." << std::endl;
    return;
  }

  std::vector<Value *> args;
  args.push_back(valor);

  // Realiza a chamada para a função "imprimei"
  builder->CreateCall(function, args);
}

void imprimer(float valor, std::shared_ptr<Module> TheModule,
              std::shared_ptr<LLVMContext> TheContext,
              std::shared_ptr<IRBuilder<>> builder) {

  // Recupera a função "imprimer" declarada lá no início do programa
  Function *function = TheModule->getFunction("imprimer");
  if (!function) {
    std::cout << "Função desconhecida." << std::endl;
    return;
  }

  // Cria um Value* a partir do valor
  Value *v = ConstantFP::get(*TheContext, APFloat(valor));
  std::vector<Value *> args;
  args.push_back(v);

  // Realiza a chamada para a função "imprimer"
  builder->CreateCall(function, args);
}

Value *gere_inteiro(std::shared_ptr<Module> TheModule,
                    std::shared_ptr<IRBuilder<>> builder) {

  // Recupera a função "gere_inteiro" declarada lá no início do programa
  Function *function = TheModule->getFunction("gere_inteiro");
  if (!function) {
    std::cout << "Função desconhecida." << std::endl;
    return NULL;
  }

  // Realiza a chamada para a função "gere_inteiro"
  std::vector<Value *> args;
  return builder->CreateCall(function, args);
}
} // namespace SimplesBiblioteca