#include "main_window.h"
#include "../ast/AbstractExpresion.h"
#include "../ast/nodos/instrucciones/instrucciones.h"
#include "../ast/nodos/instrucciones/instruccion/funcion.h"
#include "../context/context.h"
#include "../backend/arm64_generator.h"
#include "../context/error_report.h"
#include "../context/ast_report.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Variables globales necesarias para el parser
extern int yyparse(void);
extern AbstractExpresion *ast_root;
extern Context *contextoActualReporte;
extern FILE *yyin;

// Buffer para mantener el texto de entrada para el parser
static char *input_text_buffer = NULL;

MainWindow *create_main_window(void)
{
    MainWindow *main_window = g_malloc(sizeof(MainWindow));

    // Crear la ventana principal
    main_window->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window->window), "Analizador JavaLang");
    gtk_window_set_default_size(GTK_WINDOW(main_window->window), 1000, 700);
    gtk_window_set_position(GTK_WINDOW(main_window->window), GTK_WIN_POS_CENTER);

    // Crear el contenedor principal
    GtkWidget *main_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(main_window->window), main_vbox);
    gtk_container_set_border_width(GTK_CONTAINER(main_vbox), 10);

    // Crear el título
    GtkWidget *title_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(title_label), "<span size='large' weight='bold'>ANALIZADOR JAVALANG</span>");
    gtk_box_pack_start(GTK_BOX(main_vbox), title_label, FALSE, FALSE, 0);

    // Crear el área de entrada
    GtkWidget *input_frame = gtk_frame_new("Entrada:");
    gtk_box_pack_start(GTK_BOX(main_vbox), input_frame, TRUE, TRUE, 0);

    GtkWidget *input_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(input_scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(input_frame), input_scrolled);

    main_window->input_textview = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(main_window->input_textview), GTK_WRAP_WORD);
    gtk_container_add(GTK_CONTAINER(input_scrolled), main_window->input_textview);
    main_window->input_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(main_window->input_textview));

    // Crear contenedor horizontal para botones principales
    GtkWidget *main_buttons_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(main_vbox), main_buttons_hbox, FALSE, FALSE, 5);

    // Botón de abrir archivo
    main_window->open_button = gtk_button_new_with_label("Abrir Archivo .usl");
    gtk_box_pack_start(GTK_BOX(main_buttons_hbox), main_window->open_button, TRUE, TRUE, 0);

    // Botón de limpiar
    main_window->clear_button = gtk_button_new_with_label("Limpiar Editor");
    gtk_box_pack_start(GTK_BOX(main_buttons_hbox), main_window->clear_button, TRUE, TRUE, 0);

    // Botón de analizar (más prominente)
    main_window->analyze_button = gtk_button_new_with_label("Analizar");
    gtk_box_pack_start(GTK_BOX(main_buttons_hbox), main_window->analyze_button, TRUE, TRUE, 0);

    // Botón para generar código ARM64
    main_window->generate_arm_button = gtk_button_new_with_label("Generar Codigo ARM64");
    gtk_box_pack_start(GTK_BOX(main_buttons_hbox), main_window->generate_arm_button, TRUE, TRUE, 0);

    // Crear contenedor horizontal para botones de reportes
    GtkWidget *report_buttons_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(main_vbox), report_buttons_hbox, FALSE, FALSE, 0);

    // Botones de reportes
    main_window->error_report_button = gtk_button_new_with_label("ver reporte Errores");
    gtk_box_pack_start(GTK_BOX(report_buttons_hbox), main_window->error_report_button, TRUE, TRUE, 0);

    main_window->ast_report_button = gtk_button_new_with_label("ver AST");
    gtk_box_pack_start(GTK_BOX(report_buttons_hbox), main_window->ast_report_button, TRUE, TRUE, 0);

    main_window->symbol_table_button = gtk_button_new_with_label("ver reporte Tabla Símbolos");
    gtk_box_pack_start(GTK_BOX(report_buttons_hbox), main_window->symbol_table_button, TRUE, TRUE, 0);

    // Crear el área de salida
    GtkWidget *output_frame = gtk_frame_new("Salida");
    gtk_box_pack_start(GTK_BOX(main_vbox), output_frame, TRUE, TRUE, 0);

    GtkWidget *output_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(output_scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(output_frame), output_scrolled);

    main_window->output_textview = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(main_window->output_textview), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(main_window->output_textview), GTK_WRAP_WORD);
    gtk_container_add(GTK_CONTAINER(output_scrolled), main_window->output_textview);
    main_window->output_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(main_window->output_textview));

    // Conectar señales
    g_signal_connect(main_window->window, "destroy", G_CALLBACK(on_window_destroy), main_window);
    g_signal_connect(main_window->analyze_button, "clicked", G_CALLBACK(on_analyze_clicked), main_window);
    g_signal_connect(main_window->open_button, "clicked", G_CALLBACK(on_open_file_clicked), main_window);
    g_signal_connect(main_window->clear_button, "clicked", G_CALLBACK(on_clear_clicked), main_window);
    g_signal_connect(main_window->generate_arm_button, "clicked", G_CALLBACK(on_generate_arm_clicked), main_window);
    g_signal_connect(main_window->error_report_button, "clicked", G_CALLBACK(on_error_report_clicked), main_window);
    g_signal_connect(main_window->ast_report_button, "clicked", G_CALLBACK(on_ast_report_clicked), main_window);
    g_signal_connect(main_window->symbol_table_button, "clicked", G_CALLBACK(on_symbol_table_clicked), main_window);

    return main_window;
}

void destroy_main_window(MainWindow *main_window)
{
    if (main_window)
    {
        if (input_text_buffer)
        {
            free(input_text_buffer);
            input_text_buffer = NULL;
        }
        g_free(main_window);
    }
}

void on_analyze_clicked(GtkWidget *widget, gpointer data)
{
    (void)widget; // Evitar warning de parámetro no usado
    MainWindow *main_window = (MainWindow *)data;

    // Limpiar área de salida
    set_output_text(main_window, "");

    // Obtener texto de entrada
    char *input_text = get_input_text(main_window);
    if (!input_text || strlen(input_text) == 0)
    {
        set_output_text(main_window, "Error: No hay texto para analizar.\n");
        if (input_text)
            g_free(input_text);
        return;
    }

    // Guardar el texto en un archivo temporal para el parser
    FILE *temp_file = fopen("temp_input.usl", "w");
    if (!temp_file)
    {
        set_output_text(main_window, "Error: No se pudo crear archivo temporal.\n");
        g_free(input_text);
        return;
    }

    fprintf(temp_file, "%s", input_text);
    fclose(temp_file);
    g_free(input_text);

    // Configurar el parser para leer del archivo temporal
    yyin = fopen("temp_input.usl", "r");
    if (!yyin)
    {
        set_output_text(main_window, "Error: No se pudo abrir archivo temporal para análisis.\n");
        return;
    }

    // Limpiar errores previos
    liberarErrores();
    ast_root = NULL;

    append_output_text(main_window, "Iniciando análisis...\n");

    // Ejecutar el parser
    int parseResult = yyparse();
    fclose(yyin);

    if (parseResult == 0)
    {
        if (ast_root)
        {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Análisis exitoso. Cantidad de instrucciones: %ld\n", ast_root->numHijos);
            append_output_text(main_window, buffer);

            // Generar reporte del AST
            append_output_text(main_window, "\n=== Generando Reporte del Árbol AST ===\n");
            // Generar solo reporte AST básico por seguridad (DOT tiene problemas de corrupción)
            if (ast_root && ast_root->numHijos > 0)
            {
                append_output_text(main_window, "Generando reporte AST básico y seguro...\n");
                generarReporteASTBasico(ast_root, "reporte_ast_basico.txt");
                append_output_text(main_window, "Reporte AST básico generado: reporte_ast_basico.txt\n");
                append_output_text(main_window, "NOTA: Generación DOT deshabilitada por problemas de corrupción\n");
            }
            else
            {
                append_output_text(main_window, "AST vacío o inválido, saltando generación\n");
            }
            append_output_text(main_window, "=======================================\n\n");

            // Crear contexto e interpretar
            Context *contextPadre = nuevoContext(NULL);
            contextoActualReporte = contextPadre;
            contextPadre->archivo = fopen("salida.txt", "w");

            if (contextPadre->archivo == NULL)
            {
                append_output_text(main_window, "Error: No se pudo abrir el archivo de salida.\n");
                imprimirErrores();
                liberarErrores();
                return;
            }

            Result resultado = ast_root->interpret(ast_root, contextPadre);
            (void)resultado;

            // Ejecutar función main si existe
            Result resultadoMain = ejecutarFuncionMainPendiente();
            (void)resultadoMain;

            fclose(contextPadre->archivo);

            // Generar reporte de tabla de símbolos
            generarReporteTablaSimbolos(contextPadre, "tabla_simbolos.html");
            append_output_text(main_window, "Reporte de tabla de símbolos generado: tabla_simbolos.html\n");

            // Leer archivo de salida y mostrarlo
            FILE *salida_file = fopen("salida.txt", "r");
            if (salida_file)
            {
                append_output_text(main_window, "\n=== Salida del programa ===\n");
                char line[1024];
                while (fgets(line, sizeof(line), salida_file))
                {
                    append_output_text(main_window, line);
                }
                fclose(salida_file);
                append_output_text(main_window, "\n========================\n");
            }

            append_output_text(main_window, "\nAnálisis completado exitosamente.\n");
        }
        else
        {
            append_output_text(main_window, "No se analizó ninguna entrada válida.\n");
        }
    }
    else
    {
        append_output_text(main_window, "Error: El análisis sintáctico falló.\n");
    }

    // Imprimir errores en consola y generar archivo errores.txt
    imprimirErrores();

    // Mostrar errores si los hay
    if (tieneErrores())
    {
        append_output_text(main_window, "\n=== Errores encontrados ===\n");
        // Aquí podrías leer el archivo de errores y mostrarlo en la GUI
        append_output_text(main_window, "Se encontraron errores. Ver reporte de errores para más detalles.\n");
        append_output_text(main_window, "=========================\n");
    }

    // Limpiar archivo temporal
    remove("temp_input.usl");
}

void on_open_file_clicked(GtkWidget *widget, gpointer data)
{
    (void)widget; // Evitar warning de parámetro no usado
    MainWindow *main_window = (MainWindow *)data;

    GtkWidget *dialog = gtk_file_chooser_dialog_new("Abrir archivo .usl",
                                                    GTK_WINDOW(main_window->window),
                                                    GTK_FILE_CHOOSER_ACTION_OPEN,
                                                    "Cancelar", GTK_RESPONSE_CANCEL,
                                                    "Abrir", GTK_RESPONSE_ACCEPT,
                                                    NULL);

    // Filtro para archivos .usl
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Archivos USL (*.usl)");
    gtk_file_filter_add_pattern(filter, "*.usl");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

        FILE *file = fopen(filename, "r");
        if (file)
        {
            // Leer el contenido del archivo
            fseek(file, 0, SEEK_END);
            long file_size = ftell(file);
            fseek(file, 0, SEEK_SET);

            char *content = malloc(file_size + 1);
            fread(content, 1, file_size, file);
            content[file_size] = '\0';

            set_input_text(main_window, content);

            free(content);
            fclose(file);

            // Mostrar mensaje en la salida
            char message[512];
            snprintf(message, sizeof(message), "Archivo cargado: %s\n", filename);
            set_output_text(main_window, message);
        }
        else
        {
            set_output_text(main_window, "Error: No se pudo abrir el archivo seleccionado.\n");
        }

        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

void on_clear_clicked(GtkWidget *widget, gpointer data)
{
    (void)widget; // Evitar warning de parámetro no usado
    MainWindow *main_window = (MainWindow *)data;

    set_input_text(main_window, "");
    set_output_text(main_window, "Editor limpiado.\n");
}

void on_error_report_clicked(GtkWidget *widget, gpointer data)
{
    (void)widget; // Evitar warning de parámetro no usado
    (void)data;   // Evitar warning de parámetro no usado

    show_html_report("reporte_errores.html", "Reporte de Errores");
}

void on_ast_report_clicked(GtkWidget *widget, gpointer data)
{
    (void)widget; // Evitar warning de parámetro no usado
    (void)data;   // Evitar warning de parámetro no usado

    // Crear un reporte AST simplificado y seguro
    if (ast_root)
    {
        // Generar reporte AST detallado y seguro
        generarReporteASTBasico(ast_root, "reporte_ast_detallado.txt");

        // También intentar abrir el archivo
        if (access("reporte_ast_detallado.txt", F_OK) == 0)
        {
            system("xdg-open reporte_ast_detallado.txt");
        }

        // Mostrar mensaje de confirmación
        GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                                   GTK_DIALOG_MODAL,
                                                   GTK_MESSAGE_INFO,
                                                   GTK_BUTTONS_OK,
                                                   "Reporte AST generado exitosamente en 'reporte_ast_detallado.txt'");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
    else
    {
        GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                                   GTK_DIALOG_MODAL,
                                                   GTK_MESSAGE_WARNING,
                                                   GTK_BUTTONS_OK,
                                                   "No hay AST disponible. Ejecute primero el análisis.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}

void on_symbol_table_clicked(GtkWidget *widget, gpointer data)
{
    (void)widget; // Evitar warning de parámetro no usado
    (void)data;   // Evitar warning de parámetro no usado

    show_html_report("tabla_simbolos.html", "Reporte de Tabla de Símbolos");
}

void on_generate_arm_clicked(GtkWidget *widget, gpointer data)
{
    (void)widget; // Evitar warning de parámetro no usado
    MainWindow *main_window = (MainWindow *)data;

    // Verificar que exista un AST (se genera tras analizar)
    if (!ast_root)
    {
        append_output_text(main_window, "Error: No hay AST disponible. Ejecute el análisis primero.\n");
        return;
    }

    append_output_text(main_window, "Iniciando generación ARM64 (esqueleto)...\n");

    // Obtener el texto fuente actual del editor para extraer comentarios
    char *source_text = get_input_text(main_window);

    const char *outpath = "salida_arm64.s";
    // Por seguridad pasamos NULL como contexto para evitar accesos a estructuras
    // que podrían ser inválidas desde la GUI; esto aún permite generación de
    // funciones y variables locales. Si se necesita soporte global, usar la
    // versión CLI o implementar una copia segura del contexto.
    bool ok = generate_arm64_from_ast_with_source(ast_root, NULL, outpath, source_text);
    if (source_text)
        g_free(source_text);
    if (ok)
    {
        char msg[256];
        snprintf(msg, sizeof(msg), "Generación ARM64 completada: %s\n", outpath);
        append_output_text(main_window, msg);
    }
    else
    {
        append_output_text(main_window, "Error: No se pudo generar el archivo ARM64.\n");
    }
}

void on_window_destroy(GtkWidget *widget, gpointer data)
{
    (void)widget; // Evitar warning de parámetro no usado
    MainWindow *main_window = (MainWindow *)data;

    destroy_main_window(main_window);
    gtk_main_quit();
}

void set_input_text(MainWindow *main_window, const char *text)
{
    gtk_text_buffer_set_text(main_window->input_buffer, text, -1);
}

void set_output_text(MainWindow *main_window, const char *text)
{
    gtk_text_buffer_set_text(main_window->output_buffer, text, -1);
}

void append_output_text(MainWindow *main_window, const char *text)
{
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(main_window->output_buffer, &end);
    gtk_text_buffer_insert(main_window->output_buffer, &end, text, -1);

    // Auto-scroll al final
    GtkTextMark *mark = gtk_text_buffer_get_insert(main_window->output_buffer);
    gtk_text_view_scroll_mark_onscreen(GTK_TEXT_VIEW(main_window->output_textview), mark);
}

char *get_input_text(MainWindow *main_window)
{
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(main_window->input_buffer, &start, &end);
    return gtk_text_buffer_get_text(main_window->input_buffer, &start, &end, FALSE);
}

void show_html_report(const char *filename, const char *title)
{
    if (access(filename, F_OK) == 0)
    {
        // Usar el navegador predeterminado para abrir el archivo HTML
        char command[512];
        snprintf(command, sizeof(command), "xdg-open %s", filename);
        system(command);
    }
    else
    {
        GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                                   GTK_DIALOG_MODAL,
                                                   GTK_MESSAGE_WARNING,
                                                   GTK_BUTTONS_OK,
                                                   "No se encontró el archivo %s. Ejecute primero el análisis.",
                                                   title);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}

// Función para generar un reporte AST básico y seguro
void generarReporteASTBasico(AbstractExpresion *raiz, const char *nombreArchivo)
{
    if (!raiz || !nombreArchivo)
    {
        printf("Error: Parámetros inválidos para generar reporte AST básico\n");
        return;
    }

    FILE *archivo = fopen(nombreArchivo, "w");
    if (!archivo)
    {
        printf("Error: No se pudo crear el archivo %s\n", nombreArchivo);
        return;
    }

    fprintf(archivo, "=== REPORTE BÁSICO DEL ÁRBOL AST ===\n\n");
    fprintf(archivo, "NOTA: Este es un reporte básico en texto plano.\n");
    fprintf(archivo, "La generación del diagrama visual (.dot/.png) está deshabilitada\n");
    fprintf(archivo, "debido a problemas de corrupción que causan 'cuadros negros'.\n");
    fprintf(archivo, "Estado del archivo DOT: Posiblemente corrupto debido a segfault.\n\n");

    fprintf(archivo, "Información de la raíz:\n");
    fprintf(archivo, "- Número de hijos: %zu\n", raiz->numHijos);
    fprintf(archivo, "- Línea: %d, Columna: %d\n", raiz->linea, raiz->columna);
    fprintf(archivo, "- Dirección de memoria: %p\n", (void *)raiz);

    if (raiz->interpret)
    {
        fprintf(archivo, "- Función de interpretación: %p\n", (void *)raiz->interpret);
    }

    fprintf(archivo, "\nEstructura del árbol (primeros 2 niveles):\n");
    generarReporteASTBasicoRecursivo(archivo, raiz, 0, 2);

    fprintf(archivo, "\n=== FIN DEL REPORTE ===\n");
    fclose(archivo);
    printf("Reporte AST básico generado: %s\n", nombreArchivo);
}

// Función auxiliar recursiva segura para generar el reporte
void generarReporteASTBasicoRecursivo(FILE *archivo, AbstractExpresion *nodo, int nivel, int maxNivel)
{
    if (!archivo || !nodo || nivel > maxNivel)
    {
        return;
    }

    // Generar indentación
    for (int i = 0; i < nivel; i++)
    {
        fprintf(archivo, "  ");
    }

    fprintf(archivo, "- Nodo nivel %d: %zu hijos, posición (%d,%d)\n",
            nivel, nodo->numHijos, nodo->linea, nodo->columna);

    // Procesar hijos solo si no excedemos el nivel máximo
    if (nivel < maxNivel && nodo->hijos && nodo->numHijos > 0 && nodo->numHijos < 100)
    {
        for (size_t i = 0; i < nodo->numHijos && i < 10; i++)
        { // Limitar a 10 hijos por seguridad
            if (nodo->hijos[i] && nodo->hijos[i] != nodo)
            { // Evitar auto-referencia
                generarReporteASTBasicoRecursivo(archivo, nodo->hijos[i], nivel + 1, maxNivel);
            }
        }

        if (nodo->numHijos > 10)
        {
            for (int i = 0; i <= nivel; i++)
            {
                fprintf(archivo, "  ");
            }
            fprintf(archivo, "... y %zu hijos más\n", nodo->numHijos - 10);
        }
    }
}