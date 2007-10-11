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
 * @file gnut_bye_msg.h
 * @brief This is a specifications file for gnut_bye_msg_t type.
 *
 * The gnut_bye_msg.h file is a specifications file that declares the
 * gnut_bye_msg_t type and it's associated support functions.
 */

#ifndef GNUT_BYE_MSG_H
#define GNUT_BYE_MSG_H

typedef struct gnut_bye_payload {
    sxs_uint16_t code;
    char *desc_string;
    sxs_uint16_t desc_string_len;
} gnut_bye_payload_t;

int _gnut_parse_bye_msg_payload(gnut_bye_payload_t *pl,
    unsigned char *raw_pl, sxs_uint32_t raw_pl_len);

void _gnut_free_bye_msg_payload(gnut_bye_payload_t *pl);

#endif /* GNUT_BYE_MSG_H */