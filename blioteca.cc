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

using namespace llvm;

namespace SimplesBiblioteca {
void imprimei(int valor, std::shared_ptr<Module> TheModule,
              std::shared_ptr<LLVMContext> TheContext,
              std::shared_ptr<IRBuilder<>> builder) {
  Function *CalleeF = TheModule->getFunction("imprimei");
  if (!CalleeF) {
    std::cout << "Função desconhecida." << std::endl;
    return;
  }

  if (CalleeF->arg_size() != 1) {
    std::cout << "Número de pâmetros incorretos." << std::endl;
    return;
  }

  Value *v = ConstantInt::get(*TheContext, APInt(32, valor, true));
  std::vector<Value *> args;
  args.push_back(v);

  builder->CreateCall(CalleeF, args, "calltmp");
}
} // namespace SimplesBiblioteca