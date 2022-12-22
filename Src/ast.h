
#ifndef COMPILER_AST
#define COMPILER_AST

#include "lexer.h"
#include "symtable.h"
#include "functable.h"

enum NodeType
{
    UNKNOWN,
    PROGRAM,
    FUNC,
    STMT,
    EXPR,
    CONSTANT,
    IDENTIFIER,
    ACCESS,
    LOG,
    REL,
    ARI,
    UNARY,
    BLOCK,
    SEQ,
    ASSIGN,
    RETURN_STMT,
    IF_STMT,
    WHILE_STMT,
    DOWHILE_STMT
};

enum ExprType
{
    VOID,
    INT,
    FLOAT,
    BOOL
};

// retorna o equivalente ExprType para o tipo em string
int ConvertToExprType(string type);

struct Node
{
    int node_type;
    Node();
    Node(int t);
};

struct Seq : public Node
{
    Node *elemt;
    Node *elemts;
    Seq(Node *e, Node *ee);
};
struct Statement : public Node
{
    Statement();
    Statement(int type);
};

struct Expression : public Node
{
    int type;
    Token *token;
    Expression(Token *t);
    Expression(int ntype, int etype, Token *t);
    string Name();
    string Type();
};

struct Constant : public Expression
{
    Constant(int etype, Token *t);
};

struct Identifier : public Expression
{
    Identifier(int etype, Token *t);
};

struct Access : public Expression
{
    Expression *id;
    Expression *expr;
    Access(int etype, Token *t, Expression *i, Expression *e);
};

struct Logical : public Expression
{
    Expression *expr1;
    Expression *expr2;
    Logical(Token *t, Expression *e1, Expression *e2);
};

struct Relational : public Expression
{
    Expression *expr1;
    Expression *expr2;
    Relational(Token *t, Expression *e1, Expression *e2);
};

struct Arithmetic : public Expression
{
    Expression *expr1;
    Expression *expr2;
    Arithmetic(int etype, Token *t, Expression *e1, Expression *e2);
};

struct UnaryExpr : public Expression
{
    Expression *expr;
    UnaryExpr(int etype, Token *t, Expression *e);
};

struct Block : public Statement
{
    Seq *seq;
    SymMap table;
    Block(Seq *s, SymMap t);
};

struct Function : public Node
{
    Fun function;     // dados da função
    Statement *block; // instruções do corpo da função

    Function();
    Function(Fun f, Statement *b);
};

struct Program : public Node
{
    Seq *funcs;
    Program(Seq *f);
};

struct Assign : public Statement
{
    Expression *id;
    Expression *expr;
    Assign(Expression *i, Expression *e);
};

struct Return : public Statement
{
    Expression *expr;
    Return(Expression *e);
};

struct If : public Statement
{
    Expression *expr;
    Statement *stmt;
    If(Expression *e, Statement *s);
};

struct While : public Statement
{
    Expression *expr;
    Statement *stmt;
    While(Expression *e, Statement *s);
};

struct DoWhile : public Statement
{
    Statement *stmt;
    Expression *expr;
    DoWhile(Statement *s, Expression *e);
};

#endif