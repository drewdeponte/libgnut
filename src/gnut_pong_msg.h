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
 * @file gnut_pong_msgs.h
 * @brief This is a specifications file for gnut_pong_msg_t type.
 *
 * The gnut_pong_msg.h file is a specifications file that declares the
 * gnut_pong_msg_t type and it's associated support functions.
 */

#ifndef GNUT_PONG_MSG_H
#define GNUT_PONG_MSG_H

typedef struct gnut_pong_payload {
    sxs_uint16_t port_num;
    struct in_addr ip_addr;
    sxs_uint32_t num_shared_files;
    sxs_uint32_t kb_shared;
} gnut_pong_payload_t;

int _gnut_parse_pong_msg_payload(gnut_pong_payload_t *pl,
    unsigned char *raw_pl, sxs_uint32_t raw_pl_len);
    
int _gnut_build_pong_msg_payload(gnut_pong_payload_t *pl,
    unsigned char *raw_pl);
    
int _gnut_calc_pong_msg_payload_len(gnut_pong_payload_t *pl);

void _gnut_free_pong_msg_payload(gnut_pong_payload_t *pl);

#endif /* GNUT_PONG_MSG_H */