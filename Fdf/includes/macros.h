/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:13:05 by kytan             #+#    #+#             */
/*   Updated: 2024/06/16 20:13:05 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** @def W_WIDTH
 *  @brief This macro defines the width of the window display
 */
#define W_WIDTH 1800

/** @def W_HEIGHT
 *  @brief This macro defines the height of the window display
 */
#define W_HEIGHT 1000

/** @def HEX_BASE
 *  @brief This macro defines an uppercase hexadecimal base
 */
#define HEX_BASE "0123456789ABCDEF"

/** @def TRANS
 *  @brief This macro defines the size of a single translation adjustment.
 */
#define TRANS 1.5

/** @def ROT
 *  @brief This macro defines the size of a single rotation adjustment.
 */
#define ROT 0.01

/** @def ZOOM
 *  @brief This macro defines the scale factor for a single zoom adjustment.
 */
#define ZOOM 0.1

/** @def FF
 *  @brief This macro defines the flattening factor for a single altitude
 *  adjustments.
 */
#define FF  0.01

/** @def SF
 *  @brief This macro defines the scaling factor for the z-coordinate in
 *  3D transformations.
 */
#define SF  10

/** @def ESC_KEY
 *  @brief This macro represents the ESCAPE key for this OS
 */
#define ESC_KEY 65307

/** @def ESC_KEY
 *  @brief This macro represents the 'W' key for this OS
 */
#define W_KEY  119

/** @def ESC_KEY
 *  @brief This macro represents the 'A' key for this OS
 */
#define A_KEY  97

/** @def ESC_KEY
 *  @brief This macro represents the 'S' key for this OS
 */
#define S_KEY  115

/** @def D_KEY
 *  @brief This macro represents the 'D' key for this OS
 */
#define D_KEY  100

/** @def R_KEY
 *  @brief This macro represents the 'R' key for this OS
 */
#define R_KEY  114

/** @def TAB_KEY
 *  @brief This macro represents the TAB key for this OS
 */
#define TAB_KEY 65289

/** @def PS_KEY
 *  @brief This macro represents the '+' key for this OS
 */
#define PS_KEY  61

/** @def MS_KEY
 *  @brief This macro represents the '-' key for this OS
 */
#define MS_KEY  45

/** @def UP_KEY
 *  @brief This macro represents the UP ARROW key for this OS
 */
#define UP_KEY  65362

/** @def DW_KEY
 *  @brief This macro represents the DOWN ARROW key for this OS
 */
#define DW_KEY  65364

/** @def KEY_1
 *  @brief This macro represents the '1' key for this OS
 */
#define KEY_1  49

/** @def KEY_2
 *  @brief This macro represents the '2' key for this OS
 */
#define KEY_2  50

/** @def KEY_3
 *  @brief This macro represents the '3' key for this OS
 */
#define KEY_3  51

/** @def KEY_4
 *  @brief This macro represents the '4' key for this OS
 */
#define KEY_4  52

/** @def KEY_5
 *  @brief This macro represents the '5' key for this OS
 */
#define KEY_5  53

/** @def KEY_6
 *  @brief This macro represents the '6' key for this OS
 */
#define KEY_6  54

/**
 * @brief The number of bits to shift to the right to isolate the red
 * component of a color.
 */
#define RS 16

/**
 * @brief The number of bits to shift to the right to isolate the green
 * component of a color.
 */
#define GS 8

/**
 * @brief The bitmask to apply to isolate the blue component of a color.
 */
#define BM 0xFF

/**
 * @brief The number of bits to shift to isolate the alpha component
 * in a 32-bit color value.
 *
 * This macro represents the number of bits to shift a 32-bit color
 * value to the right to isolate the alpha component.
 * The color value is assumed to be in the format 0xRRGGBBAA, where RR
 * represents the red component, GG the green component,
 * BB the blue component, and AA the alpha component.
 */
#define AS 24

/**
 *  @brief This macro represents the RBG color WHITE
 */
#define WHITE 0xFFFFFF

/**
 *  @brief This macro represents the RBG color CYAN
 */
#define CYAN 0x07C1FF

/**
 *  @brief This macro represents the RGB color NEON PINK
 */
#define N_PINK 0xFF007F

/**
 *  @brief This macro represents the RGB color NEON GREEN
 */
#define N_GREEN 0x39FF14

/**
 *  @brief This macro represents the RGB color NEON BLUE
 */
#define N_BLUE 0x1B03A3

/**
 *  @brief This macro represents the RGB color NEON YELLOW
 */
#define N_YELLOW 0xFFFF33

/**
 *  @brief This macro represents the RGB color NEON ORANGE
 */
#define N_ORANGE 0xFF6600

/**
 *  @brief This macro represents the RGB color NEON PURPLE
 */
#define N_PURPLE 0xB026FF
