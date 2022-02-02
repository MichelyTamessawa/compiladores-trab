/*
 * PARSER
 */

%{

/*** C++ Declarations ***/
#include "parser.hh"
#include "scanner.hh"

#define yylex driver.scanner_->yylex

%}

%code requires {
  #include <iostream>
  #include "driver.hh"
  #include "location.hh"
  #include "position.hh"
}

%code provides {
  namespace Simples  {
    // Forward declaration of the Driver class
    class Driver;

    inline void yyerror (const char* msg) {
      std::cerr << msg << std::endl;
    }
  }
}

/* Require bison 2.3 or later */
%require "2.4"
/* enable c++ generation */
%language "C++"
%locations
/* write out a header file containing the token defines */
%defines
/* add debug output code to generated parser. disable this for release
 * versions. */
%debug
/* namespace to enclose parser in */
%define api.namespace {Simples}
/* set the parser's class identifier */
%define api.parser.class {Parser}
/* set the parser */
%parse-param {Driver &driver}
/* set the lexer */
%lex-param {Driver &driver}
/* verbose error messages */
%define parse.error verbose
/* use newer C++ skeleton file */
%skeleton "lalr1.cc"
/* Entry point of grammar */
%start program

%union
{
 /* YYLTYPE */
  int  			      integerVal;
  double 			    doubleVal;
  std::string*		stringVal;
  char*           charVal;
}

/* Tokens */
%token              TOK_EOF 0     "end of file"
%token			        EOL		        "end of line"
%token <integerVal> INTEIRO		    "inteiro"
%token <doubleVal> 	REAL		      "real"
%token <stringVal>  CADEIA        "cadeia"
%token <stringVal> 	IDENTIFICADOR "identificador"
%token <charVal>    SIMBOLO       "simbolo"
%token <stringVal>  PALAVRARESERVADA  "palavra reservada"
%%

program:  /* empty */
        | constant
        | variable
        | symbol
        | keywords

constant : INTEIRO  { std::cout << "Inteiro: " << $1 << std::endl; }
         | REAL     { std::cout << "Real: " << $1 << std::endl; }
         | CADEIA   { std::cout << "Cadeia: " << *$1 << std::endl; }

variable :  IDENTIFICADOR {  std::cout << "Identificador: " << *$1 << std::endl; }

symbol : SIMBOLO { std::cout << "Símbolo: " << $1 << std::endl; }

keywords : PALAVRARESERVADA { std::cout << "Palavra Reservada: " << *$1 << std::endl; }

%%

namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
