#include "input_functions.h"
#include <stdint.h>



void analogClipSet(uint16_t *raw_adc_array, float *clipped_adc_array, uint16_t deadzone, int array_size, float gain){

//Clipping Parameters

uint16_t maxAnalog = 4095;
uint16_t minAnalog = 0;
uint16_t meanAnalog = (maxAnalog + minAnalog)/2;

uint16_t upper_lim = meanAnalog + deadzone/2;
uint16_t lower_lim = meanAnalog - (deadzone/2);

for (int i = 0; i< array_size ; i++){
    //Delta = 0; 
        if (((raw_adc_array[i]) <= upper_lim) && (raw_adc_array[i] >= lower_lim)){
            clipped_adc_array[i] = 0;

        //Delta Positive    
        } else if(raw_adc_array[i] > upper_lim){
            clipped_adc_array[i] = gain * (raw_adc_array[i] - meanAnalog) / (maxAnalog - meanAnalog);

        //Delta Negative
        } else if(raw_adc_array[i] < lower_lim){
            clipped_adc_array[i] = - gain * (raw_adc_array[i] - meanAnalog) / (minAnalog - meanAnalog);
        }
    }
}   

