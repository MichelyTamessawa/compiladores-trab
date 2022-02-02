%{ /* -*- C++ -*- */

#include "parser.hh"
#include "scanner.hh"
#include "driver.hh"

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

%}

/*** Flex Declarations and Options ***/

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug
/* enable c++ scanner class generation */
%option c++
/* we don’t need yywrap */
%option noyywrap
%x comentario
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

pare|continue|para|enquanto|faça|fun|se|verdadeiro|falso|tipo|de|limite|var|inteiro|real|cadeia|ref|retorne|nulo|início|fim {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::PALAVRARESERVADA;
}

[A-Za-z][A-Za-z0-9_,.-]* {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::IDENTIFICADOR;
}

","|":"|";"|"("|")"|"["|"]"|"{"|"}"|"."|"+"|"-"|"*"|"/"|"<"|">"|"<"|"<="|">"|">="|"&"|"|"|":="|"="|"=="|"?" {
  yylval->charVal = &yytext[0];
  return token::SIMBOLO;
}

{double_quotes}[A-Za-z0-9_,.-]*{double_quotes} {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::CADEIA;
}

"/*"            { BEGIN(comentario); }
<comentario>"*/" { BEGIN(INITIAL); }
<comentario>.    { }
<comentario>\n   { }

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
