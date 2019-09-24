#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct nodo_ar {
	int info;
	struct nodo_ar* hder;
	struct nodo_ar* hizq;
	struct nodo_ar* padre;
};

typedef struct nodo_ar TDAAB;

TDAAB* maketree(int info);
int setright(TDAAB* p, int info);
int setleft(TDAAB* p, int info);
int isright(TDAAB* p);
int isleft(TDAAB* p);
TDAAB* right(TDAAB* p);
TDAAB* left(TDAAB* p);
TDAAB* father(TDAAB* p);
TDAAB* brother(TDAAB* p);
int info(TDAAB* p);
void InsertarInfo(TDAAB *p, int num);
void PreOrden(TDAAB* p);
void Orden(TDAAB* p);
void PostOrden(TDAAB* p);

int main() {
	TDAAB* raiz = NULL;
	int num;
	int opc_1, opc_2;

	do {
		system("cls");
		fflush(stdin);
		
		printf("1.-Ingresar numero\n");
		printf("2.-Recorridos\n");
		printf("9.-Salir\n");
		printf("Digite opcion: ");
		scanf("%d", &opc_1);
		
		switch (opc_1) {
		case 1:
			system("cls");
			fflush(stdin);
				
			printf("Ingrese numero: ");
			scanf("%d", &num);
			if(raiz == NULL)
				raiz = maketree(num);
			else
				InsertarInfo(raiz, num);

			break;
		
		case 2:
			do {
				system("cls");
				fflush(stdin);
				
				printf("1.-PreOrden\n");
				printf("2.-Orden\n");
				printf("3.-PostOrden\n");
				printf("9.-Regresar al menu principal\n");
				printf("Digite opcion: ");
				scanf("%d", &opc_2);

				switch (opc_2) {
				case 1:
					if (raiz == NULL)
						printf("No hay numeros ingresados\n");
					else
						PreOrden(raiz);
					system("pause");
					break;
				case 2:
					if (raiz == NULL)
						printf("No hay numeros ingresados\n");
					else
						Orden(raiz);
					system("pause");
					break;
				case 3:
					if (raiz == NULL)
						printf("No hay numeros ingresados\n");
					else
						PostOrden(raiz);
					system("pause");
					break;
				}
			} while (opc_2 != 9);
			break;
		}
	} while (opc_1 != 9);

	getch();
	return 0;
}


TDAAB* maketree(int info) {
	TDAAB* q;
	q = (TDAAB*) malloc(sizeof(TDAAB));
	if (q!=NULL) {
		q->info = info;
		q->hder = NULL;
		q->hizq = NULL;
		q->padre = NULL;
	}
	return q;
}

int setright(TDAAB* p, int info) {
	TDAAB* q;
	if (right(p) == NULL) {
		q = maketree(info);
		p->hder = q;
		q->padre = p;
		return 1;
	}
	return 0;
}

int setleft(TDAAB* p, int info) {
	TDAAB* q;
	if (left(p) == NULL) {
		q = maketree(info);
		p->hizq = q;
		q->padre = p;
		return 1;
	}
	return 0;
}

int isright(TDAAB* p) {
	if (father(p) == NULL)
		return 0;
	if (right(father(p)))
		return 1;
	return 0;
}

int isleft(TDAAB* p) {
	if (father(p) == NULL)
		return 0;
	if (left(father(p)))
		return 1;
	return 0;
}

TDAAB* right(TDAAB* p) {
	return p->hder;
}

TDAAB* left(TDAAB* p) {
	return p->hizq;
}

TDAAB* father(TDAAB* p) {
	return p->padre;
}

TDAAB* brother(TDAAB* p) {
	if (isright(p))
		return left(father(p));
	if (isleft(p))
		return right(father(p));
	return NULL;
}

int info(TDAAB* p) {
	return p->info;
}

void InsertarInfo(TDAAB* p, int num) {
	if(p != NULL) {
		if (num >= info(p)) {
			if (setright(p, num) == 0)
				InsertarInfo(right(p), num);
		}else
		{
			if (setleft(p, num) == 0)
				InsertarInfo(left(p), num);
		}
	}
}

void PreOrden(TDAAB* p) {
	if (p != NULL) {
		printf("%d, ", info(p));
		PreOrden(left(p));
		PreOrden(right(p));
	}
}

void Orden(TDAAB* p) {
	if (p != NULL) {
		Orden(left(p));
		printf("%d, ", info(p));
		Orden(right(p));
	}
}

void PostOrden(TDAAB* p) {
	if (p != NULL) { 
		PostOrden(left(p));
		PostOrden(right(p));
		printf("%d, ", info(p));
	}
}
