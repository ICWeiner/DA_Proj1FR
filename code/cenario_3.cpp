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
/*
    //encomendas.pop_back();
    //std::cout << encomendas.size() << '\n';

    int count = 0,steps = 0;
    for (auto itr= encomendas.end(); itr != encomendas.begin(); itr--){
        count+= itr->duracao;
        steps++;
        if (steps== 125) break;
    }

    std::cout << count << '\n';*/

    int duracaoMax = 28800;
    int n_Encomendas = 0;
    for(auto itr = encomendas.end(); itr != encomendas.begin(); --itr){
        int duracao = itr->duracao;
        //std::cout << duracao << '\n';
        if(duracaoMax-duracao>=0){
            duracaoMax-=duracao;
            n_Encomendas++;
            encomendas.pop_back();
        }
        if(encomendas.empty()) break;
    }
    return n_Encomendas;
}