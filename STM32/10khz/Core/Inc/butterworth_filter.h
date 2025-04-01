#ifndef BUTTERWORTH_FILTER_H
#define BUTTERWORTH_FILTER_H

#include <stdint.h>

// Butterworth filter coefficients
#define B0 0.00094469f
#define B1 0.00188938f
#define B2 0.00094469f
#define A1 -1.9112f
#define A2 0.91498f

/**
 * @brief Applies a second-order Butterworth low-pass filter to the given input.
 *
 * @param input         The current input sample.
 * @param inputBuffer   Pointer to the input buffer (size 3).
 * @param outputBuffer  Pointer to the output buffer (size 3).
 * @return              The filtered output sample.
 */
float applyLowPassFilter(float input, float* inputBuffer, float* outputBuffer);

#endif // BUTTERWORTH_FILTER_H
