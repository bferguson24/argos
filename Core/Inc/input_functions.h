#include <stdint.h>


void analogClipSet(uint16_t *raw_adc_array, float *clipped_adc_array, uint16_t deadzone, int array_size, float gain);


