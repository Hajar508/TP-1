#include<stdio.h>
#include<stdlib.h>
typedef struct Noeud{
    int valeur;
    struct Noeud*suivant;
}Noeud;
Noeud*cree(int val)
{
    Noeud*nv;
    nv=(Noeud*)malloc(sizeof(Noeud));
    nv->valeur=val;
    nv->suivant=NULL;
    return nv;
}
void affiche(Noeud*debut)
{
    Noeud*tmp=debut;
    while(tmp!=NULL)
    {
        printf(" les elements de la liste sont %d",tmp->valeur);
        tmp=tmp->suivant;
    }
}
Noeud*ajouterD(Noeud*debut,int val)
{
    Noeud*nv;
    nv=(Noeud*)malloc(sizeof(Noeud));
    nv->valeur=val;
    nv->suivant=NULL;
    if(debut==NULL)
    {
        printf("la liste est vide");
    }
    else{
    nv->suivant=debut;
    debut=nv;
    }
    return debut;
}
Noeud*ajouterF(Noeud*debut,int val)
{
    Noeud*nv;
    nv=(Noeud*)malloc(sizeof(Noeud));
    nv->valeur=val;
    nv->suivant=NULL;
    Noeud*tmp=debut;
    if(debut==NULL)
    {
        printf("la liste est vide");
    }
    else{
        while(tmp->suivant!=NULL)
        {
            tmp=tmp->suivant;
        }
        tmp->suivant=nv;
    }
    return debut;
}
int taille(Noeud*debut)
{
    int cmpt=0;
    Noeud*tmp=debut;
    while(tmp!=NULL)
    {
        cmpt++;
        tmp=tmp->suivant;
    }

}
Noeud*insertion(Noeud*debut,int pos,int val)
{
    Noeud*nv;
    nv=(Noeud*)malloc(sizeof(Noeud));
    nv->valeur=val;
    nv->suivant=NULL;
    Noeud*tmp=debut;
    int size=taille(debut);
    if(pos<1 || pos>size+1)
    {
        printf("la position n'est pas valide");
    }
    else if(pos==1)
    {
        nv->suivant=debut;
        debut=nv;
    }
    else{
        for(int i=1; i<pos-1; i++)
        {
            tmp=tmp->suivant;
        }
        nv->suivant=tmp->suivant;
        tmp->suivant=nv;
    }
    return debut;
}
void rechercher(Noeud*debut,int val)
{
    int trouve;
    Noeud*tmp=debut;
    while(tmp!=NULL)
    {
        if(tmp->valeur=val){
            trouve=1;
            break;
        }
        else{
            trouve=0;
        }
        tmp=tmp->suivant;
    }
    if(trouve=1){
        printf("la valeur existe");
    }
    else{
        printf("la valeur n'existe pas");
    }
}
Noeud*suppressionD(Noeud*debut)
{
    Noeud*tmp=debut;
    if(debut==NULL){
        printf("la liste est vide");
    }
    else{
        debut=debut->suivant;
        free(tmp);
    }
    return debut;
}
Noeud*suppressionF(Noeud*debut)
{
    Noeud*tmp=debut;
    if(debut==NULL){
        printf("la liste est vide");
    }
    if(tmp->suivant=NULL){
        free(tmp);
         printf("l'element a ete bien supprime");
    }
        while(tmp->suivant->suivant!=NULL){
            tmp=tmp->suivant;
        }
        free(tmp->suivant);
        tmp->suivant=NULL;
        return debut;
}
Noeud*suppressionP(Noeud*debut,int pos)
{
    Noeud*tmp,*cn=debut;
    if(debut==NULL){
        printf("la liste est vide");
        return NULL;
    }
    int size=taille(debut);
    if(pos<1 || pos>taille){
        printf("la position est invalide");
        return debut;
    }
    if(pos==1){
        debut=debut->suivant;
        free(tmp);
        return debut;
    }
    for(int i=1; i<pos-1; i++)
    {
        tmp=tmp->suivant;
    }
    cn=tmp->suivant;
    tmp->suivant=cn->suivant;
    free(cn);
    return debut;
}
Noeud*modifierD(Noeud*debut,int val)
{
    if(debut==NULL){
        printf("la liste est vide");
        return NULL;
    }
    else{
        debut->valeur=val;
    }
    return debut;
}
Noeud*modifierF(Noeud*debut,int val)
{
    Noeud*tmp=debut;
    if(debut==NULL){
        printf("la liste est vide");
        return NULL;
    }
    while(tmp->suivant!=NULL){
        tmp=tmp->suivant;
    }
    tmp->valeur=val;
    return debut;
}
Noeud*modifierP(Noeud*debut,int pos,int val)
{
    Noeud*tmp=debut;
    if(debut==NULL){
        printf("la liste est vide");
        return NULL;
    }
    int size=taille(debut);
    if(pos<1 || pos>size)
    {
        printf("la position est invalide");
        return debut;
    }
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->suivant;
    }
    tmp->valeur=val;
    return debut;
}
int main()
{
    Noeud*debut=NULL;
    Noeud*D=cree(10);
    Noeud*V=cree(20);
    Noeud*T=cree(30);
    printf("l'adresse du Noeud debut est %p\n", debut);
    printf("l'adresse du Noeud D est %p\n", D);
    printf("l'adresse du Noeud V est %p\n", V);
    printf("l'adresse du Noeud T est %p\n", T);
    debut=D;
    D->suivant=V;
    V->suivant=T;
    T->suivant=NULL;
    printf("--------------------------\n");
    printf("L'adresse du Noeud debut est %p",debut);
    printf("l'adresse du Noeud D est %p\n", D->suivant);
    printf("l'adresse du Noeud V est %p\n", V->suivant);
    printf("l'adresse du Noeud T est %p\n", T->suivant);
    printf("----------------AFFICHAGE----------------\n");
    affiche(debut);
    printf("----------------AJOUT DEBUT ET AFFICHAGE--------------\n");
    debut=ajouterD(debut,100);
    affiche(debut);
    printf("----------------AJOUT FIN ET AFFICHAGE----------------\n");
    debut=ajouterF(debut,200);
    affiche(debut);
    printf("----------------RECHERCHE-----------------------------\n");
    rechercher(debut,20);
    printf("----------------TAILLE DE LA LISTE--------------------\n");
    printf("La taille de la liste est %d",taille(debut));
    printf("----------------INSERTION A UNE POSITION--------------\n");
    debut=insertion(debut,3,555);
    affiche(debut);
    printf("----------------SUPPRESSION AU DEBUT---------------------\n");
    debut=suppressionD(debut);
    affiche(debut);
    printf("----------------SUPPRESSION A LA FIN---------------------\n");
    debut=suppressionF(debut);
    affiche(debut);
    printf("----------------SUPPRESSION A UnE POSITION----------------\n");
    debut=suppressionP(debut,4);
    affiche(debut);
    printf("----------------MODIFIER AU DEBUT-------------------------\n");
    debut=modifierD(debut,2024);
    affiche(debut);
    printf("----------------MODIFIER A LA FIN--------------------------\n");
    debut=modifierF(debut,2025);
    affiche(debut);
    printf("----------------MODIFIER UNE POSITION----------------------\n");
    debut=modifierP(debut,1,2000);
    affiche(debut);
    return 0;
}

