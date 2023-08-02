#include "main.h"

/**
 * init_params - reset buf and clears struct
 * @params: parameters struct
 * @params: parameters struct
 *
 * Return: void
 */
void init_params(params_t *params, va_list ap)
{
        params->unsign = 0;

        params->plus_flag = 0;
        params->space_flag = 0;
        params->hastag_flag = 0;
        params->zero_flag = 0;
        params->minus_flag = 0;

        params->width = 0;
        params->precision = UINT_MAX;

        params->h_modifier = 0;
        params->1_modifier = 0;
        (void)ap;
}
