#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"
#include "gotoxy.h"
#include <windows.h>
#include "ctype.h"
#include "string.h"
#include "time.h"

/*******************************
*
*   menu visual para consumos
*
********************************/

void menuconsumos (){
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
    printf ("<< CONSUMOS >>");
    gotoxy (52, 13);
    printf ("[1] Alta consumo");
    gotoxy (52, 16);
    printf ("[2] Baja consumo");
    gotoxy (48, 19);
    printf ("[3] Modificacion consumo");
    gotoxy (50, 22);
    printf ("[4] Consulta consumo");
    gotoxy (48, 25);
    printf ("[5] Listado de consumos");
    gotoxy (55, 28);
    printf ("[6] Volver");
}

/**********************************
*
*   visual alta consumo
*
**********************************/

void visualaltaconsumo (){
int y=0;
int x=0;
    system ("cls");
    fondo();
    for (x=30; x<90; x++){
        gotoxy (x, 10);
        printf ("%c", 205);
    }
    for (x=30; x<90; x++){
        gotoxy (x, 24);
        printf ("%c", 205);
    }
    gotoxy (29, 10);
    printf ("%c", 201);
    gotoxy (90, 10);
    printf ("%c", 187);
    for (y=11; y<24; y++){
        gotoxy (29, y);
        printf ("%c", 186);
    }
    for (y=11; y<24; y++){
        gotoxy (90, y);
        printf ("%c", 186);
    }
    gotoxy (29, 24);
    printf ("%c", 200);
    gotoxy (90, 24);
    printf ("%c", 188);
    gotoxy (51, 11);
    printf ("<< ALTA CONSUMO >>\n");
    gotoxy (35, 14);
    printf ("Numero de cliente:");
    gotoxy (35, 16);
    printf ("Dia:");
    gotoxy (35, 18);
    printf ("Mes:");
    gotoxy (35, 20);
    printf ("A%co:", 164);
    gotoxy (35, 22);
    printf ("MB usados:");
}

void visualconsultaconsumo (){
system ("cls");
fondo ();
int y=0;
int x=0;
    for (x=1; x<40; x++){
        gotoxy (x, 10);
        printf ("%c", 205);
    }
    for (x=1; x<40; x++){
        gotoxy (x, 20);
        printf ("%c", 205);
    }
    for (y=11; y<20; y++){
        gotoxy (0, y);
        printf ("%c", 186);
    }
    for (y=11; y<20; y++){
        gotoxy (40, y);
        printf ("%c", 186);
    }
    gotoxy (0, 10);
    printf ("%c", 201);
    gotoxy (0, 20);
    printf ("%c", 200);
    gotoxy (40, 10);
    printf ("%c", 187);
    gotoxy (40, 20);
    printf ("%c", 188);


    gotoxy(2, 12);
    printf ("Nro. de cliente:");
    gotoxy(2, 13);
    printf ("Nombre:");
    gotoxy(2, 14);
    printf ("Apellido:");
    gotoxy(2, 15);
    printf ("D.N.I:");
    gotoxy(2, 16);
    printf ("E-mail:");
    gotoxy(2, 17);
    printf ("Domicilio:");
    gotoxy(2, 18);
    printf ("celular:");

    for (x=45; x<100; x++){
        gotoxy (x, 10);
        printf ("%c", 205);
    }
    for (y=11; y<30; y++){
        gotoxy (44, y);
        printf ("%c", 186);
    }
    for (y=11; y<30; y++){
        gotoxy (100, y);
        printf ("%c", 186);
    }
    gotoxy (44, 10);
    printf ("%c", 201);
    gotoxy (100, 10);
    printf ("%c", 187);
    gotoxy (47, 11);
    printf ("[DIA]");
    gotoxy (61, 11);
    printf ("[MES]");
    gotoxy (76, 11);
    printf ("[A%cO]", 165);
    gotoxy (90, 11);
    printf ("[MEGAS]");
}

void muestraconsumo (stconsumo con, int y){

    gotoxy (47, y);
    printf ("%d", con.dia);
    gotoxy (61, y);
    printf ("%d", con.mes);
    gotoxy (76, y);
    printf ("%d", con.anio);
    gotoxy (90, y);
    printf ("%d", con.datosConsumidos);
}

void muestraclienteconsumo (stcliente c){
    gotoxy (19, 12);
    printf ("%d", c.nroCliente);
    gotoxy (10, 13);
    printf ("%s", c.nombre);
    gotoxy (12, 14);
    printf ("%s", c.apellido);
    gotoxy (9, 15);
    printf ("%d", c.dni);
    gotoxy (10, 16);
    printf ("%s", c.email);
    gotoxy (13, 17);
    printf ("%s", c.domicilio);
    gotoxy (11, 18);
    printf ("%s", c.movil);
}

void visualbajaconsumo (){
int y=0;
int x=0;
system ("cls");
fondo();

    for (x=43; x<80;x++){
        gotoxy (x, 9);
        printf ("%c", 205);
    }
    gotoxy (42, 9);
    printf ("%c", 201);
    gotoxy (80, 9);
    printf ("%c", 187);
    for (x=43; x<80;x++){
        gotoxy (x, 20);
        printf ("%c", 205);
    }
    gotoxy (42, 20);
    printf ("%c", 200);
    gotoxy (80, 20);
    printf ("%c", 188);
    for (y=10; y<20;y++){
        gotoxy (42, y);
        printf ("%c", 186);
    }
    for (y=10; y<20;y++){
        gotoxy (80, y);
        printf ("%c", 186);
    }

}

void visualmostrarmodificarconsumo (stconsumo con){
int y=0;
int x=0;
system ("cls");
fondo();
    for(x=1; x<50;x++){
        gotoxy (x, 12);
        printf ("%c",205);
    }
    for(x=1; x<50;x++){
        gotoxy (x, 16);
        printf ("%c",205);
    }
    for(y=13; y<16; y++){
        gotoxy (0, y);
        printf ("%c",186);
    }
    for(y=13; y<16; y++){
        gotoxy (50, y);
        printf ("%c",186);
    }
    gotoxy (0, 12);
    printf ("%c",201);
    gotoxy (0, 16);
    printf ("%c",200);
    gotoxy (50, 12);
    printf ("%c",187);
    gotoxy (50, 16);
    printf ("%c",188);
    gotoxy (2, 13);
    printf ("[DIA]");
    gotoxy (2, 14);
    printf ("%d", con.dia);
    gotoxy (14, 13);
    printf ("[MES]");
    gotoxy (14, 14);
    printf ("%d", con.mes);
    gotoxy (29, 13);
    printf ("[A%cO]", 165);
    gotoxy (29, 14);
    printf ("%d", con.anio);
    gotoxy (42, 13);
    printf ("[MEGAS]");
    gotoxy (42, 14);
    printf ("%d", con.datosConsumidos);
}

void visualmodificarconsumo (){
int y=0;
int x=0;
    for(x=69; x<119;x++){
        gotoxy (x, 12);
        printf ("%c",205);
    }
    for(x=69; x<119;x++){
        gotoxy (x, 16);
        printf ("%c",205);
    }
    for(y=13; y<16; y++){
        gotoxy (69, y);
        printf ("%c",186);
    }
    for(y=13; y<16; y++){
        gotoxy (119, y);
        printf ("%c",186);
    }
    gotoxy (69, 12);
    printf ("%c",201);
    gotoxy (69, 16);
    printf ("%c",200);
    gotoxy (119, 12);
    printf ("%c",187);
    gotoxy (119, 16);
    printf ("%c",188);
    gotoxy (71, 13);
    printf ("[DIA]");
    gotoxy (83, 13);
    printf ("[MES]");
    gotoxy (98, 13);
    printf ("[A%cO]", 165);
    gotoxy (111, 13);
    printf ("[MEGAS]");

}

void visualconsultaunconsumo (stconsumo con){
int y=0;
int x=0;
system ("cls");
fondo();
    for(x=35; x<85;x++){
        gotoxy (x, 10);
        printf ("%c",205);
    }
    for(x=35; x<85;x++){
        gotoxy (x, 16);
        printf ("%c",205);
    }
    for(y=11; y<16; y++){
        gotoxy (34, y);
        printf ("%c",186);
    }
    for(y=11; y<16; y++){
        gotoxy (85, y);
        printf ("%c",186);
    }
    gotoxy (34, 10);
    printf ("%c",201);
    gotoxy (34, 16);
    printf ("%c",200);
    gotoxy (85, 10);
    printf ("%c",187);
    gotoxy (85, 16);
    printf ("%c",188);
    gotoxy (49, 11);
    printf ("<< CONSULTA CONSUMO >>");
    gotoxy (36, 13);
    printf ("[DIA]");
    gotoxy (36, 14);
    printf ("%d", con.dia);
    gotoxy (49, 13);
    printf ("[MES]");
    gotoxy (49, 14);
    printf ("%d", con.mes);
    gotoxy (64, 13);
    printf ("[A%cO]", 165);
    gotoxy (64, 14);
    printf ("%d", con.anio);
    gotoxy (77, 13);
    printf ("[MEGAS]");
    gotoxy (77, 14);
    printf ("%d", con.datosConsumidos);
}
