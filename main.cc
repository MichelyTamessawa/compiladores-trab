#include <iostream>
#include <string>
#include <unistd.h>

#include "arvore.hh"
#include "driver.hh"
#include "semantic.hh"

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
  return 0;
}
