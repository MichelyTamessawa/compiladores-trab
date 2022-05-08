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
  while ((opt = getopt(argc, argv, "io:s?")) != EOF)
    switch (opt) {
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

  if (optind < argc) {
    while (optind < argc) {
      filename = argv[optind];
      break;
    }
  }

  Simples::Driver driver;
  std::cout << "- Inicializando análise sintática..." << std::endl;
  driver.parse_file(filename);
  std::cout << "- Análise sintática realizada com sucesso...\n" << std::endl;

  filename = filename.replace(filename.size() - 2, filename.size(), "");

  semantic::Inicializar(AST::ast_root, filename, imprimeIntermediario);

  // Compilação da função externa "imprimei"
  if (system("clang++ -c imprimei.cc")) {
    std::cout << "Não foi possível compilar a biblioteca de Simples."
              << std::endl;
    return 0;
  }

  // Compilação do programa e geração do executável
  std::string buildCommand =
      "clang " + filename + ".o imprimei.o -o " + executavelName;

  if (system(buildCommand.c_str())) {
    std::cout << "Não foi possível compilar o programa." << std::endl;
    throw;
  };

  std::cout << "- Arquivo executável salvo como: " + executavelName
            << std::endl;

  // Impressão do código assembly
  if (imprimeAssembly) {
    std::string buildCommand = "llc " + filename + ".ll -o " + filename + ".as";
    if (system(buildCommand.c_str())) {
      buildCommand = "llc-13 " + filename + ".ll -o " + filename + ".as";
      if (system(buildCommand.c_str())) {
        std::cout << "Não foi possível gerar o executável" << std::endl;
        throw;
      }
    }

    std::cout << "- Código assembly salvo como: " + filename + ".as"
              << std::endl;
  }

  std::cout << std::endl;
  return 0;
}
