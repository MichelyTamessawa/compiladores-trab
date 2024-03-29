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
  #include <stdio.h>
  #include "arvore.hh"
  #include "semantic.hh"
  using namespace AST;

}

%code
{
  #include "arvore.hh"
  #include "semantic.hh"

  using namespace AST;

}

%code provides {
   namespace Simples  {
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
  float 			                          doubleVal;
  Comando                               *comando; 
  Programa                              *programa;
  NodeExpr                              *nodeExpr;
  exprVetor                             listaExpr;
  TipoCampos                            *tipoCampo;
  ArgRegistro                           *argRegistro;
  argRegistroVetor                      argRegistros;
  ArgFunc                               *arcFunc;
  argFuncVetor                          arcFuncs;
  std::string                           *modificador;
  std::string                           *stringVal;
  NodeCallFunc                          *nodeCallFunc;
  DeclaracaoVar                         *declaracaoVar;
  NodeExpr                               *literal;
  DescritorTipo                         *descritorTipo;
  DeclaracaoTipo                        *declaracaoTipo;
  LocalArmazenamento                    *localArmazenamento;
  comandosVetor                          acao;
  AbstractDeclacaoFuncao                *declaracaoFuncao;
  tipoCamposVetor                       tipoCampos;
  declaracaoVarVetor                    declaracoesGlobais;
  declaracaoVarVetor                    declaracoesVar;
  declaracaoTipoVetor                   declaracoesTipo;
  declaracaoFuncVetor                   declaracoesFuncao;
  tipoConstantes                        tipoConstantesType;
  NodeExpr *nodeBinOp;
}

// Declaração de tipos

%type <programa>                        program;
%type <acao>                            acao;
%type <acao>                            lista_comandos;
%type <declaracaoTipo>                  declaracao_tipo;
%type <tipoCampo>                       tipo_campo;
%type <corpo>                           corpo;
%type <tipoCampos>                      tipo_campos;
%type <descritorTipo>                   descritor_tipo;
%type <declaracoesTipo>                 lista_declaracao_de_tipo;
%type <declaracoesTipo>                 lista_declaracao_tipo;
%type <declaracoesFuncao>               lista_declaracao_de_funcao;
%type <declaracoesFuncao>               lista_declaracao_funcao;
%type <declaracoesGlobais>              lista_declaracao_de_globais;
%type <declaracoesVar>                  declaracoes_de_locais;
%type <declaracoesGlobais>              lista_declaracao_variavel;
%type <argRegistro>                     campos;
%type <declaracaoVar>                   declaracao_variavel;
%type <declaracaoFuncao>                declaracao_funcao;
%type <nodeExpr>                        parametro;
%type <nodeCallFunc>                    chamada_de_funcao;
%type <localArmazenamento>              local_de_armazenamento;
%type <comando>                         comando;
%type <arcFunc>                         arg;
%type <arcFuncs>                        lista_args;
%type <modificador>                     modificador;
%type <nodeExpr>                        expr;
%type <nodeBinOp>                       expressao_logica;
%type <nodeBinOp>                       expressao_relacional;
%type <nodeBinOp>                       expressao_aritmetica;
%type <literal>                         literal;
%type <tipoConstantesType>              tipo_constantes;
%type <argRegistros>                    criacao_de_registro;
%type <listaExpr>                       lista_expr;
%type <listaExpr>                       lista_parametros;

/* Tokens */

%token              TOK_EOF 0       "end of file"
%token			        EOL		          "end of line"
%token <integerVal> TIPOINTEIRO		  "tipo inteiro"
%token <doubleVal> 	TIPOREAL		    "tipo real"
%token <stringVal>  TIPOCADEIA      "tipo cadeia"
%token <stringVal> 	IDENTIFICADOR   "identificador"

/* Palavras reservadas */
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

/* Simbolos */
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

/* Raiz do programa */

program : lista_declaracao_de_tipo lista_declaracao_de_globais lista_declaracao_de_funcao acao {ast_root = new Programa($1, $2, $3, $4);} 
 
/* Declaração de tipos */

lista_declaracao_de_tipo:                   {}
  | TIPO DOISPONTOS lista_declaracao_tipo   {$$ = $3;} // ver

lista_declaracao_tipo: declaracao_tipo      {$$ = DeclaracaoTipoVetor(*$1, NULL);}
  | declaracao_tipo lista_declaracao_tipo   {$$ = DeclaracaoTipoVetor(*$1, $2);}

declaracao_tipo: IDENTIFICADOR IGUAL descritor_tipo   {$$ = new DeclaracaoTipo(*$1, *$3);}

descritor_tipo: IDENTIFICADOR                                     {$$ = new DescritorTipo(*$1, NULL, NULL, "", "identificador");}
  | ABRECHAVE tipo_campos FECHACHAVE                              {$$ = new DescritorTipo("", $2, NULL, "", "registro");}
  | ABRECOLCHETE tipo_constantes FECHACOLCHETE DE IDENTIFICADOR   {$$ = new DescritorTipo("", NULL, $2, *$5, "vetor");}

tipo_campos: tipo_campo VIRGULA tipo_campos {$$ = TipoCamposVetor(*$1, $3);}
  | tipo_campo                              {$$ = TipoCamposVetor(*$1, NULL);}

tipo_campo: IDENTIFICADOR DOISPONTOS IDENTIFICADOR  {$$ = new TipoCampos(*$1, *$3);}

tipo_constantes: TIPOINTEIRO              {$$ = TipoConstantes($1, NULL);}
  | TIPOINTEIRO VIRGULA tipo_constantes   {$$ = TipoConstantes($1, $3);}

/* Declaração de variáveis */

lista_declaracao_de_globais:                      {}
  | GLOBAL DOISPONTOS lista_declaracao_variavel   {$$ = $3;}

lista_declaracao_variavel: declaracao_variavel     {$$ = DeclaracaoVarVetor(*$1, NULL);}
  | declaracao_variavel lista_declaracao_variavel  {$$ = DeclaracaoVarVetor(*$1, $2);}

declaracao_variavel: IDENTIFICADOR DOISPONTOS IDENTIFICADOR ATRIBUICAO expr   {$$ = new DeclaracaoVar(*$1, *$3, *$5); }

criacao_de_registro: campos             {$$ = ArgRegistroVetor(*$1, NULL);}
  | campos VIRGULA criacao_de_registro  {$$ = ArgRegistroVetor(*$1, $3);}

campos: IDENTIFICADOR IGUAL expr {$$ = new ArgRegistro(*$1, *$3); }

/* Declaração de funções */

lista_declaracao_de_funcao:                     {}
  | FUNCAO DOISPONTOS lista_declaracao_funcao   {$$ = $3;}

lista_declaracao_funcao: declaracao_funcao      {$$ = DeclaracaoFuncVetor(*$1, NULL);}
  | declaracao_funcao lista_declaracao_funcao   {$$ = DeclaracaoFuncVetor(*$1, $2);}

declaracao_funcao: IDENTIFICADOR ABREPARENTESE lista_args FECHAPARENTESE IGUAL corpo            {$$ = new AbstractDeclacaoFuncao(*$1, $3, "", $6, "procedimento");}
  | IDENTIFICADOR ABREPARENTESE lista_args FECHAPARENTESE DOISPONTOS IDENTIFICADOR IGUAL corpo  {$$ = new AbstractDeclacaoFuncao(*$1, $3, *$6, $8, "funcao");}

lista_args: {}
  | arg                      {$$ = ArgFuncVetor(*$1, NULL);}
  | arg VIRGULA lista_args   {$$ = ArgFuncVetor(*$1, $3);}

arg: modificador IDENTIFICADOR DOISPONTOS IDENTIFICADOR {$$ = new ArgFunc(*$1, *$2, *$4);}

modificador: VALOR  {$$ = $1;}
  | REF             {$$ = $1;}

corpo: declaracoes_de_locais acao {$$ = new Corpo($1, $2);}

declaracoes_de_locais:                          {}
  | LOCAL DOISPONTOS lista_declaracao_variavel  {$$ = $3;}

/* Ação */

acao: ACAO DOISPONTOS lista_comandos {$$ = $3;} 

/* Comandos */

lista_comandos: comando                   {$$ = ComandosVetor(*$1, NULL);}
  | comando PONTOVIRGULA lista_comandos   {$$ = ComandosVetor(*$1, $3);}

comando: local_de_armazenamento ATRIBUICAO expr                      {$$ = new Comando(new ComandoAtribuicao($1, $3), NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, std::string("atribuicao")); }
  | chamada_de_funcao                                                {$$ = new Comando(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, $1, "chamada_func"); }
  | SE expr VERDADEIRO lista_comandos FSE                            {$$ = new Comando(NULL, new ComandoIf(*$2, $4), NULL, NULL, NULL , NULL ,NULL, NULL, NULL, "if"); }
  | SE expr VERDADEIRO lista_comandos FALSO lista_comandos FSE       {$$ = new Comando(NULL, NULL, new ComandoIfElse(*$2, $4, $6), NULL, NULL, NULL, NULL, NULL, NULL, "ifelse"); }
  | PARA IDENTIFICADOR DE expr LIMITE expr FACA lista_comandos FPARA {$$ = new Comando(NULL, NULL, NULL, new ComandoFor(*$2, *$4, *$6, $8), NULL, NULL, NULL, NULL, NULL, "for"); }
  | ENQUANTO expr FACA lista_comandos FENQUANTO                      {$$ = new Comando(NULL, NULL, NULL, NULL, new ComandoWhile(*$2, $4), NULL, NULL, NULL, NULL, "while"); }
  | PARE                                                             {$$ = new Comando(NULL, NULL, NULL, NULL, NULL, new ComandoPare(), NULL, NULL, NULL, "pare"); }
  | CONTINUE                                                         {$$ = new Comando(NULL, NULL, NULL, NULL, NULL, NULL, new ComandoContinue(), NULL, NULL, "continue"); }
  | RETORNE expr                                                     {$$ = new Comando(NULL, NULL, NULL, NULL, NULL, NULL, NULL, new ComandoRetorne(*$2), NULL, "retorne"); }

local_de_armazenamento: IDENTIFICADOR                             { $$ = new LocalArmazenamento(NULL, NULL, NULL, new LocalIdentificador(*$1), "local_identificador"); }
  | local_de_armazenamento PONTO IDENTIFICADOR                    {$$ = new LocalArmazenamento($1, new LocalRegistro(*$3), NULL, NULL, "registro"); }
  | local_de_armazenamento ABRECOLCHETE lista_expr FECHACOLCHETE  {$$ = new LocalArmazenamento($1, NULL, new LocalVetor($3), NULL, "vetor"); }

lista_expr: expr              {$$ = ExprVetor(*$1, NULL);}
  | expr VIRGULA lista_expr   {$$ = ExprVetor(*$1, $3);}

chamada_de_funcao: IDENTIFICADOR ABREPARENTESE lista_parametros FECHAPARENTESE {$$ = new NodeCallFunc(*$1, $3); } 

lista_parametros:                       {}
  | parametro                           {$$ = ExprVetor(*$1, NULL);}
  | parametro VIRGULA lista_parametros  {$$ = ExprVetor(*$1, $3);}

parametro: expr {$$ = $1; }

/* Expressões */

expr: expressao_logica                       {$$  = $1;}
  | expressao_relacional                     {$$  = $1;}
  | expressao_aritmetica                     {$$  = $1;}
  | ABRECHAVE criacao_de_registro FECHACHAVE {$$ = new NodeExpr("criacao_reg", new ListArgRegistro($2), NULL, NULL, "", NULL, NULL, NULL, NULL, NULL);}
  | NULO                                     {$$ = new NodeExpr("nulo", NULL, NULL, NULL, "", NULL, NULL, NULL, NULL, NULL);} 
  | ABREPARENTESE expr FECHAPARENTESE        {$$ = new NodeExpr("expr_paren", NULL, NULL, NULL, "", NULL, $2, NULL, NULL ,NULL);} 
  | chamada_de_funcao                        {$$ = new NodeExpr("chamada_func", NULL, NULL, NULL, "", NULL, NULL, NULL, $1, NULL);}
  | local_de_armazenamento                   {$$ = new NodeExpr("local_armaz", NULL, NULL, NULL, "", NULL, NULL, $1, NULL, NULL); } 
  | literal                                  { $$ = $1;} 

expressao_logica: expr E expr {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, "&", $3, NULL, NULL, NULL, NULL); }
  | expr OU expr              {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, "|", $3, NULL, NULL, NULL, NULL); }

expressao_relacional: expr IGUALDADE expr   {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, "==", $3, NULL, NULL, NULL, NULL); }
  | expr DIFERENTE expr                     {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, "!=", $3, NULL, NULL, NULL, NULL); }
  | expr MAIOR expr                         {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, ">", $3, NULL, NULL, NULL, NULL); }
  | expr MAIORIGUAL expr                    {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, ">=", $3, NULL, NULL, NULL, NULL); }
  | expr MENOR expr                         {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, "<", $3, NULL, NULL, NULL, NULL); }
  | expr MENORIGUAL expr                    {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, "<=", $3, NULL, NULL, NULL, NULL); }

expressao_aritmetica: expr ADICAO expr      {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, "+", $3, NULL, NULL, NULL, NULL); } 
  | expr SUBTRACAO expr                     {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, "-", $3, NULL, NULL, NULL, NULL); } 
  | expr MULTIPLICACAO expr                 {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, "*", $3, NULL, NULL, NULL, NULL); } 
  | expr DIVISAO expr                       {$$ = new NodeExpr("op_binaria", NULL, NULL, $1, "/", $3, NULL, NULL, NULL, NULL); } 

literal: TIPOINTEIRO {$$ = new NodeExpr("literal_int", NULL, new Literal("inteiro", $1, "", 0.0), NULL, "", NULL, NULL, NULL, NULL, NULL);}
  | TIPOREAL         {$$ = new NodeExpr("literal_real", NULL, new Literal("real", -1, "", $1), NULL, "", NULL, NULL, NULL, NULL, NULL);}
  | TIPOCADEIA       {$$ = new NodeExpr("literal_cadeia", NULL, new Literal("cadeia", -1, *$1, -1), NULL, "", NULL, NULL, NULL, NULL, NULL);}
%%

namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
