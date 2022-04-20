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
    //see if two floats are extremely similar
    if (abs(a - b) < 1e-9) {
        return true;
    }
    return false;
}

bool cenario_2::recompensaEncomendas(const encomenda& lhs, const encomenda& rhs){
    if(compareFloatNum(lhs.recompensaKG,rhs.recompensaKG)){
        return lhs.recompensaVol > rhs.recompensaVol;
    }
    return lhs.recompensaKG > rhs.recompensaKG;
}

bool cenario_2::custoEstafetas(const estafeta& lhs, const estafeta& rhs){
    if(compareFloatNum(lhs.custoKG,rhs.custoKG) ){
        return lhs.custoVol < rhs.custoVol;
    }

    return lhs.custoKG < rhs.custoKG;
}

void cenario_2::sort(){
    std::sort(encomendas.begin(),encomendas.end(), recompensaEncomendas);
    std::sort(estafetas.begin(),estafetas.end(), custoEstafetas);
}

int cenario_2::place(){
    int n_estafetas = 0;
    int n_encomendas = 0;
    int lucro = 0;

    for(auto itr = estafetas.begin(); itr != estafetas.end() ;itr++){
        int peso = itr->pesoMax;
        int vol = itr->volMax;
        int lucroCurr = -itr->custo;
        int n_encomendasCurr = 0;
        for(auto itrEnc = encomendas.begin(); itrEnc != encomendas.end() ;itrEnc++){
            if(peso - itrEnc->peso >= 0 && vol - itrEnc->vol >= 0){
                n_encomendasCurr++;
                peso -= itrEnc->peso;
                vol -= itrEnc->vol;
                lucroCurr+= itrEnc->recompensa;
                encomendas.erase(itrEnc);
                itrEnc--;
            }else if(peso==0 || vol==0) break;
        }
        if (lucroCurr < 0){
            std::cout << "\nCenario 2: Otimizacao do lucro\n" ;
            std::cout << "Lucro total obtido:" << lucro << " Numero de estafetas utilizados:" << n_estafetas << "\n";
            std::cout << "Numero de encomendas enviado: " << n_encomendas << " Numero de encomendas descartadas:" << encomendas.size() + n_encomendasCurr << "\n";
            return lucro;
        }
        lucro+=lucroCurr;
        n_encomendas += n_encomendasCurr;
        n_estafetas++;
    }

    std::cout << "\nCenario 2: Otimizacao do lucro\n" ;
    std::cout << "Lucro total obtido:" << lucro << " Numero de estafetas utilizados:" << n_estafetas << "\n";
    std::cout << "Numero de encomendas enviado: " << n_encomendas << " Numero de encomendas descartadas:" << encomendas.size()  << "\n";
    //std::cout << n_estafetas << '\n';
    return lucro;
}
