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
  #include "ast_tree.h"

  using namespace classes_arvore;

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
  int  			                            integerVal;
  Corpo                                 *corpo;
  double 			                          doubleVal;
  Comando                               *comando; 
  Programa                              *programa;
  NodeExpr                              *nodeExpr;
  std::vector<NodeExpr>                 *listaExpr;
  TipoCampos                            *tipoCampo;
  Declaracoes                           *declaracoes;
  ArgRegistro                           *argRegistro;
  std::vector<ArgRegistro>              *argRegistros;
  ArgFunc                               *arcFunc;
  std::vector<ArgFunc>                               *arcFuncs;
  std::string                           *modificador;
  std::string                           *stringVal;
  NodeCallFunc                          *nodeCallFunc;
  DeclaracaoVar                         *declaracaoVar;
  Literal                              *literal;
  DescritorTipo                         *descritorTipo;
  DeclaracaoTipo                        *declaracaoTipo;
  LocalArmazenamento                    *localArmazenamento;
  std::vector<Comando>                  *acao;
  AbstractDeclacaoFuncao                *declaracaoFuncao;
  std::vector<TipoCampos>               *tipoCampos;
  std::vector<DeclaracaoVar>            *declaracoesGlobais;
  std::vector<DeclaracaoVar>            *declaracoesVar;
  std::vector<DeclaracaoTipo>           *declaracoesTipo;
  std::vector<DeclaracaoFuncao>         *declaracoesFuncao;
  std::vector<int>        *tipoConstantes;
  NodeBinOp *nodeBinOp;
}

// TIPOS

%type <programa> program;
%type <declaracoes> declaracoes;
%type <acao> acao;
%type <acao> lista_comandos;
%type <declaracaoTipo> declaracao_tipo;
%type <tipoCampo> tipo_campo;
%type <corpo> corpo;
%type <tipoCampos> tipo_campos;
%type <descritorTipo> descritor_tipo;
%type <declaracoesTipo> lista_declaracao_de_tipo;
%type <declaracoesTipo> lista_declaracao_tipo;
%type <declaracoesFuncao> lista_declaracao_de_funcao;
%type <declaracoesFuncao> lista_declaracao_funcao;
%type <declaracoesGlobais> lista_declaracao_de_globais;
%type <declaracoesVar> declaracoes_de_locais;
%type <declaracoesGlobais> lista_declaracao_variavel;
%type <argRegistro> campos;
%type <declaracaoVar> declaracao_variavel;
%type <declaracaoFuncao> declaracao_funcao;
%type <nodeExpr> parametro;
%type <nodeCallFunc> chamada_de_funcao;
%type <localArmazenamento> local_de_armazenamento;
%type <comando> comando;
%type <arcFunc> arg;
%type <arcFuncs> lista_args;
%type <modificador> modificador;
%type <nodeExpr> expr;
%type <nodeBinOp> expressao_logica;
%type <nodeBinOp> expressao_relacional;
%type <nodeBinOp> expressao_aritmetica;
%type <literal> literal;
%type <tipoConstantes> tipo_constantes;
%type <argRegistros> criacao_de_registro;
%type <listaExpr> lista_expr;
%type <listaExpr> lista_parametros;

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
/*   acao {$$ = new Programa($1, $2);}
 */
declaracoes: lista_declaracao_de_tipo lista_declaracao_de_globais lista_declaracao_de_funcao {$$ = new Declaracoes($1, $2, $3);}
// std::vector<DeclaracaoTipo>> declaracaoVector;
/* Tipos */

lista_declaracao_de_tipo:
  | TIPO DOISPONTOS lista_declaracao_tipo {$$ = $3;} // ver

lista_declaracao_tipo: declaracao_tipo {declaracaoTipoVetor.push_back($1); $$ = declaracaoTipoVetor;}
  | lista_declaracao_tipo declaracao_tipo {declaracaoTipoVetor.push_back($1); $$ = declaracaoTipoVetor;}

declaracao_tipo: IDENTIFICADOR IGUAL descritor_tipo {$$ = new DeclaracaoTipo($1, $3);}

descritor_tipo: IDENTIFICADOR                                     {$$ = new DescritorTipoId($1);}
  | ABRECHAVE tipo_campos FECHACHAVE                              {$$ = new DescritorTipoReg($2);}
  | ABRECOLCHETE tipo_constantes FECHACOLCHETE DE IDENTIFICADOR   {$$ = new DescritorTipoVetor($2, $5);}

tipo_campos: tipo_campos VIRGULA tipo_campo {tipoCamposVetor.push_back($3); $$ = tipoCamposVetor; std::cout << *$1 << std::endl;} // Descobrir como fazer
  | tipo_campo {tipoCamposVetor.push_back($1); $$ = tipoCamposVetor; std::cout << *$1 << std::endl;}

tipo_campo: IDENTIFICADOR DOISPONTOS IDENTIFICADOR {$$ = new TipoCampos($1, $3);}

tipo_constantes: TIPOINTEIRO {tipoConstantes.push_back($1); std::cout << *$1 << std::endl; $$ = tipoConstantes;}// Descobrir como fazer
  | tipo_constantes VIRGULA TIPOINTEIRO {tipoConstante.push_back($3); std::cout << *$1 << std::endl; $$ = tipoConstantes;}

/* Variáveis */

lista_declaracao_de_globais:
  | GLOBAL DOISPONTOS lista_declaracao_variavel {$$ = $3;}

lista_declaracao_variavel: declaracao_variavel {declaracaoVarVetor.push_back($1); $$ = declaracaoVarVetor;}
  | lista_declaracao_variavel declaracao_variavel {declaracaoVarVetor.push_back($2); $$ = declaracaoVarVetor;}

declaracao_variavel: IDENTIFICADOR DOISPONTOS IDENTIFICADOR ATRIBUICAO expr {$$ = new DeclaracaoVar($1, $3, $5); }

criacao_de_registro: campos {argRegistroVetor.push_back($1); $$ = argRegistroVetor;}
  | criacao_de_registro VIRGULA campos {argRegistroVetor.push_back($3); $$ = argRegistroVetor;}

campos: IDENTIFICADOR IGUAL expr {$$ = new ArgRegistro($1, $3); }

/* Funções */

lista_declaracao_de_funcao: 
  | FUNCAO DOISPONTOS lista_declaracao_funcao {$$ = $3;}

lista_declaracao_funcao: declaracao_funcao {declaracaoFuncVetor.push_back($1); $$ = declaracaoFuncVetor;}
  | lista_declaracao_funcao declaracao_funcao {declaracaoFuncVetor.push_back($2); $$ = declaracaoFuncVetor;}

declaracao_funcao: IDENTIFICADOR ABREPARENTESE lista_args FECHAPARENTESE IGUAL corpo            {$$ = new DeclaracaoProcedimento($1, $3, $6)}
  | IDENTIFICADOR ABREPARENTESE lista_args FECHAPARENTESE DOISPONTOS IDENTIFICADOR IGUAL corpo  {$$ = new DeclaracaoFuncao($1, $3, $6, $8)}

lista_args: 
  | arg {argFuncVetor.push_back($1); $$ = argFuncVetor;}
  | lista_args VIRGULA arg {argFuncVetor.push_back($3); $$ = argFuncVetor;}

arg: modificador IDENTIFICADOR DOISPONTOS IDENTIFICADOR {$$ = new ArgFunc($1, $2, $4);}

modificador: VALOR {$$ = $1}
  | REF {$$ = $1}

corpo: declaracoes_de_locais
  acao {$$ = new Corpo($1, $2)}

declaracoes_de_locais: 
  | LOCAL DOISPONTOS lista_declaracao_variavel {$$ = $3;} // descobrir como fazer

/* ação */

acao: ACAO DOISPONTOS lista_comandos {$$ = $3;} // TODO: descobrir como fazer

/* Comandos */

lista_comandos: comando {comandosVetor.push_back($1); $$ = comandosVetor;}
  | lista_comandos PONTOVIRGULA comando {comandosVetor.push_back($3); $$ = comandosVetor;}

comando: local_de_armazenamento ATRIBUICAO expr {$$ = new ComandoAtribuicao($1, $3); }
  | chamada_de_funcao {$$ = $1; }
  | SE expr VERDADEIRO lista_comandos FSE {$$ = new ComandoIf($2, $4); }
  | SE expr VERDADEIRO lista_comandos FALSO lista_comandos FSE {$$ = new ComandoIfElse($2, $4, $6); }
  | PARA IDENTIFICADOR DE expr LIMITE expr FACA lista_comandos FPARA {$$ = new ComandoFor($2, $4, $6, $8); }
  | ENQUANTO expr FACA lista_comandos FENQUANTO  {$$ = new ComandoWhile($2, $4); }
  | PARE  {$$ = new ComandoPare(); }
  | CONTINUE {$$ = new ComandoContinue(); }
  | RETORNE expr {$$ = new ComandoRetorne($1); }

local_de_armazenamento: IDENTIFICADOR {$$ = new LocalIdentificador($1); }
  | local_de_armazenamento PONTO IDENTIFICADOR {$$ = new LocalRegistro($1, $3); }
  | local_de_armazenamento ABRECOLCHETE lista_expr FECHACOLCHETE {$$ = new LocalVetor($1, $3); }

lista_expr: expr {exprVetor.push_back($1); $$ = $1;}
  | lista_expr VIRGULA expr {exprVetor.push_back($3); $$ = exprVetor;}

chamada_de_funcao: IDENTIFICADOR ABREPARENTESE lista_parametros FECHAPARENTESE {$$ = new NodeCallFunc($1, $3); } 

lista_parametros: /* empty */
  | parametro {exprVetor.push_back($1); $$ = $1;}
  | lista_parametros VIRGULA parametro {exprVetor.push_back($3); $$ = $1;}

parametro: expr {$$ = new NodeExpr($1); }

/* Expressões */

expr: expressao_logica {$$  = $1}
  | expressao_relacional {$$  = $1}
  | expressao_aritmetica {$$  = $1}
  | ABRECHAVE criacao_de_registro FECHACHAVE {$$ = $2} // retorna um ponteiro para o registro
  | NULO {$$ = new NodeNulo()} 
  | ABREPARENTESE expr FECHAPARENTESE {$$ = new NodeExprComParen($2)} 
  | chamada_de_funcao {$$ = $1}
  | local_de_armazenamento {$$ = $1 } 
  | literal {$$ = $1} 

expressao_logica: expr E expr {$$ = new NodeBinOp($1, $2, $3); }
  | expr OU expr              {$$ = new NodeBinOp($1, $2, $3); }

expressao_relacional: expr IGUALDADE expr   {$$ = new NodeBinOp($1, $2, $3); }
  | expr DIFERENTE expr                     {$$ = new NodeBinOp($1, $2, $3); }
  | expr MAIOR expr                         {$$ = new NodeBinOp($1, $2, $3); }
  | expr MAIORIGUAL expr                    {$$ = new NodeBinOp($1, $2, $3); }
  | expr MENOR expr                         {$$ = new NodeBinOp($1, $2, $3); }
  | expr MENORIGUAL expr                    {$$ = new NodeBinOp($1, $2, $3); }

expressao_aritmetica: expr ADICAO expr      {$$ = new NodeBinOp($1, $2, $3); } 
  | expr SUBTRACAO expr                     {$$ = new NodeBinOp($1, $2, $3); } 
  | expr MULTIPLICACAO expr                 {$$ = new NodeBinOp($1, $2, $3); } 
  | expr DIVISAO expr                       {$$ = new NodeBinOp($1, $2, $3); } 

literal: TIPOINTEIRO {$$ = new NodeInteiro($1)}
  | TIPOREAL {$$ = new NodeDouble($1)}
  | TIPOCADEIA {$$ = new NodeCadeia($1)}
%%

namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
