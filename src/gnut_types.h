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
 * @file gnut_types.h
 * @brief This is a specifications file for types to be used with lib_gnut.
 *
 * The gnut_types.h file is a specifications file that defines the
 * necessary types to hanlde the complexities of being cross-platform
 * relative to differences in data types. It also provides general types
 * to be used with lib_gnut.
 */

#ifndef GNUT_TYPES_H
#define GNUT_TYPES_H

#include <sxs/sxs.h>

/**
 * An error code.
 *
 * The sxs_error_t is a type which represents an error code.
 */
typedef sxs_int32_t gnut_error_t;

#endif /* GNUT_TYPES_H */
