//
// Created by rafael morgado on 10/04/2022.
//

#ifndef DA_PROJ1_CENARIO_2_H
#define DA_PROJ1_CENARIO_2_H

#include "data.h"
#include "dataReader.h"
#include <vector>
#include <algorithm>
#include <iostream>

/** @brief Class used for scenery nº2 <br>
 * In this scenario we are maximizing the profit of the company and ignoring packages that arent considered profitable. <br>
 * To achieve this we used a greedy algorithms based on the 0 1 knapsack problem <br>
 * @author Diogo Nunes
 * @date April 2022
 */

class cenario_2 {
private:
    /** Vector containing all "estafetas" read from dataReader
    */
    std::vector<estafeta> estafetas;
    /** Vector containing all "encomendas" read from dataReader
    */
    std::vector<encomenda> encomendas;
    /** dataReader object to read data from txt files
    */
    dataReader reader;
public:
    /** Contains: <br>
     *  A constructor from dataReader.h and two vectors. <br>
     *  One vector contains all instances of "encomendas" and the other one all instances of "estafetas". <br>
    */
    cenario_2();
    /**
     * Boolean member used to compare 2 floating point numbers, in double format
     * @param a a floating point number
     * @param b another floating point number
     * @return
     */
    static bool compareFloatNum(double a, double b);
    /**
     * Boolean to determine if "encomenda" lhs's "RecompensaKG" is bigger than  rhs's. <br>
     * If both objects contain similar "RecompensaKG" then we compare them by their "RecompensaVol" . <br>
     * @param lhs left side value
     * @param rhs right side value
     * @return true if lhs is bigger than rhs or false if its smaller
     */
    static bool recompensaEncomendas(const encomenda &lhs, const encomenda &rhs);
    /**
     * Boolean to determine if "estafeta" lhs's "CustoKG" is smaller than rhs's. <br>
     * If both objects contain similar "CustoKG" then we compare them by their "CustoVol" . <br>
     * @param lhs left side value
     * @param rhs right side value
     * @return true if lhs is smaller than rhs or false if its smaller
     */
    static bool custoEstafetas(const estafeta &lhs, const estafeta &rhs);
    /**
     * Member functin to sort each vector according to the previously defined boolean functions given.
     */
    void sort();
    /**
     * Member function to return the number of "estafetas" that will take all the "encomendas" to take from the company to deliver.
     */
    int place();
};


#endif //DA_PROJ1_CENARIO_2_H
