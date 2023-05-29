//
// Created by jonib on 5/4/2023.
//
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#ifndef PROJETO_PROJECT_H
#define PROJETO_PROJECT_H

extern int reserva_autoID;
extern int pre_reserva_autoID;

enum tipo {
    Manutencao, Lavagem
};

typedef struct tipoReserva {
    enum tipo tipoR;
    int duracao; //60 para manutencao; 30 para lavagem
} tipoReserva;

typedef struct horarioReserva {
    int dia, hora, minutos;
} horarioReserva;


typedef struct Reserva {
    int ID;
    int clientID;
    tipoReserva tipo;
    horarioReserva hora;
    //Lista Ligada do tipo Pre_Reservas
} Reserva;

typedef struct NoListaPre_Reservas {
    Reserva reserva;
    struct NoListaPre_Reservas *next;
} NoListaPre_Reservas;

typedef struct ListaPre_Reservas {
    NoListaPre_Reservas *start;
    int size;
} ListaPre_Reservas;

typedef struct NoListaReservas {
    Reserva reserva;
    ListaPre_Reservas *listaPreReservas;
    struct NoListaReservas *next;
} NoListaReservas;

typedef struct ListaReservas {
    NoListaReservas *start;
    int size;
} ListaReservas;

//funcoes
ListaReservas *create_lista_reservas();
ListaPre_Reservas *create_lista_pre_reservas();
NoListaPre_Reservas *get_pre_reservation_node(ListaPre_Reservas *lista_pre, int time_to_next);
//Reserva create_reserva(int clientId, tipoReserva tipoR, horarioReserva horas);


//void print_sorted(ListaReservas *lptr);
void menu_inicial();
void print_reservas_dia(ListaReservas *lista, int dia);
void print_pre_reservas(ListaReservas *lista, int reservationID);
void cancela_reserva(ListaReservas *lista, int reservationID);
void insert_reserva(ListaReservas *lista, int clientId, tipoReserva tipoRes, int dia, int hora, int minuto);
void insert_pre_reserva(ListaPre_Reservas *lista_pre, NoListaReservas *current, int clientId, tipoReserva tipoRes, int dia, int hora, int minuto);
void cancela_pre_reserva(ListaPre_Reservas *lista, int reservationID);
void list_all(ListaReservas *lista);

int func_comp(const void *a, const void *b);
int check_disponibilidade(ListaReservas *lista, int dia, int hora, int minuto, tipoReserva tipoRes, int clientID);
int compare_reservas_time(Reserva res1, Reserva res2);
int print_reservas(ListaReservas *lista);

#endif //PROJETO_PROJECT_H
