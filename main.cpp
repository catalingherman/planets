#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <cstring>
#include "biblioteca.h"

int main(){
	int obtiune;
	while(1){
		printf("\n\n\n");		
		printf("   ###########################  ###########################  ###########################  ###########################\n");
		printf("   #                         #  #                         #  #                         #  #                         #\n");
		printf("   #    #                    #  #  ###                    #  #  ###                    #  #    #                    #\n");
		printf("   #   ##     Crearea        #  # #   #     Afisarea      #  # #   #    Corectarea     #  #   ##      Afisarea      #\n");
		printf("   #  # #     Fisierului     #  #    #      Fisierului    #  #    #     Fisierului     #  #  # #      Selectiva     #\n");
		printf("   #    #                    #  #   #                     #  # #   #                   #  # #####                   #\n");
		printf("   #    #                    #  # #####                   #  #  ###                    #  #    #                    #\n");
		printf("   #                         #  #                         #  #                         #  #                         #\n");
		printf("   ###########################  ###########################  ###########################  ###########################\n");

		printf("   ###########################  ###########################  ###########################  ###########################\n");
		printf("   #                         #  #                         #  #                         #  #                         #\n");
		printf("   # #####                   #  # #####                   #  # #####                   #  # #####                   #\n");
		printf("   # #        Adaugare       #  # #         Sortarea      #  #    #      Crearea       #  # #   #     Crearea       #\n");
		printf("   # #####        la         #  # #####     Datelor       #  #   #       a doua        #  #  ###      Listei        #\n");
		printf("   #     #      Fisier       #  # #   #                   #  #  #        Fisiere       #  # #   #                   #\n");
		printf("   # #####                   #  # #####                   #  # #                       #  # #####                   #\n");
		printf("   #                         #  #                         #  #                         #  #                         #\n");
		printf("   ###########################  ###########################  ###########################  ###########################\n");

		printf("   ###########################  ###########################  ###########################  ###########################\n");
		printf("   #                         #  #                         #  #                         #  #                         #\n");
		printf("   # #####                   #  #   # ####                #  #   #    #                #  #  ####                   #\n");
		printf("   # #   #     Afisarea      #  #  ## #  #    Adaugarea   #  #  ##   ##     Stergerea  #  #  #  #                   #\n");
		printf("   # #####     Listei        #  # # # #  #       in       #  # # #  # #        din     #  #  #  #         EXIT      #\n");
		printf("   #     #                   #  #   # #  #     Lista      #  #   #    #       Lista    #  #  #  #                   #\n");
		printf("   # #####                   #  #   # ####                #  #   #    #                #  #  ####                   #\n");
		printf("   #                         #  #                         #  #                         #  #                         #\n");
		printf("   ###########################  ###########################  ###########################  ###########################\n");
		fflush(stdin);
		scanf("%d",&obtiune);

		switch(obtiune){
			case 1:creare();break;
			case 2:afisare();break;
			case 3:corectare();break;
			case 4:afisare_selectiva();break;
			case 5:adaugare();break;
			case 6:sortare();break;
			case 7:creare_doua_fisiere();break;
			case 8:crearea_listei();break;
			case 9:afisarea_listei();break;
			case 10:adaugarea_in_lista();break;
			case 11:stergerea_din_lista();break;
			case 0:exit(0);break;
			default:printf("Numar gresit\n");
			getch();
		}

	}

	return 0;
}