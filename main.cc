#include "arvore.hh"
#include "driver.hh"
#include "semantic.hh"
#include <bits/getopt_core.h>
#include <cstdlib>
#include <iostream>
#include <regex>
#include <string>
#include <unistd.h>

int main(int argc, char **argv) {
  std::string filename;
  std::string executavelName = "a.out";
  bool imprimeAssembly = false;
  bool imprimeIntermediario = false;

  int opt;
  while ((opt = getopt(argc, argv, "io:sf:?")) != EOF)
    switch (opt) {
    case 'f':
      filename = optarg;
      break;
    case 'i':
      imprimeIntermediario = true;
      break;
    case 'o':
      executavelName = optarg;
      break;
    case 's':
      imprimeAssembly = true;
      break;
    case '?':
      std::cerr << "Uso: sc [-i] [-s] [-o <destino>] <fonte>" << std::endl;
      break;
    default:
      break;
    }

  Simples::Driver driver;
  driver.parse_file(filename);

  filename = filename.replace(filename.size() - 2, filename.size(), "");

  semantic::Inicializar(AST::ast_root, filename, imprimeIntermediario);

  // TODO: Adicionar impressão do código assembly (descobrir como)

  if (system("clang++ -c imprimei.cc")) {
    std::cout << "Não foi possível compilar a biblioteca de Simples."
              << std::endl;
    return 0;
  }

  std::string buildCommand =
      "clang " + filename + ".o imprimei.o -o " + executavelName;

  if (system(buildCommand.c_str())) {
    std::cout << "Não foi possível compilar o programa." << std::endl;
  };

  std::cout << "Arquivo executável salvo como: " + executavelName << std::endl;
  return 0;
}
