#include "includes/minishell.h"

static void	init_head(t_list **head)
{
	char	**argv;

	// *********** ls -la ****************
	argv = (char **)malloc(sizeof(char *) * 3);
	argv[2] = NULL;
	argv[0] = ft_strdup("/bin/ls");
	argv[1] = ft_strdup("-la");
	ft_lstadd_back(head, ft_lstnew(argv));
	// ------------------------------------

	// *********** cat -e *****************
	argv = (char **)malloc(sizeof(char *) * 3);
	argv[2] = NULL;
	argv[0] = ft_strdup("/bisn/cat");
	argv[1] = ft_strdup("-e");
	ft_lstadd_back(head, ft_lstnew(argv));
	// ------------------------------------

	// *********** cat -e *****************
	argv = (char **)malloc(sizeof(char *) * 3);
	argv[2] = NULL;
	argv[0] = ft_strdup("/bin/cat");
	argv[1] = ft_strdup("-e");
	ft_lstadd_back(head, ft_lstnew(argv));
	// ------------------------------------
}

static void	error_occured(void)
{
	perror("loshara");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	t_list	*head;
	t_list	*temp;
	int		i, j;
	char	**argv_priv;
	int		ret;

	head = NULL;
	init_head(&head);
	int	fd[ft_lstsize(head) - 1][2];
	for (i = 0; i < ft_lstsize(head) - 1; i++)
		if (pipe(fd[i]) < 0)
			error_occured();
	i = 0;
	temp = head;
	while (temp)
	{
		argv_priv = (char **)temp->content;
		pid = fork();
		if (pid == -1)
			error_occured();
		if (pid == 0)
		{
			if (i == 0)
				dup2(fd[i][1], STDOUT_FILENO);
			else if (i == ft_lstsize(head) - 1)
				dup2(fd[i - 1][0], STDIN_FILENO);
			else
				dup2(fd[i][1], STDOUT_FILENO), dup2(fd[i - 1][0], STDIN_FILENO);
			for (j = 0; j < ft_lstsize(head) - 1; j++)
				close(fd[j][0]), close(fd[j][1]);
			execve(argv_priv[0], argv_priv, env);
			error_occured();
		}
		temp = temp->next;
		i++;
	}
	for (i = 0; i < ft_lstsize(head); i++)
		close(fd[i][0]), close(fd[i][1]);
	pid = waitpid(P_ALL, &ret, 0);
}
