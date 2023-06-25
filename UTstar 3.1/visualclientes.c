#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"
#include "gotoxy.h"
#include <windows.h>
#include "ctype.h"
#include "string.h"
#include "time.h"
/**********************************
*
*   menu visual para los clientes
*
***********************************/

void menuclientes (){
    int y=0;
    int x=0;

    for (x=46; x<74;x++){
        gotoxy (x, 9);
        printf ("%c", 205);
    }
    gotoxy (45, 9);
    printf ("%c", 201);
    gotoxy (74, 9);
    printf ("%c", 187);
    for (x=46; x<74;x++){
        gotoxy (x, 29);
        printf ("%c", 205);
    }
    gotoxy (45, 29);
    printf ("%c", 200);
    gotoxy (74, 29);
    printf ("%c", 188);
    for (y=10; y<29;y++){
        gotoxy (45, y);
        printf ("%c", 186);
    }
    for (y=10; y<29;y++){
        gotoxy (74, y);
        printf ("%c", 186);
    }
    gotoxy (53, 10);
    printf ("<< CLIENTES >>");
    gotoxy (52, 13);
    printf ("[1] Alta cliente");
    gotoxy (52, 16);
    printf ("[2] Baja cliente");
    gotoxy (48, 19);
    printf ("[3] Modificacion cliente");
    gotoxy (50, 22);
    printf ("[4] Consulta cliente");
    gotoxy (48, 25);
    printf ("[5] Listado de clientes");
    gotoxy (55, 28);
    printf ("[6] Volver");

}

/**************************
*
*   visual alta cliente
*
***************************/

void visualaltacliente (){
    int y=0;
    int x=0;
    system ("cls");
    fondo();
    for (x=30; x<90; x++){
        gotoxy (x, 10);
        printf ("%c", 205);
    }
    for (x=30; x<90; x++){
        gotoxy (x, 28);
        printf ("%c", 205);
    }
    gotoxy (29, 10);
    printf ("%c", 201);
    gotoxy (90, 10);
    printf ("%c", 187);
    for (y=11; y<28; y++){
        gotoxy (29, y);
        printf ("%c", 186);
    }
    for (y=11; y<28; y++){
        gotoxy (90, y);
        printf ("%c", 186);
    }
    gotoxy (29, 28);
    printf ("%c", 200);
    gotoxy (90, 28);
    printf ("%c", 188);
    gotoxy (51, 11);
    printf ("<< ALTA CLIENTE >>\n");
    gotoxy (35, 14);
    printf ("Numero de cliente:");
    gotoxy (35, 16);
    printf ("Nombre:");
    gotoxy (35, 18);
    printf ("Apellido:");
    gotoxy (35, 20);
    printf ("D.N.I:");
    gotoxy (35, 22);
    printf ("E-mail:");
    gotoxy (35, 24);
    printf ("Domicilio:");
    gotoxy (35, 26);
    printf ("Celular:\n");
}

/********************************
*
*   visual listado de clientes
*
********************************/

void visuallistadoclientes (){
    int x=0;
    int y=0;
    system ("cls");
    fondo ();
    gotoxy (0, 9);
    printf ("%c", 201);
    for (x=1; x<119; x++){
        gotoxy (x, 9);
        printf ("%c", 205);
    }
    gotoxy (119, 9);
    printf ("%c", 187);
    printf ("\n");
    printf ("\n");
    printf ("\n");
    printf ("\n");
    for (y=10; y<30; y++){
        gotoxy (0, y);
        printf ("%c", 186);
    }
    for (y=10; y<30; y++){
        gotoxy (119, y);
        printf ("%c", 186);
    }
    gotoxy (1, 10);
    printf ("[ID CLIENTE]");
    gotoxy (17, 10);
    printf ("[NOMBRE]");
    gotoxy (30, 10);
    printf ("[APELLIDO]");
    gotoxy (45, 10);
    printf ("[D.N.I]");
    gotoxy (64, 10);
    printf ("[E-Mail]");
    gotoxy (86, 10);
    printf ("[DOMICILIO]");
    gotoxy (108, 10);
    printf ("[CELULAR]");
    printf ("\n");
}

/*********************************************
*
*   Visual muestra un cliente para dar de baja
*
*********************************************/

void visualbajacliente (){
    int y=0;
    int x=0;
    system ("cls");
    fondo();
    for (x=30; x<90; x++){
        gotoxy (x, 10);
        printf ("%c", 205);
    }
    for (x=30; x<90; x++){
        gotoxy (x, 28);
        printf ("%c", 205);
    }
    gotoxy (29, 10);
    printf ("%c", 201);
    gotoxy (90, 10);
    printf ("%c", 187);
    for (y=11; y<28; y++){
        gotoxy (29, y);
        printf ("%c", 186);
    }
    for (y=11; y<28; y++){
        gotoxy (90, y);
        printf ("%c", 186);
    }
    gotoxy (29, 28);
    printf ("%c", 200);
    gotoxy (90, 28);
    printf ("%c", 188);
    gotoxy (51, 11);
    printf ("<< BAJA CLIENTE >>\n");
    gotoxy (35, 14);
    printf ("Numero de cliente:");
    gotoxy (35, 15);
    printf ("Nombre:");
    gotoxy (35, 16);
    printf ("Apellido:");
    gotoxy (35, 17);
    printf ("D.N.I:");
    gotoxy (35, 18);
    printf ("E-mail:");
    gotoxy (35, 19);
    printf ("Domicilio:");
    gotoxy (35, 20);
    printf ("Celular:\n");
}

/**************************
*
*   visual ingrese dni
*
***************************/

void visualingresedni (){
int y=0;
int x=0;
    system ("cls");
    fondo();
    for (x=30; x<90; x++){
        gotoxy (x, 10);
        printf ("%c", 205);
    }
    for (x=30; x<90; x++){
        gotoxy (x, 18);
        printf ("%c", 205);
    }
    gotoxy (29, 10);
    printf ("%c", 201);
    gotoxy (90, 10);
    printf ("%c", 187);
    for (y=11; y<18; y++){
        gotoxy (29, y);
        printf ("%c", 186);
    }
    for (y=11; y<18; y++){
        gotoxy (90, y);
        printf ("%c", 186);
    }
    gotoxy (29, 18);
    printf ("%c", 200);
    gotoxy (90, 18);
    printf ("%c", 188);
    gotoxy (38, 13);
    printf ("D.N.I del cliente: ");
}

/**********************
*
*   visual mostrar dni
*
***********************/

void visualmodificarcliente (stcliente c){
system ("cls");
fondo ();
hidecursor(0);
int x=0;
int y=0;
    for (x=1; x<45;x++){
        gotoxy (x, 11);
        printf ("%c", 205);
    }
    for (x=1; x<45;x++){
        gotoxy (x, 29);
        printf ("%c", 205);
    }
    for (y=12; y<29; y++){
        gotoxy (0, y);
        printf ("%c", 186);
    }
    for (y=12; y<29; y++){
        gotoxy (45, y);
        printf ("%c", 186);
    }
    gotoxy (0, 11);
    printf ("%c", 201);
    gotoxy (0, 29);
    printf ("%c", 200);
    gotoxy (45, 11);
    printf ("%c", 187);
    gotoxy (45, 29);
    printf ("%c", 188);

    gotoxy (12, 13);
    printf ("<<< CLIENTE ORIGINAL >>>");
    gotoxy (3, 15);
    printf ("Numero de cliente: %d", c.nroCliente);
    gotoxy (3, 17);
    printf ("Nombre: %s", c.nombre);
    gotoxy (3, 19);
    printf ("apellido: %s", c.apellido);
    gotoxy (3, 21);
    printf ("D.N.I: %d", c.dni);
    gotoxy (3, 23);
    printf ("E-mail: %s", c.email);
    gotoxy (3, 25);
    printf ("Domicilio: %s", c.domicilio);
    gotoxy (3, 27);
    printf ("celular: %s", c.movil);


    for (x=75; x<119;x++){
        gotoxy (x, 11);
        printf ("%c", 205);
    }
    for (x=75; x<119;x++){
        gotoxy (x, 29);
        printf ("%c", 205);
    }
    for (y=12; y<29; y++){
        gotoxy (74, y);
        printf ("%c", 186);
    }
    for (y=12; y<29; y++){
        gotoxy (119, y);
        printf ("%c", 186);
    }
    gotoxy (74, 11);
    printf ("%c", 201);
    gotoxy (74, 29);
    printf ("%c", 200);
    gotoxy (119, 11);
    printf ("%c", 187);
    gotoxy (119, 29);
    printf ("%c", 188);
    gotoxy (86, 13);
    printf ("<<<CLIENTE MODIFICADO>>>");
}

/**************************
*
*   visual consulte cliente
*
***************************/

void visualconsultacliente (stcliente c){
    int y=0;
    int x=0;
    system ("cls");
    fondo();
    for (x=30; x<90; x++){
        gotoxy (x, 10);
        printf ("%c", 205);
    }
    for (x=30; x<90; x++){
        gotoxy (x, 28);
        printf ("%c", 205);
    }
    gotoxy (29, 10);
    printf ("%c", 201);
    gotoxy (90, 10);
    printf ("%c", 187);
    for (y=11; y<28; y++){
        gotoxy (29, y);
        printf ("%c", 186);
    }
    for (y=11; y<28; y++){
        gotoxy (90, y);
        printf ("%c", 186);
    }
    gotoxy (29, 28);
    printf ("%c", 200);
    gotoxy (90, 28);
    printf ("%c", 188);
    gotoxy (49, 11);
    printf ("<< CONSULTA CLIENTE >>\n");
    gotoxy (35, 13);
    printf ("Numero de cliente: ");
    printf ("%d", c.nroCliente);
    gotoxy (35, 15);
    printf ("Nombre: ");
    printf ("%s", c.nombre);
    gotoxy (35, 17);
    printf ("Apellido: ");
    printf ("%s", c.apellido);
    gotoxy (35, 19);
    printf ("D.N.I: ");
    printf ("%d", c.dni);
    gotoxy (35, 21);
    printf ("E-mail: ");
    printf ("%s", c.email);
    gotoxy (35, 23);
    printf ("Domicilio: ");
    printf ("%s", c.domicilio);
    gotoxy (35, 25);
    printf ("Celular: ");
    printf ("%s", c.movil);
}

void limpiarvalidacion (){
    for (int x=35; x<85; x++){
            gotoxy (x, 12);
            color (9);
            printf ("%c", 219);
        }
}

void limpiarmodificacion (){
    for (int x=47; x<74; x++){
            gotoxy (x, 12);
            color (9);
            printf ("%c", 219);
    }
}
