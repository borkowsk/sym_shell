/* INTERFACE FOR SYMSHELL MENU AND RELEATED FEATURES */
/*****************************************************/
#ifndef _SYMSHELL_MENUFUNCTIONS_H_
#define _SYMSHELL_MENUFUNCTIONS_H_

#ifdef __cplusplus
#define DEF_VAL_IF_CPP( _P_ )  =(_P_)
#else
#define DEF_VAL_IF_CPP( _P_ )
#endif

#ifdef __cplusplus
extern "C" {
#endif

int ssh_set_window_name(const char* WindowName); /* Zmienia tytu� okna */   

typedef void* ssh_menu_handle;

ssh_menu_handle ssh_main_menu(); /* Daje uchwyt do g��wnego menu */

ssh_menu_handle ssh_sub_menu(    /* Daje uchwyt do podmenu wg. pozycji */
                    ssh_menu_handle hMenu,				
                    unsigned    Position);

int ssh_get_item_position(  /* Odnajduje pozycje itemu w jakims menu */
                     ssh_menu_handle hMenu,
                     const char* ItemName);/* Return -1 if cant find such item */

int	ssh_menu_add_item(			 /* Dodaje item do menu */
                    ssh_menu_handle hMenu,
                    const char* ItemName,
                    unsigned    Message,
                    unsigned    Flags DEF_VAL_IF_CPP(0));/* Default is ENABLE immediatelly */

int ssh_menu_mark_item(          /* Ustawia lub usuwa marker przy itemie */
                    ssh_menu_handle hMenu,
                    unsigned    Check,
                    unsigned    ItemCommandOrPosition,										
                    unsigned    asPosition DEF_VAL_IF_CPP(0));/*Have to be 1 for submenu checking*/

int ssh_menu_remove_item(          /* Usuwa item z menu */
                    ssh_menu_handle hMenu,
                    unsigned    ItemCommandOrPosition,
                    unsigned    asPosition DEF_VAL_IF_CPP(0));

int ssh_realize_menu(ssh_menu_handle hMenu);/* Zapewnia ze menu bedzie wygladac zgodnie z poprzednimi poleceniami */

#ifdef unix
extern int 		ssh_menu_trace; 	/* For debuging purposes - external accesible */
extern char*    ssh_menu_options; 	/*MOTIF STYLE OPTIONS */
#endif

#ifdef __cplusplus
};
#endif



#endif
/********************************************************************/
/*           THIS CODE IS DESIGNED & COPYRIGHT  BY:                 */
/*            W O J C I E C H   B O R K O W S K I                   */
/* Zaklad Systematyki i Geografii Roslin Uniwersytetu Warszawskiego */
/*  & Instytut Studiow Spolecznych Uniwersytetu Warszawskiego       */
/*        WWW:  http://moderato.iss.uw.edu.pl/~borkowsk             */
/*        MAIL: borkowsk@iss.uw.edu.pl                              */
/*                               (Don't change or remove this note) */
/********************************************************************/




