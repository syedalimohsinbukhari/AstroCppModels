//
// Created by syedalimohsinbukhari on 9/11/24.
//

#include "planckLaw.hpp"
#include "constants.hpp"

vd planckLawWavelength(const vd & wavelength, double_t temperature) {
    vd output = allocateVector(wavelength);
    
    const double_t amplitudeFactor = (2 * PLANCK_CONSTANT * int_pow(SPEED_OF_LIGHT_IN_VACUUM, 2));
    const double_t exponentFactor = (PLANCK_CONSTANT * SPEED_OF_LIGHT_IN_VACUUM) / (BOLTZMANN_CONSTANT * temperature);
    
    FOR_LOOP(wavelength, {
        double_t amplitude = amplitudeFactor / int_pow(wavelength[i], 5);
        double_t exponential = exp(exponentFactor / wavelength[i]) - 1;
        output[i] = amplitude / exponential;
    })
    
    return output;
}

vd planckLawFrequency(const vd & frequency, double_t temperature) {
    vd output = allocateVector(frequency);
    
    const double_t amplitudeFactor = (2 * PLANCK_CONSTANT) / int_pow(SPEED_OF_LIGHT_IN_VACUUM, 2);
    const double_t exponentFactor = PLANCK_CONSTANT / (BOLTZMANN_CONSTANT * temperature);
    
    FOR_LOOP(frequency, {
        double_t amplitude = amplitudeFactor * int_pow(frequency[i], 3);
        double_t exponential = exp(exponentFactor * frequency[i]) - 1;
        output[i] = amplitude / exponential;
    })
    
    return output;
}

vd planckLawAngularFrequency(const vd & angular_frequency, double_t temperature) {
    vd output = allocateVector(angular_frequency);
    
    const double_t amplitudeFactor = REDUCED_PLANCK_CONSTANT / (4 * int_pow(PI, 3) * int_pow(SPEED_OF_LIGHT_IN_VACUUM, 2));
    const double_t exponentFactor = REDUCED_PLANCK_CONSTANT / (BOLTZMANN_CONSTANT * temperature);
    
    FOR_LOOP(angular_frequency, {
        double_t amplitude = amplitudeFactor * int_pow(angular_frequency[i], 3);
        double_t exponential = exp(exponentFactor * angular_frequency[i]) - 1;
        output[i] = amplitude / exponential;
    })
    
    return output;
}

vd planckLawAngularWavelength(const vd & angular_wavelength, double_t temperature) {
    vd output = allocateVector(angular_wavelength);
    
    const double_t amplitudeFactor = (REDUCED_PLANCK_CONSTANT * int_pow(SPEED_OF_LIGHT_IN_VACUUM, 2)) / (4 * int_pow(PI, 3));
    const double_t exponentFactor = (REDUCED_PLANCK_CONSTANT * SPEED_OF_LIGHT_IN_VACUUM) / (BOLTZMANN_CONSTANT * temperature);
    
    FOR_LOOP(angular_wavelength, {
        double_t amplitude = amplitudeFactor / int_pow(angular_wavelength[i], 5);
        double_t exponential = exp(exponentFactor / angular_wavelength[i]) - 1;
        output[i] = amplitude / exponential;
    })
    
    return output;
}

vd intensityOfLight(const vd & frequency, double_t temperature) {
    vd output = allocateVector(frequency);
    
    const double_t amplitudeFactor = (2 * PLANCK_CONSTANT) / int_pow(SPEED_OF_LIGHT_IN_VACUUM, 2);
    const double_t exponentFactor = PLANCK_CONSTANT / (BOLTZMANN_CONSTANT * temperature);
    
    FOR_LOOP(frequency, {
        double_t amplitude = amplitudeFactor * int_pow(frequency[i], 3);
        double_t exponential = exp(exponentFactor * frequency[i]) - 1;
        output[i] = amplitude / exponential;
    })
    
    return output;
}
