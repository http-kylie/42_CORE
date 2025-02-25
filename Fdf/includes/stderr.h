/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stderr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:13:13 by kytan             #+#    #+#             */
/*   Updated: 2024/06/16 20:13:13 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** @brief This macro converts the parameter (x) into a string literal.
 
#define ERROR_TYPE(x) #x*/
/** @brief This macro is the ANSI escape code for setting terminal
 *  output color to yellow
 */
#define COLOR_ERR_MSG "\033[33m"

/** @brief This macro is to reset ANSI escape code coloring
 */
#define RESET_ERR_MSG "\033[0m"

/** @brief This macro defines the exit status SUCCESS for error handling
 */
#define SUCCESS 0

/** @brief This macro defines the exit status FAILURE for error handling
 */
#define FAILURE 1

/** @brief This macro defines the exit status INVALID_ARGS_ERROR for error
 * 	handling
 */
#define INVALID_ARGS_ERROR  2

/** @brief This macro defines the exit status FILE_OPEN_ERROR for error handling
 */
#define FILE_OPEN_ERROR     3

/** @brief This macro defines the exit status MEM_ALLOC_ERROR for error handling
 */
#define MEM_ALLOC_ERROR     4

/** @brief This macro defines the exit status MAP_EMPTY_ERROR for error handling
 */
#define MAP_EMPTY_ERROR     5

/** @brief This macro defines the exit status LIBFT_ERROR for error handling
 */
#define LIBFT_ERROR         6

/** @brief This macro defines the exit status MLX_ERROR for error handling
 */
#define MLX_ERROR           7

/** @brief This macro defines the exit status ASIAN_FAILURE_ERROR for
 * 	error handling
 */
#define ASIAN_FAILURE_ERROR 8
