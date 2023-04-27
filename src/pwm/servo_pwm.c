#include "pwm.h"

uint32_t angle_to_duty_v1(
                int16_t angle, 
                int16_t min_angle, 
                int16_t max_angle, 
                uint32_t min_duty, 
                uint32_t max_duty) 
{
        int16_t old_range = (max_angle - min_angle);    /* calculate angle range */
        uint32_t new_range = (max_duty - min_duty);             /* calculate duty range*/

        /**
         * scale angle by subtracting from min_angle and multiplying the result
         * by the ratio of the new_range to old_range, then adding the min
         * duty
         */
        uint32_t duty = (((angle - min_angle) * new_range) / old_range) + min_duty;     

        return duty;
}


