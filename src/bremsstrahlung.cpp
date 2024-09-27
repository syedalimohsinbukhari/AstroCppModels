//
// Created by syedalimohsinbukhari on 9/3/24.
//

#include "bremsstrahlung.hpp"

vd opticallyThinThermalBremsstrahlung(const vd & energy,
                                      double_t amplitude, double_t electronTemperature, double_t pivotEnergy) {
    vd output = allocateVector(energy);
    
    const double_t energyRatio = exp(pivotEnergy / electronTemperature);
    
    FOR_LOOP(energy, {
        output[i] = amplitude * exp(-energy[i] / electronTemperature) * energyRatio * pow(energy[i] / pivotEnergy, -1);
    })
    
    return output;
}
