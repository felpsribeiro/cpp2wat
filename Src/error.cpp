#include "error.h"
#include <iostream>
using std::cout;
using std::endl;

SyntaxError::SyntaxError(int line, string msg) : lineno(line), desc(msg) {}

void SyntaxError::What()
{
	cout << "Erro (linha " << lineno << "): " << desc << endl;
}

OpenFileError::OpenFileError(string msg) : desc(msg) {}

void OpenFileError::What()
{
	cout << "Falha ao tentar abrir o arquivo: " << desc << endl;
}
