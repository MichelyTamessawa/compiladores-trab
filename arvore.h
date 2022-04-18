
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

    class ArgFunc
    {
        std::string modificador;
        std::string identificador;
        std::string tipo;

    public:
        ArgFunc(std::string modificador, std::string identificador, std::string tipo) : modificador(modificador), identificador(identificador), tipo(tipo) {}
    };

    class DescritorTipo
    {

    public:
        DescritorTipo() {}
    };

    class TipoCampos
    {
        std::string identificador;
        std::string tipo;

    public:
        TipoCampos(std::string identificador, std::string tipo) : identificador(identificador), tipo(tipo) {}
    };

    class DescritorTipoId : public DescritorTipo
    {
        std::string identificador;

    public:
        DescritorTipoId(std::string identificador) : identificador(identificador) {}
    };

    class DescritorTipoReg : public DescritorTipo
    {
        tipoCamposVetor campos;

    public:
        DescritorTipoReg(tipoCamposVetor campos) : campos(campos) {}
    };

    class DescritorTipoVetor : public DescritorTipo
    {
        tipoConstantes constantes;
        std::string tipoVetor;

    public:
        DescritorTipoVetor(tipoConstantes constantes, std::string tipoVetor) : constantes(constantes), tipoVetor(tipoVetor) {}
    };

    // Expressões
    class NodeExpr
    {
        std::string type;

    public:
        NodeExpr(std::string type) : type(type) {}

        virtual ~NodeExpr() {}
    };

    class ArgRegistro
    {
        std::string identificador;
        NodeExpr expr;

    public:
        ArgRegistro(std::string identificador, NodeExpr expr) : identificador(identificador), expr(expr) {}
    };

    class ListArgRegistro : public NodeExpr
    {
        argRegistroVetor args;

    public:
        ListArgRegistro(argRegistroVetor args) : NodeExpr("lista_args"), args(args) {}
    };

    class Literal : public NodeExpr
    {
        std::string nome;

    public:
        Literal(std::string nome) : NodeExpr(nome), nome(nome) {}
    };

    // inteiro
    class NodeInteiro : public Literal
    {
        int number;

    public:
        NodeInteiro(int number) : Literal("inteiro"), number(number) {}
    };

    // cadeia
    class NodeCadeia : public Literal
    {
        std::string cadeia;

    public:
        NodeCadeia(std::string cadeia) : Literal("cadeia"), cadeia(cadeia) {}
    };

    // reais
    class NodeDouble : public Literal
    {
        double number;

    public:
        NodeDouble(double number) : Literal("real"), number(number) {}
    };

    // identificadores
    class NodeVar : public NodeExpr
    {
        std::string name;

    public:
        NodeVar(const std::string name) : NodeExpr("identificador"), name(name) {}
    };

    // ==, -, +, /, *, >=, >, <, <=, &, |, !=
    class NodeBinOp : public NodeExpr
    {
        NodeExpr exprEsq;
        std::string Op;
        NodeExpr exprDir;

    public:
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
        NodeExpr expr;

    public:
        NodeExprComParen(NodeExpr expr) : NodeExpr("expr_paren"), expr(expr) {}
    };

    class Comando
    {
        std::string type;

    public:
        Comando(std::string type) : type(type) {}

        virtual ~Comando() {}
    };

    // Chamanda de função
    class NodeCallFunc : public NodeExpr, public Comando
    {
        std::string nameFunc;
        exprVetor params;

    public:
        NodeCallFunc(const std::string &nameFunc,
                     exprVetor params)
            : NodeExpr("chamada_de_funcao"), Comando("chamada_de_funcao"), nameFunc(nameFunc), params(params) {} // validar dps
    };

    class NodeCriacaoRegistro : public NodeExpr
    {
        argRegistroVetor args;

    public:
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
        LocalArmazenamento identificador;
        std::string propriedade;

    public:
        LocalRegistro(LocalArmazenamento identificador, std::string &propriedade) : identificador(identificador), propriedade(propriedade) {}
    };

    class LocalIdentificador : public LocalArmazenamento
    {
        std::string identificador;

    public:
        LocalIdentificador(std::string &identificador) : identificador(identificador) {}
    };

    class LocalVetor : public LocalArmazenamento
    {
        LocalArmazenamento identificador;
        exprVetor lista_expr;

    public:
        LocalVetor(LocalArmazenamento identificador, exprVetor lista_expr) : identificador(identificador), lista_expr(lista_expr) {}
    };

    // Comandos

    class ComandoAtribuicao : public Comando
    {
        LocalArmazenamento identificador;
        NodeExpr valorExpr;

    public:
        ComandoAtribuicao(LocalArmazenamento identificador, NodeExpr valorExpr) : Comando("atribuicao"), identificador(identificador), valorExpr(valorExpr) {}
    };

    class ComandoIf : public Comando
    {
        NodeExpr expr;
        comandosVetor comandos;

    public:
        ComandoIf(NodeExpr expr, comandosVetor comandos) : Comando("if"), expr(expr), comandos(comandos) {}
    };

    class ComandoIfElse : public Comando
    {
        NodeExpr expr;
        comandosVetor comandos;
        comandosVetor comandosElse;

    public:
        ComandoIfElse(NodeExpr expr, comandosVetor comandos, comandosVetor comandosElse) : Comando("ifElse"), expr(expr), comandos(comandos), comandosElse(comandosElse) {}
    };

    class ComandoFor : public Comando
    {
        std::string identificador;
        NodeExpr exprInicio;
        NodeExpr exprLimite;
        comandosVetor comandos;

    public:
        ComandoFor(std::string identificador, NodeExpr exprInicio, NodeExpr exprLimite, comandosVetor comandos)
            : Comando("for"), identificador(identificador), exprInicio(exprInicio), exprLimite(exprLimite), comandos(comandos) {}
    };

    class ComandoWhile : public Comando
    {
        NodeExpr expr;
        comandosVetor comandos;

    public:
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
        NodeExpr valorRetorno;

    public:
        ComandoRetorne(NodeExpr valorRetorno) : Comando("retorno"), valorRetorno(valorRetorno) {}
    };

    // Declarações

    // Local
    class DeclaracaoVar
    {
        std::string identificador;
        std::string tipo;
        NodeExpr valor;

    public:
        DeclaracaoVar(std::string identificador, std::string tipo, NodeExpr valor) : identificador(identificador), tipo(tipo), valor(valor) {}
    };

    class Corpo
    {

        declaracaoVarVetor declaracoes;
        comandosVetor comandos;

    public:
        Corpo(declaracaoVarVetor declaracoes, comandosVetor comandos) : declaracoes(declaracoes), comandos(comandos) {}
    };

    class DeclaracaoTipo
    {
        std::string identificador;
        DescritorTipo tipo;

    public:
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
        std::string nome;
        argFuncVetor args;
        std::string identificador; // Tipo de retorno
        Corpo corpo;

    public:
        DeclaracaoFuncao(std::string nome, argFuncVetor args, std::string identificador, Corpo corpo)
            : nome(nome), args(args), identificador(identificador), corpo(corpo) {}
    };

    class DeclaracaoProcedimento : public AbstractDeclacaoFuncao
    {
        std::string nome;
        argFuncVetor args;
        Corpo corpo;

    public:
        DeclaracaoProcedimento(std::string nome, argFuncVetor args, Corpo corpo)
            : nome(nome), args(args), corpo(corpo) {}
    };

    class Declaracoes
    {
        declaracaoTipoVetor declaracoesTipo;
        declaracaoVarVetor declaracoesGlobais;
        declaracaoFuncVetor declaracoesFuncao;

    public:
        Declaracoes(declaracaoTipoVetor declaracoesTipo, declaracaoVarVetor declaracoesGlobais, declaracaoFuncVetor declaracoesFuncao)
            : declaracoesTipo(declaracoesTipo), declaracoesGlobais(declaracoesGlobais), declaracoesFuncao(declaracoesFuncao) {}
    };
    // programa
    class Programa
    {
        Declaracoes declaracoes;
        comandosVetor acao;

    public:
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
    extern declaracaoVarVetor *DeclaracaoVarVetor(DeclaracaoVar head, declaracaoVarVetor tail);
    extern declaracaoFuncVetor *DeclaracaoFuncVetor(AbstractDeclacaoFuncao head, declaracaoFuncVetor tail);
    extern comandosVetor *ComandosVetor(Comando head, comandosVetor tail);
    extern exprVetor *ExprVetor(NodeExpr head, exprVetor tail);
    extern declaracaoTipoVetor *DeclaracaoTipoVetor(DeclaracaoTipo head, declaracaoTipoVetor tail);
    extern tipoConstantes *TipoConstantes(int head, tipoConstantes tail);
    extern tipoCamposVetor *TipoCamposVetor(TipoCampos head, tipoCamposVetor tail);
    extern argFuncVetor *ArgFuncVetor(ArgFunc head, argFuncVetor tail);
    extern argRegistroVetor *ArgRegistroVetor(ArgRegistro head, argRegistroVetor tail);
}

#endif // MYCOMPILER_ABSYNTREE_H