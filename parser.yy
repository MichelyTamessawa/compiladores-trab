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
}

/* Tokens */
%token              TOK_EOF 0       "end of file"
%token			        EOL		          "end of line"
%token <integerVal> TIPOINTEIRO		  "tipo inteiro"
%token <doubleVal> 	TIPOREAL		    "tipo real"
%token <stringVal>  TIPOCADEIA      "tipo cadeia"
%token <stringVal> 	IDENTIFICADOR   "identificador"

/* palavras reservadas */
%token <stringVal>  PARE            "pare"
%token <stringVal>  CONTINUE        "continue"
%token <stringVal>  PARA            "para"
%token <stringVal>  ENQUANTO        "enquanto"
%token <stringVal>  FACA            "faca"
%token <stringVal>  FUN             "fun"
%token <stringVal>  SE              "se"
%token <stringVal>  VERDADEIRO      "verdadeiro"
%token <stringVal>  FALSO           "falso"
%token <stringVal>  TIPO            "tipo"
%token <stringVal>  DE              "de"
%token <stringVal>  LIMITE          "limite"
%token <stringVal>  VAR             "var"
%token <stringVal>  INTEIRO         "inteiro"
%token <stringVal>  REAL            "real"
%token <stringVal>  CADEIA          "cadeia"
%token <stringVal>  REF             "ref"
%token <stringVal>  RETORNE         "retorne"
%token <stringVal>  NULO            "nulo"
%token <stringVal>  INICIO          "inicio"
%token <stringVal>  FIM             "fim"

/* simbolos */
%token <stringVal>  VIRGULA         "virgula"
%token <stringVal>  DOISPONTOS      "dois pontos"
%token <stringVal>  PONTOVIRGULA    "ponto virgula"
%token <stringVal>  ABREPARENTESE   "abre parentese"
%token <stringVal>  FECHAPARENTESE  "fecha parentese"
%token <stringVal>  ABRECOLCHETE    "abre colchete"
%token <stringVal>  FECHACOLCHETE   "fecha colchete"
%token <stringVal>  ABRECHAVE       "abre chave"
%token <stringVal>  FECHACHAVE      "fecha chave"
%token <stringVal>  PONTO           "ponto"
%token <stringVal>  ADICAO          "adicao"
%token <stringVal>  SUBTRACAO       "subtracao"
%token <stringVal>  MULTIPLICACAO   "multiplicacao"
%token <stringVal>  DIVISAO         "divisao"
%token <stringVal>  DIFERENTE       "diferente"
%token <stringVal>  MENOR           "menor"
%token <stringVal>  MENORIGUAL      "menor igual"
%token <stringVal>  MAIOR           "maior"
%token <stringVal>  MAIORIGUAL      "maior igual"
%token <stringVal>  E               "e"
%token <stringVal>  OU              "ou"
%token <stringVal>  ATRIBUICAO      "atribuicao"
%token <stringVal>  IGUAL           "igual"
%token <stringVal>  IGUALDADE       "igualdade"
%token <stringVal>  INTERROGACAO    "interrogacao"

%%

program : /* empty */
        | constant
        | variable
        | symbol
        | keywords

constant : TIPOINTEIRO  { std::cout << "Inteiro: " << $1 << std::endl; }
         | TIPOREAL     { std::cout << "Real: " << $1 << std::endl; }
         | TIPOCADEIA   { std::cout << "Cadeia: " << *$1 << std::endl; }

variable :  IDENTIFICADOR { std::cout << "Identificador: " << *$1 << std::endl; }

symbol: VIRGULA { std::cout << "Símbolo: " << *$1 << std::endl; }
      | DOISPONTOS { std::cout << "Símbolo: " << *$1 << std::endl; }
      | PONTOVIRGULA { std::cout << "Símbolo: " << *$1 << std::endl; }
      | ABREPARENTESE { std::cout << "Símbolo: " << *$1 << std::endl; }
      | FECHAPARENTESE { std::cout << "Símbolo: " << *$1 << std::endl; }
      | ABRECOLCHETE { std::cout << "Símbolo: " << *$1 << std::endl; }
      | FECHACOLCHETE { std::cout << "Símbolo: " << *$1 << std::endl; }
      | ABRECHAVE { std::cout << "Símbolo: " << *$1 << std::endl; }
      | FECHACHAVE { std::cout << "Símbolo: " << *$1 << std::endl; }
      | PONTO { std::cout << "Símbolo: " << *$1 << std::endl; }
      | ADICAO { std::cout << "Símbolo: " << *$1 << std::endl; }
      | SUBTRACAO { std::cout << "Símbolo: " << *$1 << std::endl; }
      | MULTIPLICACAO { std::cout << "Símbolo: " << *$1 << std::endl; }
      | DIVISAO { std::cout << "Símbolo: " << *$1 << std::endl; }
      | DIFERENTE { std::cout << "Símbolo: " << *$1 << std::endl; }
      | MENOR { std::cout << "Símbolo: " << *$1 << std::endl; }
      | MENORIGUAL { std::cout << "Símbolo: " << *$1 << std::endl; }
      | MAIOR { std::cout << "Símbolo: " << *$1 << std::endl; }
      | MAIORIGUAL { std::cout << "Símbolo: " << *$1 << std::endl; }
      | E { std::cout << "Símbolo: " << *$1 << std::endl; }
      | OU { std::cout << "Símbolo: " << *$1 << std::endl; }
      | ATRIBUICAO { std::cout << "Símbolo: " << *$1 << std::endl; }
      | IGUAL { std::cout << "Símbolo: " << *$1 << std::endl; }
      | IGUALDADE { std::cout << "Símbolo: " << *$1 << std::endl; }
      | INTERROGACAO { std::cout << "Símbolo: " << *$1 << std::endl; }

keywords: PARE { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | CONTINUE { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | PARA { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | ENQUANTO { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | FACA { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | FUN { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | SE { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | VERDADEIRO { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | FALSO { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | TIPO { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | DE { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | LIMITE { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | VAR { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | INTEIRO { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | REAL { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | CADEIA { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | REF { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | RETORNE { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | NULO { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | INICIO { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
        | FIM { std::cout << "Palavra Reservada: " << *$1 << std::endl; }
%%

namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
