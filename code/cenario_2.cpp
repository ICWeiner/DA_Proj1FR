//
// Created by rafael morgado on 10/04/2022.
//

#include "cenario_2.h"


cenario_2::cenario_2(){
    estafetas = reader.readEstafetas();
    encomendas = reader.readEncomendas();
    cenario_2::sort();
}

bool cenario_2::compareFloatNum(double a, double b) {
    // Correct method to compare
    // floating-point numbers
    if (abs(a - b) < 1e-9) {
        return true;
    }
    return false;
}

bool cenario_2::recompensaEncomendas(const encomenda& lhs, const encomenda& rhs){
    if(compareFloatNum(lhs.recompensaKG,rhs.recompensaKG)){
        return lhs.recompensaVol > rhs.recompensaVol;
    }
    return lhs.recompensaVol < rhs.recompensaVol;
}

bool cenario_2::custoEstafetas(const estafeta& lhs, const estafeta& rhs){
    if(compareFloatNum(lhs.custoKG,rhs.custoKG) ){
        return lhs.custoVol > rhs.custoVol;
    }

    return lhs.custoVol < rhs.custoVol;
}

void cenario_2::sort(){
    std::sort(encomendas.begin(),encomendas.end(), recompensaEncomendas);
    std::sort(estafetas.begin(),estafetas.end(), custoEstafetas);
}

int cenario_2::place(){
    int n_estafetas = 0;
    int lucro = 0;

    for(auto itr = estafetas.begin(); itr != estafetas.end() ;itr++){
        int peso = itr->pesoMax;
        int vol = itr->volMax;
        //int lucroCurr = lucro;
        //lucroCurr-= itr->custo;
        while (peso >= 0 && vol >= 0) {
            if(encomendas.empty()) return lucro;
            if(peso - encomendas.end()->peso > 0 && vol - encomendas.end()->vol > 0) {
                peso -= encomendas.end()->peso;
                vol -= encomendas.end()->vol;
                //lucroCurr += encomendas.end()->recompensa;
                lucro += encomendas.end()->recompensa;
                encomendas.pop_back();
            }
            else break;
        }
        lucro -= itr->custo;
        n_estafetas++;
    }
    //std::cout << n_estafetas << '\n';
    return lucro;
}
