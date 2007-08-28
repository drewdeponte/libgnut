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
 * @file gnut_msgs.h
 * @brief This is a specifications file for lib_gnut API.
 *
 * The gnut_msgs.h file is a specifications file that declares the
 * functions and types which compose the general API for lib_gnut.
 */

#ifndef GNUT_MSGS_H
#define GNUT_MSGS_H

#include <sxs/sxs.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "gnut_export.h"
#include "gnut_types.h"
#include "gnut_error.h"

#include "gnut_ping_msg.h"
#include "gnut_pong_msg.h"

#define GNUT_MSG_ID_LEN 16 /**< Length of Message ID in bytes */
#define GNUT_INITIAL_TTL 0x07 /**< Initial TTL (time-to-live) */
#define GNUT_INITIAL_HOPS 0x00 /**< Initial HOPS */

/**
 * A Gnutella Message Header
 *
 * The gnut_msg_hdr_t is a type which represents a complete Gnutella
 * Message Header.
 */
typedef struct GNUT_EXPORT gnut_msg_hdr {
    unsigned char message_id[GNUT_MSG_ID_LEN];  /* Message ID */
    unsigned char type;                         /* Payload Type */
    unsigned char ttl;                          /* TTL (Time To Live) */
    unsigned char hops;                         /* Hops */
    sxs_uint32_t pl_len;                        /* Payload Length */
} gnut_msg_hdr_t;

/**
 * A Gnutella Message
 *
 * The gnut_msg_t is a type which represents a Gnutella Message.
 */
typedef struct GNUT_EXPORT gnut_msg {
    gnut_msg_hdr_t header;
    union gnut_msg_spec_payload {
        /* The following would be declared if empty structures were allowed
         * in Microsoft compilers.
        struct gnut_ping_payload ping;
         */
         
        struct gnut_pong_payload pong;
        /*
        struct gnut_query_payload query;
        struct gnut_query_hit_payload query_hit;
        struct gnut_bye_payload bye;
        */
    } payload;
} gnut_msg_t;

/**
 * Build a Gnutella Message ID
 *
 * The gnut_build_msg_id() function builds a randomly generated Message
 * ID and stores in the gnutella message header that 'p_header' points
 * to. The Message ID is 16 bytes consisting of bytes which are all
 * assigned random values, except for byte 8 which has a value of 0xff
 * and byte 15 which has a value of 0x00. Note: The bytes are number
 * 0-15.
 * @param p_header Pointer to message header to store Message ID in.
 * @return A value representing an error or success.
 * @retval GNUT_SUCCESS Successfully built message id.
 */
GNUT_EXPORT gnut_error_t gnut_build_msg_id(gnut_msg_hdr_t *p_header);

/**
 * Build a Gnutella Message Header
 *
 * The gnut_build_msg_hdr() function builds a Message Header given a
 * pointer to a header structure to store the produced header in as well
 * as a message type and payload length.
 * @param p_header Pointer to message header to fill in.
 * @param type Payload type, one of the following values (0x00 = Ping,
 * 0x01 = Pong, 0x02 = Bye, 0x40 = Push, 0x80 = Query, 0x81 = Query
 * Hit).
 * @param pl_len The length of the payload in bytes.
 * @return A value representing an error or success.
 * @retval GNUT_SUCCESS Successfully built message header.
 * @retval GNUT_EBUILD_MSG_ID Error, failed to build message id.
 */
GNUT_EXPORT gnut_error_t gnut_build_msg_hdr(gnut_msg_hdr_t *p_header,
    unsigned char type, sxs_uint32_t pl_len);

/**
 * Build a Gnutella Message Header given a Message ID
 *
 * The gnut_build_msg_hder_given_msg_id() function builds a Message Header
 * given a pointer to a header structure to store the produced header in as
 * well as a Message ID, type, and payload length.
 * @param p_header Pointer to message header to fill in.
 * @param message_id Pointer to unsigned char array containing Message ID.
 * @param type Payload type, one of the following values (0x00 = Ping,
 * 0x01 = Pong, 0x02 = Bye, 0x04 = Push, 0x80 = Query, 0x81 = Query Hit).
 * @param pl_len The length of the payload in bytes.
 * @return A value representing an error or success.
 * @retval GNUT_SUCCESS Successfully built message header.
 */
GNUT_EXPORT gnut_error_t gnut_build_msg_hdr_given_msg_id(
    gnut_msg_hdr_t *p_header, const unsigned char *message_id,
    unsigned char type, sxs_uint32_t pl_len);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GNUT_MSGS_H */
