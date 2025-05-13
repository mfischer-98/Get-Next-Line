/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_v01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:53:52 by mefische          #+#    #+#             */
/*   Updated: 2025/05/13 15:08:06 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *stash, char *buffer)
{
		int	read_size;//para verificar se deu erro ao ler o ficheiro

	read_size = 1;
	while (ft_strchr(buffer, '\n') == NULL && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buffer);
			buffer = NULL;
			return  NULL;
		}
		if (read_size == 0)
			break ;
		buffer[read_size] = '\0';
		stash = ft_strjoin(stash, buffer);//quero juntar o que tem no buffer a stash pq o buffer vai ser sempre substituido quando usamos read
	}
	free(buffer);
	buffer = NULL;
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer; //o pedaco de texto que a read leu
	static char	*stash; //para guardar os restos
	char		*line; //linha que quero retornar
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = NULL;
	buffer = malloc ((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	*buffer = 0; //preciso inicializar para fazer a condicao do ciclo (== '\0')
 	stash = ft_read(fd, stash, buffer); //funcao pra ler e guardar info na stash
	if (!stash)
		return NULL;
	line = ft_strcdup(stash, '\n'); //ja colocar o \n
	if (!line)
		return NULL;
	stash = ft_substr(stash, ft_strlen(line), ft_strlen(stash) - ft_strlen(line)); //preciso mover o stash para depois do \n e guardar o que tem dps
	if (!*stash)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}

int	main()
{
	char	*line;
	int	fd = open("text.txt", O_RDONLY);

	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	if (close(fd) == -1)
		return(1);
	return (0);
}

/* int main()
{
	int	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	char *str = get_next_line(fd);;
	for (int i = 0; i < 5; i++)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return 0;
} */