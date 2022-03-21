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
    std::unique_ptr<NodeExpr> LHS, RHS;

public:
    NodeBinOp(std::string op, std::unique_ptr<NodeExpr> LHS,
              std::unique_ptr<NodeExpr> RHS)
        : Op(op), LHS(std::move(LHS)), RHS(std::move(RHS)), NodeExpr("operador") {}
};

// Chamanda de função
class NodeCallFunc : public NodeExpr, public Comando
{
    std::string nameFunc;
    std::vector<std::unique_ptr<NodeExpr>> params;

public:
    NodeCallFunc(const std::string &nameFunc,
                 std::vector<std::unique_ptr<NodeExpr>> params)
        : nameFunc(nameFunc), params(std::move(params)), NodeExpr("chamada_de_funcao"), Comando("chamada_de_funcao") {} // validar dps
};

// Local
class LocalArmazenamento
{

public:
    LocalArmazenamento() {}
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
    LocalArmazenamento tipoAtribuicao;
    NodeExpr valorExpr;

public:
    ComandoAtribuicao(LocalArmazenamento tipoAtribuicao, NodeExpr valorExpr) : tipoAtribuicao(tipoAtribuicao), valorExpr(valorExpr), Comando("atribuicao") {}
};

// Declarações

// Local
class NodeLocal
{
    std::string identificador;
    std::string tipo;
    NodeExpr valor;

public:
    NodeLocal(std::string identificador, std::string tipo, NodeExpr valor) : identificador(identificador), tipo(tipo), valor(valor) {}
};

// Funções
class NodeFunction
{
    std::string nome;
    std::vector<NodeLocal> declaracoes;
    std::vector<Comando> comandos;

public:
    NodeFunction(std::vector<NodeLocal> declaracoes,
                 std::vector<Comando> comandos, std::string nome)
        : declaracoes(declaracoes), comandos(comandos), nome(nome) {}
};
