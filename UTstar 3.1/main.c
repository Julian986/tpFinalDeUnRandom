#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"
#include "gotoxy.h"
#include <windows.h>
#include "time.h"

int main()
{
///quecolor();
///system ("pause");
int opc;
    do{
        menu();
        opc = getch();
        clientes_consumos(opc);
    }
    while (opc != 51);
    system ("cls");
    printf ("gracias por confiar en juani's corporations...\n");
    printf ("\t\thasta la proxima!\n");
    return 0;
}

