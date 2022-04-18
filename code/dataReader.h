//
// Created by Diogo Nunes on 3/4/22.
//

#ifndef DA_PROJ1_DATAREADER_H
#define DA_PROJ1_DATAREADER_H

#include "data.h"
#include <fstream>
#include <vector>

/** @brief Class used for file reading purposes <br>
 * Can read files provided for this project with data for "estafeta"
 * and "encomenda" if they follow  the correct format.<br>
 * Files should be placed in a folder named "input"
 * on the same folder the project is run on.<br>
 * Files with "estafeta" data should be named "carrinhas.txt"
 * and should follow the following format: volMax pesoMax custo.<br>
 * Files with "encomenda" data should be named "encomendas.txt"
 * and should follow the following format: volume peso recompensa duração.<br>
 * @author Diogo Nunes
 * @date April 2022
 */
class dataReader{
protected:
    std::fstream file;
public:
    /** Default constructor. Does nothing
     */
    dataReader();
    /** Reads "estafeta" data
     * @return vector with all "estafeta" data
     */
    std::vector<estafeta> readEstafetas();
    /** Reads "encomenda" data
     * @return vector with all "encomenda" data
     */
    std::vector<encomenda>  readEncomendas();
};

#endif //DA_PROJ1_DATAREADER_H
