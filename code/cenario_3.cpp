//
// Created by rafael morgado on 14/04/2022.
//

#include <algorithm>
#include <iostream>
#include "cenario_3.h"
#include "data.h"

cenario_3::cenario_3() {
    encomendas = reader.readEncomendas();
    sort();
}

bool cenario_3::pesoEncomendas(const encomenda& lhs, const encomenda& rhs){
    if(lhs.duracao == rhs.duracao){
        return lhs.vol >= rhs.vol;
    }
    return lhs.duracao > rhs.duracao;
}

void cenario_3::sort(){
    std::sort(encomendas.begin(),encomendas.end(), pesoEncomendas);
}

int cenario_3::place(){
    int duracaoMax = 28800;
    int n_encomendas = 0;
    for(auto itr = encomendas.end(); itr != encomendas.begin(); --itr){
        int duracao = itr->duracao;
        //std::cout << duracao << '\n';
        if(duracaoMax-duracao>=0){
            duracaoMax-=duracao;
            n_encomendas++;
            encomendas.pop_back();
        }
        if(encomendas.empty()) break;
    }
    std::cout << "\nCenario 3: Otimizacao das entregas expresso\n" ;
    std::cout << "Numero de encomendas enviado: " << n_encomendas << " Numero de encomendas descartadas:" << encomendas.size() << "\n";
    std::cout << "Tempo de sobra: " << duracaoMax;
    return n_encomendas;
}