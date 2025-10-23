#if defined(__has_include)
#if __has_include(<gtk/gtk.h>)
#include <gtk/gtk.h>
#include "gui/main_window.h"
#define HAVE_GTK 1
#else
#define HAVE_GTK 0
#endif
#else
#include <gtk/gtk.h>
#include "gui/main_window.h"
#define HAVE_GTK 1
#endif

#include "ast/AbstractExpresion.h"
#include "context/context.h"

// If GTK headers are not available, provide minimal stubs so this file
// can be parsed/compiled by tools that don't have GTK installed.
#if !HAVE_GTK
typedef struct _MainWindow
{
    void *window;
} MainWindow;

/* create_main_window should be provided by the real GUI implementation.
   This stub returns NULL so the rest of the program can still compile. */
static MainWindow *create_main_window(void)
{
    return NULL;
}

/* Minimal stubs for the GTK functions used in this file. These are no-ops
   and only exist so editors/compilers without GTK headers don't error out. */
static void gtk_init(int *argc, char ***argv)
{
    (void)argc;
    (void)argv;
}
static void gtk_widget_show_all(void *widget) { (void)widget; }
static void gtk_main(void) {}
#endif

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