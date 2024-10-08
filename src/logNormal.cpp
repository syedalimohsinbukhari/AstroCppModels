//
// Created by syedalimohsinbukhari on 9/2/24.
//

#include "logNormal.hpp"

vd logNormalEnergy(const vd &energy,
                   const double_t amplitude, const double_t mean, const double_t sigma) {
    vd output = allocateVector(energy);

    const double_t normalization = amplitude / (sqrt(2 * M_PI) * sigma);

    FOR_LOOP(energy, {
        output[i] = (normalization / energy[i]) * exp(-0.5 * pow((log(energy[i]) - mean) / sigma, 2));
    })

    return output;
}
