#pragma once

#include "arvore.hh"
#include <fstream>
#include <iostream>
#include <string>

namespace Simples {
/// Forward declarations of classes
class Parser;
class Scanner;
class location;

class Driver {
public:
  Driver();
  ~Driver();

  int parse();
  int parse_file(std::string &path);

  void reset();

private:
  Scanner *scanner_;
  Parser *parser_;
  location *location_;
  int error_;

  /// Allows Parser and Scanner to access private attributes
  /// of the Driver class
  friend class Parser;
  friend class Scanner;
};
} // namespace Simples
