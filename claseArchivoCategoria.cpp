#include "claseArchivoCategoria.h"
#include <iostream>
using namespace std;

    Categoria ArchivoCategoria::leerRegistro(int pos){
            Categoria reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int ArchivoCategoria::contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Categoria);
            fclose(p);
            return cant;
        }
        bool ArchivoCategoria::grabarRegistro(Categoria reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
      void ArchivoCategoria::modificar(Categoria obj,int num){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL)return;
        fseek(p, sizeof(Categoria)*num, 0);
        fwrite(&obj, sizeof(Categoria), 1, p);
        fclose(p);
        return;
        }
    int ArchivoCategoria::buscarRegistro(int num){
            Categoria cat;
            int pos=0;
            FILE *p;
            p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            while(fread(&cat,sizeof(Categoria),1,p)){
                if(cat.getIdCategoria()==num){
                    break;
                }
                pos++;
            }
            fclose(p);
            if(cat.getIdCategoria()==num){return pos;}
            else{return -1;}
        }
        bool ArchivoCategoria::crearBackup(const char *nombreB){
            FILE *pBk;
            Categoria obj;
            pBk=fopen(nombreB,"wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Categoria),1,pBk);
            }
            fclose(pBk);
            return true;
       }
       bool ArchivoCategoria::baja(){
            FILE *pBk;
            Categoria obj;
            pBk=fopen("borrarCat.dat","wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Categoria),1,pBk);
            }
            fclose(pBk);
            return true;
       }
      bool ArchivoCategoria::restaurarRegistros(const char *nombreB){
           FILE *p;
           Categoria obj;
           ArchivoCategoria categoriaBackUp(nombreB);
           int cantReg=categoriaBackUp.contarRegistros();
           p=fopen(nombre,"wb");
           for(int i=0;i<cantReg;i++){
            obj=categoriaBackUp.leerRegistro(i);
            obj.setEstado(true);
            fwrite(&obj,sizeof(Categoria),1,p);
           }
            fclose(p);
            return true;

       }
       bool ArchivoCategoria::crearBajaFisica(){
           FILE *p;
           Categoria obj;
           ArchivoCategoria baja("borrarCat.dat");
           int cantReg=baja.contarRegistros();
           p=fopen(nombre,"wb");
           for(int i=0;i<cantReg;i++){
            obj=baja.leerRegistro(i);
            if(obj.getEstado()==true){
            fwrite(&obj,sizeof(Categoria),1,p);
            }
           }
            fclose(p);
            return true;
           }


