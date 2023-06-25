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
*   saber codigo de los colores
*
********************************/

void quecolor (){
    for (int i=0; i<256; i++){
        color(i);
        printf ("color: %c : %i\n", 219, i);
    }
}
void menu (){
    system ("cls");
    hidecursor(0);
    fondo ();
    opcionesmenu ();
}

/*******************************
*
*   Fondo mas logo del programa
*
********************************/

void fondo (){
    int y=0;
    int x=0;
    system ("color 9D");
    color(159);
    gotoxy (20,1);
    printf ("%c", 201);
    for (x=21; x<100; x++){
        gotoxy (x, 1);
        printf ("%c", 205);
    }
    gotoxy (20,7);
    printf ("%c", 200);
    for (y=2; y<7; y++){
        gotoxy (20, y);
        printf ("%c", 186);
    }
    gotoxy (100,1);
    printf ("%c", 187);
    for (y=2; y<7; y++){
        gotoxy (100, y);
        printf ("%c", 186);
    }
    gotoxy (100,7);
    printf ("%c", 188);
    for (x=21; x<100; x++){
        gotoxy (x, 7);
        printf ("%c", 205);
    }
    gotoxy (21, 2);
    printf ("UTN Mar del Plata");
    gotoxy (68, 6);
    printf ("Powered by Juan Ignacio Zappulla");
    for (x=21; x<55; x++){
        gotoxy (x, 4);
        printf ("%c", 219);
    }
    printf (" <<UTstar>> ");
    for (x=67; x<100; x++){
        gotoxy (x, 4);
        printf ("%c", 219);
    }

}

/*************************
*
*   menu principal
*
*************************/

void opcionesmenu (){
    int x=0;
    int y=0;
    for (x=52; x<70; x++){
        gotoxy (x, 10);
        printf ("%c", 205);
    }
    for (x=52; x<70; x++){
        gotoxy (x, 22);
        printf ("%c", 205);
    }
    gotoxy (51, 10);
    printf ("%c", 201);
    gotoxy (70, 10);
    printf ("%c", 187);
    for (y=11; y<22; y++){
        gotoxy (51, y);
        printf ("%c", 186);
    }
    for (y=11; y<22; y++){
        gotoxy (70, y);
        printf ("%c", 186);
    }
    gotoxy (70,22);
    printf ("%c", 188);
    gotoxy (51,22);
    printf ("%c", 200);
    gotoxy (56, 11);
    printf ("<< MENU >>");
    gotoxy (55, 14);
    printf ("[1] clientes");
    gotoxy (55, 17);
    printf ("[2] consumos");
    gotoxy (56, 20);
    printf ("[3] salir");
}

/*********************************
*
*   seleccion cliente - consumos
*
*********************************/

void clientes_consumos (int opc){
int opccliente;
int opcconsumo;
char salir;
const char ESC = 27;
    switch (opc){
        case 49:
            do{
            system ("cls");
            fondo ();
            hidecursor(0);
            menuclientes();
            fflush (stdin);
            opccliente = getch ();
            switch (opccliente){
                case 49:
                        guardaclienteenarchivo ();
                    break;
                case 50:
                    do{
                        system ("cls");
                        dardebajacliente();
                        hidecursor(0);
                        printf ("\n");
                        printf ("\t\t\t\t\tpresione ESC para volver al menu anterior...");
                        salir = getch();
                    }while (salir != ESC);
                    break;
                case 51:
                    do{
                        system ("cls");
                        modificaruncliente();
                        printf ("\n");
                        hidecursor(0);
                        printf ("\t\t\t\t\tpresione ESC para volver al menu anterior...");
                        salir = getch();
                    }while (salir != ESC);
                    break;
                case 52:
                    do{
                        system ("cls");
                        consultacliente();
                        printf ("\n");
                        printf ("\n");
                        hidecursor(0);
                        printf ("\t\t\t\t\tpresione ESC para volver al menu anterior...");
                        salir = getch();
                    }while (salir != ESC);
                    break;
                case 53:
                    do{
                        system ("cls");
                        leerarchivoclientes ();
                        printf ("\n");
                        printf ("\n");
                        printf ("\t\t\t\t\tpresione ESC para volver al menu anterior...");
                        salir = getch();
                    }while (salir != ESC);
                    break;
                }
            }
            while (opccliente != 54);
            break;
        case 50:
            do{
                system ("cls");
                fondo ();
                hidecursor(0);
                menuconsumos();
                fflush(stdin);
                opcconsumo = getch ();
                switch (opcconsumo){
                    case 49:
                        guardarenarchivo ();
                        break;
                    case 50:
                    do{
                        system ("cls");
                        bajaconsumo ();
                        printf ("\t\t\t\t\tpresione ESC para volver al menu anterior...");
                        hidecursor(0);
                        salir = getch();
                    }while (salir != ESC);
                        break;
                    case 51:
                    do{
                        system ("cls");
                        modificaconsumo ();
                        printf ("\t\t\t\t\tpresione ESC para volver al menu anterior...");
                        hidecursor(0);
                        salir = getch();
                    }while (salir != ESC);
                        break;
                    case 52:
                    do{
                        system ("cls");
                        consultaconsumo ();
                        printf ("\t\t\t\t\tpresione ESC para volver al menu anterior...");
                        hidecursor(0);
                        salir = getch();
                    }while (salir != ESC);
                        break;
                    case 53:
                    do{
                        system ("cls");
                        muestraconsumoscliente();
                        printf ("presione ESC para volver al menu anterior...");
                        hidecursor(0);
                        salir = getch();
                    }while (salir != ESC);
                        break;
                    case 56:
                        system ("cls");
                        easteregg ();
                        break;
                }
            }while (opcconsumo != 54);
            break;
        }
}
