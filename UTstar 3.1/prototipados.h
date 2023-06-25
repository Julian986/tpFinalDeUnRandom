#ifndef PROTOTIPADOS_H_INCLUDED
#define PROTOTIPADOS_H_INCLUDED

#define AR_CLI "archivoclientes.dat"
#define AR_CON "archivoconsumos.dat"

typedef struct{
   int  id; /// campo único y autoincremental
   int nroCliente;
   char nombre[30];
   char apellido[30];
   int dni;
   char email[30];
   char domicilio[45];
   char movil[15];
   int baja; /// 0 si está activo - 1 si está eliminado
}stcliente;

typedef struct{
   int id;  /// campo único y autoincremental
   int idCliente;
   int anio;
   int mes; /// 1 a 12
   int dia; /// 1 a … dependiendo del mes
   int datosConsumidos;  /// expresados en mb.
   int baja; /// 0 si está activo - 1 si está eliminado
}stconsumo;

void menu ();
void fondo ();
void opcionesmenu ();
void clientes_consumos (int opc);

/// clientes
int idautoincremental ();
int ncroclienteautoincremental ();
stcliente altauncliente ();
void archivo (stcliente c);
void guardaclienteenarchivo ();
void muestrauncliente (stcliente c, int y);
void leerarchivoclientes ();
int buscapordni(int dni);
void dardebajacliente();
int dardebaja (int pos);
void modificaruncliente ();
int modificarpordni (int dni, int flag);
stcliente modificarcliente(stcliente c);
void consultacliente ();
int consultapordni (int dni);

///visual clientes
void menuclientes ();
void visualaltacliente ();
void visuallistadoclientes ();
void visualbajacliente ();
void visualmodificarcliente (stcliente c);
void visualconsultacliente (stcliente c);

///consumos
void parametrosmodcon (int id_cliente);
int modificacionporfecha (int dia, int mes, int anio, int id);
stconsumo modconsumo(stconsumo aux);

///funcion extra
void seleccionarcliente (int random);

#endif // PROTOTIPADOS_H_INCLUDED
