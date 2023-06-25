#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"
#include "gotoxy.h"
#include <windows.h>
#include "ctype.h"
#include "string.h"
#include "time.h"
/***********************
*
*   id autoincremental
*
************************/

int idautoincremental (){
stcliente c;
int id=0;
    FILE *parchcli = fopen(AR_CLI, "rb");
    if(parchcli){
        fseek(parchcli, sizeof(stcliente)*(-1),SEEK_END);
        if(fread(&c ,sizeof(stcliente),1,parchcli) > 0){
            id = c.id;
        }
        fclose(parchcli);
    }
return id;
}

/*************************************
*
*   NrCliente unico y autoincremental
*
**************************************/

int ncroclienteautoincremental (){
stcliente c;
int nrcliente=0;
    FILE *parchcli = fopen(AR_CLI, "rb");
    if(parchcli){
        fseek(parchcli, sizeof(stcliente)*(-1),SEEK_END);
        if(fread(&c ,sizeof(stcliente),1,parchcli) > 0){
            nrcliente = c.nroCliente;
        }
        fclose(parchcli);
    }
return nrcliente;
}

/***********************
*
*   alta un cliente
*
************************/

stcliente altauncliente (){
int y=0;
int x=0;
int aux;
int nrcliente;
char salir;
stcliente c;
    hidecursor(1);
    visualaltacliente ();
    aux = idautoincremental();
    c.id = aux + 1;
    nrcliente = ncroclienteautoincremental ();
    c.nroCliente = nrcliente + 1;
    gotoxy (54, 14);
    fflush (stdin);
    printf ("%d", c.nroCliente);
    do{
        color (159);
        gotoxy (43, 16);
        fflush (stdin);
        scanf(" %29[^\n]",&c.nombre);
    }while (verificacionnombreyapellido(c.nombre, 16, 43, 70));
    limpiarvalidacion();
    do{
        color (159);
        gotoxy (45, 18);
        fflush (stdin);
        scanf(" %29[^\n]",&c.apellido);
    }while (verificacionnombreyapellido(c.apellido, 18, 45, 70));
    limpiarvalidacion();
        do{
            color (159);
            gotoxy (42, 20);
            fflush (stdin);
            scanf("%d",&c.dni);
        }while (dninorepetido(c.dni) || validaciondni(c.dni, 20, 42, 70));
    limpiarvalidacion();
    do{
        color (159);
        gotoxy (43, 22);
        fflush (stdin);
        scanf(" %29[^\n]",&c.email);
    }while (validacionmail(c.email, 22, 43, 70));
    limpiarvalidacion();
        color (159);
        gotoxy (46, 24);
        fflush (stdin);
        scanf(" %44[^\n]",&c.domicilio);
    limpiarvalidacion();
    do{
    color (159);
    gotoxy (44, 26);
    scanf ("%s", &c.movil);
    }while (validacioncelular(c.movil, 26, 43, 70));
    limpiarvalidacion();
    c.baja = 0;
    color (159);
return c;
}

/*****************************
*
*   guarda cliente en archivo
*
******************************/

void archivo (stcliente c){
    FILE *parchcli = fopen (AR_CLI, "ab");
    if (parchcli){
        fwrite (&c, sizeof(stcliente), 1, parchcli);
        fclose (parchcli);
    }
}

void guardaclienteenarchivo (){
stcliente c;
char salir;
const char ESC = 27;
    do{
        c = altauncliente();
        archivo(c);
        gotoxy (37, 28);
        printf ("Si no desea cargar mas clientes, presione ESC...");
        salir = getche();
        system ("cls");
    }
    while (salir != ESC);
}

/*********************************
*
*   Muestra un cliente
*
*********************************/

void muestrauncliente (stcliente c, int y){
        gotoxy (2, y);
        printf ("%d", c.nroCliente);
        gotoxy (17, y);
        printf ("%s", c.nombre);
        gotoxy (30, y);
        printf ("%s", c.apellido);
        gotoxy (45, y);
        printf ("%d", c.dni);
        gotoxy (56, y);
        printf ("%s", c.email);
        gotoxy (86, y);
        printf ("%s", c.domicilio);
        gotoxy (108, y);
        printf ("%s", c.movil);
}

/**********************************************
*
*   muestra listado de clientes si c.baja != 1
*
***********************************************/

void leerarchivoclientes (){
stcliente c;
int y = 11;
FILE *parchcli = fopen (AR_CLI, "rb");
    visuallistadoclientes ();
    if (parchcli){
    while (fread(&c, sizeof(stcliente), 1, parchcli) > 0){
        if (c.baja != 1){
            muestrauncliente(c, y);
            y++;
        }
    }
        fclose (parchcli);
    }
}

/**********************************************
*
*   Busca posicion por dni
*
**********************************************/

int buscapordni(int dni){
    int pos = -1;
    stcliente c;
    FILE *parchcli = fopen(AR_CLI,"rb");
    if(parchcli){
        while(pos == -1 && fread(&c, sizeof(stcliente), 1, parchcli) > 0){
            if(c.dni == dni && c.baja == 0){
                pos = ftell(parchcli)/sizeof(stcliente)-1;
            }
        }
        fclose(parchcli);
    }
    return pos;
}

/*************************************
*
*   busqueda por dni para dar de baja
*
**************************************/

void dardebajacliente(){
int pos = -1;
int dni;
int flag;
char salir;
const char ESC = 27;
    hidecursor(1);
    visualingresedni ();
    gotoxy (52, 11);
    printf ("<< BAJA CLIENTE >>");
    gotoxy (38, 13);
    printf ("D.N.I del cliente: ");
    gotoxy (57, 13);
    fflush (stdin);
    scanf ("%d", &dni);
    pos = buscapordni(dni);
    if (pos == -1){
        gotoxy (50, 15);
        printf ("No se encuentra el cliente");
    }
    else{
        flag = dardebaja(pos);
        if (flag == 0){
            gotoxy (47, 15);
            printf ("el cliente ya esta dado de baja");
        }
        else {
            gotoxy (41, 15);
            printf ("el cliente fue dado de baja con exito!");
        }
    }
}

/****************************
*
* Dar de baja cliente
*
*****************************/

int dardebaja (int pos){
int flag = 0;
stcliente c;
    FILE *parchcli = fopen (AR_CLI, "r+b");
    if (parchcli){
        fseek(parchcli, sizeof(stcliente)*pos, SEEK_SET);
        fread(&c, sizeof(stcliente), 1, parchcli);
        if (c.baja == 0){
            c.baja = 1;
            fseek(parchcli, sizeof(stcliente)*(-1), SEEK_CUR);
            fwrite (&c, sizeof(stcliente), 1, parchcli);
            flag = 1;
        }
        fclose (parchcli);
    }
return flag;
}

/**************************
*
*   modificar un cliente
*
***************************/

void modificaruncliente (){
int dni;
int flag = 0;
stcliente c;
hidecursor(1);
    visualingresedni ();
    gotoxy (49, 11);
    printf ("<< MODIFICAR CLIENTE >>");
    gotoxy (57, 13);
    fflush (stdin);
    scanf ("%d", &dni);
    flag = modificarpordni(dni, flag);
    if (flag == 1){
        gotoxy (45, 8);
        printf ("cliente modificado con exito!\n");
    }
    else if (flag == 0){
        gotoxy (47, 15);
        printf ("no se encuentra el cliente\n");
    }
    else if (flag == -1){
        gotoxy (35, 15);
        printf ("no se puede modificar. El cliente fue dado de baja\n");
    }
}

/**************************************
*
*   busca y tetorna un cliente por dni
*
**************************************/

int modificarpordni (int dni, int flag){
stcliente c;
stcliente aux;
    FILE *parchcli = fopen (AR_CLI, "r+b");
    if (parchcli){
        while (fread(&aux, sizeof (stcliente), 1, parchcli) > 0){
            if (dni == aux.dni){
                if (aux.baja == 1){
                    flag = -1;
                }
                else{
                    fseek(parchcli, sizeof(stcliente)*(-1),SEEK_CUR);
                    visualmodificarcliente (aux);
                    c = modificarcliente(aux);
                    fwrite(&c, sizeof(stcliente), 1, parchcli);
                    flag = 1;
                }
            }
            else {
                flag = 0;
            }
        }
        fclose(parchcli);
    }
return flag;
}

stcliente modificarcliente(stcliente c){
    hidecursor (1);
    gotoxy (76, 15);
    printf ("Numero de cliente: %d", c.nroCliente);
    gotoxy (76, 17);
    printf ("Nombre: ");
    gotoxy (76, 19);
    printf ("Apellido: ");
    gotoxy (76, 21);
    printf ("D.N.I: ");
    gotoxy (76, 23);
    printf ("E-mail: ");
    gotoxy (76, 25);
    printf ("Domicilio: ");
    gotoxy (76, 27);
    printf ("Celular: ");
    do{
        color (159);
        gotoxy (84, 17);
        fflush (stdin);
        gets (&c.nombre);
    }while (verificacionnombreyapellido(c.nombre, 17, 84, 95));
    limpiarmodificacion ();
    do{
        color (159);
        gotoxy (86, 19);
        fflush (stdin);
        gets (&c.apellido);
    }while (verificacionnombreyapellido(c.apellido, 19, 86, 110));
    do{
        color (159);
        gotoxy (83, 21);
        fflush (stdin);
        scanf ("%d", &c.dni);
    }while (validaciondni (c.dni, 21, 83, 110));
    do{
        color (159);
        gotoxy (84, 23);
        fflush (stdin);
        gets (&c.email);
    }while (validacionmail(c.email, 23, 84, 115));
    limpiarmodificacion ();
    color (159);
    gotoxy (87, 25);
    fflush (stdin);
    gets (&c.domicilio);
    do{
        color (159);
        gotoxy (85, 27);
        fflush (stdin);
        gets (&c.movil);
    }while(validacioncelular(c.movil, 27, 84, 115));
    limpiarmodificacion ();
    color (159);
return c;
}

/***************************
*
*   consulta cliente por dni
*
****************************/

void consultacliente (){
int dni;
int flag;
    visualingresedni ();
    hidecursor(1);
    gotoxy (50, 11);
    printf ("<< CONSULTA CLIENTE >>");
    gotoxy (38, 13);
    printf ("D.N.I del cliente: ");
    gotoxy (57, 13);
    fflush (stdin);
    scanf ("%d", &dni);
    flag = consultapordni(dni);
    if (flag == 0){
        gotoxy (47, 15);
        printf ("No se encuentra el cliente");
    }
    else if (flag == -1){
        gotoxy (47, 15);
        printf ("El cliente fue dado de baja");
    }
}

int consultapordni (int dni){
    int flag = 0;
    stcliente c;
    FILE *parchcli = fopen (AR_CLI, "rb");
    if (parchcli){
        while (fread(&c, sizeof(stcliente), 1, parchcli)>0){
            if (c.dni == dni && c.baja == 0){
                visualconsultacliente(c);
                flag = 1;
            }
            else if (c.dni == dni && c.baja == 1){
                flag = -1;
            }
        }
        fclose(parchcli);
    }
return flag;
}

void verificacionnombreyapellido (char nombre [30], int y, int w, int z){
int flag = 0;
    flag = validacionchar (nombre, flag);
    if (flag == 1){
        gotoxy (49, 12);
        printf ("Ingrese solo letras...");
        for (int x=w; x<z; x++){
            gotoxy (x, y);
            color (9);
            printf ("%c", 219);
        }
    }
}

int validacionchar (char n[30], int flag){
int i = 0;
int j;
    j=strlen(n);
    while (i<j && flag == 0){
        if (isdigit(n[i]) == 0){
            i++;
        }
        else {
            flag = 1;
        }
    }
return flag;
}

int validaciondni (int dni, int y, int w, int z){
int flag = 0;
        flag = verificardni(dni, flag);
        if (flag == 1){
            gotoxy (48, 12);
            printf ("Ingrese un D.N.I valido...");
            for (int x=w; x<z; x++){
                gotoxy (x, y);
                color (9);
                printf ("%c", 219);
            }
        }
return flag;
}

int verificardni (int dni, int flag){
    if (dni > 1000000 && dni < 99999999){
        flag = 0;
    }
    else {
        flag = 1;
    }
return flag;
}

int validacionmail (char mail[30], int y, int w, int z){
int flag = 0;
    color (159);
    if (strchr(mail, '@') == NULL){
        flag = 1;
        gotoxy (47, 12);
        printf ("Ingrese un E-Mail valido...");
        for (int x=w; x<z; x++){
            gotoxy (x, y);
            color (9);
            printf ("%c", 219);
        }
    }
return flag;
}

int dninorepetido(int dni){
    int flag = 0;
    stcliente c;
    limpiarvalidacion();
    color (159);
    FILE *parchcli = fopen(AR_CLI,"rb");
    if(parchcli){
        while(flag == 0 && fread(&c, sizeof(stcliente), 1, parchcli) > 0){
            if(dni == c.dni && c.baja == 0){
                flag = 1;
            }
        }
        fclose(parchcli);
    }
    if (flag == 1){
        gotoxy (38, 12);
        printf ("Este D.N.I ya esta usado para otro cliente...");
    for (int x=42; x<70; x++){
        gotoxy (x, 20);
        color (9);
        printf ("%c", 219);
    }
    }
    return flag;
}

int validacioncelular (char movil[15], int y, int w, int z){
int i = 0;
int flag = 0;
int j;
    j=strlen(movil);
    while (i<j && flag == 0){
        if (j>=9 && j<=11){
            if (isdigit(movil[i]) != 0){
                i++;
            }
        }
        else {
            flag = 1;
        }
    }
    if (flag == 1){
        gotoxy (47, 12);
        printf ("Ingrese un celular valido...");
        for (int x=w; x<z; x++){
            gotoxy (x, y);
            color (9);
            printf ("%c", 219);
        }
    }
return flag;
}
