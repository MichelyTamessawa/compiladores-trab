#include <stdio.h>
#include <string>
#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <utility>
#include <vector>

namespace classes_arvore
{


    class ArgFunc
    {
        std::string modificador;
        std::string identificador;
        std::string tipo;

    public:
        ArgFunc(std::string modificador, std::string identificador, std::string tipo) : modificador(modificador), identificador(identificador), tipo(tipo) {}
    };

    std::vector<ArgFunc> argFuncVetor;

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

    std::vector<TipoCampos> tipoCamposVetor;
    std::vector<int> tipoConstantes;


    class DescritorTipoId : public DescritorTipo
    {
        std::string identificador;

    public:
        DescritorTipoId(std::string identificador) : identificador(identificador) {}
    };

    class DescritorTipoReg : public DescritorTipo
    {
        std::vector<TipoCampos> campos;

    public:
        DescritorTipoReg(std::string identificador, std::vector<TipoCampos> campos) : campos(campos) {}
    };

    class DescritorTipoVetor : public DescritorTipo
    {
        std::vector<int> constantes;
        std::string tipoVetor;

    public:
        DescritorTipoVetor(std::string identificador, std::vector<int> constantes, std::string tipoVetor) : constantes(constantes), tipoVetor(tipoVetor) {}
    };

    // Expressões
    class NodeExpr
    {
        std::string type;

    public:
        NodeExpr(std::string type) : type(type) {}

        virtual ~NodeExpr() {}
    };

    std::vector<NodeExpr> exprVetor;

    class ArgRegistro
    {
        std::string identificador;
        NodeExpr expr;

    public:
        ArgRegistro(std::string identificador, NodeExpr expr) : identificador(identificador), expr(expr) {}
    };

    std::vector<ArgRegistro> argRegistroVetor;

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
        std::unique_ptr<NodeExpr> exprEsq;
        std::string Op;
        std::unique_ptr<NodeExpr> exprDir;

    public:
        NodeBinOp(std::unique_ptr<NodeExpr> exprEsq, std::string op, std::unique_ptr<NodeExpr> exprDir)
            : NodeExpr("operador"), exprEsq(std::move(exprEsq)), Op(op), exprDir(std::move(exprDir)) {}
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

    std::vector<Comando> comandosVetor;

    // Chamanda de função
    class NodeCallFunc : public NodeExpr, public Comando
    {
        std::string nameFunc;
        std::vector<std::unique_ptr<NodeExpr>> params;

    public:
        NodeCallFunc(const std::string &nameFunc,
                     std::vector<std::unique_ptr<NodeExpr>> params)
            : NodeExpr("chamada_de_funcao"), Comando("chamada_de_funcao"), nameFunc(nameFunc), params(std::move(params)) {} // validar dps
    };

    class NodeCriacaoRegistro : public NodeExpr
    {
        std::vector<ArgRegistro> args;

    public:
        NodeCriacaoRegistro(std::vector<ArgRegistro> args) : NodeExpr("expr_paren"), args(args) {}
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
        std::vector<NodeExpr> lista_expr;

    public:
        LocalVetor(LocalArmazenamento identificador, std::vector<NodeExpr> lista_expr) : identificador(identificador), lista_expr(lista_expr) {}
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
        std::vector<Comando> comandos;

    public:
        ComandoIf(NodeExpr expr, std::vector<Comando> comandos) : Comando("if"), expr(expr), comandos(comandos) {}
    };

    class ComandoIfElse : public Comando
    {
        NodeExpr expr;
        std::vector<Comando> comandos;
        std::vector<Comando> comandosElse;

    public:
        ComandoIfElse(NodeExpr expr, std::vector<Comando> comandos, std::vector<Comando> comandosElse) : Comando("ifElse"), expr(expr), comandos(comandos), comandosElse(comandosElse) {}
    };

    class ComandoFor : public Comando
    {
        std::string identificador;
        NodeExpr exprInicio;
        NodeExpr exprLimite;
        std::vector<Comando> comandos;

    public:
        ComandoFor(std::string identificador, NodeExpr exprInicio, NodeExpr exprLimite, std::vector<Comando> comandos)
            : Comando("for"), identificador(identificador), exprInicio(exprInicio), exprLimite(exprLimite), comandos(comandos) {}
    };

    class ComandoWhile : public Comando
    {
        NodeExpr expr;
        std::vector<Comando> comandos;

    public:
        ComandoWhile(NodeExpr expr, std::vector<Comando> comandos) : Comando("while"), expr(expr), comandos(comandos) {}
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

    class Corpo
    {

        std::vector<DeclaracaoVar> declaracoes;
        std::vector<Comando> comandos;

    public:
        Corpo(std::vector<DeclaracaoVar> declaracoes, std::vector<Comando> comandos) : declaracoes(declaracoes), comandos(comandos) {}
    };

    // Local
    class DeclaracaoVar
    {
        std::string identificador;
        std::string tipo;
        NodeExpr valor;

    public:
        DeclaracaoVar(std::string identificador, std::string tipo, NodeExpr valor) : identificador(identificador), tipo(tipo), valor(valor) {}
    };

    std::vector<DeclaracaoVar> declaracaoVarVetor;

    class DeclaracaoTipo
    {
        std::string identificador;
        DescritorTipo tipo;

    public:
        DeclaracaoTipo(std::string identificador, DescritorTipo tipo) : identificador(identificador), tipo(tipo) {}
    };

    std::vector<DeclaracaoTipo> declaracaoTipoVetor;

    class AbstractDeclacaoFuncao
    {
    public:
        AbstractDeclacaoFuncao() {}
    };
    // Funções
    class DeclaracaoFuncao : public AbstractDeclacaoFuncao
    {
        std::string nome;
        std::vector<ArgFunc> args;
        std::string identificador; // Tipo de retorno
        Corpo corpo;

    public:
        DeclaracaoFuncao(std::string nome, std::vector<ArgFunc> args, std::string identificador, Corpo corpo)
            : nome(nome), args(args), identificador(identificador), corpo(corpo) {}
    };

    std::vector<DeclaracaoFuncao> declaracaoFuncVetor;

    class DeclaracaoProcedimento : public AbstractDeclacaoFuncao
    {
        std::string nome;
        std::vector<ArgFunc> args;
        Corpo corpo;

    public:
        DeclaracaoProcedimento(std::string nome, std::vector<ArgFunc> args, Corpo corpo)
            : nome(nome), args(args), corpo(corpo) {}
    };

    class Declaracoes
    {
        std::vector<DeclaracaoTipo> declaracoesTipo;
        std::vector<DeclaracaoVar> declaracoesGlobais;
        std::vector<DeclaracaoFuncao> declaracoesFuncao;

    public:
        Declaracoes(std::vector<DeclaracaoTipo> declaracoesTipo, std::vector<DeclaracaoVar> declaracoesGlobais, std::vector<DeclaracaoFuncao> declaracoesFuncao)
            : declaracoesTipo(declaracoesTipo), declaracoesGlobais(declaracoesGlobais), declaracoesFuncao(declaracoesFuncao) {}
    };
    // programa
    class Programa
    {
        Declaracoes declaracoes;
        std::vector<Comando> acao;

    public:
        Programa(Declaracoes declaracoes, std::vector<Comando> acao) : declaracoes(declaracoes), acao(acao) {}
    };
}
// tipos
