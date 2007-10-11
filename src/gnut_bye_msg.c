/*
 * Copyright 2006-2007 Andrew De Ponte
 *
 * This file is part of lib_gnut.
 *
 * lib_gnut is the intellectual property of Andrew De Ponte; any
 * distribution and/or modification and/or reproductions of any portion
 * of lib_gnut MUST be approved by Andrew De Ponte.
 *
 * lib_gnut is distributed WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 */

/**
 * @file gnut_bye_msg.c
 * @brief This is an implementation file for gnut_bye_msg_t type.
 *
 * The gnut_bye_msg.c file is an implementation file that defines
 * the gnut_bye_msg_t type's associated support functions.
 */
 
int _gnut_parse_by_msg_payload(gnut_bye_payload_t *pl,
    unsigned char *raw_pl, sxs_uint32_t raw_pl_len) {
    
    unsigned char *tmp_p;
    int desc_string_len;
    
    tmp_p = raw_pl;
    
    pl->code = *((sxs_uint16_t *)tmp_p);
    tmp_p = tmp_p + sizeof(sxs_uint16_t);
    
    desc_string_len = strlen((const char *)tmp_p);
    
    if (desc_string_len == (raw_pl_len - sizeof(sxs_uint16_t) - 1)) {
        pl->desc_string = malloc(desc_string_len + 1);
        if (pl->desc_string = NULL) {
            return -1;
        }
    } else if (desc_string_len > (raw_pl_len - sizeof(sxs_uint16_t))) {
        /* missing a null character terminating the description string */
        return -2;
    } else {
        pl->desc_string = malloc(desc_string_len + 1);
        if (pl->desc_string == NULL) {
            return -3;
        }
    }
    
    memcpy((void *)pl->desc_string, (const void *)tmp_p, desc_string_len);
    pl->desc_string[desc_string_len] = '\0';
    
    pl->desc_string_len = desc_string_len + 1;
    
    return 0;
}

void _gnut_free_bye_msg_payload(gnut_bye_payload_t *pl) {
    if (pl->desc_string != NULL) {
        free(pl->desc_string);
    }
}