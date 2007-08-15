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
 * @file gnut_msgs.c
 * @brief This is an implementation file for lib_gnut API.
 *
 * The gnut_msgs.c file is an implementation file that defines the
 * functions and types which compose the general API for lib_gnut.
 */

#include <stdlib.h> /* NULL, srand(), rand() */
#include <time.h> /* time() */

#include "gnut_msgs.h"

gnut_error_t gnut_build_msg_id(gnut_msg_hdr_t *p_header) {
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < GNUT_MSG_ID_LEN; i++) {
        p_header->message_id[i] = (char)(rand() % 255);
    }
    p_header->message_id[8] = 0xff;
    p_header->message_id[15] = 0x00;
    
    return GNUT_SUCCESS;
}

gnut_error_t gnut_build_msg_hdr(gnut_msg_hdr_t *p_header, unsigned char type,
    sxs_uint32_t pl_len) {

    gnut_error_t reterr;

    reterr = gnut_build_msg_id(p_header);
    if (reterr != GNUT_SUCCESS) {
        return GNUT_EBUILD_MSG_ID;
    }

    p_header->type = type;
    p_header->ttl = GNUT_INITIAL_TTL;
    p_header->hops = GNUT_INITIAL_HOPS;
    p_header->pl_len = pl_len;

    return GNUT_SUCCESS;
}

gnut_error_t gnut_build_msg_hdr_given_msg_id(gnut_msg_hdr_t *p_header,
    const unsigned char *message_id, unsigned char type,
    sxs_uint32_t pl_len) {

    memcpy((void *)p_header->message_id, (const void *)message_id,
        GNUT_MSG_ID_LEN);

    p_header->type = type;
    p_header->ttl = GNUT_INITIAL_TTL;
    p_header->hops = GNUT_INITIAL_HOPS;
    p_header->pl_len = pl_len;

    return GNUT_SUCCESS;
}
