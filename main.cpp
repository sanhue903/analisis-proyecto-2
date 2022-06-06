#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <chrono>
#include <ctime>
#include "primer_hash.h"

int main(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,PRIME - 1);
    
    std::vector<std::string> vec;
    std::set<std::string> st;
    std::ifstream file_in("genomas/100000-genomes.txt");
    if(!file_in) {}

    std::string s;
    while(std::getline(file_in, s)) st.insert(s);

    for(std::set<std::string>::iterator it = st.begin(); it != st.end(); it++)
    {
        vec.push_back(*it);
    }
    primer_hash * h = new primer_hash(distribution,generator,vec);
    h->buildTable();
    h->printTable();
    h->find("CGACGCCGGTTCATC");

    /*
    *   MEDICIONES DE TIEMPO:
    *
    *   Para probar con distintos numeros de kmers importar archivos de distintos tamanos,
    *   abajo se calcula un promedio de construir la tabla y buscar un elemento n veces con
    *   el tamano del archivo de kmers importado.
    */
    /*
    int n = 1000;
    double nano = 1000000000;//Variable usada para pasar a nanoSegundos
    double tiempoConstruir = 0, tiempoBuscar = 0;       
    clock_t start = std::clock();
    
    std::cout << " construir ; buscar " << std::endl;
    for(int i = 0; i < n; i++)
    {
        primer_hash * h = new primer_hash(distribution,generator,vec);
        h->buildTable();
        h->printTable();
    }
    tiempoConstruir = ((double)std::clock() - start)/CLOCKS_PER_SEC;

    start = clock();
    for(int i = 0; i < n; i++)
    {
        // search
    }
    tiempoBuscar = ((double)std::clock()-start)/CLOCKS_PER_SEC;

    std::cout << n << ";" << (tiempoConstruir/(double)n)*nano << ";" << (tiempoBuscar/(double)n)*nano << std::endl;
    */
    return 0;
}
