#include <stdio.h>

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int 	ft_strcmp(char *s1, char *s2);

int main(void)
{
	int		a;
	int		b;

	a = 0;
	b = 1;
	ft_putchar('t');
	ft_putstr(" hamza ");
	printf("%d", ft_strcmp("hamza ", "hamza "));
	printf("\n%d %d\n", a, b);
	ft_swap(&a, &b);
	printf("%d %d\n", a, b);
	printf("%d\n", ft_strlen("hamza"));
	return (0);
}