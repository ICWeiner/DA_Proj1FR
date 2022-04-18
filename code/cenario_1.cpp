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
    for(auto itr = estafetas.begin(); itr != estafetas.end() ;itr++) {
        int peso = itr->pesoMax;
        int vol = itr->volMax;
        //std::cout << encomendas.size() << '\n';
        while (peso >= 0 && vol >= 0 && !encomendas.empty()) {
            //std::cout << encomendas.end()->peso << '\n';
            if(peso - encomendas.end()->peso > 0 && vol - encomendas.end()->vol > 0) {
                peso -= encomendas.end()->peso;
                vol -= encomendas.end()->vol;
                encomendas.pop_back();
            }
            else break;
        }
        n_estafetas++;
        if(encomendas.empty()) return n_estafetas;
    }
    return n_estafetas;
}