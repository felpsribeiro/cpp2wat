void ffor()
{
    int cont = 0;

    for (int i = 0; i < 5; i++)
        cont += i;

    int aux = 0;
    for (cont = 3; cont != 0; cont--)
    {
        aux += 5;
    }
}

void fwhile()
{
    int aux = 20;
    while (aux > 10)
    {
        aux -= 5;
    }
}

void fdowhile()
{
    int aux = 1;
    do
        aux *= 5;
    while (aux < 30);
}

int main()
{
    ffor();
    fwhile();
    fdowhile();
}