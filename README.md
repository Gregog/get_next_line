# get_next_line
Реализация проекта get_next_line в рамках обучения в Школе21. Является аналогом readline из Python
### Пример main.c для считывания строки из документа указанного в аргументах
```c 
int main(int argc, char **argv)
	int		fd;
	char	*line;
	int		ret;

	i = 0;
	fd = open((argv[1]), O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("|%s|\n", line);
	}
}
```
### При компиляции необходимо явно указывать буфер, с которым вы хотите считать строку, либо добавить макрос в .h файл
### Пример:
```bash
gcc -D BUFFER_SIZE=32 main.c get_next_line.c get_next_line_utils.c
```
