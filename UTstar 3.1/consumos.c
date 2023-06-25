#include <stdio.h>
#include <stdlib.h>
#include "prototipados.h"
#include "gotoxy.h"
#include <windows.h>
#include "ctype.h"
#include "string.h"
#include "time.h"

/******************************************************************
*
*   busca id y nro de cliente y lo carga en id y nrocliente consumo
*
*******************************************************************/

int buscaidcliente (){
int dni;
int pos = -1;
    visualingresedni();
    gotoxy (52, 11);
    hidecursor(1);
    printf ("<< ALTA CONSUMO >>");
    gotoxy (57, 13);
    fflush (stdin);
    scanf ("%d", &dni);
    pos = buscapordni(dni);
return pos;
}

/***********************
*
*   id autoincremental
*
************************/

int idautoincrementalconsumo (){
stconsumo con;
int id=0;
    FILE *parchcon = fopen(AR_CON, "rb");
    if(parchcon){
        fseek(parchcon, sizeof(stconsumo)*(-1),SEEK_END);
        if(fread(&con ,sizeof(stconsumo),1,parchcon) > 0){
            id = con.id;
        }
        fclose(parchcon);
    }
return id;
}

/*****************************************
*
*   valida un cliente para cargar consumo
*
******************************************/

int validacionbaja (int pos, int val){
stconsumo con;
stcliente c;
    FILE *parchcli = fopen (AR_CLI, "rb");
        if (parchcli){
            fseek(parchcli, sizeof(stcliente)*pos, SEEK_SET);
            fread(&c, sizeof(stcliente), 1, parchcli);
            if (c.baja == 1){
                val = 1;
            }
            fclose (parchcli);
        }
return val;
}

stconsumo validacion (int pos){
stconsumo con;
stcliente c;
    FILE *parchcli = fopen (AR_CLI, "rb");
        if (parchcli){
            fseek(parchcli, sizeof(stcliente)*pos, SEEK_SET);
            fread(&c, sizeof(stcliente), 1, parchcli);
            con.idCliente = c.id;
            con.baja = c.baja;
            fclose (parchcli);
        }
return con;
}

/**************************
*
*   carga un consumo
*
**************************/

stconsumo cargaconsumo (){
stconsumo con;
int pos = -1;
int val = 0;
int aux;
    pos = buscaidcliente();
    val = validacionbaja (pos, val);
    if (pos == -1){
        gotoxy (47, 15);
        printf ("no se encuentra el cliente...");
    }
    else if (val == 0){
        aux = idautoincrementalconsumo ();
        con.id = aux + 1;
        con = validacion (pos);
        visualaltaconsumo ();
        gotoxy (54, 14);
        printf ("%d", con.idCliente);
        gotoxy (40, 16);
        fflush(stdin);
        scanf ("%d", &con.dia);
        gotoxy (40, 18);
        fflush(stdin);
        scanf ("%d", &con.mes);
        gotoxy (40, 20);
        fflush(stdin);
        scanf ("%d", &con.anio);
        gotoxy (46, 22);
        fflush(stdin);
        scanf ("%d", &con.datosConsumidos);
        con.baja = 0;
    }
    else if (val == 1){
        gotoxy (47, 15);
        printf ("el cliente fue dado de baja");
    }
return con;
}

/**************************
*
*   archivo de consumo
*
***************************/

void archivoconsumo (stconsumo con){
    FILE *parchcon = fopen (AR_CON, "ab");
    if (parchcon){
        fwrite (&con, sizeof(stconsumo), 1, parchcon);
        fclose (parchcon);
    }
}

/*****************NO FUNCIONA******************/
/*
int sumaigualfecha (int consumo, int dia, int mes, int anio){
stconsumo aux;
int flag = 0;
FILE *parchcon = fopen (AR_CON, "r+b");
    if (parchcon){
        while (flag == 0 && fread(&aux, sizeof(stconsumo), 1, parchcon) > 0){
            if (aux.dia == dia && aux.mes == mes && aux.anio == anio && aux.baja == 0){
                fseek(parchcon, sizeof(stconsumo)*(-1), SEEK_CUR);
                aux.datosConsumidos = aux.datosConsumidos + consumo;
                fwrite(&aux, sizeof (stcliente), 1, parchcon);
                flag = 1;
            }
        }
        fclose (parchcon);
    }
return flag;
}
int busquedamismoid (int id, int flag){
stconsumo aux;
FILE *parchcon = fopen (AR_CON, "rb");
    if (parchcon){
        while (flag == 0 && fread(&aux, sizeof(stconsumo), 1, parchcon) > 0){
            if (id == aux.idCliente){
                printf ("id 1: %d\n", id);
                printf ("id 2: %d\n", aux.idCliente);
                system ("pause");
                flag = 1;
            }
        }
        fclose (parchcon);
    }
return flag;
}
*/
/****************LA IDEA ERA HACER QUE SUME CONSUMOS SI LA FECHA ES IGUAL PERO POR FALTA DE TIEMPO NO VA A FUNCIONAR****************/

/*******************************
*
*   guarda consumo en archivo
*
********************************/

void guardarenarchivo (){
stconsumo con;
char salir;
const char ESC = 27;
    do{
        con = cargaconsumo();
        archivoconsumo (con);
        printf ("\n");
        hidecursor(0);
        printf ("\t\t\t\t\tSi no desea cargar mas consumos, presione ESC...");
        salir = getche();
        system ("cls");
    }while (salir != ESC);
}

/*************************************
*
*   muestra consumos de un cliente
*
***************************************/

void muestraconsumoscliente (){
int dni;
int pos = -1;
int y = 12;
int id_cliente;
stconsumo con;
stcliente c;
    visualingresedni();
    gotoxy (51, 11);
    printf ("<< LISTADO CONSUMO >>");
    hidecursor (1);
    gotoxy (57, 13);
    fflush (stdin);
    scanf ("%d", &dni);
    pos = buscapordni(dni);
    if (pos != -1){
    FILE *parchcli = fopen (AR_CLI, "rb");
    FILE *parchcon = fopen (AR_CON, "rb");
        if (parchcon && parchcli){
            fseek(parchcli, sizeof(stcliente)*pos, SEEK_SET);
            fread(&c, sizeof(stcliente), 1, parchcli);
            if (c.baja == 0){
                visualconsultaconsumo ();
                muestraclienteconsumo (c);
                id_cliente = c.id;
                while (fread(&con, sizeof(stconsumo), 1, parchcon) > 0){
                    if (con.baja == 0 && con.idCliente == id_cliente){
                        muestraconsumo (con, y);
                        y++;
                    }
                }
                gotoxy (0, 21);
            }
            else {
                gotoxy (47, 15);
                printf ("el cliente fue dado de baja");
                gotoxy (40, 16);
            }
            fclose (parchcli);
            fclose (parchcon);
        }
    }
    else {
        gotoxy (47, 15);
        printf ("no se encuentra el cliente");
        gotoxy (40, 16);
    }
}

/***************************
*
*   da de baja un consumo
*
***************************/

void bajaconsumo (){
int dni;
int pos;
int id_cliente;
stconsumo con;
stcliente c;
    visualingresedni();
    gotoxy (51, 11);
    printf ("<< BAJA CONSUMO >>");
    hidecursor (1);
    gotoxy (57, 13);
    fflush (stdin);
    scanf ("%d", &dni);
    pos = buscapordni(dni);
    if (pos == -1){
        gotoxy (47, 15);
        printf ("no se encuentra el cliente\n");
    }
    else{
        FILE *parchcli = fopen (AR_CLI, "rb");
        if (parchcli){
            fseek(parchcli, sizeof(stcliente)*pos, SEEK_SET);
            fread(&c, sizeof(stcliente), 1, parchcli);
            id_cliente = c.id;
            fclose(parchcli);
        }
        visualbajaconsumo ();
        parametrosconsumo(id_cliente);
    }
}

/******************************
*
*   verifica consumo
*
******************************/

void parametrosconsumo (int id_cliente){
int flag = 0;
int dia;
int mes;
int anio;
    hidecursor(1);
    gotoxy (52, 11);
    printf ("<< BAJA CONSUMO >>");
    gotoxy (45, 14);
    printf ("ingrese el dia del consumo: ");
    gotoxy (45, 16);
    printf ("ingrese el mes: ");
    gotoxy (45, 18);
    printf ("ingrese el a%co: ", 164);
    gotoxy (73, 14);
    scanf ("%d", &dia);
    gotoxy (61, 16);
    scanf ("%d", &mes);
    gotoxy (61, 18);
    scanf ("%d", &anio);
    flag = busquedaybajaporfecha(dia, mes, anio, id_cliente);
    if (flag == 1){
        gotoxy (47, 22);
        printf ("consumo dado de baja con exito!\n");
    }
    else{
        gotoxy (47, 22);
        printf ("no se encuentra el consumo\n");
    }
}

/**************************
*
*   da de baja un consumo
*
***************************/

int busquedaybajaporfecha (int dia, int mes, int anio, int id){
stconsumo con;
int flag = 0;
    FILE *parchcon = fopen (AR_CON, "r+b");
    if (parchcon){
        while (flag == 0 && fread(&con, sizeof(stconsumo), 1, parchcon) > 0){
            if (con.dia == dia && con.mes == mes && con.anio == anio && con.idCliente == id && con.baja == 0){
                fseek(parchcon, sizeof(stconsumo)*(-1),SEEK_CUR);
                con.baja = 1;
                fwrite(&con, sizeof(stconsumo),1 , parchcon);
                flag = 1;
            }
        }
        fclose(parchcon);
    }
return flag;
}

/***************************
*
*   modifica un consumo
*
****************************/

void modificaconsumo (){
int dni;
int pos;
int id_cliente;
stconsumo con;
stcliente c;
    visualingresedni();
    gotoxy (50, 11);
    printf ("<< MODIFICA CONSUMO >>");
    hidecursor (1);
    gotoxy (57, 13);
    fflush (stdin);
    scanf ("%d", &dni);
    pos = buscapordni(dni);
    if (pos == -1){
        gotoxy (47, 15);
        printf ("no se encuentra el cliente\n");
    }
    else{
        FILE *parchcli = fopen (AR_CLI, "rb");
        if (parchcli){
            fseek(parchcli, sizeof(stcliente)*pos, SEEK_SET);
            fread(&c, sizeof(stcliente), 1, parchcli);
            if (c.baja == 0){
                id_cliente = c.id;
                visualbajaconsumo ();
                parametrosmodcon(id_cliente);
            }
            else {
                gotoxy (47, 15);
                printf ("el cliente fue dado de baja\n");
            }
            fclose(parchcli);
        }
    }
}
/******************************
*
*   verifica consumo
*
******************************/

void parametrosmodcon (int id_cliente){
int flag = 0;
int dia;
int mes;
int anio;
    hidecursor(1);
    gotoxy (51, 11);
    printf ("<< MODFICA CONSUMO >>");
    gotoxy (45, 14);
    printf ("ingrese el dia del consumo: ");
    gotoxy (45, 16);
    printf ("ingrese el mes: ");
    gotoxy (45, 18);
    printf ("ingrese el a%co: ", 164);
    gotoxy (73, 14);
    scanf ("%d", &dia);
    gotoxy (61, 16);
    scanf ("%d", &mes);
    gotoxy (62, 18);
    scanf ("%d", &anio);
    flag = modificacionporfecha(dia, mes, anio, id_cliente);
    if (flag == 1){
        gotoxy (47, 22);
        printf ("consumo modificado con exito!\n");
    }
    else{
        gotoxy (47, 22);
        printf ("no se encuentra el consumo\n");
    }
}

/**************************
*
*   modifica consumo
*
***************************/

int modificacionporfecha (int dia, int mes, int anio, int id){
stconsumo aux;
stconsumo con;
int flag = 0;
    FILE *parchcon = fopen (AR_CON, "r+b");
    if (parchcon){
        while (flag == 0 && fread(&aux, sizeof(stconsumo), 1, parchcon) > 0){
            if (aux.dia == dia && aux.mes == mes && aux.anio == anio && aux.idCliente == id && aux.baja == 0){
                fseek(parchcon, sizeof(stconsumo)*(-1),SEEK_CUR);
                visualmostrarmodificarconsumo (aux);
                con = modconsumo(aux);
                fwrite(&con, sizeof(stconsumo),1 , parchcon);
                flag = 1;
            }
        }
        fclose(parchcon);
    }
return flag;
}

/************************
*
*   modifica un consumo
*
*************************/

stconsumo modconsumo(stconsumo aux){
stconsumo con;
visualmodificarconsumo ();
    con.id = aux.id;
    con.idCliente = aux.idCliente;
    gotoxy (71, 14);
    scanf ("%d", &con.dia);
    gotoxy (83, 14);
    scanf ("%d", &con.mes);
    gotoxy (98, 14);
    scanf ("%d", &con.anio);
    gotoxy (111, 14);
    scanf ("%d", &con.datosConsumidos);
    con.baja = aux.baja;
return con;
}

/***********************
*
*   consulta consumo
*
************************/

void consultaconsumo (){
int dni;
int pos;
int id_cliente;
stconsumo con;
stcliente c;
    visualingresedni();
    gotoxy (49, 11);
    printf ("<< CONSULTA CONSUMO >>");
    hidecursor (1);
    gotoxy (57, 13);
    fflush (stdin);
    scanf ("%d", &dni);
    pos = buscapordni(dni);
    if (pos == -1){
        gotoxy (47, 15);
        printf ("no se encuentra el cliente\n");
    }
    else{
        FILE *parchcli = fopen (AR_CLI, "rb");
        if (parchcli){
            fseek(parchcli, sizeof(stcliente)*pos, SEEK_SET);
            fread(&c, sizeof(stcliente), 1, parchcli);
            if (c.baja == 0){
                id_cliente = c.id;
                visualbajaconsumo ();
                parametrosconsulta (id_cliente);
                gotoxy(0, 23);
            }
            else{
                gotoxy (47, 15);
                printf ("el cliente fue dado de baja\n");
            }
            fclose(parchcli);
        }
    }
}

/****************************
*
*   dia, mes, año para consulta
*
*****************************/

void parametrosconsulta (int id_cliente){
int flag = 0;
int dia;
int mes;
int anio;
    hidecursor(1);
    gotoxy (51, 11);
    printf ("<< CONSULTA CONSUMO >>");
    gotoxy (45, 14);
    printf ("ingrese el dia del consumo: ");
    gotoxy (45, 16);
    printf ("ingrese el mes: ");
    gotoxy (45, 18);
    printf ("ingrese el a%co: ", 164);
    gotoxy (73, 14);
    scanf ("%d", &dia);
    gotoxy (61, 16);
    scanf ("%d", &mes);
    gotoxy (61, 18);
    scanf ("%d", &anio);
    flag = consulta(dia, mes, anio, id_cliente);
    if (flag == 0){
        gotoxy (47, 22);
        printf ("no se encuentra el consumo");
    }
}

/****************************
*
*   busca y muestra consulta
*
*****************************/

int consulta (int dia, int mes, int anio, int id){
stconsumo aux;
stconsumo con;
int flag = 0;
    FILE *parchcon = fopen (AR_CON, "r+b");
    if (parchcon){
        while (flag == 0 && fread(&aux, sizeof(stconsumo), 1, parchcon) > 0){
            if (aux.dia == dia && aux.mes == mes && aux.anio == anio && aux.idCliente == id && aux.baja == 0){
                fseek(parchcon, sizeof(stconsumo)*(-1),SEEK_CUR);
                visualconsultaunconsumo (aux);
                flag = 1;
            }
        }
        fclose(parchcon);
    }
return flag;
}

/*************************
*
*   seleccionar cliente al azar
*
**************************/

void easteregg (){
int random;
stconsumo con;
    printf ("Felicitaciones! has encontrado la funcion oculta...\n");
    printf ("Esta funcion carga de un cliente al azar, un consumo al azar. Usala bajo tu responsabilidad.\n");
    printf ("Tene cuidado que la AFIP te puede rastrear si nota movimientos sospechosos\n");
    printf ("vas a ser el empleado del a%co con esta funcion... Tu jefe te va a amar!!\n", 164);
    random = seleccionalazar();
    printf ("\n");
    printf ("id cliente random: %d\n", random);
    seleccionarcliente(random);
    system ("pause");
}


int seleccionalazar (){
stcliente c;
int dim;
int va = 0;
int idclientes [dim];
int idrandom;
int valor;
FILE *parchcli = fopen (AR_CLI, "rb");
    if (parchcli){
        fseek(parchcli,0, SEEK_END);
        dim = ftell (parchcli)/ sizeof(stcliente);
        fseek(parchcli,0, SEEK_SET);
        while (va<dim && fread(&c, sizeof(stcliente), 1, parchcli) > 0){
            if (c.baja == 0){
                idclientes [va] = c.nroCliente;
                va++;
            }
        }
        fclose (parchcli);
    }
    valor = rand() % va;
    idrandom = idclientes [valor];
return idrandom;
}

void seleccionarcliente (int random){
stconsumo con;
int N = 2020;
int M = 2010;
int flag = 0;
int id;
FILE *parchcon = fopen (AR_CON, "ab");
    if (parchcon){
       id = idautoincrementalconsumo();
        con.id = id + 1;
        con.idCliente = random;
        con.dia = rand ()%30;
        con.mes = rand ()%12;
        con.anio = rand ()%(N-M+1) + M;
        con.datosConsumidos = rand ()%2500;
        con.baja = 0;
        fwrite (&con, sizeof(stconsumo),1, parchcon);
        fclose (parchcon);
    }
}
