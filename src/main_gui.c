#include <gtk/gtk.h>
#include "gui/main_window.h"
#include "ast/AbstractExpresion.h"
#include "context/context.h"

// Variables globales necesarias para el parser (definidas aquí para la versión GUI)
AbstractExpresion *ast_root = NULL;
Context *contextoActualReporte = NULL;

int main(int argc, char *argv[])
{
    // Inicializar GTK
    gtk_init(&argc, &argv);

    // Crear la ventana principal
    MainWindow *main_window = create_main_window();

    // Mostrar la ventana
    gtk_widget_show_all(main_window->window);

    // Ejecutar el bucle principal de GTK
    gtk_main();

    return 0;
}