// 1. create_str (buffer + str)
// 2. Enquanto nao houver \n ler para o buffer e fazer string join do buffer;
// 3. mover o buffer para a esquerda
// 
// create_str(char *str, char * buffer)
// shift(char *buffer)
// has_new_line(char *buffer)

#include "get_next_line.h"

void	ft_strcopy(char *new, char *line, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			new[i] = line[i];
			i++;
		}
	}
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		new[i + j] = buffer[j];
		j++;
	}		
	if (buffer[j] == '\n')
	{
		new[i + j] = '\n';
		j++;
	}
	new[i + j] = '\0';
}

char	*create_str(char *old, char *buffer)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	if (old)
		while (old[i])
			i++;
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
		j++;
	if (buffer[j] == '\n')
		++j;
	new = malloc(i + j + 1);
	if (!new)
		return (NULL);
	ft_strcopy(new, old, buffer);
	if (old)
		free(old);
	return (new);
}

void	shift(char *buffer)
{
	int	i;
	int j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		++i;
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = '\0';
}
		

int	has_new_line(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	char static	buffer[BUFFER_SIZE + 1];
	char 		*line;
	int			bytes;

	line = NULL;
	line = create_str(line, buffer);
	while(!has_new_line(buffer))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			break;
		line = create_str(line, buffer);
		if (buffer[0] == '\0' || bytes == 0)
		{
			free(line);
			return (NULL);
		}
		if (bytes < BUFFER_SIZE)
			buffer[bytes] = '\0';
	}
	shift(buffer);
	return (line);
}

#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int fd = open("gnl.c", O_RDONLY);
	char *str;

	while ((str = get_next_line(fd)))
		printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	return (0);
}
