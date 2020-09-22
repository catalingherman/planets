int nr_de_planete=0;//variabila globala

struct planeta{//structura pentru fisiere
	char nume[15];
	double diametru;
	double masa;
	int nr_orbita;
	int rotirea_anuala;
	int nr_sateliti;
}planeta[20];

typedef struct planete{//structura pentru liste
	char nume[15];
	double diametru;
	double masa;
	int nr_orbita;
	int rotirea_anuala;
	int nr_sateliti;
	struct planete *urm, *prec;
}nod;

nod *lista;

void creare(){//crearea fisierului si introducerea planetelor initiale
	FILE *f;
	int i=0,z;
	f=fopen("planete.txt","wb");

	printf("---Crearea Fisierului---\n");
	inceput:	printf("Introduceti numele planetei : ");
			fflush(stdin);
			scanf("%s",planeta[i].nume);
			printf("\nIntroduceti diamentrul planetei : ");
			fflush(stdin);
			scanf("%lf",&planeta[i].diametru);
			printf("\nIntroduceti masa planetei : ");
			fflush(stdin);
			scanf("%lf",&planeta[i].masa);
			printf("\nIntroduceti numarul de ordine a orbitei de la Soare : ");
			fflush(stdin);
			scanf("%d",&planeta[i].nr_orbita);
			printf("\nIntroduceti numarul de zile in care planeta executa o rotatie totala in jurul soarelui : ");
			fflush(stdin);
			scanf("%d",&planeta[i].rotirea_anuala);
			printf("\nIntroduceti numarul de sateliti ai planetei : ");
			fflush(stdin);
			scanf("%d",&planeta[i].nr_sateliti);
			i++;
	printf("Mai introduceti o planeta?(1/0) \n");
	fflush(stdin);
	scanf("%d",&z);
	if(z!=0)
		goto inceput;
	else{
		nr_de_planete=i+1;
		fwrite(&planeta, sizeof(planeta[0]), nr_de_planete, f);
		fclose(f);
	}
}

void afisare(){//afisarea fisierului
	FILE *f;
	int i, j=0;
	f=fopen("planete.txt","rb");
	while(!feof(f)){
		fread(&planeta[j], sizeof(planeta[0]), 1, f);
		j++;
	}
	printf("\n\n\n\n");
	printf("---Afisarea planetelor din fisier---\n");
	printf("  ____________________________________________________________________________________________________________________\n");
	printf(" | Id |        Nume        |       Diametru     |        Masa        |  Nr orbitei  | Rotirea Anuala | Nr de Sateliti |\n");
 	printf("  ____________________________________________________________________________________________________________________\n");
 	for(i=1;i<nr_de_planete;i++){
	 	printf(" | %-2d |  %-16s  |%-20.0f|%-20.0f|%-14d|%-16d|%-16d|\n", i, planeta[i-1].nume, planeta[i-1].diametru, planeta[i-1].masa, planeta[i-1].nr_orbita, planeta[i-1].rotirea_anuala, planeta[i-1].nr_sateliti);
	}
	printf("  ____________________________________________________________________________________________________________________\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fclose(f);
	getch();
 }

void corectare(){//modificarea fisierului
	int id,j=0,p;
	FILE *f;
	f=fopen("planete.txt","rb");
	idgresit:printf("Introduceti id-ul planetei pe care doriti sa o modificati : ");
	fflush(stdin);
	scanf("%d",&id);
	if(id<1 || id>nr_de_planete){
		printf("\nId e gresit, introduceti altul!\n");
		goto idgresit;
	}
	while(!feof(f)){
		fread(&planeta[j], sizeof(planeta[0]), 1, f);
		j++;
	}
	fclose(f);
	greseala :  printf("\nAlegeti parametrul pe care doriti sa il modificati : \n");
				printf("1) Numele\n");
				printf("2)Diametrul\n");
				printf("3)Masa\n");
				printf("4)Numarul orbitei\n");
				printf("5)Rotirea anuala\n");
				printf("6)Numarul de sateliti\n");
				fflush(stdin);
				scanf("%d",&p);
	switch(p){
		case 1:printf("\nIntroduceti numele nou : ");
			   scanf("%s",planeta[id-1].nume);
			   break;
		case 2:printf("\nIntroduceti diametrul nou : ");
			   scanf("%lf",&planeta[id-1].diametru);
			   break;
		case 3:printf("\nIntroduceti masa noua : ");	
			   scanf("%lf",&planeta[id-1].masa);
			   break;
		case 4:printf("\nIntroduceti numarul nou al orbitei : ");
			   scanf("%d",&planeta[id-1].nr_orbita);
			   break;
		case 5:printf("\nIntroduceti numarul nou de zile : ");
			   scanf("%d",&planeta[id-1].rotirea_anuala);
			   break;
		case 6:printf("\nIntroduceti numarul nou de sateliti : ");
			   scanf("%d",&planeta[id-1].nr_sateliti);
			   break;	
		default:printf("\nParametru gresit,introduceti din nou! \n");
				goto greseala;					 	 
	}
	f=fopen("planete.txt","wb");
	fwrite(&planeta, sizeof(planeta[0]), nr_de_planete, f);
	fclose(f);	
}

void afisare_selectiva(){
	int criteriu,j=0,i;
	double min, max;
	FILE *f;
	printf("\nAlegeti criteriul pentru afisarea selectiva\n");
	printf("1)Dupa diametru\n");
	printf("2)Dupa masa\n");
	printf("3)Dupa numarul orbitei\n");
	printf("4)Dupa numarul de zile necesare pentru implinirea rotirei anuale\n");
	printf("5)Dupa numarul de sateliti\n");
	fflush(stdin);
	scanf("%d", &criteriu);
	printf("\nIntroduceti diapazonul :\n");
	printf("Min : ");
	scanf("%lf",&min);
	printf("\nMax : ");
	scanf("%lf",&max);
	f=fopen("planete.txt","rb");
	while(!feof(f)){
		fread(&planeta[j], sizeof(planeta[0]), 1, f);
		j++;
	}
	printf("\n\n\n\n");
	printf("---Afisarea selectiva a planetelor din fisier---\n");
	printf("  ____________________________________________________________________________________________________________________\n");
	printf(" | Id |        Nume        |       Diametru     |        Masa        |  Nr orbitei  | Rotirea Anuala | Nr de Sateliti |\n");
 	printf("  ____________________________________________________________________________________________________________________\n");
 	for(i=1;i<nr_de_planete;i++){
 		if(criteriu==1 && (planeta[i-1].diametru<min || planeta[i-1].diametru>max)) continue;
 		if(criteriu==2 && (planeta[i-1].masa<min || planeta[i-1].masa>max)) continue;
 		if(criteriu==3 && (planeta[i-1].nr_orbita<min || planeta[i-1].nr_orbita>max)) continue;
 		if(criteriu==4 && (planeta[i-1].rotirea_anuala<min || planeta[i-1].rotirea_anuala>max)) continue;
 		if(criteriu==5 && (planeta[i-1].nr_sateliti<min || planeta[i-1].nr_sateliti>max)) continue;
	 	printf(" | %-2d |  %-16s  |%-20.0f|%-20.0f|%-14d|%-16d|%-16d|\n", i, planeta[i-1].nume, planeta[i-1].diametru, planeta[i-1].masa, planeta[i-1].nr_orbita, planeta[i-1].rotirea_anuala, planeta[i-1].nr_sateliti);
	}
	printf("  ____________________________________________________________________________________________________________________\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fclose(f);
	getch();
}

void adaugare(){
	FILE *f;
	int i, j=0, z;
	f=fopen("planete.txt","rb");
	while(!feof(f)){
		fread(&planeta[j], sizeof(planeta[0]), 1, f);
		j++;
	}
	fclose(f);
	i=nr_de_planete-1;
	printf("---Adaugarea planetelor in fisier---\n");
	goadaugare:	printf("Introduceti numele planetei : ");
			fflush(stdin);
			scanf("%s",planeta[i].nume);
			printf("\nIntroduceti diamentrul planetei : ");
			fflush(stdin);
			scanf("%lf",&planeta[i].diametru);
			printf("\nIntroduceti masa planetei : ");
			fflush(stdin);
			scanf("%lf",&planeta[i].masa);
			printf("\nIntroduceti numarul de ordine a orbitei de la Soare : ");
			fflush(stdin);
			scanf("%d",&planeta[i].nr_orbita);
			printf("\nIntroduceti numarul de zile in care planeta executa o rotatie totala in jurul soarelui : ");
			fflush(stdin);
			scanf("%d",&planeta[i].rotirea_anuala);
			printf("\nIntroduceti numarul de sateliti ai planetei : ");
			fflush(stdin);
			scanf("%d",&planeta[i].nr_sateliti);
			i++;
	printf("Mai introduceti o planeta?(1/0) \n");
	fflush(stdin);
	scanf("%d",&z);
	if(z!=0)
		goto goadaugare;
	else{
		nr_de_planete=i+1;
		f=fopen("planete.txt","wb");
		fwrite(&planeta, sizeof(planeta[0]), nr_de_planete, f);
		fclose(f);
	}
}

void sortare(){//sortare prin metoda Shell
	int i, j, k, n, l=0, criteriu;
	struct planeta temp;
	FILE *f;
	n=nr_de_planete-1;
	f=fopen("planete.txt","rb");
	while(!feof(f)){
		fread(&planeta[l], sizeof(planeta[0]), 1, f);
		l++;
	}
	fclose(f);
	sorterror:	printf("\nAlegeti criteriul pentru sortare\n");
	printf("1)Dupa diametru\n");
	printf("2)Dupa masa\n");
	printf("3)Dupa numarul orbitei\n");
	printf("4)Dupa numarul de zile necesare pentru implinirea rotirei anuale\n");
	printf("5)Dupa numarul de sateliti\n");
	fflush(stdin);
	scanf("%d", &criteriu);

    switch(criteriu){
		case 1:
			for (i = n / 2; i > 0; i = i / 2){
		        for (j = i; j < n; j++){
		            for(k = j - i; k >= 0; k = k - i){
		                if (planeta[k+i].diametru >= planeta[k].diametru)
		                    break;
		                else{
		                    temp = planeta[k];
		                    planeta[k] = planeta[k+i];
		                    planeta[k+i] = temp;
		                }
		            }
		        }
		    }





		    
			break;
		case 2:for (i = n / 2; i > 0; i = i / 2){
			        for (j = i; j < n; j++){
			            for(k = j - i; k >= 0; k = k - i){
			                if (planeta[k+i].masa >= planeta[k].masa)
			                    break;
			                else{
			                    temp = planeta[k];
			                    planeta[k] = planeta[k+i];
			                    planeta[k+i] = temp;
			                }
			            }
			        }
			    }
			   break;
		case 3:for (i = n / 2; i > 0; i = i / 2){
			        for (j = i; j < n; j++){
			            for(k = j - i; k >= 0; k = k - i){
			                if (planeta[k+i].nr_orbita >= planeta[k].nr_orbita)
			                    break;
			                else{
			                    temp = planeta[k];
			                    planeta[k] = planeta[k+i];
			                    planeta[k+i] = temp;
			                }
			            }
			        }
			    }
			   break;
		case 4:for (i = n / 2; i > 0; i = i / 2){
			        for (j = i; j < n; j++){
			            for(k = j - i; k >= 0; k = k - i){
			                if (planeta[k+i].rotirea_anuala >= planeta[k].rotirea_anuala)
			                    break;
			                else{
			                    temp = planeta[k];
			                    planeta[k] = planeta[k+i];
			                    planeta[k+i] = temp;
			                }
			            }
			        }
			    }
			   break;
		case 5:for (i = n / 2; i > 0; i = i / 2){
			        for (j = i; j < n; j++){
			            for(k = j - i; k >= 0; k = k - i){
			                if (planeta[k+i].nr_sateliti >= planeta[k].nr_sateliti)
			                    break;
			                else{
			                    temp = planeta[k];
			                    planeta[k] = planeta[k+i];
			                    planeta[k+i] = temp;
			                }
			            }
			        }
			    }
			   break;	
		default:printf("\nCriteriu gresit,introduceti din nou! \n");
				goto sorterror;					 	 
	}
    f=fopen("planete.txt","wb");
    fwrite(&planeta, sizeof(planeta[0]), nr_de_planete, f);
	fclose(f);
}

void creare_doua_fisiere(){
	int j=0, i, nm=0, mn=0;
	struct planeta planeta2[10], planeta3[10];
	FILE *f, *f2, *f3;
	f=fopen("planete.txt","rb");
	f2=fopen("planete_mai_mari_ca_pamantul.txt","wb");
	f3=fopen("planete_mai_mici_ca_pamantul.txt","wb");
	while(!feof(f)){
		fread(&planeta[j], sizeof(planeta[0]), 1, f);
		j++;
	}
	fclose(f);
	for(i=0;i<nr_de_planete;i++){
		if(planeta[i].diametru > 12756){
			planeta2[nm]=planeta[i];
			nm++;
		}
		else if(planeta[i].diametru < 12756){
			planeta3[mn]=planeta[i];
			mn++;
		}
	}
	fwrite(&planeta2, sizeof(planeta2[0]), nm, f2);
	fwrite(&planeta3, sizeof(planeta3[0]), mn, f3);
	printf("\n\n\n\n\n\n");
	printf("---Afisarea planetelor din fisierul nr 2 (Care sunt mai mari ca Pamantul)---\n");
	printf("  ____________________________________________________________________________________________________________________\n");
	printf(" | Id |        Nume        |       Diametru     |        Masa        |  Nr orbitei  | Rotirea Anuala | Nr de Sateliti |\n");
 	printf("  ____________________________________________________________________________________________________________________\n");
 	for(i=1;i<=nm;i++){
	 	printf(" | %-2d |  %-16s  |%-20.0f|%-20.0f|%-14d|%-16d|%-16d|\n", i, planeta2[i-1].nume, planeta2[i-1].diametru, planeta2[i-1].masa, planeta2[i-1].nr_orbita, planeta2[i-1].rotirea_anuala, planeta2[i-1].nr_sateliti);
	}
	printf("  ____________________________________________________________________________________________________________________\n");

	printf("\n\n");
	printf("---Afisarea planetelor din fisierul nr 3 (Care sunt mai mici ca Pamantul)---\n");
	printf("  ____________________________________________________________________________________________________________________\n");
	printf(" | Id |        Nume        |       Diametru     |        Masa        |  Nr orbitei  | Rotirea Anuala | Nr de Sateliti |\n");
 	printf("  ____________________________________________________________________________________________________________________\n");
 	for(i=1;i<mn;i++){
	 	printf(" | %-2d |  %-16s  |%-20.0f|%-20.0f|%-14d|%-16d|%-16d|\n", i, planeta3[i-1].nume, planeta3[i-1].diametru, planeta3[i-1].masa, planeta3[i-1].nr_orbita, planeta3[i-1].rotirea_anuala, planeta3[i-1].nr_sateliti);
	}
	printf("  ____________________________________________________________________________________________________________________\n");
	printf("\n\n");
	getch();
	fclose(f2);
	fclose(f3);
}

void crearea_listei2(int i){
	/* Alocare si initializare nod*/
	nod *q=(nod*)malloc(sizeof(nod));
	 strcpy(q->nume, planeta[i].nume);
	 q->diametru = planeta[i].diametru;
	 q->masa = planeta[i].masa;
	 q->nr_orbita = planeta[i].nr_orbita;
	 q->rotirea_anuala = planeta[i].rotirea_anuala;
	 q->nr_sateliti = planeta[i].nr_sateliti;
	 q->urm = NULL;
	 q->prec = NULL;
	if (lista==NULL){/*daca avem lista vida*/
		 lista = q; /*modificam capul listei*/
	}else{
	 	nod *p = lista;
		while (p->urm != NULL)
		 	p = p->urm; /* parcurgem lista pana la ultimul nod*/
		 p->urm = q;/* adaugam elementul nou in lista */
		 q->prec = p;
	}	
}

void crearea_listei(){//copierea elementelor fisierului in nodurile listei
	int i;
	for(i=0;i<nr_de_planete;i++){
		crearea_listei2(i);
	}
	printf("\nLista creata cu succes! \n");
	getch();
}

void afisarea_listei(){
	nod *t = lista;
	int i=1;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Lista cu planete : \n");
	printf("  ____________________________________________________________________________________________________________________\n");
	printf(" | Id |        Nume        |       Diametru     |        Masa        |  Nr orbitei  | Rotirea Anuala | Nr de Sateliti |\n");
 	printf("  ____________________________________________________________________________________________________________________\n");
	while(t->urm != NULL){
	 	printf(" | %-2d |  %-16s  |%-20.0f|%-20.0f|%-14d|%-16d|%-16d|\n", i, t->nume, t->diametru, t->masa, t->nr_orbita, t->rotirea_anuala, t->nr_sateliti);
		t=t->urm;
		i++;
	}
  	printf("  ____________________________________________________________________________________________________________________\n");

	printf("\n\n\n\n\n\n");
	getch();
}

void adaugarea_in_lista(){
	int z, i;
	nod *p = lista;
	printf("---Adaugarea in lista a doua elemente dupa elementul indicat---\n");
	printf("\nIntroduceti id elementului : ");
	fflush(stdin);
	scanf("%d",&z);
	for(i=1;i<z;i++){
		p = p->urm;
	}

	 nod *q=(nod*)malloc(sizeof(nod));
	 printf("\nIntroduceti numele planetei : ");
			fflush(stdin);
			scanf("%s",q->nume);
	 printf("\nIntroduceti diametrul planetei : ");
			fflush(stdin);
			scanf("%lf",&q->diametru);
	 printf("\nIntroduceti masa planetei : ");
			fflush(stdin);
			scanf("%lf",&q->masa);
	 printf("\nIntroduceti numarul de ordine a orbitei de la Soare : ");
			fflush(stdin);
			scanf("%d",&q->nr_orbita);
	 printf("\nIntroduceti numarul de zile in care planeta executa o rotatie totala in jurul soarelui : ");
			fflush(stdin);
			scanf("%d",&q->rotirea_anuala);
	 printf("\nIntroduceti numarul de sateliti ai planetei : ");
			fflush(stdin);
			scanf("%d",&q->nr_sateliti);
	if(z==0){
		q->prec = NULL;
	}else{
		 q->urm = NULL;
		 q->prec = p;
	}


	 nod *t=(nod*)malloc(sizeof(nod));
	 printf("\n\nIntroduceti numele planetei urmatoare : ");
			fflush(stdin);
			scanf("%s",t->nume);
	 printf("\nIntroduceti diametrul planetei : ");
			fflush(stdin);
			scanf("%lf",&t->diametru);
	 printf("\nIntroduceti masa planetei : ");
			fflush(stdin);
			scanf("%lf",&t->masa);
	 printf("\nIntroduceti numarul de ordine a orbitei de la Soare : ");
			fflush(stdin);
			scanf("%d",&t->nr_orbita);
	 printf("\nIntroduceti numarul de zile in care planeta executa o rotatie totala in jurul soarelui : ");
			fflush(stdin);
			scanf("%d",&t->rotirea_anuala);
	 printf("\nIntroduceti numarul de sateliti ai planetei : ");
			fflush(stdin);
			scanf("%d",&t->nr_sateliti);
	 t->prec = q;
	 q->urm = t;
	 if(z==0){
	 	t->urm = p;
	 	lista = q;
	 }else{
		 t->urm = p->urm;
		 p->urm = q;
	 }
	 printf("\n\nElementele au fost adaugate cu succes!\n");
	 getch();
}

void stergerea_din_lista(){
	int z, i;
	nod *p = lista;
	printf("\n\n\n\n\n\n\n\n---Stergerea din lista a doua elemente consecutive de la elementul indicat---\n");
	printf("\nIntroduceti id elementului : ");
	fflush(stdin);
	scanf("%d",&z);
	for(i=1;i<z;i++){
		p = p->urm;
	}
	p->prec->urm=p->urm->urm;
	p->urm->urm->prec=p->prec;
	free(p->urm);
	free(p);
	printf("\nElementele listei cu indicele %d si %d au fost eliminate!\n",z,z+1);
	getch();
}
