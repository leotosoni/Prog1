#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BORRAR system("cls")
#define ESPACIO printf("\n")
#define ARCHIVO_USUARIO "usuarios.dat" // el nombre del archivo de usuario
#define DIMENSION 50

typedef struct
{
    char PLATOS [DIMENSION];
    // para ranking
    int contador ;

}stCOMIDAS ;

typedef struct usuario
{
    char nombreUsuario[DIMENSION];
    char contrasena[DIMENSION];
    char nombre[DIMENSION];
    char apellido[DIMENSION];
    char barrio[DIMENSION];
    char email[DIMENSION];
    char fechaDeNacimiento[DIMENSION];
    char tipoDeComida[DIMENSION];
    int acceso; /// usuario comun 0 - administrador 1
    int estado; /// activo 0 - eliminado 1

}stUsuario;



int main()
{
//    stUsuario lista[50];
//    stUsuario usuario;
//    int validos = 0;
//
//    FILE* archivo = fopen("usuario.bin", "rb");
//    if(archivo!=NULL)
//    {
//        while(fread(&usuario, sizeof(stUsuario), 1, archivo)>0)
//        {
//            lista[validos]=usuario;
//            validos++;
//        }
//        fclose(archivo);
//    }
//
//    FILE *file = fopen("usuarios.dat", "wb");
//    if(file!=NULL)
//    {
//        for(int i = 0; i<validos ; i++)
//        {
//        fwrite(&lista[i], sizeof(stUsuario), 1, file);
//        }
//        fclose(file);
//    }
    //guardarUsuarios();
    menu_principal();

    return 0;
}

void menu_principal()
{
    char opcion;
    do
    {
        BORRAR;
        printf ("\n\n\n\t\tMENU PRINCIPAL\n");
        printf ("\n\t[1] - Menu USUARIOS");
        ESPACIO;
        printf ("\n\t[2] - Menu RESTAURANTES");
        ESPACIO;
        printf ("\n\t[3] - Salir\n");
        fflush (stdin);
        opcion = getch ();
    }
    while (opcion < '1' || opcion > '3');


    switch (opcion)
    {
    case '1':
        menu_usuarios();
        break ;
    case '2':
        // menu_restaurantes(); /// pedirle a Hugo
        break ;
    case '3':
//        salir();
        break ;
    }
}

void menu_usuarios()
{

    char opcion;
    do
    {
        BORRAR;
        printf("\n\n\n\t\tPANEL DE USUARIOS\n\n");
        printf("\t[1] - Listado de usuarios\n");
        ESPACIO;
        printf("\t[2] - Busqueda por Nombre\n");
        ESPACIO;
        printf("\t[3] - Busqueda por Apellido\n");
        ESPACIO;
        printf("\t[4] - Busqueda por tipo de comida\n");
        ESPACIO;
        printf("\t[5] - Modificacion de usuario\n");
        ESPACIO;
        printf("\t[6] - Baja de usuario\n");
        ESPACIO;
        printf("\t[7] - Borrar todos los usuarios\n");
        ESPACIO;
        printf("\t[8] - Volver al menu anterior\n\n");
        fflush (stdin);
        opcion = getch ();
    }
    while (opcion < '1' || opcion > '8');

    switch (opcion)
    {
    case '1':
        listado_usuarios();
        break ;
    case '2':
        buscar_por_nombre();
        break ;
    case '3':
        buscar_por_apellido();
        break ;
    case '4':
        buscar_por_comida();
        break ;
    case '5':
        modificacion_usuario();
        break ;
    case '6':
        baja_usuario();
        break ;
    case '7':
        borrar_usuarios_todos();
        break ;
    case '8':
        menu_principal();
        break ;
    }
}

void listado_usuarios()
{
    BORRAR;
    FILE* file = fopen(ARCHIVO_USUARIO,"rb");
    if(file!=NULL)
    {
        stUsuario usuario;

        encabezado_lista();
        printf("\n");
        while(fread(&usuario, sizeof(usuario), 1, file)>0)
        {
            mostrarUsuario2(usuario);
        }
        fclose(file);
    }
    ESPACIO;
    salir_con_escape();
}

void buscar_por_nombre()
{
    char tecla = 13;
    int contador = 0;

    while(tecla == 13)
    {
        FILE* file = fopen(ARCHIVO_USUARIO,"rb");

        if(file!=NULL)
        {
            BORRAR;
            stUsuario usuario; // crea un usuario para guardar los datos
            char nombre_a_buscar[DIMENSION]; // creo un arreglo para guardar el nombre a buscar
            char titulo[]="BUSQUEDA POR NOMBRE";
            mensajeExitos(titulo);
            printf("Ingrese el nombre del usuario que desea buscar: ");
            fflush(stdin);
            gets(nombre_a_buscar);
            BORRAR;
            while(fread(&usuario, sizeof(usuario), 1, file)>0)
            {
                if(strcmpi(usuario.nombre,nombre_a_buscar)==0 && usuario.estado == 0)
                {
                    mostrarUsuario(usuario);
                    contador++;
                }
            }
            printf("Se encontraron %d coincidencia(s)\n", contador);
            fclose(file);
        }
        mensaje_otra_busqueda();
        tecla = getch();
        contador = 0;
    }
    menu_usuarios();

}

void buscar_por_apellido()
{

    int contador = 0;
    char tecla = 13;

    while(tecla == 13)
    {
        FILE* file = fopen(ARCHIVO_USUARIO,"rb");
        if(file!=NULL)
        {
            BORRAR;
            stUsuario usuario; // crea un usuario para guardar los datos
            char apellido_a_buscar[DIMENSION]; // creo un arreglo para guardar el nombre a buscar
            char titulo[]="BUSQUEDA POR APELLIDO";
            mensajeExitos(titulo);
            printf("Ingrese el apellido del usuario que desea buscar: ");
            fflush(stdin);
            gets(apellido_a_buscar);
            BORRAR;
            while(fread(&usuario, sizeof(usuario), 1, file)>0)
            {
                if(strcmpi(usuario.apellido,apellido_a_buscar)==0 && usuario.estado == 0)
                {
                    mostrarUsuario(usuario);
                    contador++;
                }
            }
            printf("Se encontraron %d coincidencia(s)\n", contador);
            fclose(file);
        }
        mensaje_otra_busqueda();
        tecla = getch();
        contador = 0;
    }
    menu_usuarios();
}
void buscar_por_comida()
{

    int contador = 0;
    char tecla = 13;

    while(tecla == 13)
    {
        FILE* file = fopen(ARCHIVO_USUARIO,"rb");
        if(file!=NULL)
        {
            BORRAR;
            stUsuario usuario; // crea un usuario para guardar los datos
            char tipo_comida[DIMENSION]; // creo un arreglo para guardar el nombre a buscar
            char titulo[]="BUSQUEDA POR TIPO DE COMIDA";
            mensajeExitos(titulo);
            printf("Ingrese el tipo de comida que desea buscar: ");
            fflush(stdin);
            gets(tipo_comida);
            BORRAR;
            while(fread(&usuario, sizeof(usuario), 1, file)>0)
            {
                if(strstr(usuario.tipoDeComida,tipo_comida)!=NULL && usuario.estado == 0)
                {
                    mostrarUsuario(usuario);
                    contador++;
                }
            }
            printf("Se encontraron %d coincidencia(s)\n", contador);
            fclose(file);
        }
        mensaje_otra_busqueda();
        tecla = getch();
        contador = 0;
    }
    menu_usuarios();
}

void modificacion_usuario()
{
    char opcion;
    do
    {
        BORRAR;
        printf ("\n\n\n\t\tMENU MODIFICACION DE DATOS\n\n");
        printf("\t[1] - Modificacion del NOMBRE\n");
        ESPACIO;
        printf("\t[2] - Modificacion del APELLIDO\n");
        ESPACIO;
        printf("\t[3] - Modificacion del NOMBRE DE USUARIO\n");
        ESPACIO;
        printf("\t[4] - Modificacion de la CONTRASENIA\n");
        ESPACIO;
        printf("\t[5] - Modificacion del TIPO DE COMIDA\n");
        ESPACIO;
        printf("\t[6] - Modificacion del E-MAIL\n");
        ESPACIO;
        printf("\t[7] - Modificacion de la FECHA DE NACIMIENTO\n");
        ESPACIO;
        printf("\t[8] - Modificacion del tipo de ACCESO\n");
        ESPACIO;
        printf("\t[9] - Volver al menu anterior\n");
        fflush (stdin);
        opcion = getch ();
    }
    while (opcion < '1' || opcion > '9');

    switch (opcion)
    {
    case '1':
        modificacion_nombre();
        break ;
    case '2':
        modificacion_apellido();
        break ;
    case '3':
        modificacion_nombreUsuario();
        break ;
    case '4':
        modificacion_contrasenia();
        break ;
    case '5':
        modificacion_tipocomida();
        break ;
    case '6':
        modificacion_email();
        break ;
    case '7':
        modificacion_fecha();
        break ;
    case '8':
        modificacion_acceso();
        break ;
    case '9':
        menu_usuarios();
        break ;
    }
}

void baja_usuario()
{
    BORRAR;
    FILE* file = fopen(ARCHIVO_USUARIO, "r+b");

    char tecla = 13;
    int flag = 0;
    if(file!=NULL)
    {
        while(tecla == 13)
        {
            stUsuario usuario;
            char nombreUsuario[20];
            char titulo[]="BAJA DE USUARIO";
            mensajeExitos(titulo);
            printf("Ingrese el nombre de usuario: ");
            fflush(stdin);
            gets(nombreUsuario);
            while(fread(&usuario, sizeof(stUsuario), 1, file)>0)
            {
                if(strcmp(nombreUsuario, usuario.nombreUsuario)==0)
                {

                    printf("\n\t\t||| USUARIO ENCONTRADO |||\n");
                    printf("\nConfirma la baja del usuario %s?\n", nombreUsuario);
                    printf("\t%c Para SI, apriete ENTER\n",26);
                    printf("\t%c Para volver al menu anterior, apriete cualquier otra tecla\n",26);
                    fflush(stdin);
                    tecla = getch();
                    if(tecla == 13)
                    {
                        usuario.estado = 1;
                        fseek(file, sizeof(stUsuario)*(-1),SEEK_CUR);
                        fwrite(&usuario, sizeof(stUsuario), 1, file);
                        fseek(file, sizeof(stUsuario),SEEK_CUR);
                        BORRAR;
                        printf("\nEl usuario ha sido dado de baja\n");
                        flag = 1;
                    }
                    else
                    {
                        flag = 1;
                        BORRAR;
                    }

                }
            }
            if(flag == 0)
            {
                usuario_no_encontrado();
            }
            rewind(file);
            flag = 0;
            printf("\n\nDesea hacer la baja de otro usuario?\n\n");
            printf("\t%c Apriete ENTER si desea realizar otro cambio\n", 26);
            printf("\t%c Apriete cualquier otra tecla para volver al menu anterior\n", 26);
            fflush(stdin);
            tecla = getch();
            BORRAR;
        }
        fclose(file);
    }
    menu_usuarios();
}

void borrar_usuarios_todos()
{
    BORRAR;
    char tecla = 0;
    char titulo[]="ELIMINACION DE TODOS LOS USUARIOS";
    mensajeExitos(titulo);
    printf("Esta seguro que desea eliminar todos los usuarios?\n");
    printf("\t%cPara continuar, presione ENTER\n",26);
    printf("\t%cPara volver al menu anterior, presione cualquier otra tecla\n",26);
    fflush(stdin);
    tecla = getch();
    if(tecla == 13)
    {
        FILE* file = fopen(ARCHIVO_USUARIO,"r+b");

        if(file!=NULL)
        {
            stUsuario usuario; // crea un usuario para guardar los datos

            while(fread(&usuario, sizeof(usuario), 1, file)>0)
            {
                usuario.estado = 1;
                fseek(file, sizeof(stUsuario)*(-1),SEEK_CUR);
                fwrite(&usuario, sizeof(stUsuario), 1, file);
                fseek(file, sizeof(stUsuario),SEEK_CUR);
            }
            fclose(file);
            BORRAR;
            printf("Se eliminaron todos los usuarios exitosamente\n");
            printf("Presione cualquier tecla para volver al menu anterior\n");
            system("pause");
        }
    }
    else
    {
    }
    menu_usuarios();

}

void salir_con_escape()
{
    char salir = 0;
    fflush(stdin);

    while(salir!=27)
    {
        printf("Para salir, presione ESC\n");
        salir = getch();

    }

    if(salir == 27)
    {
        menu_usuarios();
    }
}

void mostrarUsuario(stUsuario usuario)
{
    char activo[] = "Activo";
    char inactivo[] = "Inactivo";
    char user[] = "User";
    char admin[] = "Admin";
    printf("NOMBRE: %s\n", usuario.nombre);
    printf("APELLIDO: %s\n", usuario.apellido);
    printf("NOMBRE DE USUARIO: %s\n", usuario.nombreUsuario);
    printf("CONTRASENIA: %s\n", usuario.contrasena);
    printf("TIPO DE COMIDA: %s\n", usuario.tipoDeComida);
    printf("TIPO DE ACCESO: ");
     if(usuario.acceso == 0)
    {
        printf("%s\n", user);
    }
    else
    {
        printf("%s\n", admin);
    }
    printf("ESTADO: ");
    if(usuario.estado == 0)
    {
        printf("%s\n", activo);
    }
    else
    {
        printf("%s\n", inactivo);
    }
    printf("----------------------------\n");

}

void mostrarUsuario2(stUsuario usuario)
{
    char space[] = " ";

    int letrasNombre = tamanioNombre() - strlen(usuario.nombre);
    char espaciosNombre[50];
    strcpy(espaciosNombre, space);
    for(int i = 0 ; i < letrasNombre+3 ; i++)
    {
        strcat(espaciosNombre,space);
    }

    int letrasApellido = tamanioApellido()-strlen(usuario.apellido);
    char espaciosApellido[50];
    strcpy(espaciosApellido, space);
    for(int i = 0 ; i < letrasApellido+3 ; i++)
    {
        strcat(espaciosApellido,space);
    }

    int letrasNomU = tamanioNomUsuario()-strlen(usuario.nombreUsuario);
    char espaciosNomU[50];
    strcpy(espaciosNomU, space);
    for(int i = 0 ; i < letrasNomU+3 ; i++)
    {
        strcat(espaciosNomU,space);
    }

    int letrasContra = tamanioContrasenia()-strlen(usuario.contrasena);
    char espaciosContra[50];
    strcpy(espaciosContra, space);
    for(int i = 0 ; i < letrasContra+3 ; i++)
    {
        strcat(espaciosContra,space);
    }

    int letrasComida = tamanioComida()- strlen(usuario.tipoDeComida);
    char espaciosComida[50];
    strcpy(espaciosComida, space);

    for(int i = 0 ; i < letrasComida+3 ; i++)
    {
        strcat(espaciosComida,space);
    }

    int letrasEmail = tamanioEmail()-strlen(usuario.email);
    char espaciosEmail[DIMENSION];
    strcpy(espaciosEmail,space);
    for(int i = 0 ; i < letrasEmail+3 ; i++)
    {
        strcat(espaciosEmail,space);
    }

    int letrasFecha = tamanioFecha()-strlen(usuario.fechaDeNacimiento);
    char espaciosFecha[DIMENSION];
    strcpy(espaciosFecha,space);
    for(int i = 0 ; i < letrasFecha+5 ; i++)
    {
        strcat(espaciosFecha,space);
    }


    int letrasBarrio = tamanioBarrio()-strlen(usuario.barrio);
    char espaciosBarrio[DIMENSION];
    strcpy(espaciosBarrio,space);
    for(int i = 0 ; i < letrasBarrio+3 ; i++)
    {
        strcat(espaciosBarrio,space);
    }


    char admin[DIMENSION] = "Admin   ";
    char user[DIMENSION] = "User    ";
    char activo[] = "Activo";
    char inactivo[] = "Inactivo";

    if(usuario.estado == 0)
    {
        if(usuario.acceso == 0)
        {
            printf("\t%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",
                   usuario.nombre,
                   espaciosNombre,
                   usuario.apellido,
                   espaciosApellido,
                   usuario.nombreUsuario,
                    espaciosNomU,
                    usuario.contrasena,
                    espaciosContra,
                    usuario.email,
                    espaciosEmail,
                    usuario.fechaDeNacimiento,
                    espaciosFecha,
                    usuario.barrio,
                    espaciosBarrio,
                    usuario.tipoDeComida,
                     espaciosComida,
                        user,
                        activo);
        }
        else
        {
            printf("\t%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",usuario.nombre, espaciosNombre, usuario.apellido, espaciosApellido, usuario.nombreUsuario, espaciosNomU, usuario.contrasena, espaciosContra, usuario.email, espaciosEmail, usuario.fechaDeNacimiento, espaciosFecha, usuario.barrio, espaciosBarrio, usuario.tipoDeComida, espaciosComida, admin, activo);
        }
    }

    if(usuario.estado == 1)
    {
        if(usuario.acceso == 0)
        {
            printf("\t%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",usuario.nombre, espaciosNombre, usuario.apellido, espaciosApellido, usuario.nombreUsuario, espaciosNomU, usuario.contrasena, espaciosContra, usuario.email, espaciosEmail, usuario.fechaDeNacimiento, espaciosFecha, usuario.barrio, espaciosBarrio, usuario.tipoDeComida, espaciosComida, user, inactivo);
        }
        else
        {
            printf("\t%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",usuario.nombre, espaciosNombre, usuario.apellido, espaciosApellido, usuario.nombreUsuario, espaciosNomU, usuario.contrasena, espaciosContra, usuario.email, espaciosEmail, usuario.fechaDeNacimiento, espaciosFecha, usuario.barrio, espaciosBarrio, usuario.tipoDeComida, espaciosComida, admin, inactivo);
        }
    }

}


void modificacion_nombre()
{
    BORRAR;
    FILE* file = fopen(ARCHIVO_USUARIO, "r+b");

    char tecla = 13;
    int flag = 0;
    if(file!=NULL)
    {
        while(tecla == 13)
        {
            stUsuario usuario;
            char nombreUsuario[20];
            char titulo[]="MODIFICACION DEL NOMBRE";
            mensajeExitos(titulo);
            printf("\nIngrese el nombre de usuario: ");
            fflush(stdin);
            gets(nombreUsuario);
            while(fread(&usuario, sizeof(stUsuario), 1, file)>0)
            {
                if(strcmp(nombreUsuario, usuario.nombreUsuario)==0)
                {
                    printf("\n\t\t||| USUARIO ENCONTRADO |||\n");
                    printf("\nNombre actual: %s\n\n", usuario.nombre);
                    printf("Ingrese un nuevo nombre: ");
                    fflush(stdin);
                    gets(&usuario.nombre);
                    fseek(file, sizeof(stUsuario)*(-1),SEEK_CUR);
                    fwrite(&usuario, sizeof(stUsuario), 1, file);
                    fseek(file, sizeof(stUsuario),SEEK_CUR);
                    flag = 1;
                    BORRAR;
                    char mensaje[]="EL NOMBRE FUE MODIFICADO CON EXITO!!";
                    mensajeExitos(mensaje);
                }
            }
            if(flag == 0)
            {
                usuario_no_encontrado();
            }
            rewind(file);
            flag = 0;
            char mensaje[]="el nombre";
            mensaje_otro_cambio(mensaje);
            fflush(stdin);
            tecla = getch();
            BORRAR;
        }
        fclose(file);
    }
    modificacion_usuario();
}

void modificacion_apellido()
{
    BORRAR;
    FILE* file = fopen(ARCHIVO_USUARIO, "r+b");

    char tecla = 13;
    int flag = 0;
    if(file!=NULL)
    {
        while(tecla == 13)
        {
            stUsuario usuario;
            char nombreUsuario[20];
            char titulo[]="MODIFICACION DEL APELLIDO";
            mensajeExitos(titulo);
            printf("\nIngrese el nombre de usuario: ");
            fflush(stdin);
            gets(nombreUsuario);
            while(fread(&usuario, sizeof(stUsuario), 1, file)>0)
            {
                if(strcmp(nombreUsuario, usuario.nombreUsuario)==0)
                {
                    printf("\n\t\t||| USUARIO ENCONTRADO |||\n");
                    printf("\nApellido actual: %s\n\n", usuario.apellido);
                    printf("Ingrese un nuevo apellido: ");
                    fflush(stdin);
                    gets(&usuario.apellido);
                    fseek(file, sizeof(stUsuario)*(-1),SEEK_CUR);
                    fwrite(&usuario, sizeof(stUsuario), 1, file);
                    fseek(file, sizeof(stUsuario),SEEK_CUR);
                    flag = 1;
                    BORRAR;
                    char mensaje[]="EL APELLIDO FUE MODIFICADO CON EXITO";
                    mensajeExitos(mensaje);
                }
            }
            if(flag == 0)
            {
                usuario_no_encontrado();
            }
            rewind(file);
            flag = 0;
            char mensaje[]="el apellido";
            mensaje_otro_cambio(mensaje);
            fflush(stdin);
            tecla = getch();
            BORRAR;
        }
        fclose(file);
    }
    modificacion_usuario();
}
void modificacion_nombreUsuario()
{
    BORRAR;
    FILE* file = fopen(ARCHIVO_USUARIO, "r+b");

    char tecla = 13;
    int flag = 0;
    if(file!=NULL)
    {
        while(tecla == 13)
        {
            stUsuario usuario;
            char nombreUsuario[20];
            char titulo[]="MODIFICACION DEL NOMBRE DE USUARIO";
            mensajeExitos(titulo);
            printf("\nIngrese el nombre de usuario: ");
            fflush(stdin);
            gets(nombreUsuario);
            while(fread(&usuario, sizeof(stUsuario), 1, file)>0)
            {
                if(strcmp(nombreUsuario, usuario.nombreUsuario)==0)
                {
                    printf("\n\t\t||| USUARIO ENCONTRADO |||\n");
                    printf("Nuevo nombre de usuario: ");
                    fflush(stdin);
                    gets(&usuario.nombreUsuario);
                    fseek(file, sizeof(stUsuario)*(-1),SEEK_CUR);
                    fwrite(&usuario, sizeof(stUsuario), 1, file);
                    fseek(file, sizeof(stUsuario),SEEK_CUR);
                    flag = 1;
                    BORRAR;
                    char mensaje[]="EL NOMBRE DE USUARIO FUE MODIFICADO CON EXITO!!";
                    mensajeExitos(mensaje);
                }
            }
            if(flag == 0)
            {
                usuario_no_encontrado();
            }
            rewind(file);
            flag = 0;
            char mensaje[]="el nombre de usuario";
            mensaje_otro_cambio(mensaje);
            fflush(stdin);
            tecla = getch();
            BORRAR;
        }
        fclose(file);
    }
    modificacion_usuario();
}
void modificacion_contrasenia()
{
    BORRAR;
    FILE* file = fopen(ARCHIVO_USUARIO, "r+b");

    char tecla = 13;
    int flag = 0;
    if(file!=NULL)
    {
        while(tecla == 13)
        {
            stUsuario usuario;
            char nombreUsuario[20];
            char titulo[]="MODIFICACION DE LA CONTRASENIA";
            mensajeExitos(titulo);
            printf("\nIngrese el nombre de usuario: ");
            fflush(stdin);
            gets(nombreUsuario);
            while(fread(&usuario, sizeof(stUsuario), 1, file)>0)
            {
                if(strcmp(nombreUsuario, usuario.nombreUsuario)==0)
                {
                    printf("\n\t\t||| USUARIO ENCONTRADO |||\n");
                    printf("\nContrasenia actual: %s\n\n", usuario.contrasena);
                    printf("Ingrese una nueva contrasenia: ");
                    fflush(stdin);
                    gets(&usuario.contrasena);
                    fseek(file, sizeof(stUsuario)*(-1),SEEK_CUR);
                    fwrite(&usuario, sizeof(stUsuario), 1, file);
                    fseek(file, sizeof(stUsuario),SEEK_CUR);
                    flag = 1;
                    BORRAR;
                    char mensaje[]="LA CONTRASENIA FUE MODIFICADA CON EXITO!!";
                    mensajeExitos(mensaje);
                }
            }
            if(flag == 0)
            {
                usuario_no_encontrado();
            }
            rewind(file);
            flag = 0;
            char mensaje[]="la contrasenia";
            mensaje_otro_cambio(mensaje);
            fflush(stdin);
            tecla = getch();
            BORRAR;
        }
        fclose(file);
    }
    modificacion_usuario();
}

void  modificacion_tipocomida()
{
    BORRAR;
    FILE* file = fopen(ARCHIVO_USUARIO, "r+b");

    char tecla = 13;
    int flag = 0;
    if(file!=NULL)
    {
        while(tecla == 13)
        {
            stUsuario usuario;
            char nombreUsuario[20];
            char titulo[]="MODIFICACION DEL TIPO DE COMIDA";
            mensajeExitos(titulo);
            printf("\nIngrese el nombre de usuario: ");
            fflush(stdin);
            gets(nombreUsuario);
            while(fread(&usuario, sizeof(stUsuario), 1, file)>0)
            {
                if(strcmp(nombreUsuario, usuario.nombreUsuario)==0)
                {

                    printf("\n\t\t||| USUARIO ENCONTRADO |||\n");
                    printf("\nTipo(s) de comida actual: %s\n\n", usuario.tipoDeComida);
                    printf("Ingrese un nuevo tipo(s) de comida: ");
                    fflush(stdin);
                    gets(&usuario.tipoDeComida);
                    fseek(file, sizeof(stUsuario)*(-1),SEEK_CUR);
                    fwrite(&usuario, sizeof(stUsuario), 1, file);
                    fseek(file, sizeof(stUsuario),SEEK_CUR);
                    flag = 1;
                    BORRAR;
                    char mensaje[]="EL CAMBIO FUE REALIZADO CON EXITO!!";
                    mensajeExitos(mensaje);
                }
            }
            if(flag == 0)
            {
                usuario_no_encontrado();
            }
            rewind(file);
            flag = 0;
            char mensaje[]="el tipo de comida";
            mensaje_otro_cambio(mensaje);
            fflush(stdin);
            tecla = getch();
            BORRAR;
        }
        fclose(file);
    }
    modificacion_usuario();
}

void modificacion_email()
{
    BORRAR;
    FILE* file = fopen(ARCHIVO_USUARIO, "r+b");

    char tecla = 13;
    int flag = 0;
    if(file!=NULL)
    {
        while(tecla == 13)
        {
            stUsuario usuario;
            char nombreUsuario[20];
            char titulo[]="MODIFICACION DEL E-MAIL";
            mensajeExitos(titulo);
            printf("\nIngrese el nombre de usuario: ");
            fflush(stdin);
            gets(nombreUsuario);
            while(fread(&usuario, sizeof(stUsuario), 1, file)>0)
            {
                if(strcmp(nombreUsuario, usuario.nombreUsuario)==0)
                {
                    printf("\n\t\t||| USUARIO ENCONTRADO |||\n");
                    printf("\nE-mail actual: %s\n\n", usuario.email);
                    printf("Ingrese un nuevo email: ");
                    fflush(stdin);
                    gets(&usuario.email);
                    fseek(file, sizeof(stUsuario)*(-1),SEEK_CUR);
                    fwrite(&usuario, sizeof(stUsuario), 1, file);
                    fseek(file, sizeof(stUsuario),SEEK_CUR);
                    flag = 1;
                    BORRAR;
                    char mensaje[]="EL EMAIL FUE MODIFICADO CON EXITO!!";
                    mensajeExitos(mensaje);
                }
            }
            if(flag == 0)
            {
                usuario_no_encontrado();
            }
            rewind(file);
            flag = 0;
            char mensaje[]="el email";
            mensaje_otro_cambio(mensaje);
            fflush(stdin);
            tecla = getch();
            BORRAR;
        }
        fclose(file);
    }
    modificacion_usuario();
}

void modificacion_fecha()
{
    BORRAR;
    FILE* file = fopen(ARCHIVO_USUARIO, "r+b");

    char tecla = 13;
    int flag = 0;
    if(file!=NULL)
    {
        while(tecla == 13)
        {
            stUsuario usuario;
            char nombreUsuario[20];
            char titulo[]="MODIFICACION DE LA FECHA DE NACIMIENTO";
            mensajeExitos(titulo);
            printf("\nIngrese el nombre de usuario: ");
            fflush(stdin);
            gets(nombreUsuario);
            while(fread(&usuario, sizeof(stUsuario), 1, file)>0)
            {
                if(strcmp(nombreUsuario, usuario.nombreUsuario)==0)
                {
                    printf("\n\t\t||| USUARIO ENCONTRADO |||\n");
                    printf("\nFecha de nacimiento actual: %s\n\n", usuario.fechaDeNacimiento);
                    printf("Ingrese una nueva fecha como dd/mm/aaaa: ");
                    fflush(stdin);
                    gets(&usuario.fechaDeNacimiento);
                    fseek(file, sizeof(stUsuario)*(-1),SEEK_CUR);
                    fwrite(&usuario, sizeof(stUsuario), 1, file);
                    fseek(file, sizeof(stUsuario),SEEK_CUR);
                    flag = 1;
                    BORRAR;
                    char mensaje[]="LA FECHA DE NACIMIENTO FUE MODIFICADA CON EXITO!!";
                    mensajeExitos(mensaje);
                }
            }
            if(flag == 0)
            {
                usuario_no_encontrado();
            }
            rewind(file);
            flag = 0;
            char mensaje[]="la fecha de nacimiento";
            mensaje_otro_cambio(mensaje);
            fflush(stdin);
            tecla = getch();
            BORRAR;
        }
        fclose(file);
    }
    modificacion_usuario();
}
void modificacion_acceso()
{
    BORRAR;
    FILE* file = fopen(ARCHIVO_USUARIO, "r+b");

    char tecla = 13;
    char opcion = 0;
    int flag = 0;
    if(file!=NULL)
    {
        while(tecla == 13)
        {
            stUsuario usuario;
            char nombreUsuario[20];
            char titulo[]="MODIFICACION DEL TIPO DE ACCESO";
            mensajeExitos(titulo);
            printf("\nIngrese el nombre de usuario: ");
            fflush(stdin);
            gets(nombreUsuario);
            while(fread(&usuario, sizeof(stUsuario), 1, file)>0)
            {
                if(strcmp(nombreUsuario, usuario.nombreUsuario)==0)
                {
                    printf("\n\t\t||| USUARIO ENCONTRADO |||\n");
                    printf("\nPara cambiar a usuario tipo 'user', apriete '1'\n");
                    printf("Para cambiar a usuario tipo 'admin', apriete '2'\n");
                    fflush(stdin);
                    opcion = getch();
                    while(flag == 0)
                    {
                        if (opcion == '1')
                        {
                            usuario.acceso = 0;
                            fseek(file, sizeof(stUsuario)*(-1),SEEK_CUR);
                            fwrite(&usuario, sizeof(stUsuario), 1, file);
                            fseek(file, sizeof(stUsuario),SEEK_CUR);
                            flag = 1;
                        }
                        else if (opcion == '2')
                        {
                            usuario.acceso = 1;
                            fseek(file, sizeof(stUsuario)*(-1),SEEK_CUR);
                            fwrite(&usuario, sizeof(stUsuario), 1, file);
                            fseek(file, sizeof(stUsuario),SEEK_CUR);
                            flag = 1;
                        }
                        else
                        {
                            printf("\nINGRESO UNA OPCION INCORRECTA!!!\n");
                            printf("\nPara usuario tipo 'user', apriete '1'\n");
                            printf("Para usuario tipo 'admin', apriete '2'\n");
                            fflush(stdin);
                            opcion = getch();
                        }
                    }
                    BORRAR;
                    char mensaje[]="EL CAMBIO FUE REALIZADO CON EXITO!!";
                    mensajeExitos(mensaje);
                }
            }
            if(flag == 0)
            {
                usuario_no_encontrado();
            }
            rewind(file);
            flag = 0;
            char mensaje[]="el tipo de acceso";
            mensaje_otro_cambio(mensaje);
            fflush(stdin);
            tecla = getch();
            BORRAR;
        }
        fclose(file);
    }
    modificacion_usuario();
}

void guardarUsuarios()
{
    FILE* archivo = fopen(ARCHIVO_USUARIO, "ab");

    char tecla = 13;

    if(archivo!=NULL)
    {
        while(tecla == 13)
        {
            cargar_usuario(archivo);
            printf("Continuar\n");
            fflush(stdin);
            tecla = getch();
        }
        fclose(archivo);
    }

}
void cargar_usuario(FILE* file)
{
    stUsuario usuario;
    printf("Ingrese el nombre: ");
    gets(usuario.nombre);
    printf("Ingrese el apellido: ");
    gets(usuario.apellido);
    printf("Ingrese el nombre de usuario: ");
    gets(usuario.nombreUsuario);
    printf("Ingrese la contrasenia: ");
    gets(usuario.contrasena);
    printf("Ingrese la direccion de e-mail: ");
    gets(usuario.email);
    printf("Ingrese el barrio\n");
    gets(usuario.barrio);
    printf("Ingrese la fecha de nacimiento: ");
    gets(usuario.fechaDeNacimiento);
    system("cls");
            printf ("\n\t\t\t\t\t\t\tAHORA SELECCIONA TU COMIDA FAVORITA\n");
            fflush (stdin);
    mostrarOpciones(3, "opciones.dat");
    int opcion;
            gotoxy(0, 24);
            printf ("\n\t\t\t\t\t\t\tOPCION: ");
            fflush(stdin);
            scanf ("%d", &opcion);

            COPIAR_REGISTRO(opcion , usuario.tipoDeComida);


            system ("cls");
    usuario.acceso = 1 ;
    usuario.estado = 0;

    fwrite(&usuario, sizeof(stUsuario), 1, file);
}

int tamanioNombre()
{
    FILE* file = fopen(ARCHIVO_USUARIO,"rb");

    stUsuario usuario;
    int arreglo_nombre[100];
    int i = 0;
    if(file!=NULL)
    {
        while(fread(&usuario,sizeof(usuario),1,file)>0)
        {
            arreglo_nombre[i] = strlen(usuario.nombre);
            i++;
        }
        fclose(file);

    }
    int mayor = arreglo_nombre[0];
    for(int j = 0 ; j<i ; j++)
    {
        if(arreglo_nombre[j] > mayor)
        {
            mayor = arreglo_nombre[j];
        }
    }
    return mayor;
}

int tamanioFecha()
{
    FILE* file = fopen(ARCHIVO_USUARIO,"rb");

    stUsuario usuario;
    int arreglo_fecha[100];
    int i = 0;
    if(file!=NULL)
    {
        while(fread(&usuario,sizeof(usuario),1,file)>0)
        {
            arreglo_fecha[i] = strlen(usuario.fechaDeNacimiento);
            i++;
        }
        fclose(file);

    }
    int mayor = arreglo_fecha[0];
    for(int j = 0 ; j<i ; j++)
    {
        if(arreglo_fecha[j] > mayor)
        {
            mayor = arreglo_fecha[j];
        }
    }
    return mayor;
}

int tamanioApellido()
{
    FILE* file = fopen(ARCHIVO_USUARIO,"rb");

    stUsuario usuario;
    int arreglo_apellido[100];
    int i = 0;
    if(file!=NULL)
    {
        while(fread(&usuario,sizeof(usuario),1,file)>0)
        {
            arreglo_apellido[i] = strlen(usuario.apellido);
            i++;
        }
        fclose(file);

    }
    int mayor = arreglo_apellido[0];
    for(int j = 0 ; j<i ; j++)
    {
        if(arreglo_apellido[j] > mayor)
        {
            mayor = arreglo_apellido[j];
        }
    }
    return mayor;
}

int tamanioNomUsuario()
{
    FILE* file = fopen(ARCHIVO_USUARIO,"rb");

    stUsuario usuario;
    int arreglo_nomUsuario[100];
    int i = 0;
    if(file!=NULL)
    {
        while(fread(&usuario,sizeof(usuario),1,file)>0)
        {
            arreglo_nomUsuario[i] = strlen(usuario.nombreUsuario);
            i++;
        }
        fclose(file);

    }
    int mayor = arreglo_nomUsuario[0];
    for(int j = 0 ; j<i ; j++)
    {
        if(arreglo_nomUsuario[j] > mayor)
        {
            mayor = arreglo_nomUsuario[j];
        }
    }
    return mayor;
}

int tamanioContrasenia()
{
    FILE* file = fopen(ARCHIVO_USUARIO,"rb");

    stUsuario usuario;
    int arreglo_contrasenia[100];
    int i = 0;
    if(file!=NULL)
    {
        while(fread(&usuario,sizeof(usuario),1,file)>0)
        {
            arreglo_contrasenia[i] = strlen(usuario.contrasena);
            i++;
        }
        fclose(file);

    }
    int mayor = arreglo_contrasenia[0];
    for(int j = 0 ; j<i ; j++)
    {
        if(arreglo_contrasenia[j] > mayor)
        {
            mayor = arreglo_contrasenia[j];
        }
    }
    return mayor;
}

int tamanioComida()
{
    FILE* file = fopen(ARCHIVO_USUARIO,"rb");

    stUsuario usuario;
    int arreglo_comida[100];
    int i = 0;
    if(file!=NULL)
    {
        while(fread(&usuario,sizeof(usuario),1,file)>0)
        {
            arreglo_comida[i] = strlen(usuario.tipoDeComida);
            i++;
        }
        fclose(file);

    }
    int mayor = arreglo_comida[0];
    for(int j = 0 ; j<i ; j++)
    {
        if(arreglo_comida[j] > mayor)
        {
            mayor = arreglo_comida[j];
        }
    }
    return mayor;
}

int tamanioEmail()
{
    FILE* file = fopen(ARCHIVO_USUARIO,"rb");

    stUsuario usuario;
    int arreglo_email[100];
    int i = 0;
    if(file!=NULL)
    {
        while(fread(&usuario,sizeof(usuario),1,file)>0)
        {
            arreglo_email[i] = strlen(usuario.email);
            i++;
        }
        fclose(file);

    }
    int mayor = arreglo_email[0];
    for(int j = 0 ; j<i ; j++)
    {
        if(arreglo_email[j] > mayor)
        {
            mayor = arreglo_email[j];
        }
    }
    return mayor;
}

int tamanioBarrio()
{
    FILE* file = fopen(ARCHIVO_USUARIO,"rb");

    stUsuario usuario;
    int arreglo[100];
    int i = 0;
    if(file!=NULL)
    {
        while(fread(&usuario,sizeof(usuario),1,file)>0)
        {
            arreglo[i] = strlen(usuario.barrio);
            i++;
        }
        fclose(file);

    }
    int mayor = arreglo[0];
    for(int j = 0 ; j<i ; j++)
    {
        if(arreglo[j] > mayor)
        {
            mayor = arreglo[j];
        }
    }
    return mayor;
}

int tamanioAcceso()
{
    FILE* file = fopen(ARCHIVO_USUARIO,"rb");

    stUsuario usuario;
    int arreglo_acceso[100];
    int i = 0;
    if(file!=NULL)
    {
        while(fread(&usuario,sizeof(usuario),1,file)>0)
        {
            arreglo_acceso[i] = strlen(usuario.acceso);
            i++;
        }
        fclose(file);

    }
    int mayor = arreglo_acceso[0];
    for(int j = 0 ; j<i ; j++)
    {
        if(arreglo_acceso[j] > mayor)
        {
            mayor = arreglo_acceso[j];
        }
    }
    return mayor;
}
void encabezado_lista()
{
    char space[] = " ";

    char nombre[DIMENSION]="|NOMBRE|   ";
    char apellido[DIMENSION]="|APELLIDO|  ";
    char nombreUs[DIMENSION]="|USUARIO|  ";
    char contrasenia[DIMENSION]="|CONTRASENA|         ";
    char email[DIMENSION]="|EMAIL|         ";
    char fecha[DIMENSION]="|FECHA DE NAC.|    ";
    char barrio[DIMENSION] = "|ZONA|     ";
    char comida[DIMENSION]="|COMIDA|   ";
    char acceso[DIMENSION]="|ACCESO|  ";
    char estado[DIMENSION] = "|ESTADO|";
//    int letrasNombre = tamanioNombre()- strlen(nombre);
//
//    for(int i = 0 ; i < letrasNombre+3 ; i++)
//    {
//        strcat(nombre,space);
//    }
//    int letrasApellido = tamanioApellido()- strlen(apellido);
//
//    for(int i = 0 ; i < letrasApellido+3 ; i++)
//    {
//        strcat(apellido,space);
//    }
//    int letrasnombreUs = tamanioNomUsuario()- strlen(nombreUs);
//
//    for(int i = 0 ; i < letrasnombreUs+2 ; i++)
//    {
//        strcat(nombreUs,space);
//    }
//
//    int letrasContra = tamanioContrasenia()- strlen(contrasenia);
//
//    for(int i = 0 ; i < letrasContra+3 ; i++)
//    {
//        strcat(contrasenia,space);
//    }
//
//    int letrasEmail = tamanioEmail()-strlen(email);
//    for(int i = 0 ; i < letrasEmail+2 ; i++)
//    {
//        strcat(email,space);
//    }
//
//      int letrasBarrio = tamanioBarrio()- strlen(barrio);
//
//    for(int i = 0 ; i < letrasBarrio+2 ; i++)
//    {
//        strcat(barrio,space);
//    }
//
//    int letrasComida = tamanioComida()- strlen(comida);
//
//    for(int i = 0 ; i < letrasComida+2 ; i++)
//    {
//        strcat(comida,space);
//    }
////      int letrasAcceso = tamanioAcceso()- strlen(acceso);
////
////    for(int i = 0 ; i < letrasAcceso+2 ; i++)
////    {
////        strcat(acceso,space);
////    }

    printf("\t%s%s%s%s%s%s%s%s%s%s\n",nombre, apellido, nombreUs, contrasenia, email,  fecha, barrio , comida, acceso, estado);
}

void mensajeExitos(char arreglo[])
{
    char guion = 205, palito = 186;
    char esd = 201, esi = 187, eid = 200, eii =  200;
    int tam = strlen(arreglo);

    printf("\n\t\t%c",esd);
    for (int i = 0 ; i<tam ; i++)
    {
        printf("%c",guion);
    }
    printf("%c",esi);

    printf("\n\t\t%c%s%c\n", palito,arreglo,palito);

    printf("\t\t%c",eid);
    for (int i = 0 ; i<tam ; i++)
    {
        printf("%c",guion);
    }
    printf("%c",eii);

    printf("\n\n");

}

void mensaje_otra_busqueda()
{
    char vineta = 196, flecha = 62;
    printf("\n\n\n\n\n\n\n\n%c%c Para realizar otra busqueda, presione ENTER\n", vineta,flecha);
    printf("%c%c Para volver al menu anterior, presione cualquier otra tecla\n",vineta,flecha );
}

void mensaje_otro_cambio(char arreglo[])
{
    printf("\n\nDesea cambiar %s de otro usuario?\n\n", arreglo);

    printf("\t%c Apriete ENTER si desea realizar otro cambio\n", 26);
    printf("\t%c Apriete cualquier otra tecla para volver al menu anterior\n", 26);
}
void usuario_no_encontrado()
{
    BORRAR;
    char ausente[]="USUARIO NO ENCONTRADO";
    mensajeExitos(ausente);
}

void mostrarOpciones(int altura, char nombreArchivo[])
{
        int i = 0 ;
        int j = 0;
        FILE *archivo;
        archivo = fopen (nombreArchivo , "rb");
        if (archivo != NULL)
        {
            stCOMIDAS platos ;
            while(fread (&platos, sizeof(stCOMIDAS), 1 , archivo) > 0)
            {
                if(i < 21)
                {
                    printf("[%-2d]-%s \n", i, platos.PLATOS);
                    i++;
                }
                else
                {
                    gotoxy(30, altura);
                    printf("[%-2d]-%s \n", i, platos.PLATOS);
                    i++;
                    altura++;
                }
                }
            }
        fclose(archivo);
        }

void COPIAR_REGISTRO (int OPCION , char ARREGLO [])
{
//  CALCULA LOS BITS QUE SE VA A MOVER EL INDICADOR
   int TAMANIO = TAMANIO_ARCHIVO_SEGUN_POSICION (OPCION);
    FILE* ARCHIVO ;
    ARCHIVO = fopen ("opciones.DAT" , "rb");

    if (ARCHIVO !=NULL && OPCION < 33)
    {
//       int REGISTROS = CANTIDAD_REGISTROS ()  ;
//       int FLAG = 0 ;
        stCOMIDAS COMIDA ;
        //POSICIONA EL INDICADOR AL COMIENZO DEL REGISTRO
        fseek ( ARCHIVO , TAMANIO , SEEK_SET);
         //LEE EL REGISTRO Y Y LO ALAMACENA EN EL ARREGLO ALUMNOS PARA LUEGO MOSTRARLO
        // POR PANTALLA
        fread (&COMIDA , sizeof (stCOMIDAS) , 1 , ARCHIVO);
        strcpy (ARREGLO ,COMIDA.PLATOS );
        rewind (ARCHIVO);
        fclose (ARCHIVO);

    }
    else
    {
        printf ("\n ERROR DE ARCHIVO O NUMERO DE REGISTRO NO EXISTE\n");    }
}

int TAMANIO_ARCHIVO_SEGUN_POSICION (  int NUMERO_REGISTRO)
{
    FILE*ARCHIVO ;
    ARCHIVO = fopen ("opciones.DAT" , "rb");

    if (ARCHIVO != NULL )
    {
        stCOMIDAS COMIDA ;
        fseek (ARCHIVO , sizeof(stCOMIDAS)*NUMERO_REGISTRO , SEEK_SET);
        int TAMANIO = ftell (ARCHIVO);
        rewind(ARCHIVO);
        fclose(ARCHIVO);

        return TAMANIO ;
    }

}
