/**
* @file main.cpp
* @description programın ana classı main
* @course Dersi 1. öğretin a grubu
* @assignment 2. ödev
* @date 8.12.2023
* @author Furkan YILDIZ furkan.yildiz12@ogr.sakarya.edu.tr
*/
#include "FileReader.hpp"
#include "AVLTree.hpp"
#include <iostream>
#include <list>
using namespace std;
int main() {


    // Dosya adını ve yolunu belirtin
    std::string dosyaAdi = "Veri.txt";
    
    // FileReader sınıfından bir nesne oluşturun
    FileReader fileReader(dosyaAdi);

    // Dosyayı aç
    if (!fileReader.DosyayiAc()) {
        std::cerr << "Dosya acilamadi: " << dosyaAdi << std::endl;
        return 1;
    }

    // Dosyadan oku ve ekrana yazdır
    fileReader.DosyadanOkuVeYazdir();

    //işlem yapabilmek için listeyi main kısmına çektik
    list<AVLTree *> AVLTreeList = fileReader.AVLTreeList;

    // Dosyayı kapat
    fileReader.DosyayiKapat();




    AVLTree* temp = AVLTreeList.front();

    bool flag = false;
    
    while(AVLTreeList.size()!=1){
    
        flag =false;
        //en küçüğü bulma
        for (const auto& element : AVLTreeList) {
            if(element->stack->isEmpty()){
                flag=true;
                system("cls");
                for (const auto& element : AVLTreeList) {
                    cout<<static_cast<char>(element->sumOfRoot%(90-65 + 1) + 65);
                }
                AVLTreeList.remove(element);
                //cout<< "sayisi" << AVLTreeList.size() << endl;
                element->stack->~Stack();
                element->~AVLTree();
                
                
            }
            if(element->stack->peek() < temp->stack->peek()){

                temp = element;
            }
        }
        if(flag) continue;
        temp->stack->pop();
        temp = AVLTreeList.front();
        
        //en büyüğü bulma
        for (const auto& element : AVLTreeList) {
            if(element->stack->isEmpty()){
                flag=true;
                system("cls");
                for (const auto& element : AVLTreeList) {
                    cout<<static_cast<char>(element->sumOfRoot%(90-65 + 1) + 65);
                }
                AVLTreeList.remove(element);
                //cout<< "sayisi" << AVLTreeList.size() << endl;
                element->stack->~Stack();
                element->~AVLTree();

            }    
            if(element->stack->peek() > temp->stack->peek()){
                temp = element;
            }
        }
        if(flag) continue;
        temp->stack->pop();
        temp = AVLTreeList.front();

                
            
            // yığını boşalan varsa silme işlemi ve ekrana harfleri yazdırma
        
        
    
    }
    cout<<"SON KARAKTER  : "<<static_cast<char>(AVLTreeList.front()->sumOfRoot%(90-65 + 1) + 65)<<endl;
    cout<<"SIRA NUMARASI : "<<AVLTreeList.front()->siraNo<<endl;


    return 0;
}
