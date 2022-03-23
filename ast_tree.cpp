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

// tipos

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
    std::string identificador;
    std::vector<TipoCampos> campos;

public:
    DescritorTipoReg(std::string identificador, std::vector<TipoCampos> campos) : campos(campos), identificador(identificador) {}
};

class DescritorTipoVetor : public DescritorTipo
{
    std::string identificador;
    std::vector<int> constantes;
    std::string tipoVetor;

public:
    DescritorTipoVetor(std::string identificador, std::vector<int> constantes, std::string tipoVetor) : constantes(constantes), identificador(identificador), tipoVetor(tipoVetor) {}
};

class ArgRegistro
{
    std::string identificador;
    NodeExpr expr;

public:
    ArgRegistro(std::string identificador, NodeExpr expr) : identificador(identificador), expr(expr) {}
};

// Expressões
class NodeExpr
{
    std::string type;

public:
    NodeExpr(std::string type) : type(type) {}

    virtual ~NodeExpr() {}
};

// inteiro
class NodeInteiro : public NodeExpr
{
    int number;

public:
    NodeInteiro(int number) : number(number), NodeExpr("inteiro") {}
};

// cadeia
class NodeCadeia : public NodeExpr
{
    std::string cadeia;

public:
    NodeCadeia(std::string cadeia) : cadeia(cadeia), NodeExpr("cadeia") {}
};

// reais
class NodeDouble : public NodeExpr
{
    double number;

public:
    NodeDouble(double number) : number(number), NodeExpr("real") {}
};

// identificadores
class NodeVar : public NodeExpr
{
    std::string name;

public:
    NodeVar(const std::string name) : name(name), NodeExpr("identificador") {}
};

// ==, -, +, /, *, >=, >, <, <=, &, |, !=
class NodeBinOp : public NodeExpr
{
    std::string Op;
    std::unique_ptr<NodeExpr> exprEsq, exprDir;

public:
    NodeBinOp(std::string op, std::unique_ptr<NodeExpr> exprEsq,
              std::unique_ptr<NodeExpr> exprDir)
        : Op(op), exprEsq(std::move(exprEsq)), exprDir(std::move(exprDir)), NodeExpr("operador") {}
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
    NodeExprComParen(NodeExpr expr) : expr(expr), NodeExpr("expr_paren") {}
};

// Chamanda de função
class NodeCallFunc : public NodeExpr,
                     public Comando
{
    std::string nameFunc;
    std::vector<std::unique_ptr<NodeExpr>> params;

public:
    NodeCallFunc(const std::string &nameFunc,
                 std::vector<std::unique_ptr<NodeExpr>> params)
        : nameFunc(nameFunc), params(std::move(params)), NodeExpr("chamada_de_funcao"), Comando("chamada_de_funcao") {} // validar dps
};

class NodeCriacaoRegistro : public NodeExpr
{
    std::vector<ArgRegistro> args;

public:
    NodeCriacaoRegistro(std::vector<ArgRegistro> args) : args(args), NodeExpr("expr_paren") {}
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
class Comando
{
    std::string type;

public:
    Comando(std::string type) : type(type) {}

    virtual ~Comando() {}
};

class ComandoAtribuicao : public Comando
{
    LocalArmazenamento identificador;
    NodeExpr valorExpr;

public:
    ComandoAtribuicao(LocalArmazenamento identificador, NodeExpr valorExpr) : identificador(identificador), valorExpr(valorExpr), Comando("atribuicao") {}
};

class ComandoIf : public Comando
{
    NodeExpr expr;
    std::vector<Comando> comandos;

public:
    ComandoIf(NodeExpr expr, std::vector<Comando> comandos) : expr(expr), comandos(comandos), Comando("if") {}
};

class ComandoIfElse : public Comando
{
    NodeExpr expr;
    std::vector<Comando> comandos;
    std::vector<Comando> comandosElse;

public:
    ComandoIfElse(NodeExpr expr, std::vector<Comando> comandos, std::vector<Comando> comandosElse) : expr(expr), comandos(comandos), comandosElse(comandosElse), Comando("ifElse") {}
};

class ComandoFor : public Comando
{
    std::string identificador;
    NodeExpr exprInicio;
    NodeExpr exprLimite;
    std::vector<Comando> comandos;

public:
    ComandoFor(std::string identificador, NodeExpr exprInicio, NodeExpr exprLimite, std::vector<Comando> comandos, std::vector<Comando> comandosElse) : exprInicio(exprInicio), exprLimite(exprLimite), comandos(comandos), identificador(identificador), Comando("for") {}
};

class ComandoWhile : public Comando
{
    NodeExpr expr;
    std::vector<Comando> comandos;

public:
    ComandoWhile(NodeExpr expr, std::vector<Comando> comandos) : expr(expr), comandos(comandos), Comando("while") {}
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
    ComandoRetorne(NodeExpr valorRetorno) : valorRetorno(valorRetorno), Comando("retorno") {}
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

class DeclaracaoTipo
{
    std::string identificador;
    DescritorTipo tipo;

public:
    DeclaracaoTipo(std::string identificador, DescritorTipo tipo) : identificador(identificador), tipo(tipo) {}
};

// Funções
class DeclaracaoFuncao
{
    std::string nome;
    std::vector<ArgFunc> args;
    std::vector<DeclaracaoVar> declaracoes;
    std::vector<Comando> comandos;
    std::string identificador; // Tipo de retorno

public:
    DeclaracaoFuncao(std::vector<DeclaracaoVar> declaracoes,
                     std::vector<Comando> comandos, std::string nome, std::vector<ArgFunc> args, std::string identificador)
        : declaracoes(declaracoes), comandos(comandos), nome(nome), args(args), identificador(identificador) {}
};

class DeclaracaoProcedimento
{
    std::string nome;
    std::vector<ArgFunc> args;
    std::vector<DeclaracaoVar> declaracoes;
    std::vector<Comando> comandos;

public:
    DeclaracaoProcedimento(std::vector<DeclaracaoVar> declaracoes,
                           std::vector<Comando> comandos, std::string nome, std::vector<ArgFunc> args)
        : declaracoes(declaracoes), comandos(comandos), nome(nome), args(args) {}
};

// programa
class Programa
{
    std::vector<DeclaracaoTipo> declaracoesTipo;
    std::vector<DeclaracaoFuncao> declaracoesFuncao;
    std::vector<DeclaracaoVar> declaracoesGlobais;
    std::vector<Comando> acao;

public:
    Programa(std::vector<DeclaracaoTipo> declaracoesTipo,
             std::vector<DeclaracaoFuncao> declaracoesFuncao,
             std::vector<DeclaracaoVar> declaracoesGlobais,
             std::vector<Comando> acao) : declaracoesTipo(declaracoesTipo), declaracoesFuncao(declaracoesFuncao), declaracoesGlobais(declaracoesGlobais), acao(acao) {}
};