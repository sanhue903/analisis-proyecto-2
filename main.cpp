#include <iostream>
#include <fstream>
#include <vector>

std::string loadText();

std::vector<std::string> makeKmers(std::string,int);

int main(){
    int S = 0;
    int k = 15;

    std::string genoma = loadText();
    std::vector<std::string> kmers = makeKmers(genoma,k);
    
 
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