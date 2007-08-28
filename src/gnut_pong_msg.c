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
 * @file gnut_pong_msg.c
 * @brief This is an implementation file for gnut_pong_msg_t type.
 *
 * The gnut_pong_msg.c file is an implementation file that defines
 * the gnut_pong_msg_t type's associated support functions.
 */

#include "gnut_pong_msg.h"

int _gnut_parse_pong_msg_payload(gnut_pong_payload_t *pl, unsigned char *raw_pl, sxs_uint32_t raw_pl_len) {

    unsigned char *tmp_p;
    
    tmp_p = raw_pl;
    pl->port_num = sxs_ntohs(*((sxs_uint16_t *)tmp_p));
    tmp_p += sizeof(sxs_uint16_t);
    
    pl->ip_addr.s_addr = sxs_ntohs(*((sxs_uint32_t *)tmp_p));
    tmp_p += sizeof(sxs_uint32_t);
    
    pl->num_shared_files = sxs_ntohs(*((sxs_uint32_t *)tmp_p));
    tmp_p += sizeof(sxs_uint32_t);
    
    pl->kb_shared = sxs_ntohs(*((sxs_uint32_t *)tmp_p));
    tmp_ += sizeof(sxs_uint32_t);
    
    return 0;
}

int _gnut_build_pong_msg_payload(gnut_pong_payload_t *pl, unsigned char *raw_pl) {
   
    unsigned char *tmp_p;
    
    tmp_p = raw_pl;
    
    *((sxs_uint16_t)tmp_p) = sxs_htons(pl->port_num);
    tmp_p = tmp_p + sizeof(sxs_uint16_t);
    
    *((sxs_uint32_t)tmp_p) = sxs_htonl(pl->ip_addr.s_addr);
    tmp_p = tmp_p + sizeof(sxs_uint32_t);
    
    *((sxs_uint32_t)tmp_p) = sxs_htonl(pl->num_shared_files);
    tmp_p = tmp_p + sizeof(sxs_uint32_t);
    
    *((sxs_uint32_t)tmp_p) = sxs_htonl(pl->kb_shared);
    tmp_p = tmp_p + sizeof(sxs_uint32_t);
    
    return 0;
}

int _gnut_calc_pong_msg_payload_len(gnut_pong_payload_t *pl) {
    return (sizeof(sxs_uint16_t) + sizeof(sxs_uint32_t) + sizeof(sxs_uint32_t) + sizeof(sxs_uint32_t));
}

void _gnut_free_pong_msg_payload(gnut_pong_payload_t *pl) {
    return;
}