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
    NodeVar(const std::string &name) : name(name), NodeExpr("identificador") {}
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

class NodeCallFunc : public NodeExpr
{
    std::string nameFunc;
    std::vector<std::unique_ptr<NodeExpr>> params;

public:
    NodeCallFunc(const std::string &nameFunc,
                 std::vector<std::unique_ptr<NodeExpr>> params)
        : nameFunc(nameFunc), params(std::move(params)), NodeExpr("funcao") {}
};