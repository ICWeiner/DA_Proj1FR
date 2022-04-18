//
// Created by Diogo Nunes on 3/4/22.
//

#ifndef DA_PROJ1_DATA_H
#define DA_PROJ1_DATA_H

/** @brief Represents a "estafeta". Stores the associated values
 * @author Diogo Nunes
 * @date April 2022
 */
struct estafeta{
    int volMax;
    int pesoMax;
    int custo;
    float custoKG;
    float custoVol;
};

/** @brief Represents a "encomenda". Stores the associated values
 * @author Diogo Nunes
 * @date April 2022
 */
struct encomenda{
    int vol;
    int peso;
    int recompensa;
    int duracao;
    float recompensaKG;
    float recompensaVol;
};

#endif //DA_PROJ1_DATA_H
