
#ifndef ARVORE_H
#define ARVORE_H

#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <utility>
#include <vector>
#include <symbol.hh>

namespace AST
{

    typedef struct declaracaoTipoVetor_ *declaracaoTipoVetor;
    typedef struct declaracaoVarVetor_ *declaracaoVarVetor;
    typedef struct declaracaoFuncVetor_ *declaracaoFuncVetor;
    typedef struct comandosVetor_ *comandosVetor;
    typedef struct argRegistroVetor_ *argRegistroVetor;
    typedef struct exprVetor_ *exprVetor;
    typedef struct tipoConstantes_ *tipoConstantes;
    typedef struct tipoCamposVetor_ *tipoCamposVetor;
    typedef struct argFuncVetor_ *argFuncVetor;

    extern S_table _tabelaSimbolos;

    class ArgFunc
    {
    public:
        std::string modificador;
        std::string identificador;
        std::string tipo;
        ArgFunc(std::string modificador, std::string identificador, std::string tipo) : modificador(modificador), identificador(identificador), tipo(tipo) {}
    };

    class DescritorTipo
    {

    public:
        std::string tipoIdentificador;
        std::string identificador;

        DescritorTipo(std::string tipoIdentificador,
                      std::string identificador) : tipoIdentificador(tipoIdentificador), identificador(identificador) {}

        virtual ~DescritorTipo() {}
    };

    class TipoCampos
    {
    public:
        std::string identificador;
        std::string tipo;

        TipoCampos(std::string identificador, std::string tipo) : identificador(identificador), tipo(tipo) {}
    };

    class DescritorTipoId : public DescritorTipo
    {
    public:
        std::string identificador;

        // bool validar() {}

        DescritorTipoId(std::string identificador) : DescritorTipo("identificador", identificador), identificador(identificador) {}
    };

    class DescritorTipoReg : public DescritorTipo
    {
    public:
        tipoCamposVetor campos;

        DescritorTipoReg(tipoCamposVetor campos) : DescritorTipo("registro", ""), campos(campos) {}
    };

    class DescritorTipoVetor : public DescritorTipo
    {
    public:
        tipoConstantes constantes;
        std::string tipoVetor;

        DescritorTipoVetor(tipoConstantes constantes, std::string tipoVetor) : DescritorTipo("vetor", ""), constantes(constantes), tipoVetor(tipoVetor) {}
    };

    // Expressões
    class NodeExpr
    {
    public:
        std::string type;

        NodeExpr(std::string type) : type(type) {}

        virtual ~NodeExpr() {}
    };

    class ArgRegistro
    {
    public:
        std::string identificador;
        NodeExpr expr;

        ArgRegistro(std::string identificador, NodeExpr expr) : identificador(identificador), expr(expr) {}
    };

    class ListArgRegistro : public NodeExpr
    {
    public:
        argRegistroVetor args;

        ListArgRegistro(argRegistroVetor args) : NodeExpr("lista_args"), args(args) {}
    };

    class Literal : public NodeExpr
    {
    public:
        std::string nome;

        Literal(std::string nome) : NodeExpr(nome), nome(nome) {}
    };

    // inteiro
    class NodeInteiro : public Literal
    {
    public:
        int number;

        NodeInteiro(int number) : Literal("inteiro"), number(number) {}
    };

    // cadeia
    class NodeCadeia : public Literal
    {
    public:
        std::string cadeia;

        NodeCadeia(std::string cadeia) : Literal("cadeia"), cadeia(cadeia) {}
    };

    // reais
    class NodeDouble : public Literal
    {
    public:
        double number;

        NodeDouble(double number) : Literal("real"), number(number) {}
    };

    // identificadores
    class NodeVar : public NodeExpr
    {
    public:
        std::string name;

        NodeVar(const std::string name) : NodeExpr("identificador"), name(name) {}
    };

    // ==, -, +, /, *, >=, >, <, <=, &, |, !=
    class NodeBinOp : public NodeExpr
    {
    public:
        NodeExpr exprEsq;
        std::string Op;
        NodeExpr exprDir;

        NodeBinOp(NodeExpr exprEsq, std::string op, NodeExpr exprDir)
            : NodeExpr("operador"), exprEsq(exprEsq), Op(op), exprDir(exprDir) {}
    };

    class NodeNulo : public NodeExpr
    {

    public:
        NodeNulo() : NodeExpr("nulo") {}
    };

    class NodeExprComParen : public NodeExpr
    {
    public:
        NodeExpr expr;

        NodeExprComParen(NodeExpr expr) : NodeExpr("expr_paren"), expr(expr) {}
    };

    class Comando
    {
    public:
        std::string type;

        Comando(std::string type) : type(type) {}

        virtual ~Comando() {}
    };

    // Chamanda de função
    class NodeCallFunc : public NodeExpr, public Comando
    {
    public:
        std::string nameFunc;
        exprVetor params;

        NodeCallFunc(const std::string &nameFunc,
                     exprVetor params)
            : NodeExpr("chamada_de_funcao"), Comando("chamada_de_funcao"), nameFunc(nameFunc), params(params) {} // validar dps
    };

    class NodeCriacaoRegistro : public NodeExpr
    {
    public:
        argRegistroVetor args;

        NodeCriacaoRegistro(argRegistroVetor args) : NodeExpr("expr_paren"), args(args) {}
    };

    // Local
    class LocalArmazenamento : public NodeExpr
    {

    public:
        LocalArmazenamento() : NodeExpr("local_armazenamento") {}
    };

    class LocalRegistro : public LocalArmazenamento
    {
    public:
        LocalArmazenamento identificador;
        std::string propriedade;

        LocalRegistro(LocalArmazenamento identificador, std::string &propriedade) : identificador(identificador), propriedade(propriedade) {}
    };

    class LocalIdentificador : public LocalArmazenamento
    {
    public:
        std::string identificador;

        LocalIdentificador(std::string &identificador) : identificador(identificador) {}
    };

    class LocalVetor : public LocalArmazenamento
    {
    public:
        LocalArmazenamento identificador;
        exprVetor lista_expr;

        LocalVetor(LocalArmazenamento identificador, exprVetor lista_expr) : identificador(identificador), lista_expr(lista_expr) {}
    };

    // Comandos

    class ComandoAtribuicao : public Comando
    {
    public:
        LocalArmazenamento identificador;
        NodeExpr valorExpr;

        ComandoAtribuicao(LocalArmazenamento identificador, NodeExpr valorExpr) : Comando("atribuicao"), identificador(identificador), valorExpr(valorExpr) {}
    };

    class ComandoIf : public Comando
    {
    public:
        NodeExpr expr;
        comandosVetor comandos;

        ComandoIf(NodeExpr expr, comandosVetor comandos) : Comando("if"), expr(expr), comandos(comandos) {}
    };

    class ComandoIfElse : public Comando
    {
    public:
        NodeExpr expr;
        comandosVetor comandos;
        comandosVetor comandosElse;
        ComandoIfElse(NodeExpr expr, comandosVetor comandos, comandosVetor comandosElse) : Comando("ifElse"), expr(expr), comandos(comandos), comandosElse(comandosElse) {}
    };

    class ComandoFor : public Comando
    {
    public:
        std::string identificador;
        NodeExpr exprInicio;
        NodeExpr exprLimite;
        comandosVetor comandos;
        ComandoFor(std::string identificador, NodeExpr exprInicio, NodeExpr exprLimite, comandosVetor comandos)
            : Comando("for"), identificador(identificador), exprInicio(exprInicio), exprLimite(exprLimite), comandos(comandos) {}
    };

    class ComandoWhile : public Comando
    {
    public:
        NodeExpr expr;
        comandosVetor comandos;
        ComandoWhile(NodeExpr expr, comandosVetor comandos) : Comando("while"), expr(expr), comandos(comandos) {}
    };

    class ComandoPare : public Comando
    {
    public:
        ComandoPare() : Comando("pare") {}
    };

    class ComandoContinue : public Comando
    {
    public:
        ComandoContinue() : Comando("continue") {}
    };

    class ComandoRetorne : public Comando
    {
    public:
        NodeExpr valorRetorno;

        ComandoRetorne(NodeExpr valorRetorno) : Comando("retorno"), valorRetorno(valorRetorno) {}
    };

    // Declarações

    // Local
    class DeclaracaoVar
    {
    public:
        std::string identificador;
        std::string tipo;
        NodeExpr valor;
        DeclaracaoVar(std::string identificador, std::string tipo, NodeExpr valor) : identificador(identificador), tipo(tipo), valor(valor) {}
    };

    class Corpo
    {
    public:
        declaracaoVarVetor declaracoes;
        comandosVetor comandos;

        Corpo(declaracaoVarVetor declaracoes, comandosVetor comandos) : declaracoes(declaracoes), comandos(comandos) {}
    };

    class DeclaracaoTipo
    {
    public:
        std::string identificador;
        DescritorTipo tipo;

        bool validar()
        {
            S_symbol idSymbol = S_Symbol(identificador);
            // ver se identificador está na tabela de simbolos

            if (S_look(_tabelaSimbolos, idSymbol) == NULL)
            {
                printf("Não achou o simbolo!!! %s\n", identificador.c_str());
                // se nao estiver -> insere
                // validar o tipo
            }
            // se estiver -> erro semantico
            return false;
        };

        // void traduzir() {}

        DeclaracaoTipo(std::string identificador, DescritorTipo tipo) : identificador(identificador), tipo(tipo) {}
    };

    class AbstractDeclacaoFuncao
    {
    public:
        AbstractDeclacaoFuncao() {}
    };

    // Funções
    class DeclaracaoFuncao : public AbstractDeclacaoFuncao
    {
    public:
        std::string nome;
        argFuncVetor args;
        std::string identificador; // Tipo de retorno
        Corpo corpo;

        DeclaracaoFuncao(std::string nome, argFuncVetor args, std::string identificador, Corpo corpo)
            : nome(nome), args(args), identificador(identificador), corpo(corpo) {}
    };

    class DeclaracaoProcedimento : public AbstractDeclacaoFuncao
    {
    public:
        std::string nome;
        argFuncVetor args;
        Corpo corpo;

        DeclaracaoProcedimento(std::string nome, argFuncVetor args, Corpo corpo)
            : nome(nome), args(args), corpo(corpo) {}
    };

    class Declaracoes
    {
    public:
        declaracaoTipoVetor declaracoesTipo;
        declaracaoVarVetor declaracoesGlobais;
        declaracaoFuncVetor declaracoesFuncao;

        Declaracoes(declaracaoTipoVetor declaracoesTipo, declaracaoVarVetor declaracoesGlobais, declaracaoFuncVetor declaracoesFuncao)
            : declaracoesTipo(declaracoesTipo), declaracoesGlobais(declaracoesGlobais), declaracoesFuncao(declaracoesFuncao) {}
    };
    // programa
    class Programa
    {
    public:
        Declaracoes declaracoes;
        comandosVetor acao;

        Programa(Declaracoes declaracoes, comandosVetor acao) : declaracoes(declaracoes), acao(acao) {}
    };

    // extern argFuncVetor argFuncVetor;
    // extern tipoCamposVetor tipoCamposVetor;
    // extern tipoConstantes tipoConstantes;
    // extern exprVetor exprVetor;
    // extern argRegistroVetor argRegistroVetor;
    // extern comandosVetor comandosVetor;
    // extern declaracaoVarVetor declaracaoVarVetor;
    // extern declaracaoTipoVetor declaracaoTipoVetor;
    // extern declaracaoFuncVetor declaracaoFuncVetor;

    /*  */
    struct declaracaoTipoVetor_
    {
        DeclaracaoTipo head;
        declaracaoTipoVetor tail;
    };

    struct declaracaoVarVetor_
    {
        DeclaracaoVar head;
        declaracaoVarVetor tail;
    };

    struct declaracaoFuncVetor_
    {
        AbstractDeclacaoFuncao head;
        declaracaoFuncVetor tail;
    };

    struct comandosVetor_
    {
        Comando head;
        comandosVetor tail;
    };

    struct argRegistroVetor_
    {
        ArgRegistro head;
        argRegistroVetor tail;
    };

    struct exprVetor_
    {
        NodeExpr head;
        exprVetor tail;
    };

    struct tipoConstantes_
    {
        int head;
        tipoConstantes tail;
    };

    struct tipoCamposVetor_
    {
        TipoCampos head;
        tipoCamposVetor tail;
    };

    struct argFuncVetor_
    {
        ArgFunc head;
        argFuncVetor tail;
    };

    /* function prototypes */
    extern declaracaoVarVetor DeclaracaoVarVetor(DeclaracaoVar head, declaracaoVarVetor tail);
    extern declaracaoFuncVetor DeclaracaoFuncVetor(AbstractDeclacaoFuncao head, declaracaoFuncVetor tail);
    extern comandosVetor ComandosVetor(Comando head, comandosVetor tail);
    extern exprVetor ExprVetor(NodeExpr head, exprVetor tail);
    extern declaracaoTipoVetor DeclaracaoTipoVetor(DeclaracaoTipo head, declaracaoTipoVetor tail);
    extern tipoConstantes TipoConstantes(int head, tipoConstantes tail);
    extern tipoCamposVetor TipoCamposVetor(TipoCampos head, tipoCamposVetor tail);
    extern argFuncVetor ArgFuncVetor(ArgFunc head, argFuncVetor tail);
    extern argRegistroVetor ArgRegistroVetor(ArgRegistro head, argRegistroVetor tail);

    extern Programa *ast_root;
}

#endif // MYCOMPILER_ABSYNTREE_H
