// A Bison parser, made by GNU Bison 3.7.6.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 5 "parser.yy"


/*** C++ Declarations ***/
#include "parser.hh"
#include "scanner.hh"
#define yylex driver.scanner_->yylex


#line 50 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"


#include "parser.hh"


// Unqualified %code blocks.
#line 27 "parser.yy"

  #include "arvore.hh"
  #include "semantic.hh"

  using namespace AST;


#line 65 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 58 "parser.yy"
namespace Simples {
#line 158 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"

  /// Build a parser object.
  Parser::Parser (Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: lista_declaracao_de_tipo lista_declaracao_de_globais lista_declaracao_de_funcao acao
#line 212 "parser.yy"
                                                                                               {ast_root = new Programa((yystack_[3].value.declaracoesTipo), (yystack_[2].value.declaracoesGlobais), (yystack_[1].value.declaracoesFuncao), (yystack_[0].value.acao));}
#line 625 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 3: // lista_declaracao_de_tipo: %empty
#line 216 "parser.yy"
                                            {}
#line 631 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 4: // lista_declaracao_de_tipo: "tipo" "dois pontos" lista_declaracao_tipo
#line 217 "parser.yy"
                                            {(yylhs.value.declaracoesTipo) = (yystack_[0].value.declaracoesTipo);}
#line 637 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 5: // lista_declaracao_tipo: declaracao_tipo
#line 219 "parser.yy"
                                            {(yylhs.value.declaracoesTipo) = DeclaracaoTipoVetor(*(yystack_[0].value.declaracaoTipo), NULL);}
#line 643 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 6: // lista_declaracao_tipo: declaracao_tipo lista_declaracao_tipo
#line 220 "parser.yy"
                                            {(yylhs.value.declaracoesTipo) = DeclaracaoTipoVetor(*(yystack_[1].value.declaracaoTipo), (yystack_[0].value.declaracoesTipo));}
#line 649 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 7: // declaracao_tipo: "identificador" "igual" descritor_tipo
#line 222 "parser.yy"
                                                      {(yylhs.value.declaracaoTipo) = new DeclaracaoTipo(*(yystack_[2].value.stringVal), *(yystack_[0].value.descritorTipo));}
#line 655 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 8: // descritor_tipo: "identificador"
#line 224 "parser.yy"
                                                                  {(yylhs.value.descritorTipo) = new DescritorTipo(*(yystack_[0].value.stringVal), NULL, NULL, "", "identificador");}
#line 661 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 9: // descritor_tipo: "abre chave" tipo_campos "fecha chave"
#line 225 "parser.yy"
                                                                  {(yylhs.value.descritorTipo) = new DescritorTipo("", (yystack_[1].value.tipoCampos), NULL, "", "registro");}
#line 667 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 10: // descritor_tipo: "abre colchete" tipo_constantes "fecha colchete" "de" "identificador"
#line 226 "parser.yy"
                                                                  {(yylhs.value.descritorTipo) = new DescritorTipo("", NULL, (yystack_[3].value.tipoConstantesType), *(yystack_[0].value.stringVal), "vetor");}
#line 673 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 11: // tipo_campos: tipo_campo "virgula" tipo_campos
#line 228 "parser.yy"
                                            {(yylhs.value.tipoCampos) = TipoCamposVetor(*(yystack_[2].value.tipoCampo), (yystack_[0].value.tipoCampos));}
#line 679 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 12: // tipo_campos: tipo_campo
#line 229 "parser.yy"
                                            {(yylhs.value.tipoCampos) = TipoCamposVetor(*(yystack_[0].value.tipoCampo), NULL);}
#line 685 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 13: // tipo_campo: "identificador" "dois pontos" "identificador"
#line 231 "parser.yy"
                                                    {(yylhs.value.tipoCampo) = new TipoCampos(*(yystack_[2].value.stringVal), *(yystack_[0].value.stringVal));}
#line 691 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 14: // tipo_constantes: "tipo inteiro"
#line 233 "parser.yy"
                                          {(yylhs.value.tipoConstantesType) = TipoConstantes((yystack_[0].value.integerVal), NULL);}
#line 697 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 15: // tipo_constantes: "tipo inteiro" "virgula" tipo_constantes
#line 234 "parser.yy"
                                          {(yylhs.value.tipoConstantesType) = TipoConstantes((yystack_[2].value.integerVal), (yystack_[0].value.tipoConstantesType));}
#line 703 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 16: // lista_declaracao_de_globais: %empty
#line 238 "parser.yy"
                                                  {}
#line 709 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 17: // lista_declaracao_de_globais: "global" "dois pontos" lista_declaracao_variavel
#line 239 "parser.yy"
                                                  {(yylhs.value.declaracoesGlobais) = (yystack_[0].value.declaracoesGlobais);}
#line 715 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 18: // lista_declaracao_variavel: declaracao_variavel
#line 241 "parser.yy"
                                                   {(yylhs.value.declaracoesGlobais) = DeclaracaoVarVetor(*(yystack_[0].value.declaracaoVar), NULL);}
#line 721 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 19: // lista_declaracao_variavel: declaracao_variavel lista_declaracao_variavel
#line 242 "parser.yy"
                                                   {(yylhs.value.declaracoesGlobais) = DeclaracaoVarVetor(*(yystack_[1].value.declaracaoVar), (yystack_[0].value.declaracoesGlobais));}
#line 727 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 20: // declaracao_variavel: "identificador" "dois pontos" "identificador" "atribuicao" expr
#line 244 "parser.yy"
                                                                              {(yylhs.value.declaracaoVar) = new DeclaracaoVar(*(yystack_[4].value.stringVal), *(yystack_[2].value.stringVal), *(yystack_[0].value.nodeExpr)); }
#line 733 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 21: // criacao_de_registro: campos
#line 246 "parser.yy"
                                        {(yylhs.value.argRegistros) = ArgRegistroVetor(*(yystack_[0].value.argRegistro), NULL);}
#line 739 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 22: // criacao_de_registro: campos "virgula" criacao_de_registro
#line 247 "parser.yy"
                                        {(yylhs.value.argRegistros) = ArgRegistroVetor(*(yystack_[2].value.argRegistro), (yystack_[0].value.argRegistros));}
#line 745 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 23: // campos: "identificador" "igual" expr
#line 249 "parser.yy"
                                 {(yylhs.value.argRegistro) = new ArgRegistro(*(yystack_[2].value.stringVal), *(yystack_[0].value.nodeExpr)); }
#line 751 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 24: // lista_declaracao_de_funcao: %empty
#line 253 "parser.yy"
                                                {}
#line 757 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 25: // lista_declaracao_de_funcao: "funcao" "dois pontos" lista_declaracao_funcao
#line 254 "parser.yy"
                                                {(yylhs.value.declaracoesFuncao) = (yystack_[0].value.declaracoesFuncao);}
#line 763 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 26: // lista_declaracao_funcao: declaracao_funcao
#line 256 "parser.yy"
                                                {(yylhs.value.declaracoesFuncao) = DeclaracaoFuncVetor(*(yystack_[0].value.declaracaoFuncao), NULL);}
#line 769 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 27: // lista_declaracao_funcao: declaracao_funcao lista_declaracao_funcao
#line 257 "parser.yy"
                                                {(yylhs.value.declaracoesFuncao) = DeclaracaoFuncVetor(*(yystack_[1].value.declaracaoFuncao), (yystack_[0].value.declaracoesFuncao));}
#line 775 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 28: // declaracao_funcao: "identificador" "abre parentese" lista_args "fecha parentese" "igual" corpo
#line 259 "parser.yy"
                                                                                                {(yylhs.value.declaracaoFuncao) = new AbstractDeclacaoFuncao(*(yystack_[5].value.stringVal), (yystack_[3].value.arcFuncs), "", (yystack_[0].value.corpo), "procedimento");}
#line 781 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 29: // declaracao_funcao: "identificador" "abre parentese" lista_args "fecha parentese" "dois pontos" "identificador" "igual" corpo
#line 260 "parser.yy"
                                                                                                {(yylhs.value.declaracaoFuncao) = new AbstractDeclacaoFuncao(*(yystack_[7].value.stringVal), (yystack_[5].value.arcFuncs), *(yystack_[2].value.stringVal), (yystack_[0].value.corpo), "funcao");}
#line 787 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 30: // lista_args: %empty
#line 262 "parser.yy"
            {}
#line 793 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 31: // lista_args: arg
#line 263 "parser.yy"
                             {(yylhs.value.arcFuncs) = ArgFuncVetor(*(yystack_[0].value.arcFunc), NULL);}
#line 799 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 32: // lista_args: arg "virgula" lista_args
#line 264 "parser.yy"
                             {(yylhs.value.arcFuncs) = ArgFuncVetor(*(yystack_[2].value.arcFunc), (yystack_[0].value.arcFuncs));}
#line 805 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 33: // arg: modificador "identificador" "dois pontos" "identificador"
#line 266 "parser.yy"
                                                        {(yylhs.value.arcFunc) = new ArgFunc(*(yystack_[3].value.modificador), *(yystack_[2].value.stringVal), *(yystack_[0].value.stringVal));}
#line 811 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 34: // modificador: "valor"
#line 268 "parser.yy"
                    {(yylhs.value.modificador) = (yystack_[0].value.stringVal);}
#line 817 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 35: // modificador: "ref"
#line 269 "parser.yy"
                    {(yylhs.value.modificador) = (yystack_[0].value.stringVal);}
#line 823 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 36: // corpo: declaracoes_de_locais acao
#line 271 "parser.yy"
                                  {(yylhs.value.corpo) = new Corpo((yystack_[1].value.declaracoesVar), (yystack_[0].value.acao));}
#line 829 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 37: // declaracoes_de_locais: %empty
#line 273 "parser.yy"
                                                {}
#line 835 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 38: // declaracoes_de_locais: "local" "dois pontos" lista_declaracao_variavel
#line 274 "parser.yy"
                                                {(yylhs.value.declaracoesVar) = (yystack_[0].value.declaracoesGlobais);}
#line 841 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 39: // acao: "ação" "dois pontos" lista_comandos
#line 278 "parser.yy"
                                     {(yylhs.value.acao) = (yystack_[0].value.acao);}
#line 847 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 40: // lista_comandos: comando
#line 282 "parser.yy"
                                          {(yylhs.value.acao) = ComandosVetor(*(yystack_[0].value.comando), NULL);}
#line 853 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 41: // lista_comandos: comando "ponto virgula" lista_comandos
#line 283 "parser.yy"
                                          {(yylhs.value.acao) = ComandosVetor(*(yystack_[2].value.comando), (yystack_[0].value.acao));}
#line 859 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 42: // comando: local_de_armazenamento "atribuicao" expr
#line 285 "parser.yy"
                                                                     {(yylhs.value.comando) = new Comando(new ComandoAtribuicao((yystack_[2].value.localArmazenamento), (yystack_[0].value.nodeExpr)), NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, std::string("atribuicao")); }
#line 865 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 43: // comando: chamada_de_funcao
#line 286 "parser.yy"
                                                                     {(yylhs.value.comando) = new Comando(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, (yystack_[0].value.nodeCallFunc), "chamada_func"); }
#line 871 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 44: // comando: "se" expr "verdadeiro" lista_comandos "fse"
#line 287 "parser.yy"
                                                                     {(yylhs.value.comando) = new Comando(NULL, new ComandoIf(*(yystack_[3].value.nodeExpr), (yystack_[1].value.acao)), NULL, NULL, NULL , NULL ,NULL, NULL, NULL, "if"); }
#line 877 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 45: // comando: "se" expr "verdadeiro" lista_comandos "falso" lista_comandos "fse"
#line 288 "parser.yy"
                                                                     {(yylhs.value.comando) = new Comando(NULL, NULL, new ComandoIfElse(*(yystack_[5].value.nodeExpr), (yystack_[3].value.acao), (yystack_[1].value.acao)), NULL, NULL, NULL, NULL, NULL, NULL, "ifelse"); }
#line 883 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 46: // comando: "para" "identificador" "de" expr "limite" expr "faca" lista_comandos "fpara"
#line 289 "parser.yy"
                                                                     {(yylhs.value.comando) = new Comando(NULL, NULL, NULL, new ComandoFor(*(yystack_[7].value.stringVal), *(yystack_[5].value.nodeExpr), *(yystack_[3].value.nodeExpr), (yystack_[1].value.acao)), NULL, NULL, NULL, NULL, NULL, "for"); }
#line 889 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 47: // comando: "enquanto" expr "faca" lista_comandos "fenquanto"
#line 290 "parser.yy"
                                                                     {(yylhs.value.comando) = new Comando(NULL, NULL, NULL, NULL, new ComandoWhile(*(yystack_[3].value.nodeExpr), (yystack_[1].value.acao)), NULL, NULL, NULL, NULL, "while"); }
#line 895 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 48: // comando: "pare"
#line 291 "parser.yy"
                                                                     {(yylhs.value.comando) = new Comando(NULL, NULL, NULL, NULL, NULL, new ComandoPare(), NULL, NULL, NULL, "pare"); }
#line 901 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 49: // comando: "continue"
#line 292 "parser.yy"
                                                                     {(yylhs.value.comando) = new Comando(NULL, NULL, NULL, NULL, NULL, NULL, new ComandoContinue(), NULL, NULL, "continue"); }
#line 907 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 50: // comando: "retorne" expr
#line 293 "parser.yy"
                                                                     {(yylhs.value.comando) = new Comando(NULL, NULL, NULL, NULL, NULL, NULL, NULL, new ComandoRetorne(*(yystack_[0].value.nodeExpr)), NULL, "retorne"); }
#line 913 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 51: // local_de_armazenamento: "identificador"
#line 295 "parser.yy"
                                                                  { (yylhs.value.localArmazenamento) = new LocalArmazenamento(NULL, NULL, NULL, new LocalIdentificador(*(yystack_[0].value.stringVal)), "local_identificador"); }
#line 919 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 52: // local_de_armazenamento: local_de_armazenamento "ponto" "identificador"
#line 296 "parser.yy"
                                                                  {(yylhs.value.localArmazenamento) = new LocalArmazenamento((yystack_[2].value.localArmazenamento), new LocalRegistro(*(yystack_[0].value.stringVal)), NULL, NULL, "registro"); }
#line 925 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 53: // local_de_armazenamento: local_de_armazenamento "abre colchete" lista_expr "fecha colchete"
#line 297 "parser.yy"
                                                                  {(yylhs.value.localArmazenamento) = new LocalArmazenamento((yystack_[3].value.localArmazenamento), NULL, new LocalVetor((yystack_[1].value.listaExpr)), NULL, "vetor"); }
#line 931 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 54: // lista_expr: expr
#line 299 "parser.yy"
                              {(yylhs.value.listaExpr) = ExprVetor(*(yystack_[0].value.nodeExpr), NULL);}
#line 937 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 55: // lista_expr: expr "virgula" lista_expr
#line 300 "parser.yy"
                              {(yylhs.value.listaExpr) = ExprVetor(*(yystack_[2].value.nodeExpr), (yystack_[0].value.listaExpr));}
#line 943 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 56: // chamada_de_funcao: "identificador" "abre parentese" lista_parametros "fecha parentese"
#line 302 "parser.yy"
                                                                               {(yylhs.value.nodeCallFunc) = new NodeCallFunc(*(yystack_[3].value.stringVal), (yystack_[1].value.listaExpr)); }
#line 949 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 57: // lista_parametros: %empty
#line 304 "parser.yy"
                                        {}
#line 955 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 58: // lista_parametros: parametro
#line 305 "parser.yy"
                                        {(yylhs.value.listaExpr) = ExprVetor(*(yystack_[0].value.nodeExpr), NULL);}
#line 961 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 59: // lista_parametros: parametro "virgula" lista_parametros
#line 306 "parser.yy"
                                        {(yylhs.value.listaExpr) = ExprVetor(*(yystack_[2].value.nodeExpr), (yystack_[0].value.listaExpr));}
#line 967 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 60: // parametro: expr
#line 308 "parser.yy"
                {(yylhs.value.nodeExpr) = (yystack_[0].value.nodeExpr); }
#line 973 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 61: // expr: expressao_logica
#line 312 "parser.yy"
                                             {(yylhs.value.nodeExpr)  = (yystack_[0].value.nodeBinOp);}
#line 979 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 62: // expr: expressao_relacional
#line 313 "parser.yy"
                                             {(yylhs.value.nodeExpr)  = (yystack_[0].value.nodeBinOp);}
#line 985 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 63: // expr: expressao_aritmetica
#line 314 "parser.yy"
                                             {(yylhs.value.nodeExpr)  = (yystack_[0].value.nodeBinOp);}
#line 991 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 64: // expr: "abre chave" criacao_de_registro "fecha chave"
#line 315 "parser.yy"
                                             {(yylhs.value.nodeExpr) = new NodeExpr("criacao_reg", new ListArgRegistro((yystack_[1].value.argRegistros)), NULL, NULL, "", NULL, NULL, NULL, NULL, NULL);}
#line 997 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 65: // expr: "nulo"
#line 316 "parser.yy"
                                             {(yylhs.value.nodeExpr) = new NodeExpr("nulo", NULL, NULL, NULL, "", NULL, NULL, NULL, NULL, NULL);}
#line 1003 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 66: // expr: "abre parentese" expr "fecha parentese"
#line 317 "parser.yy"
                                             {(yylhs.value.nodeExpr) = new NodeExpr("expr_paren", NULL, NULL, NULL, "", NULL, (yystack_[1].value.nodeExpr), NULL, NULL ,NULL);}
#line 1009 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 67: // expr: chamada_de_funcao
#line 318 "parser.yy"
                                             {(yylhs.value.nodeExpr) = new NodeExpr("chamada_func", NULL, NULL, NULL, "", NULL, NULL, NULL, (yystack_[0].value.nodeCallFunc), NULL);}
#line 1015 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 68: // expr: local_de_armazenamento
#line 319 "parser.yy"
                                             {(yylhs.value.nodeExpr) = new NodeExpr("local_armaz", NULL, NULL, NULL, "", NULL, NULL, (yystack_[0].value.localArmazenamento), NULL, NULL); }
#line 1021 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 69: // expr: literal
#line 320 "parser.yy"
                                             { (yylhs.value.nodeExpr) = (yystack_[0].value.literal);}
#line 1027 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 70: // expressao_logica: expr "e" expr
#line 322 "parser.yy"
                              {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), "&", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1033 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 71: // expressao_logica: expr "ou" expr
#line 323 "parser.yy"
                              {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), "|", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1039 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 72: // expressao_relacional: expr "igualdade" expr
#line 325 "parser.yy"
                                            {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), "==", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1045 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 73: // expressao_relacional: expr "diferente" expr
#line 326 "parser.yy"
                                            {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), "!=", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1051 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 74: // expressao_relacional: expr "maior" expr
#line 327 "parser.yy"
                                            {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), ">", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1057 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 75: // expressao_relacional: expr "maior igual" expr
#line 328 "parser.yy"
                                            {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), ">=", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1063 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 76: // expressao_relacional: expr "menor" expr
#line 329 "parser.yy"
                                            {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), "<", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1069 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 77: // expressao_relacional: expr "menor igual" expr
#line 330 "parser.yy"
                                            {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), "<=", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1075 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 78: // expressao_aritmetica: expr "adicao" expr
#line 332 "parser.yy"
                                            {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), "+", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1081 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 79: // expressao_aritmetica: expr "subtracao" expr
#line 333 "parser.yy"
                                            {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), "-", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1087 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 80: // expressao_aritmetica: expr "multiplicacao" expr
#line 334 "parser.yy"
                                            {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), "*", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1093 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 81: // expressao_aritmetica: expr "divisao" expr
#line 335 "parser.yy"
                                            {(yylhs.value.nodeBinOp) = new NodeExpr("op_binaria", NULL, NULL, (yystack_[2].value.nodeExpr), "/", (yystack_[0].value.nodeExpr), NULL, NULL, NULL, NULL); }
#line 1099 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 82: // literal: "tipo inteiro"
#line 337 "parser.yy"
                     {(yylhs.value.literal) = new NodeExpr("literal_int", NULL, new Literal("inteiro", (yystack_[0].value.integerVal), "", 0.0), NULL, "", NULL, NULL, NULL, NULL, NULL);}
#line 1105 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 83: // literal: "tipo real"
#line 338 "parser.yy"
                     {(yylhs.value.literal) = new NodeExpr("literal_real", NULL, new Literal("real", -1, "", (yystack_[0].value.doubleVal)), NULL, "", NULL, NULL, NULL, NULL, NULL);}
#line 1111 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;

  case 84: // literal: "tipo cadeia"
#line 339 "parser.yy"
                     {(yylhs.value.literal) = new NodeExpr("literal_cadeia", NULL, new Literal("cadeia", -1, *(yystack_[0].value.stringVal), -1), NULL, "", NULL, NULL, NULL, NULL, NULL);}
#line 1117 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"
    break;


#line 1121 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -60;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      -6,   -15,    24,     4,    22,   -60,     8,    12,   -19,   -60,
      22,    58,    36,    43,     1,   -60,    41,   -60,    58,    66,
      44,   -60,   -60,    70,    69,   -60,    71,   -60,    46,   -60,
      66,     2,    47,    45,    53,    61,    55,    48,    23,   -60,
      68,   -60,   -60,    95,     0,     0,     0,   -60,    72,   -17,
     -60,    70,    83,    98,   -60,    69,     0,   -60,   -60,    74,
      76,   102,     0,    90,   -60,   -60,   -60,   -60,     0,   104,
     -20,   -60,   103,   -60,   -60,   -60,   -60,   150,   128,     2,
       0,   105,     0,   -60,   107,   -60,   -60,   128,   -28,    23,
      84,    82,    88,   128,     0,   202,    67,    81,    91,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,   -60,    86,   184,   -60,   128,   -60,   116,
     101,   -60,   118,   -60,     0,   162,   -60,     0,   -60,   104,
     113,     9,     9,   -60,   -60,     3,     3,     3,     3,     3,
       3,    15,    15,     5,   -60,     0,    77,   108,   -60,    43,
     -60,   -60,     0,   128,   -60,   -60,   -60,     2,   -60,   101,
      58,   -60,   115,   117,   -60,   -60,     2,   -60,   121,   -60
  };

  const signed char
  Parser::yydefact_[] =
  {
       3,     0,     0,    16,     0,     1,     0,    24,     0,     4,
       5,     0,     0,     0,     0,     6,     0,    17,    18,     0,
       0,     2,     8,     0,     0,     7,     0,    19,     0,    25,
      26,     0,    14,     0,     0,     0,    12,     0,    30,    27,
      51,    48,    49,     0,     0,     0,     0,    39,    40,     0,
      43,     0,     0,     0,     9,     0,     0,    34,    35,     0,
      31,     0,    57,     0,    82,    83,    84,    65,     0,     0,
      68,    67,     0,    61,    62,    63,    69,     0,    50,     0,
       0,     0,     0,    15,     0,    13,    11,    20,     0,    30,
       0,     0,    58,    60,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,    54,    52,    42,    10,     0,
      37,    32,     0,    56,    57,     0,    66,     0,    64,     0,
       0,    78,    79,    80,    81,    72,    73,    76,    77,    74,
      75,    70,    71,     0,    53,     0,     0,     0,    28,     0,
      33,    59,     0,    23,    22,    47,    44,     0,    55,    37,
       0,    36,     0,     0,    29,    38,     0,    45,     0,    46
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -60,   -60,   -60,   124,   -60,   -60,    80,   -60,    89,   -60,
     -18,   -60,    51,   -60,   -60,   111,   -60,    92,   -60,   -60,
      25,   -60,    33,   -59,   -60,   -30,    40,   -29,    62,   -60,
     -14,   -60,   -60,   -60,   -60
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     2,     3,     9,    10,    25,    35,    36,    33,     7,
      17,    18,    97,    98,    13,    29,    30,    59,    60,    61,
     148,   149,    21,    47,    48,    70,   114,    71,    91,    92,
      93,    73,    74,    75,    76
  };

  const unsigned char
  Parser::yytable_[] =
  {
      27,    49,    50,   119,    64,    65,    66,    40,    22,    40,
      41,    42,    43,     1,    44,    80,     4,    45,    80,    81,
     113,   156,    81,   157,     5,   120,     6,    67,    46,     8,
      72,    77,    78,    68,    14,    82,    23,    69,    24,    11,
     130,    12,    87,   100,   101,   102,   103,    57,    58,    49,
      50,   102,   103,   143,    95,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,    16,   115,    19,   117,    49,
      50,    20,    26,    28,    32,    31,    34,    51,    37,    38,
     125,    52,    49,    50,    53,    55,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   163,    54,
      56,    62,    63,    84,    79,    85,    89,   168,    88,    90,
      94,    96,   116,   153,   118,   122,   123,    99,   124,   128,
     127,   129,   144,   146,   147,   150,   155,    49,    50,   166,
     159,   115,   169,   167,    15,    86,    49,    50,   162,   160,
      83,    39,   165,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     154,   121,   161,   152,   164,   158,   151,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   126,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111
  };

  const short
  Parser::yycheck_[] =
  {
      18,    31,    31,    31,     4,     5,     6,     7,     7,     7,
       8,     9,    10,    19,    12,    35,    31,    15,    35,    39,
      79,    16,    39,    18,     0,    53,    22,    27,    26,     7,
      44,    45,    46,    33,    53,    52,    35,    37,    37,    31,
      99,    29,    56,    40,    41,    42,    43,    24,    25,    79,
      79,    42,    43,   112,    68,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,     7,    80,    31,    82,    99,
      99,    28,    31,     7,     4,    31,     7,    30,     7,    33,
      94,    36,   112,   112,    31,    30,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   157,    38,
      52,    33,     7,    20,    32,     7,    30,   166,    34,     7,
      20,     7,     7,   127,     7,    31,    34,    14,    30,    38,
      53,    30,    36,     7,    23,     7,    13,   157,   157,    14,
      53,   145,    11,    16,    10,    55,   166,   166,   152,    31,
      51,    30,   160,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    17,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
     129,    89,   149,    21,   159,   145,   124,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    19,    55,    56,    31,     0,    22,    63,     7,    57,
      58,    31,    29,    68,    53,    57,     7,    64,    65,    31,
      28,    76,     7,    35,    37,    59,    31,    64,     7,    69,
      70,    31,     4,    62,     7,    60,    61,     7,    33,    69,
       7,     8,     9,    10,    12,    15,    26,    77,    78,    79,
      81,    30,    36,    31,    38,    30,    52,    24,    25,    71,
      72,    73,    33,     7,     4,     5,     6,    27,    33,    37,
      79,    81,    84,    85,    86,    87,    88,    84,    84,    32,
      35,    39,    52,    62,    20,     7,    60,    84,    34,    30,
       7,    82,    83,    84,    20,    84,     7,    66,    67,    14,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    17,    77,    80,    84,     7,    84,     7,    31,
      53,    71,    31,    34,    30,    84,    34,    53,    38,    30,
      77,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    77,    36,    30,     7,    23,    74,    75,
       7,    82,    21,    84,    66,    13,    16,    18,    80,    53,
      31,    76,    84,    77,    74,    64,    14,    16,    77,    11
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      59,    60,    60,    61,    62,    62,    63,    63,    64,    64,
      65,    66,    66,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    71,    72,    73,    73,    74,    75,    75,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    80,    80,    81,    82,    82,    82,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    85,    86,    86,    86,    86,    86,    86,    87,    87,
      87,    87,    88,    88,    88
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     4,     0,     3,     1,     2,     3,     1,     3,
       5,     3,     1,     3,     1,     3,     0,     3,     1,     2,
       5,     1,     3,     3,     0,     3,     1,     2,     6,     8,
       0,     1,     3,     4,     1,     1,     2,     0,     3,     3,
       1,     3,     3,     1,     5,     7,     9,     5,     1,     1,
       2,     1,     3,     4,     1,     3,     4,     0,     1,     3,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"end of line\"",
  "\"tipo inteiro\"", "\"tipo real\"", "\"tipo cadeia\"",
  "\"identificador\"", "\"pare\"", "\"continue\"", "\"para\"", "\"fpara\"",
  "\"enquanto\"", "\"fenquanto\"", "\"faca\"", "\"se\"", "\"fse\"",
  "\"verdadeiro\"", "\"falso\"", "\"tipo\"", "\"de\"", "\"limite\"",
  "\"global\"", "\"local\"", "\"valor\"", "\"ref\"", "\"retorne\"",
  "\"nulo\"", "\"ação\"", "\"funcao\"", "\"virgula\"", "\"dois pontos\"",
  "\"ponto virgula\"", "\"abre parentese\"", "\"fecha parentese\"",
  "\"abre colchete\"", "\"fecha colchete\"", "\"abre chave\"",
  "\"fecha chave\"", "\"ponto\"", "\"adicao\"", "\"subtracao\"",
  "\"multiplicacao\"", "\"divisao\"", "\"igualdade\"", "\"diferente\"",
  "\"menor\"", "\"menor igual\"", "\"maior\"", "\"maior igual\"", "\"e\"",
  "\"ou\"", "\"atribuicao\"", "\"igual\"", "$accept", "program",
  "lista_declaracao_de_tipo", "lista_declaracao_tipo", "declaracao_tipo",
  "descritor_tipo", "tipo_campos", "tipo_campo", "tipo_constantes",
  "lista_declaracao_de_globais", "lista_declaracao_variavel",
  "declaracao_variavel", "criacao_de_registro", "campos",
  "lista_declaracao_de_funcao", "lista_declaracao_funcao",
  "declaracao_funcao", "lista_args", "arg", "modificador", "corpo",
  "declaracoes_de_locais", "acao", "lista_comandos", "comando",
  "local_de_armazenamento", "lista_expr", "chamada_de_funcao",
  "lista_parametros", "parametro", "expr", "expressao_logica",
  "expressao_relacional", "expressao_aritmetica", "literal", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   212,   212,   216,   217,   219,   220,   222,   224,   225,
     226,   228,   229,   231,   233,   234,   238,   239,   241,   242,
     244,   246,   247,   249,   253,   254,   256,   257,   259,   260,
     262,   263,   264,   266,   268,   269,   271,   273,   274,   278,
     282,   283,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   295,   296,   297,   299,   300,   302,   304,   305,   306,
     308,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     322,   323,   325,   326,   327,   328,   329,   330,   332,   333,
     334,   335,   337,   338,   339
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
    };
    // Last valid token kind.
    const int code_max = 308;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 58 "parser.yy"
} // Simples
#line 1778 "/home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc"

#line 340 "parser.yy"


namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
