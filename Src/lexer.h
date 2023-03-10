#ifndef COMPILER_LEXER
#define COMPILER_LEXER

#include <unordered_map>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::unordered_map;

// cada token possui uma tag (número a partir de 256)
// a tag de caracteres individuais é seu código ASCII
enum Tag
{
	ID = 256,
	INTEGER,
	REAL,
	TYPE,
	TRUE,
	FALSE,
	MAIN,
	IF,
	ELSE,
	WHILE,
	DO,
	FOR,
	ATTADD,
	ATTSUB,
	ATTMUL,
	ATTDIV,
	ATTREM,
	ATTOR,
	ATTAND,
	PLUSPLUS,
	LESSLESS,
	OR,
	AND,
	EQ,
	NEQ,
	LTE,
	GTE,
	RETURN
};

// classe para representar tokens
struct Token
{
	int tag;
	string lexeme;

	Token() : tag(0) {}
	Token(char ch) : tag(int(ch)), lexeme({ch}) {}
	Token(int t, string s) : tag(t), lexeme(s) {}
};

// analisador léxico
class Lexer
{
private:
	char peek;	  // último caractere lido
	Token token;  // último token retornado
	int line = 1; // número da linha atual

	// tabela para identificadores e palavras-chave
	unordered_map<string, Token> token_table;

public:
	Lexer();					  // construtor
	int Lineno();				  // retorna linha atual
	Token *Scan();				  // retorna próximo token da entrada
	char Peek() { return peek; }; // volta peek para o caracter anterior
};

#endif
