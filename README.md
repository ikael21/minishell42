# MINISHELL42 (School21 or Ecole 42 project)
## As beautiful as shell
The objective of this project is to create a simple shell
to learn about processes and file discriptors.

## USAGE
1. Apply **make** command in the root directory to compile the program
2. Run the program with the following command **./minishell**
## Implemented features
- launching the right executable (based on the PATH variable or by using relative or absolute path)
- showing commands history when pressing up or down
- **echo**(builtin) with option -n
- **cd**(builtin) with only a relative or absolute path
- **pwd**(builtin) with no options
- **export**(builtin) with no options
- **unset**(builtin) with no options
- **env**(builtin) with no options or arguments
- **exit**(builtin) with no options
## REDIRECTIONS
- **<** redirect input
- **>** redirect output
- **<<** read input from the current source until only the delimiter presented
- **>>** redirect output with append mode
## PIPES
The output of each command in the pipeline is connected
via a pipe to the input of the next command
## SIGNALS
**ctrl-C ctrl-D ctrl-\\** work like in bash.
