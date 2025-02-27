#include "claseArchivoClientes.h"

        Clientes ArchivoClientes::leerRegistro(int pos){
            Clientes reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int ArchivoClientes::contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Clientes);
            fclose(p);
            return cant;
        }
        int ArchivoClientes::buscarRegistro(int num){
            Clientes obj;
            int pos=0;
            FILE *p;
            p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            while(fread(&obj,sizeof(Clientes),1,p)){
                if(obj.getDni()==num){
                    break;
                }
                pos++;
            }
            fclose(p);
            if(obj.getDni()==num){return pos;}
            else{return -1;}
        }
        bool ArchivoClientes::grabarRegistro(Clientes reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        void ArchivoClientes::modificar(Clientes obj,int num){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL)return;
        fseek(p, sizeof(Clientes)*num, 0);
        fwrite(&obj, sizeof(Clientes), 1, p);
        fclose(p);
        return;
        }
        bool ArchivoClientes::crearBackup(const char *nombreB){
            FILE *pBk;
            Clientes obj;
            pBk=fopen(nombreB,"wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Clientes),1,pBk);
            }
            fclose(pBk);
            return true;
       }
       bool ArchivoClientes::baja(){
            FILE *pBk;
            Clientes obj;
            pBk=fopen("borrarC.dat","wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Clientes),1,pBk);
            }
            fclose(pBk);
            return true;
       }
      bool ArchivoClientes::restaurarRegistros(const char *nombreB){
           FILE *p;
           Clientes obj;
           ArchivoClientes clientesBackUp(nombreB);
           int cantReg=clientesBackUp.contarRegistros();
           p=fopen(nombre,"wb");
           if(p==NULL)return false;
           for(int i=0;i<cantReg;i++){
            obj=clientesBackUp.leerRegistro(i);
            obj.setEstado(true);
            fwrite(&obj,sizeof(Clientes),1,p);
           }
            fclose(p);
            return true;

       }
       bool ArchivoClientes::crearBajaFisica(){
           FILE *p;
           Clientes obj;
           ArchivoClientes baja("borrarC.dat");
           int cantReg=baja.contarRegistros();
           p=fopen(nombre,"wb");
           for(int i=0;i<cantReg;i++){
            obj=baja.leerRegistro(i);
            if(obj.getEstado()==true){
            fwrite(&obj,sizeof(Clientes),1,p);
            }
           }
            fclose(p);
            return true;
           }
