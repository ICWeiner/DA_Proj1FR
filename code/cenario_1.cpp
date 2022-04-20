//
// Created by Diogo Almeida on 03/04/2022.
//

#include <iostream>
#include "cenario_1.h"


cenario_1::cenario_1() {
    estafetas = reader.readEstafetas();
    encomendas = reader.readEncomendas();
    cenario_1::sort();
}

bool cenario_1::pesoEncomendas(const encomenda& lhs, const encomenda& rhs){
    if(lhs.peso == rhs.peso){
        return lhs.vol >= rhs.vol;
    }
    return lhs.peso > rhs.peso;
}

bool cenario_1::pesoEstafetas(const estafeta& lhs, const estafeta& rhs){
    if(lhs.pesoMax == rhs.pesoMax){
        return lhs.volMax >= rhs.volMax;
    }
    return lhs.pesoMax > rhs.pesoMax;
}

void cenario_1::sort(){
    std::sort(encomendas.begin(),encomendas.end(), pesoEncomendas);
    std::sort(estafetas.begin(),estafetas.end(), pesoEstafetas);
}

int cenario_1::place(){
    int n_estafetas = 0;
    int n_encomendas = 0;
    for(auto itr = estafetas.begin(); itr != estafetas.end() ;itr++) {
        //std::cout << encomendas.end()->peso << '\n';
        int peso = itr->pesoMax;
        int vol = itr->volMax;
        int counter = 0;
        //std::cout << encomendas.size() << '\n';
        while (peso - encomendas.begin()->peso >= 0 && vol - encomendas.begin()->vol >= 0 && !encomendas.empty()){
            counter++;
            peso -= encomendas.begin()->peso;
            vol -= encomendas.begin()->vol;
            encomendas.erase(encomendas.begin());
            n_encomendas++;
        }
        while (peso - encomendas.end()->peso >= 0 && vol - encomendas.end()->vol >= 0  && !encomendas.empty()) {
            counter++;
            peso -= encomendas.end()->peso;
            vol -= encomendas.end()->vol;
            encomendas.pop_back();
            n_encomendas++;
        }
        n_estafetas++;
        /*std::cout << "estafeta n " << n_estafetas << " has this many packages " << counter << "\n";
        std::cout << "leftover weight:" <<  peso  << " leftover vol:" <<    vol  << "\n" ;
        std::cout << "heaviest thing weight:"<< encomendas.begin()->peso  <<  " heaviest thing vol:" << encomendas.begin()->vol
        << "\n" << "lightest thing weight:" << encomendas.end()->peso << " lightest thing vol:" << encomendas.end()->vol << "\n" ;*/

        if(encomendas.empty()){
            std::cout << "\nCenario 1: Otimizacao do número de estafetas\n" ;
            std::cout << "Numero de estafetas utilizados:" << n_estafetas << "\n";
            std::cout << "Numero de encomendas enviado: " << n_encomendas << " Numero de encomendas descartadas:" << encomendas.size()  << "\n";
            return n_estafetas;
        }
    }
    std::cout << "\nCenario 1: Otimizacao do número de estafetas\n" ;
    std::cout << "Numero de estafetas utilizados:" << n_estafetas << "\n";
    std::cout << "Numero de encomendas enviado: " << n_encomendas << " Numero de encomendas descartadas:" << encomendas.size()  << "\n";
    return n_estafetas;
}