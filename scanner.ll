%{ /* -*- C++ -*- */

#include "parser.hh"
#include "scanner.hh"
#include "driver.hh"
#include <typeinfo>


/*  Defines some macros to update locations */
#define STEP() do {driver.location_->step();} while (0)
#define COL(col) driver.location_->columns(col)
#define LINE(line) do {driver.location_->lines(line);} while (0)
#define YY_USER_ACTION COL(yyleng);

/* import the parser's token type into a local typedef */
typedef Simples::Parser::token token;
typedef Simples::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::TOK_EOF

char string_buffer[1024]; /* auxilia na constante de cadeia */

%}

/*** Flex Declarations and Options ***/

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug
/* enable c++ scanner class generation */
%option c++
/* we don’t need yywrap */
%option noyywrap
/* you should not expect to be able to use the program interactively */
%option never-interactive
/* provide the global variable yylineno */
%option yylineno
/* do not fabricate input text to be scanned */
%option nounput
/* the manual says "somewhat more optimized" */
%option batch
/* change the name of the scanner class. results in "SimplesFlexLexer" */
%option prefix="Simples"

%x comentario
%x cadeia

/*
%option stack
*/

/* Abbreviations.  */

blank   [ \t]+
eol     [\n\r]+
tab     [\t]
double_quotes ["]

%%

 /* The following paragraph suffices to track locations accurately. Each time
 yylex is invoked, the begin position is moved onto the end position. */
%{
  STEP();
%}

 /*** BEGIN EXAMPLE - Change the example lexer rules below ***/

[0-9]+ {
     yylval->integerVal = atoi(yytext);
     return token::INTEIRO;
 }

[0-9]+"."[0-9]* {
  yylval->doubleVal = atof(yytext);
  return token::REAL;
}

pare {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::PARE;
}

continue {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::CONTINUE;
}

para {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::PARA;
}

enquanto {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::ENQUANTO;
}

faça {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FACA;
}

fun {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FUN;
}

se {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::SE;
}

verdadeiro {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::VERDADEIRO;
}

falso {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FALSO;
}

tipo {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::TIPO;
}

de {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::DE;
}

limite {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::LIMITE;
}

var {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::VAR;
}

inteiro {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::INTEIRO;
}

real {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::REAL;
}

cadeia {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::CADEIA;
}

ref {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::REF;
}

retorne {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::RETORNE;
}

nulo {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::NULO;
}

início {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::INICIO;
}

fim {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FIM;
}

"," {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::VIRGULA;
}

":" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::DOISPONTOS;
} 

";" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::PONTOVIRGULA;
} 

"(" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::ABREPARENTESE;
} 

")" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FECHAPARENTESE;
} 

"[" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::ABRECOLCHETE;
} 

"]" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FECHACOLCHETE;
} 

"{" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::ABRECHAVE;
} 

"}" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FECHACHAVE;
} 

"." {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::PONTO;
} 

"+" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::ADICAO;
} 

"-" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::SUBTRACAO;
} 

"*" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::MULTIPLICACAO;
} 

"/" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::DIVISAO;
} 

"<>" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::DIFERENTE;
} 

"<" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::MENOR;
} 

"<=" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::MENORIGUAL;
} 

">" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::MAIOR;
} 

">=" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::MAIORIGUAL;
} 

"&" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::E;
} 

"|" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::OU;
} 

":=" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::ATRIBUICAO;
} 

"=" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::IGUAL;
} 

"==" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::IGUALDADE;
} 

"?" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::INTERROGACAO;
} 

[A-Za-z][A-Za-z0-9_,.-]* {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::IDENTIFICADOR;
}

\" { 
strcpy(string_buffer, ""); BEGIN(cadeia); }
<cadeia>\" { 
  yylval->stringVal = new std::string(string_buffer, strlen(string_buffer)); 
  BEGIN(INITIAL); 
  return token::TIPOCADEIA;}
<cadeia>[^\"]+ {
  strcat(string_buffer, yytext); }

"/*"            { BEGIN(comentario); }
<comentario>"*/" { BEGIN(INITIAL); }
<comentario>[^*/] {}

{tab}+

{blank} { STEP(); }

{eol}  { LINE(yyleng); }

.             {
                std::cerr << *driver.location_ << " Unexpected token : "
                                              << *yytext << std::endl;
                driver.error_ = (driver.error_ == 127 ? 127
                                : driver.error_ + 1);
                STEP ();
              }

%%

/* CUSTOM C++ CODE */

namespace Simples {

  Scanner::Scanner() : SimplesFlexLexer() {}

  Scanner::~Scanner() {}

  void Scanner::set_debug(bool b) {
    yy_flex_debug = b;
  }
}

#ifdef yylex
# undef yylex
#endif

int SimplesFlexLexer::yylex()
{
  std::cerr << "call parsepitFlexLexer::yylex()!" << std::endl;
  return 0;
}
