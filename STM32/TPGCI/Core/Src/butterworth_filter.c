#include "butterworth_filter.h"

float applyLowPassFilter(float input, float* inputBuffer, float* outputBuffer) {
    // Shift previous inputs and outputs
    inputBuffer[2] = inputBuffer[1];
    inputBuffer[1] = inputBuffer[0];
    inputBuffer[0] = input;

    outputBuffer[2] = outputBuffer[1];
    outputBuffer[1] = outputBuffer[0];

    // Calculate the filtered output
    float output = B0 * inputBuffer[0] + B1 * inputBuffer[1] + B2 * inputBuffer[2]
                 - A1 * outputBuffer[1] - A2 * outputBuffer[2];

    outputBuffer[0] = output;  // Store current output for next iteration

    return output;
}
