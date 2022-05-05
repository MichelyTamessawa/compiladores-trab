#include "arvore.hh"
#include "driver.hh"
#include "semantic.hh"
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>

int main(int argc, char **argv) {
  std::string filename;
  int opt;
  while ((opt = getopt(argc, argv, "i:?")) != EOF)
    switch (opt) {
    case 'i':
      filename = optarg;
      break;
    case '?':
      std::cerr << "Usuage: tc -i <filename>" << std::endl;
      break;
    default:
      std::cerr << std::endl;
      abort();
    }

  Simples::Driver driver;
  driver.parse_file(filename);

  semantic::Inicializar(AST::ast_root);

  system("clang output.o -o test");
  return 0;
}
