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

%option case-insensitive

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


[0-9]+ {
     yylval->integerVal = atoi(yytext);
     return token::TIPOINTEIRO;
 }

[0-9]+"."[0-9]* {
  yylval->doubleVal = atof(yytext);
  return token::TIPOREAL;
}


pare { return token::PARE; }

continue { return token::CONTINUE; }

para { return token::PARA; }

fpara { return token::FPARA; }

enquanto { return token::ENQUANTO; }

fenquanto { return token::FENQUANTO; }

fa(ç|Ç)a { return token::FACA; }

se { return token::SE; }

fse { return token::FSE; }

verdadeiro { return token::VERDADEIRO; }

falso { return token::FALSO; }

tipo { return token::TIPO; }

de { return token::DE; }

limite { return token::LIMITE; }

global { return token::GLOBAL; }

local { return token::LOCAL; }

valor { return token::VALOR; }

ref { return token::REF; }

retorne { return token::RETORNE; }

nulo { return token::NULO; }

a(ç|Ç)(ã|Ã)o { return token::ACAO; }

fun(ç|Ç)(ã|Ã)o { return token::FUNCAO; }


"," { return token::VIRGULA; }

";" { return token::PONTOVIRGULA; } 

"(" { return token::ABREPARENTESE; } 

")" { return token::FECHAPARENTESE; } 

"[" { return token::ABRECOLCHETE; } 

"]" { return token::FECHACOLCHETE; } 

"{" { return token::ABRECHAVE; } 

"}" { return token::FECHACHAVE; } 

"." { return token::PONTO; } 

"+" { return token::ADICAO; } 

"-" { return token::SUBTRACAO; } 

"*" { return token::MULTIPLICACAO; } 

"/" { return token::DIVISAO; } 

"==" { return token::IGUALDADE; } 

"!=" { return token::DIFERENTE; } 

"<" { return token::MENOR; } 

"<=" { return token::MENORIGUAL; } 

">" { return token::MAIOR; } 

">=" { return token::MAIORIGUAL; } 

"&" { return token::E; } 

"|" { return token::OU; } 

":=" { return token::ATRIBUICAO; } 

":" { return token::DOISPONTOS; } 

"=" { return token::IGUAL; } 

[A-Za-z][A-Za-z0-9_]* {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::IDENTIFICADOR;
}

\" { strcpy(string_buffer, ""); BEGIN(cadeia); }
<cadeia>\"      { yylval->stringVal = new std::string(string_buffer, strlen(string_buffer)); 
                  BEGIN(INITIAL); 
                  return token::TIPOCADEIA; }
<cadeia>[^\"]+ { strcat(string_buffer, yytext); }

"/*" { BEGIN(comentario); }
<comentario>"*/"   { BEGIN(INITIAL); }
<comentario>[^*/]  {}

{tab}+

{blank} { STEP(); }

{eol}  { LINE(yyleng); }

.             {
                std::cerr << *driver.location_ << " Token não esperado : "
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
