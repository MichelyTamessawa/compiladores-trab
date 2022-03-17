// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 5 "parser.yy"


/*** C++ Declarations ***/
#include "parser.hh"
#include "scanner.hh"

#define yylex driver.scanner_->yylex


#line 50 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"


#include "parser.hh"




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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 44 "parser.yy"
namespace Simples {
#line 147 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"


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
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
    , location (std::move (that.location))
  {}
#endif

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
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
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

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
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
    that.type = empty_symbol;
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
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
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
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
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
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
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

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
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
  case 9:
#line 150 "parser.yy"
                                                                  {std::cout << "declaração do tipo identificador: " << *(yystack_[0].value.stringVal) << std::endl;}
#line 643 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 10:
#line 151 "parser.yy"
                                                                  {std::cout << "declaração do tipo registro" << std::endl;}
#line 649 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 11:
#line 152 "parser.yy"
                                                                  {std::cout << "declaração do tipo vetor: " << *(yystack_[4].value.stringVal) << std::endl;}
#line 655 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 21:
#line 170 "parser.yy"
                                                                            {std::cout << "declaração da variável: " << *(yystack_[4].value.stringVal) << std::endl;}
#line 661 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 29:
#line 185 "parser.yy"
                                                                                                {std::cout << "declaração de procedimento: " << *(yystack_[5].value.stringVal) << std::endl;}
#line 667 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 30:
#line 186 "parser.yy"
                                                                                                {std::cout << "declaração de função: " << *(yystack_[7].value.stringVal) <<  std::endl;}
#line 673 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 57:
#line 229 "parser.yy"
                                                                               {std::cout << "chamada da função: " << *(yystack_[3].value.stringVal) << std::endl;}
#line 679 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 71:
#line 249 "parser.yy"
                              {std::cout << "Op de and" << std::endl;}
#line 685 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 72:
#line 250 "parser.yy"
                              {std::cout << "Op de or" << std::endl;}
#line 691 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 73:
#line 252 "parser.yy"
                                            {std::cout << "Op de igualdade" << std::endl;}
#line 697 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 74:
#line 253 "parser.yy"
                                            {std::cout << "Op de diferença" << std::endl;}
#line 703 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 75:
#line 254 "parser.yy"
                                            {std::cout << "Op de maior" << std::endl;}
#line 709 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 76:
#line 255 "parser.yy"
                                            {std::cout << "Op de maior igual" << std::endl;}
#line 715 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 77:
#line 256 "parser.yy"
                                            {std::cout << "Op de menor" << std::endl;}
#line 721 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 78:
#line 257 "parser.yy"
                                            {std::cout << "Op de menor igual" << std::endl;}
#line 727 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 79:
#line 259 "parser.yy"
                                       {std::cout << "Op de adição" << std::endl;}
#line 733 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 80:
#line 260 "parser.yy"
                                       {std::cout << "Op de subtração" << std::endl;}
#line 739 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 81:
#line 261 "parser.yy"
                                       {std::cout << "Op de multiplicação" << std::endl;}
#line 745 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;

  case 82:
#line 262 "parser.yy"
                                       {std::cout << "Op de divisão" << std::endl;}
#line 751 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"
    break;


#line 755 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"

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
      YY_STACK_PRINT ();

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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
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

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

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
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

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
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -52;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      30,    21,    66,    41,    52,    85,   -52,    79,   -52,    87,
      93,    55,    85,   -52,    46,   116,    94,   -52,     9,   -52,
      91,   -52,   -52,   120,    14,    14,    14,    97,   -52,   -29,
     -52,   101,   116,   -52,   126,   -52,   130,   128,   -52,    14,
     121,   -52,   -52,   -52,   -52,    14,   129,    28,   -52,    54,
     -52,   -52,   -52,   -52,   -12,   147,    46,    14,   163,    14,
     164,   -52,   104,   126,   -52,   -52,   -22,   111,   -26,   -52,
     -21,   -52,   147,    14,   135,   119,   -23,   -52,    46,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    46,   -52,   -19,   147,   -52,   147,   122,    92,   -52,
     169,   189,   203,   128,   -52,    14,   -52,   117,   -52,    14,
     129,   -52,   -10,    78,    78,   -52,   -52,    72,    72,    72,
      72,    72,    72,   159,   159,    44,    14,   -52,    14,   -52,
     -52,    77,   -52,   204,   -52,   205,   -52,   -52,   -52,    14,
     147,   -52,   -52,   -52,    46,   147,   147,    92,    17,   182,
     -52,   105,    59,   -52,   207,   192,   209,    46,   -52,   165,
     186,   -52,    41,   -52,    39,   192,   116,   -52,   -52,   -52,
     116
  };

  const signed char
  Parser::yydefact_[] =
  {
       4,     0,     0,     0,    17,     0,     1,     0,     2,     0,
      25,     0,     5,     6,     0,     0,     0,     3,     0,     7,
      52,    49,    50,     0,     0,     0,     0,    40,    41,     0,
      44,     0,    18,    19,     0,     9,     0,     0,     8,    58,
       0,    83,    84,    85,    66,     0,     0,    69,    68,     0,
      62,    63,    64,    70,     0,    51,     0,     0,     0,     0,
       0,    20,     0,    26,    27,    15,     0,     0,     0,    13,
       0,    59,    61,     0,     0,     0,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,    55,    53,    43,     0,    31,    28,
       0,     0,     0,     0,    10,     0,    57,     0,    67,     0,
       0,    65,     0,    79,    80,    81,    82,    73,    74,    77,
      78,    75,    76,    71,    72,     0,     0,    54,     0,    35,
      36,     0,    32,     0,    16,     0,    14,    12,    60,     0,
      24,    23,    48,    45,     0,    56,    21,     0,     0,     0,
      11,     0,     0,    33,     0,    38,     0,     0,    46,     0,
       0,    29,     0,    34,     0,    38,     0,    37,    47,    30,
      39
  };

  const short
  Parser::yypgoto_[] =
  {
     -52,   -52,   -52,   -52,   -52,   208,   -52,   -52,   118,   -52,
     -52,    53,   -30,   -52,   112,   -52,   -52,   160,   -52,    80,
     -52,    60,   -52,    62,   -51,   170,   -14,   -52,   -13,   -52,
     123,     0,   -52,   -52,   -52,   -52
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    12,    13,    38,    68,    69,    66,
      10,    32,    33,    76,    77,    17,    63,    64,   131,   132,
     133,   161,   162,     8,    27,    28,    47,    93,    48,    70,
      71,    72,    50,    51,    52,    53
  };

  const unsigned char
  Parser::yytable_[] =
  {
      29,    30,    61,   142,   103,    91,    57,   110,   100,   105,
      58,   126,   104,   106,   101,   111,    35,   127,    41,    42,
      43,    20,    56,    59,    49,    54,    55,   112,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
     125,    44,    29,    30,    36,    74,    37,    45,   154,     1,
     168,    46,     5,    20,    21,    22,    23,    94,    24,    96,
     143,    25,   144,    57,    29,    30,     6,    58,    78,     7,
     155,    56,    26,   107,     9,   158,    56,    29,    30,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    56,    11,   152,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   164,   147,    18,   140,
      14,   148,    79,    80,    81,    82,   129,   130,    15,   157,
      81,    82,    16,    31,    39,    34,   145,    40,   146,    56,
      29,    30,    60,    62,    65,    67,    75,    98,   139,   151,
      61,    73,   102,    29,    30,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   108,
      95,    97,   109,   134,   128,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   135,
     136,   149,   150,   156,   159,   160,   163,   166,   165,   170,
      19,   137,   141,    99,   167,   169,    92,   153,   138
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      14,    14,    32,    13,    30,    17,    35,    30,    30,    30,
      39,    30,    38,    34,    36,    38,     7,    36,     4,     5,
       6,     7,    32,    52,    24,    25,    26,    78,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      91,    27,    56,    56,    35,    45,    37,    33,    31,    19,
      11,    37,    31,     7,     8,     9,    10,    57,    12,    59,
      16,    15,    18,    35,    78,    78,     0,    39,    14,    28,
      53,    32,    26,    73,    22,    16,    32,    91,    91,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    32,     7,   144,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,   157,    30,    53,   109,
      31,    34,    40,    41,    42,    43,    24,    25,    31,    14,
      42,    43,    29,     7,    33,    31,   126,     7,   128,    32,
     144,   144,    31,     7,     4,     7,     7,    33,    21,   139,
     170,    20,    31,   157,   157,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    34,
       7,     7,    53,     4,    52,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    20,
       7,     7,     7,    31,     7,    23,     7,    31,    53,   166,
      12,   103,   110,    63,   162,   165,    56,   147,   105
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    19,    55,    56,    57,    31,     0,    28,    77,    22,
      64,     7,    58,    59,    31,    31,    29,    69,    53,    59,
       7,     8,     9,    10,    12,    15,    26,    78,    79,    80,
      82,     7,    65,    66,    31,     7,    35,    37,    60,    33,
       7,     4,     5,     6,    27,    33,    37,    80,    82,    85,
      86,    87,    88,    89,    85,    85,    32,    35,    39,    52,
      31,    66,     7,    70,    71,     4,    63,     7,    61,    62,
      83,    84,    85,    20,    85,     7,    67,    68,    14,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    17,    79,    81,    85,     7,    85,     7,    33,    71,
      30,    36,    31,    30,    38,    30,    34,    85,    34,    53,
      30,    38,    78,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    78,    30,    36,    52,    24,
      25,    72,    73,    74,     4,    20,     7,    62,    84,    21,
      85,    68,    13,    16,    18,    85,    85,    30,    34,     7,
       7,    85,    78,    73,    31,    53,    31,    14,    16,     7,
      23,    75,    76,     7,    78,    53,    31,    77,    11,    75,
      65
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    54,    55,    56,    57,    57,    58,    58,    59,    60,
      60,    60,    61,    61,    62,    63,    63,    64,    64,    65,
      65,    66,    67,    67,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    72,    73,    74,    74,    75,    76,    76,
      77,    78,    78,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    80,    81,    81,    82,    83,    83,
      83,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    87,    87,    87,    87,    87,    87,    88,
      88,    88,    88,    89,    89,    89
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     3,     0,     3,     1,     2,     3,     1,
       3,     5,     3,     1,     3,     1,     3,     0,     3,     1,
       2,     5,     1,     3,     3,     0,     3,     1,     2,     6,
       8,     0,     1,     3,     4,     1,     1,     2,     0,     3,
       3,     1,     3,     3,     1,     5,     7,     9,     5,     1,
       1,     2,     1,     3,     4,     1,     3,     4,     0,     1,
       3,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"end of line\"",
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
  "declaracoes", "lista_declaracao_de_tipo", "lista_declaracao_tipo",
  "declaracao_tipo", "descritor_tipo", "tipo_campos", "tipo_campo",
  "tipo_constantes", "lista_declaracao_de_globais",
  "lista_declaracao_variavel", "declaracao_variavel",
  "criacao_de_registro", "campos", "lista_declaracao_de_funcao",
  "lista_declaracao_funcao", "declaracao_funcao", "lista_args", "arg",
  "modificador", "corpo", "declaracoes_de_locais", "acao",
  "lista_comandos", "comando", "local_de_armazenamento", "lista_expr",
  "chamada_de_funcao", "lista_parametros", "parametro", "expr",
  "expressao_logica", "expressao_relacional", "expressao_aritmetica",
  "literal", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   135,   135,   138,   142,   143,   145,   146,   148,   150,
     151,   152,   154,   155,   157,   159,   160,   164,   165,   167,
     168,   170,   172,   173,   175,   179,   180,   182,   183,   185,
     186,   188,   189,   190,   192,   194,   195,   197,   200,   201,
     205,   209,   210,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   222,   223,   224,   226,   227,   229,   231,   232,
     233,   235,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   249,   250,   252,   253,   254,   255,   256,   257,   259,
     260,   261,   262,   264,   265,   266
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
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

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
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
    const int user_token_number_max_ = 308;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 44 "parser.yy"
} // Simples
#line 1331 "/home/michely/Documentos/UEM/compiladores/compiladores-trab/build/parser.cc"

#line 268 "parser.yy"


namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
