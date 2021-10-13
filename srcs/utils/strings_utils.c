/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjerrica <mjerrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:15 by ikael             #+#    #+#             */
/*   Updated: 2021/10/07 17:56:43 by mjerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ****************************************************** */
/* splits the given string into three parts               */
/* first part contains symbols from 0 to POS1             */
/* the second contains symbols from (POS1 + 1) to POS2    */
/* the third part contains symbols from (POS2 + 1) to     */
/* the end of the string                                  */
/* returns an array of resulting strings                  */
/* ****************************************************** */
char	**split_into_three_parts(char *str, int pos1, int pos2)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * 4);
	if (result == NULL)
		exit(EXIT_FAILURE);
	result[3] = NULL;
	result[0] = ft_substr(str, 0, pos1);
	result[1] = ft_substr(str, pos1 + 1, pos2 - pos1 - 1);
	result[2] = ft_substr(str, pos2 + 1, ft_strlen(str) - pos2 - 1);
	if (result[0] == NULL || result[1] == NULL || result[2] == NULL)
		exit(EXIT_FAILURE);
	return (result);
}

/* ****************************************************** */
/* splits the given string into two parts                 */
/* where first part contains symbols from 0 to POS1       */
/* and the second contains symbols from POS2 to the end   */
/* of the string, returns an array of resulting strings   */
/* ****************************************************** */
char	**split_into_two_parts(char *str, int pos1, int pos2)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * 3);
	if (result == NULL)
		exit(EXIT_FAILURE);
	result[2] = NULL;
	result[0] = ft_substr(str, 0, pos1);
	result[1] = ft_substr(str, pos2, ft_strlen(str) - pos2);
	if (result[0] == NULL || result[1] == NULL)
		exit(EXIT_FAILURE);
	return (result);
}

/* ****************************************************** */
/* merges the given strings into big one                  */
/* str3 is optional and considers if is not equal to NULL */
/* it is assumed that given strings were allocated using  */
/* malloc or similar functions (realloc, calloc, etc)     */
/* str1, str2, str3(if is not NULL) will be freed         */
/* ****************************************************** */
char	*merge_strings(char *str1, char *str2, char *str3)
{
	char	*result_string;
	char	*temp;

	result_string = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	if (result_string == NULL)
		exit(EXIT_FAILURE);
	if (str3)
	{
		temp = ft_strjoin(result_string, str3);
		free(result_string);
		free(str3);
		result_string = temp;
	}
	return (result_string);
}
