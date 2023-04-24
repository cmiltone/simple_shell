# simple_shell
#alx #simple_shell
----------------------------------------------
This is a manual on the tasks at hand
**********************************************
Some key notes to point is the use of CLI
	i.) Command-line Interface(CLI)
==> a shell is a command line interface that usually allows the user to
interact with the os by typing commands to it. it usually reads the input
interprets it and executes the appropriate system commands.
	ii.) Input and Output
==> see, input comes from the user using the keyboard and then it displays
on the screen, in order to handle input and output, you need to use the standard input and output streams. They are the predefined streams provided by the operating system that allows the shell to read input and give output

	ii.) Parsing
==> well, Whenever a user types a command into the shell, the shell must parse
the input to determine which of the comamnads to execute and what type of
arguments to pass to the command.
Therefore, parsing involves breaking the input into tokens and then
analyzing the tokens to determine the commands and arguments.

	iii.) Process Management
==> The shell has the ability to create, manage and stop or rather to
terminate a process.Any time that a user executes a command, the shell
creates a new process id for the session, The shell also has a uniqueness
to manage multiple processes occuring concurently at the same time.
	iv.) Environment Variables
==> Well, these are variables that are set in the shell's env and can be acessed by programs running in that env. the shell must be able to set and also manage its  environment variables.
These variables are often used to manage system commands.
	v.) Built-in Commands
==> The shell also may provide some built-in commands that are executed directly by the shell. Without creating a new process.i.e the cd, pwd echo, cat etc.

