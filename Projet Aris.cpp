#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <mem.h>
#define ttch 50 //Nombre total de chambres

typedef struct infos
{
	int numch;                  //Représentant le numéro de chambre
	char nom[100];              //Représentant le nom du client
	char prenom[100];           //Représentant le prénom du client
	char sexe[2];               //Représentant le sexe du client
	char CNI[20];               //Représentant le CNI du client
	char datearr[12];           //Représentant la date d'arrivée du client
	char datedep[12];           //Représentant la date de départ du du client
	 
};

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//FONCTIONS AJOUTER 

void ajouter(infos *info,int numch)
{

	char nom[100];
	char prenom[100];
	char sexe[2];
	char CNI[20];
	char datearr[12];
	char datedep[12];

info[numch].numch=numch;
printf("\nEntrez le nom sans espaces svp\t"); 
scanf("%s",nom);
strcpy(info[numch].nom,nom);
printf("\nEntrez prenom(s) sans espaces svp\t");
scanf("%s",prenom);
strcpy(info[numch].prenom,prenom);
printf("\nEntrez le sexe (M ou F)\t");
scanf("%s",sexe);
strcpy(info[numch].sexe,sexe);
printf("\nEntrez CNI\t");
scanf("%s",CNI);
strcpy(info[numch].CNI,CNI);
printf("\nEntrez date d-arrivee en format jj-mm-aaaa\t");
scanf("%s",datearr);
strcpy(info[numch].datearr,datearr);
printf("\nEntrez date de depart en format jj-mm-aaaa\t");
scanf("%s",datedep);
strcpy(info[numch].datedep,datedep);

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//FONCTIONS AFFICHER A BASE DU NOM

void afficher_nom(infos *info,char nom[])
{
	printf("\n");
int i;int z=0;
for(i=1;i<ttch+1;i++)//Balaye le tableau de structure
{
	if(strstr(info[i].nom,nom)||strstr(nom,info[i].nom))//Teste si le nom fourni est égal au nom présent dans cette rangée
	{
		if(info[i].numch==ttch+1)//une chambre avec le numéro ttch+1 represente une chambre vide
		{
		printf("Numero de chambre:%d\tNom:%s\tPrenom:%s\nSexe:%s\tCNI:%s\nDate d-arrivee:%s\tDate de depart:%s",info[i].numch,info[i].nom,info[i].prenom,info[i].sexe,info[i].CNI,info[i].datearr,info[i].datedep);
		printf("\n");
		z++;
	}
	}
	

}
	if(z==0) printf("\n Aucun adherant ne porte ce nom");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//FONCTIONS AFFICHER A BASE DU PRENOM

void afficher_prenom(infos *info,char prenom)
{
	printf("\n");
int i;int z=0;
for(i=1;i<ttch+1;i++)//Balaye le tableau de structure
{
	if(strstr(info[i].prenom,prenom)&&strstr(prenom,info[i].prenom))//Teste si le prénom fourni est égal au prénom présent dans cette rangée
	{
		if(info[i].numch!=ttch+1)//une chambre avec le numéro ttch+1 represente une chambre vide
		{
		printf("Numero de chambre:%d\tNom:%s\tPrenom:%s\nSexe:%s\tCNI:%s\nDate d-arrivee:%s\tDate de depart:%s",info[i].numch,info[i].nom,info[i].prenom,info[i].sexe,info[i].CNI,info[i].datearr,info[i].datedep);
		printf("\n");
		z++;
	}
	}
	

}
	if(z==0) printf("\n Aucun adherant ne porte ce prenom");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//FONCTIONS AFFICHER A BASE DU CNI

void afficher_CNI(infos *info,char *CNI)
{
	printf("\n");
int i;int z=0;
for(i=1;i<ttch+1;i++)//Balaye le tableau de structure
{
	if(strstr(info[i].CNI,CNI)&&strstr(CNI,info[i].CNI))//Teste si le CNI fourni est égal au nom CNI dans cette rangée
	{
		if(info[i].numch!=ttch+1)
		{
		printf("Numero de chambre:%d\tNom:%s\tPrenom:%s\nSexe:%s\tCNI:%s\nDate d-arrivee:%s\tDate de depart:%s",info[i].numch,info[i].nom,info[i].prenom,info[i].sexe,info[i].CNI,info[i].datearr,info[i].datedep);
		printf("\n");
		z++;	
		}
		
	}
	

}
	if(z==0) printf("\nAucun adherant ne porte ce CNI");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//FONCTIONS AFFICHER A BASE DU NUMERO DE CHAMBRE

void afficher_num(infos *info,int numch)
{
	printf("\n");
int i;int z=0;
for(i=1;i<ttch+1;i++)//Balaye le tableau de structure
{
	if(info[i].numch!=ttch+1)//une chambre avec le numéro ttch+1 represente une chambre vide
	{
	
	if(info[i].numch==numch)//Teste si le numéro de chambre fourni est égal au nom numéro de chambre dans cette rangée
	{
		printf("Numero de chambre:%d\tNom:%s\tPrenom:%s\nSexe:%s\tCNI:%s\nDate d-arrivee:%s\tDate de depart:%s",info[i].numch,info[i].nom,info[i].prenom,info[i].sexe,info[i].CNI,info[i].datearr,info[i].datedep);
		printf("\n");
		z++;
	}
}

}
	if(z==0) printf("\nAucun adherant n'est dans cette chambre");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//FONCTIONS  SUPPRIMER //La suppression d'un client remplace la case par une chambre avec le numero <ttch+1>

void supprimer(infos *info)
{
	printf("\n");

	char nom[100];
	char prenom[100];
	char CNI[20];


printf("\nEntrez le nom sans espaces svp\t"); 
scanf("%s",nom);

printf("\nEntrez un prenom sans espaces svp\t");
scanf("%s",prenom);

printf("\nEntrez CNI\t");
scanf("%s",CNI);

int i;int z=0;
for(i=1;i<ttch+1;i++)//Balaye le tableau de structure et procède à une série de 3 tests imbriqués sur les similitude du nom, du prénom et du CNI
{
	if(strstr(info[i].nom,nom)||strstr(nom,info[i].nom))
	{
		if(strstr(info[i].prenom,prenom)||strstr(prenom,info[i].prenom))
		{
				if(strstr(info[i].CNI,CNI)&&strstr(CNI,info[i].CNI))
				{
			
info[i].numch=ttch+1;// le numéro de chambre <ttch+1> désigne toujours une case vide et ses arguments sont tels
strcpy(info[i].nom,"NOM");
strcpy(info[i].prenom,"PRENOM");
strcpy(info[i].sexe,"M");
strcpy(info[i].CNI,"CNI");
strcpy(info[i].datearr,"00-00-0000");
strcpy(info[i].datedep,"00-00-0000");
z++; 

				}
		
		}
		
	}
	

}
	if(z==0) printf("\n Aucun adherant ne porte ne remplit ces conditions...");
	
	
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//FONCTIONS PERMUTER

void permuter(infos *info,int numch1,int numch2)
{

//Déclaration de variables intermédiaires
	int numch;
	char nom[100];
	char prenom[100];
	char sexe[2];
	char CNI[20];
	char datearr[12];
	char datedep[12];
//Permutation proprement dite
numch=info[numch1].numch;
strcpy(nom,info[numch1].nom);
strcpy(prenom,info[numch1].prenom);
strcpy(sexe,info[numch1].sexe);
strcpy(CNI,info[numch1].CNI);
strcpy(datearr,info[numch1].datearr);
strcpy(datedep,info[numch1].datedep);

info[numch1].numch=info[numch2].numch;
strcpy(info[numch1].nom,info[numch2].nom);
strcpy(info[numch1].prenom,info[numch2].prenom);
strcpy(info[numch1].sexe,info[numch2].sexe);
strcpy(info[numch1].CNI,info[numch2].CNI);
strcpy(info[numch1].datearr,info[numch2].datearr);
strcpy(info[numch1].datedep,info[numch2].datedep);

info[numch2].numch=numch;
strcpy(info[numch2].nom,nom);
strcpy(info[numch2].prenom,prenom);
strcpy(info[numch2].sexe,sexe);
strcpy(info[numch2].CNI,CNI);
strcpy(info[numch2].datearr,datearr);
strcpy(info[numch2].datedep,datedep);

numch=info[numch1].numch;
info[numch1].numch=info[numch2].numch;
info[numch2].numch=numch;

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//FONCTIONS CHERCHER DES CHAMBRES VIDES

void chercher_vid(infos *info)
{
	printf("\n");
int i;int z=0;//z va stocker le nombre de fois que le if a été executé pour dire s'il y a une chambre vide ou pas
for(i=1;i<ttch+1;i++)
{
	if(info[i].numch==ttch+1)
	{
		printf("Chambre:%d libre",i);
		printf("\n");
		z++;
}

}
	if(z==0) printf("\nAucune chambre n'est libre");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//FONCTIONS AFFICHER TOUTES LES INFORMATIONS PAR NUMERO DE CHAMBRE

void afficher_tout1(infos *info)
{
	printf("\n");
int i;int z=0;
for(i=1;i<ttch+1;i++)//Balaye de tableau de structure et affiche juste eles informations aux chambres dont le numéro est différent de <ttch+1>
{
	if(info[i].numch!=ttch+1)
	{
		printf("Numero de chambre:%d\tNom:%s\tPrenom:%s\nSexe:%s\tCNI:%s\nDate d-arrivee:%s\tDate de depart:%s",info[i].numch,info[i].nom,info[i].prenom,info[i].sexe,info[i].CNI,info[i].datearr,info[i].datedep);
		printf("\n\n");
		z++;
	
}

}
	if(z==0) printf("\nAucune chambre n'est occupee...");
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//FONCTIONS AFFICHER TOUTES LES INFORMATIONS PAR ORDRE ALPHABETIQUE

void afficher_tout2(infos *info)
{
	printf("\n");
int i;int z=0;
for(i=1;i<ttch+1;i++)
{
	if(info[i].numch!=51) z++;//z va compter le nombre de chambres occupées	
}

if(z!=0)
{
	infos *T;int j=0;
	T=(infos*)calloc(z,sizeof(infos));//T sera un tableau sur les chambres occupées
	for(i=1;i<ttch+1;i++)
{
	
			if(info[i].numch!=ttch+1)
	{
		T[j].numch=info[i].numch;
strcpy(T[j].nom,info[i].nom);
strcpy(T[j].prenom,info[i].prenom);
strcpy(T[j].sexe,info[i].sexe);
strcpy(T[j].CNI,info[i].CNI);
strcpy(T[j].datearr,info[i].datearr);
strcpy(T[j].datedep,info[i].datedep);
		
	
		j++;	
}
}

  for(i=0; i<=z-1; i++)
    {
        for(j=z-1; j>i; j--)
        {
            if(strcmp(T[i].nom, T[j].nom )> 0)// Tri du tableau suivant le nom
            {
               permuter(T,i,j);
               
            }
            if(strcmp(T[i].nom, T[j].nom )== 0)
            {
             if(strcmp(T[i].prenom, T[j].prenom )> 0)// Tri du tableau suivant le prenom si les noms sont les mêmes
            {
               permuter(T,i,j);
               
            }	
			}
            
        }
    }


	for(i=0;i<z;i++)//Affichage du tableau trié
	{
		printf("\n");
		printf("Numero de chambre:%d\tNom:%s\tPrenom:%s\nSexe:%s\tCNI:%s\nDate d-arrivee:%s\tDate de depart:%s",T[i].numch,T[i].nom,T[i].prenom,T[i].sexe,T[i].CNI,T[i].datearr,T[i].datedep);
		printf("\n");
	}	
		
	free(T);
}


	if(z==0) printf("\nAucune donnee n'a ete enregistree...");
}






main()
{
	//D'abord une série de questions afin d'être sur de la valeur de la constante ttch
	printf("\nB I E N V E N U E   A   L A   B A S E   D E   G E S T I O N   D E   V O T R E   M O T E L ------- DESIGNED BY ARIS\n");
int on;// Valeur du premier test
printf("EST-CE VOTRE PREMIERE UTLISATION?");
do
{
printf("\nTAPEZ 1 SI OUI\nTAPEZ 2 SI NON\t");
scanf("%d",&on);	
}while(on!=1&&on!=2);

if(on==1)//Au cas où c'est la première utilisation
{
	printf("\nLA VALEUR PAR DEFAUT DU NOMBRE TOTAL DE CHAMBRES EST DE %d... EST-CE EGAL VOTRE NOMBRE DE CHAMBRES?",ttch);
	do
{
printf("\nTAPEZ 1 SI OUI\nTAPEZ 2 SI NON \t");
scanf("%d",&on);	
}while(on!=1&&on!=2);
	if(on==1) 
	{
	printf("\n P A R F A I T!");
		int i;
			FILE *aa=fopen("projetaris.txt","r");
		for(i=1;i<=ttch;i++)
		{
			fprintf(aa,"%d\t%s\t%s\t%s\t%s\t%s\t\t%s\n",ttch+1,"NOM","PRENOM","M","CNI","00-00-0000","00-00-0000");//une chambre avec le numéro ttch+1 represente une chambre vide
			}
			fclose(aa);
		printf("\n VOUS N-ETES OFFICIELLMENT PLUS A VOTRE PREMIERE UTILISATION\n");
		goto ici;
	}
	else {
		printf("\nAVEZ-VOUS DEJA EU A LA MODIFIER?");
		do{
		printf("\nTAPEZ 1 SI OUI\nTAPEZ 2 SI NON\t");
		scanf("%d",&on);	
		}while(on!=1&&on!=2);
		if(on==1)
		{
			int i;
			FILE *aa=fopen("projetaris.txt","w");
		for(i=1;i<=ttch;i++)
		{
			fprintf(aa,"%d\t%s\t%s\t%s\t%s\t%s\t\t%s\n",ttch+1,"NOM","PRENOM","M","CNI","00-00-0000","00-00-0000");//une chambre avec le numéro ttch+1 represente une chambre vide
			}	
			fclose(aa);
		printf("\nM E R C I");
		printf("\n VOUS N-ETES OFFICIELLEMENT PLUS A VOTRE PREMIERE UTILISATION\n");
		goto ici;
		}
		else
		{
		printf("\n-FERMEZ L-EXECUTABLE \n-MODIFIEZ LE NOMBRE DE CHAMBRES DANS #DEFINE DU FICHIER C SOURCE\nEN CAS D'INACCESSIBILITE, CONTACTEZ LE PROGRAMMEUR\n-REDEMARREZ EN SUIVANT LES MEMES INSTRUCTIONS PRECEDENTES JUSQU-A CE NIVEAU");
		printf("\nVOUS ETES TOUJOURS A VOTRE PREMIERE UTILISATION DANS LA PROCHAINE EXECUTION");
		printf("\nET CELA RESTERA AINSI JUSQU-A CE QUE LE PROGRAMME VOUS DISE LE CONTRAIRE SVP");
		getch();
		exit(1);
			}
}
}

if(on==2)//Au cas où le fichier a été déjà initialisé pour sa première fois
{
	ici :  //Il s'agit d'un marquer afin de l'utiliser pour revenir au menu 
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//DECLARATIONS

FILE *aa,*bb;
int i;
infos info[ttch]; int valm; int valm2;//valm est la valeur renvoyee par le menu

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//LECTURE DU FICHIER .TXT

aa=fopen("projetaris.txt","w");

for(i=0;i<ttch;i++)
{
	fscanf(aa,"%d%s%s%s%s%s%s",&info[i+1].numch,info[i+1].nom,info[i+1].prenom,info[i+1].sexe,info[i+1].CNI,info[i+1].datearr,info[i+1].datedep);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//MENU ET REQUETE DE LA COMMANDE VOULUE
printf("\n RE-B I E N V E N U E   A   L A   B A S E   D E   G E S T I O N   D E   V O T R E   M O T E L ------- DESIGNED BY ARIS");
printf("\n(Fermez le fichier .txt avant de commencer)");
do
{
printf("\n\nM E N U\nTAPEZ 1 POUR AJOUTER UN ADHERANT\nTAPEZ 2 POUR AFFICHER LES INFORMATONS PAR RAPPORT A UNE CHAMBRE\nTAPEZ 3 POUR SUPPRIMER UN ADHERANT\nTAPEZ 4 POUR PERMUTER DEUX ADHERANTS\nTAPEZ 5 POUR MODIFIER LES DONNES UN ADHERANT\nTAPEZ 6 POUR CHERCHER LES CHAMBRES VIDES\nTAPEZ 7 POUR AFFICHER TOUTES VOS INFORMATIONS\nTAPEZ 8 POUR QUITTER\n");
scanf("%d",&valm);	
}while(valm<1||valm>8);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE
switch(valm)
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 1 AJOUTER
{
case 1:{

int numch;
do{
printf("\n\nEntrez le numero de chambre (de 1 a %d)\t",ttch);
scanf("%d",&numch);	
}while(numch<1 || numch>ttch+1);

if(numch==info[numch].numch) //En d'autres termes, cette case est déjà occupée
{
	printf("\nLa chambre est deja occupee");
	printf("\nAttendez le %s pour cette chambre\t",info[numch].datedep);
}
else//Cas où la chambre est libre, autrement dit, le numéro de chambre est <ttch+1>
{
ajouter(info,numch);	
}

	break;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 2 AFFICHAGE DES DONNEES D'UNE PERSONNE
case 2:{
do{
	printf("\n\nM E N U C O N T E X T U E L\nTAPEZ 1 SI VOUS DIPOSEZ DU NOM\nTAPEZ 2 SI VOUS DIPOSEZ DU PRENOM\nTAPEZ 3 SI VOUS DIPOSEZ DU CNI\nTAPEZ 4 SI VOUS DIPOSEZ DU NUMERO DE CHAMBRE\n");
scanf("%d",&valm2);
}while(valm2<1||valm2>4);
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 2  1 CHERCHER UNE PERSONNE A BASE DE SON NOM
if(valm2=1)
{
	char nom[100];
	printf("\n Entrez alors le nom sans espaces biensur SVP\t");
	scanf("%s",nom);
	afficher_nom(info,nom);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 2  2  CHERCHER UNE PERSONNE A BASE DE SON PRENOM
if(valm2==2)
{
	char prenom[100];
	printf("\n Entrez alors le Prenom sans espaces biensur SVP\t");
	scanf("%s",prenom);
	afficher_prenom(info,prenom);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 2  3  CHERCHER UNE PERSONNE A BASE DE SON CNI
if(valm2==3)
{
	char CNI[100];
	printf("\n Entrez alors le CNI sans espaces SVP\t");
	scanf("%s",CNI);
	afficher_CNI(info,CNI);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 2  4  CHERCHER UNE PERSONNE A BASE DE SON NUMERO DE CHAMBRE
if(valm2==4)
{
	int numch;
	printf("\n Entrez alors le numero de chambre SVP\t");
	scanf("%d",&numch);
	afficher_num(info,numch);
}


	break;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 3 SUPPRIMER UNE PERSONNE
case 3:{
	supprimer(info);
		break;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 4 PERMUTER  DEUX CLIENTS
case 4:{
	int numch1,numch2;
do{
printf("\n\nEntrez le numero de la premiere chambre\t");
scanf("%d",&numch1);	
}while(numch1<1 || numch1>ttch+1);
do{
printf("\nEntrez le numero de la premiere chambre\t");
scanf("%d",&numch2);	
}while(numch2<1 || numch2>ttch+1);	
	
	
	permuter(info,numch1,numch2);
		break;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 5 MODIFIER LES INFORMATIONS D-UNE CHAMBRE  
case 5:{
	int numch;
do{
printf("\n\nEntrez le numero de la chambre\t");
scanf("%d",&numch);	
}while(numch<1 || numch>ttch+1);	
		
	ajouter(info,numch);
		break;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 6 CHERCHER LES CHAMBRES VIDES  
case 6:{
		
	chercher_vid(info);
		break;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 7 AFFICHER TOUTES LES INFORMATIONS
case 7:{
		
	do{
	printf("\n\nM E N U C O N T E X T U E L\nTAPEZ 1 POUR AFFICHER LES INFORMATIONS SUIVANT LE NUMERO DE CHAMBRE\nTAPEZ 2 POUR AFFICHER LES INFORMATIONS PAR ORDRE ALPHABETIQUE DES CLIENTS\n");
scanf("%d",&valm2);
}while(valm2<1||valm2>2);
	if(valm2==1) afficher_tout1(info);
	else afficher_tout2(info);
	
		break;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SWITCH CASE  CAS 8 QUITTER 
case 8:{
	goto ici2;
		
		break;
}
	break;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//MODIFICATION  DU FICHIER
ici2 :
fclose(aa);
bb=fopen("projetaris.txt","w");
for(i=0;i<ttch;i++)
{
	fprintf(bb,"%d\t%s\t%s\t%s\t%s\t%s\t\t%s\n",info[i+1].numch,info[i+1].nom,info[i+1].prenom,info[i+1].sexe,info[i+1].CNI,info[i+1].datearr,info[i+1].datedep);
}

fclose(bb);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//DEMANDE SI L'UTILISATEUR VEUT QUITTER LE PROGRAMME OU BIEN REVENIR AU MENU
	int returnmenu;
	do
	{
		printf("\nTAPEZ 1 POUR REVENIR AU MENU\nTAPEZ 2 POUR QUITTER \t");
scanf("%d",&returnmenu);
	}while(returnmenu!=1&&returnmenu!=2);

if(returnmenu==1) goto ici;
else exit(1);
	return 0;
}
}
