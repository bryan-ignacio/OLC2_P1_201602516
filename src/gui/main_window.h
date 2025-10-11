#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtk/gtk.h>
#include <stdio.h>
#include "../ast/AbstractExpresion.h"

// Estructura para mantener referencias a los widgets principales
typedef struct
{
    GtkWidget *window;
    GtkWidget *input_textview;
    GtkWidget *output_textview;
    GtkTextBuffer *input_buffer;
    GtkTextBuffer *output_buffer;
    GtkWidget *analyze_button;
    GtkWidget *open_button;
    GtkWidget *clear_button;
    GtkWidget *error_report_button;
    GtkWidget *ast_report_button;
    GtkWidget *symbol_table_button;
} MainWindow;

// Funciones principales
MainWindow *create_main_window(void);
void destroy_main_window(MainWindow *main_window);

// Callbacks
void on_analyze_clicked(GtkWidget *widget, gpointer data);
void on_open_file_clicked(GtkWidget *widget, gpointer data);
void on_clear_clicked(GtkWidget *widget, gpointer data);
void on_error_report_clicked(GtkWidget *widget, gpointer data);
void on_ast_report_clicked(GtkWidget *widget, gpointer data);
void on_symbol_table_clicked(GtkWidget *widget, gpointer data);
void on_window_destroy(GtkWidget *widget, gpointer data);

// Funciones auxiliares
void set_input_text(MainWindow *main_window, const char *text);
void set_output_text(MainWindow *main_window, const char *text);
void append_output_text(MainWindow *main_window, const char *text);
char *get_input_text(MainWindow *main_window);
void show_html_report(const char *filename, const char *title);

// Funciones para reporte AST básico
void generarReporteASTBasico(AbstractExpresion *raiz, const char *nombreArchivo);
void generarReporteASTBasicoRecursivo(FILE *archivo, AbstractExpresion *nodo, int nivel, int maxNivel);

#endif // MAIN_WINDOW_H