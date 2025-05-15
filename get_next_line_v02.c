/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:24:18 by mefische          #+#    #+#             */
/*   Updated: 2025/05/13 15:59:25 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_copystr(char *new_line, char *old, char *buffer)
{
	 int	i;
	 int	j;

	i = 0;
	if (old)//se tiver algo na old quero copiar primeiro
	{
		while (old[i])
		{
			new_line[i] = old[i];
			i++;
		}
	}
	j = 0;
	while(buffer[j] && buffer[j] != '\n')//copiar buffer ate antes do \n
	{
		new_line[i + j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')//se tiver \n no buffer quero copiar, otherwise, quero colocar so o \0
	{
		new_line[i + j] = '\n';
		j++;
	}
	new_line[i + j] = '\0';
}

char	*ft_createstr(char *old, char *buffer) //quero encontrar o tamanho de old + buffer pra alocar memoria e depois na funcao strjoin copiar para a nova line
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	if (old) //se tiver algo na linha quero contar o espaco
		while(old[i++]);
	j = 0;
	while (buffer[j] && buffer[j] != '\n') //ver tamanho do buffer
		j++;
 	if (buffer[j] == '\n')
		++j;
	new_line = malloc((i + j + 1) * sizeof (char));//minha newline vai ter o tamanho do buffer + old
	if (!new_line)
		return (NULL);
	ft_copystr(new_line, old, buffer);
	if (old)
		free(old);
	return(new_line);
}

void	ft_shiftbuffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while(buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = '\0';
}
int	ft_check(char *str)
{
	while(*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *line = NULL;
    int bytes;

    // Ver se tem algo no buffer antes de ler
    if (buffer[0] != '\0')
        line = ft_createstr(NULL, buffer);
    while (!ft_check(buffer))
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0)
            return (free(line), NULL);
        buffer[bytes] = '\0';
        if (bytes == 0) // EOF
        {
            if (line && line[0] != '\0')
                return line;
            return (free(line), NULL);
        }
        line = ft_createstr(line, buffer);
    }
    ft_shiftbuffer(buffer);
    return line;
}

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
    char *str;
    
    if (fd < 0)
    {
        printf("Error opening file\n");
        return 1;
    }
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("%s", str);
        free(str);
    }
	str = get_next_line(fd);
	printf("%s", str);
    close(fd);
    return 0;
}