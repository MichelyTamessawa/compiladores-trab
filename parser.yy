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
%token <stringVal>  FPARA           "fpara"
%token <stringVal>  ENQUANTO        "enquanto"
%token <stringVal>  FENQUANTO       "fenquanto"
%token <stringVal>  FACA            "faca"
%token <stringVal>  SE              "se"
%token <stringVal>  FSE             "fse"
%token <stringVal>  VERDADEIRO      "verdadeiro"
%token <stringVal>  FALSO           "falso"
%token <stringVal>  TIPO            "tipo"
%token <stringVal>  DE              "de"
%token <stringVal>  LIMITE          "limite"
%token <stringVal>  GLOBAL          "global"
%token <stringVal>  LOCAL           "local"
%token <stringVal>  VALOR           "valor"
%token <stringVal>  REF             "ref"
%token <stringVal>  RETORNE         "retorne"
%token <stringVal>  NULO            "nulo"
%token <stringVal>  ACAO            "ação"
%token <stringVal>  FUNCAO          "funcao"

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
%token <stringVal>  IGUALDADE       "igualdade"
%token <stringVal>  DIFERENTE       "diferente"
%token <stringVal>  MENOR           "menor"
%token <stringVal>  MENORIGUAL      "menor igual"
%token <stringVal>  MAIOR           "maior"
%token <stringVal>  MAIORIGUAL      "maior igual"
%token <stringVal>  E               "e"
%token <stringVal>  OU              "ou"
%token <stringVal>  ATRIBUICAO      "atribuicao"
%token <stringVal>  IGUAL           "igual"

/* Precedência */
%left E OU
%left IGUALDADE DIFERENTE MAIOR MENOR MAIORIGUAL MENORIGUAL
%left ADICAO SUBTRACAO
%left MULTIPLICACAO DIVISAO

%%

/* programa */

program : declaracoes
  acao

declaracoes: lista_declaracao_de_tipo lista_declaracao_de_globais lista_declaracao_de_funcao

/* Tipos */

lista_declaracao_de_tipo:
  | TIPO DOISPONTOS lista_declaracao_tipo

lista_declaracao_tipo: declaracao_tipo
  | lista_declaracao_tipo declaracao_tipo

declaracao_tipo: IDENTIFICADOR IGUAL descritor_tipo 

descritor_tipo: IDENTIFICADOR                                     {std::cout << "declaração do tipo identificador: " << *$1 << std::endl;}
  | ABRECHAVE tipo_campos FECHACHAVE                              {std::cout << "declaração do tipo registro" << std::endl;}
  | ABRECOLCHETE tipo_constantes FECHACOLCHETE DE IDENTIFICADOR   {std::cout << "declaração do tipo vetor: " << *$1 << std::endl;}

tipo_campos: tipo_campos VIRGULA tipo_campo
  | tipo_campo

tipo_campo: IDENTIFICADOR DOISPONTOS IDENTIFICADOR

tipo_constantes: TIPOINTEIRO
  | tipo_constantes VIRGULA TIPOINTEIRO

/* Variáveis */

lista_declaracao_de_globais:
  | GLOBAL DOISPONTOS lista_declaracao_variavel

lista_declaracao_variavel: declaracao_variavel
  | lista_declaracao_variavel declaracao_variavel

declaracao_variavel: IDENTIFICADOR DOISPONTOS IDENTIFICADOR ATRIBUICAO expr {std::cout << "declaração da variável: " << *$1 << std::endl;}

criacao_de_registro: campos
  | criacao_de_registro VIRGULA campos

campos: IDENTIFICADOR IGUAL expr

/* Funções */

lista_declaracao_de_funcao: /* empty */
  | FUNCAO DOISPONTOS lista_declaracao_funcao 

lista_declaracao_funcao: declaracao_funcao 
  | lista_declaracao_funcao declaracao_funcao

declaracao_funcao: IDENTIFICADOR ABREPARENTESE lista_args FECHAPARENTESE IGUAL corpo            {std::cout << "declaração de procedimento: " << *$1 << std::endl;}
  | IDENTIFICADOR ABREPARENTESE lista_args FECHAPARENTESE DOISPONTOS IDENTIFICADOR IGUAL corpo  {std::cout << "declaração de função: " << *$1 <<  std::endl;}

lista_args: /* empty */
  | arg
  | lista_args VIRGULA arg

arg: modificador IDENTIFICADOR DOISPONTOS IDENTIFICADOR

modificador: VALOR
  | REF

corpo: declaracoes_de_locais
  acao

declaracoes_de_locais: /* empty */
  | LOCAL DOISPONTOS lista_declaracao_variavel

/* ação */

acao: ACAO DOISPONTOS lista_comandos

/* Comandos */

lista_comandos: comando
  | lista_comandos PONTOVIRGULA comando

comando: local_de_armazenamento ATRIBUICAO expr {} // check
  | chamada_de_funcao // check
  | SE expr VERDADEIRO lista_comandos FSE // check
  | SE expr VERDADEIRO lista_comandos FALSO lista_comandos FSE // check
  | PARA IDENTIFICADOR DE expr LIMITE expr FACA lista_comandos FPARA // check
  | ENQUANTO expr FACA lista_comandos FENQUANTO // check
  | PARE  // check
  | CONTINUE // check
  | RETORNE expr // check

local_de_armazenamento: IDENTIFICADOR // check
  | local_de_armazenamento PONTO IDENTIFICADOR {}
  | local_de_armazenamento ABRECOLCHETE lista_expr FECHACOLCHETE

lista_expr: expr
  | lista_expr VIRGULA expr

chamada_de_funcao: IDENTIFICADOR ABREPARENTESE lista_parametros FECHAPARENTESE {std::cout << "chamada da função: " << *$1 << std::endl;}

lista_parametros: /* empty */
  | parametro
  | lista_parametros VIRGULA parametro

parametro: expr

/* Expressões */

expr: expressao_logica // check
  | expressao_relacional // check
  | expressao_aritmetica // check
  | ABRECHAVE criacao_de_registro FECHACHAVE // retorna um ponteiro para o registro -- check
  | NULO // check
  | ABREPARENTESE expr FECHAPARENTESE // expressão_com_parênteses -- check
  | chamada_de_funcao // -- check
  | local_de_armazenamento // -- check
  | literal // inteiro, real ou cadeia - check

expressao_logica: expr E expr {std::cout << "Op de and" << std::endl;}
  | expr OU expr              {std::cout << "Op de or" << std::endl;}

expressao_relacional: expr IGUALDADE expr   {std::cout << "Op de igualdade" << std::endl;}
  | expr DIFERENTE expr                     {std::cout << "Op de diferença" << std::endl;}
  | expr MAIOR expr                         {std::cout << "Op de maior" << std::endl;}
  | expr MAIORIGUAL expr                    {std::cout << "Op de maior igual" << std::endl;}
  | expr MENOR expr                         {std::cout << "Op de menor" << std::endl;}
  | expr MENORIGUAL expr                    {std::cout << "Op de menor igual" << std::endl;}

expressao_aritmetica: expr ADICAO expr {std::cout << "Op de adição" << std::endl;}
  | expr SUBTRACAO expr                {std::cout << "Op de subtração" << std::endl;}
  | expr MULTIPLICACAO expr            {std::cout << "Op de multiplicação" << std::endl;}
  | expr DIVISAO expr                  {std::cout << "Op de divisão" << std::endl;}

literal: TIPOINTEIRO
  | TIPOREAL
  | TIPOCADEIA

%%

namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
