#include <iostream>
#include <fstream>
#include <vector>
#include "primer_hash.h"
#include "segundo_hash.h"

std::string loadText();

std::vector<std::string> makeKmers(std::string,int);

void test(std::vector<std::string> test);


int main(){
    srand(time(NULL));
    int S = 0;
    int k = 15;

    std::string genoma = loadText();
    std::vector<std::string> kmers = makeKmers(genoma,k);
    
    S = kmers.size();
    
    test(kmers);


    return 0;
}

std::string loadText(){
    std::string aux;
    std::string output;

    std::ifstream text;

    text.open("genomas/prueba1.txt",std::ios::in);

    if (text.is_open()){
        while (!text.eof()){
            getline(text,aux);
            output+= aux;
        }

        text.close();    
    }

    return output;
}

std::vector<std::string> makeKmers(std::string text,int k){
    std::vector<std::string> kmers;
    std::string aux = text.substr(0,k);

    int i = 0;

    while (aux.length() == k){
        kmers.push_back(aux);

        i++;
        aux = text.substr(i,k);
    }

    /*
    std::vector<std::string>::iterator it = kmers.begin();
    while(it != kmers.end()){
        std::cout<<*it<<std::endl;
        it++;
    }*/

    return kmers;
    }

void test(std::vector<std::string> test){
    std::vector<std::string>::iterator it = test.begin();
    std::vector<std::string>::iterator end = test.end();

    std::vector<long long> prueba;

    long long integer = 0;
    while(it != end){
        integer = func::stringToInteger(*it);
        prueba.push_back(integer);
        
        it++;
    }

    hashT2 tabla = hashT2(prueba);

    tabla.imprimir();


    /*
    std::vector<long long>::iterator testIt = prueba.begin();
    std::vector<long long>::iterator testEnd = prueba.end();

    while(testIt != testEnd){
        std::cout<<*testIt<<std::endl;
        testIt++;
    }*/
}