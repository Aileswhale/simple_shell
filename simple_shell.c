#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int main(void) {
	char *input = NULL;  // Dynamically allocate memory for input
	size_t input_size = 0;
	char *argv[2];  // We'll only execute single-word commands
	char *prompt = "#cisfun$ ";

	while (1) {
		printf("%s", prompt);

		// Use getline to read user input
		ssize_t read_size = getline(&input, &input_size, stdin);

		if (read_size == -1) {
			// Handle EOF (Ctrl+D) or error
			break;
		}

		// Remove the newline character from input
		input[strcspn(input, "\n")] = '\0';

		// Check if the command is "exit" to exit the shell
		if (strcmp(input, "exit") == 0) {
			break;
		}

		// Fork a child process
		pid_t pid = fork();

		if (pid < 0) {
			perror("fork");
			free(input);  // Free dynamically allocated memory
			exit(EXIT_FAILURE);
		}

		if (pid == 0) {
			// Child process
			argv[0] = input;
			argv[1] = NULL;

			execve(input, argv, NULL); // Execute the command

			// If execve fails, print an error message
			perror("./shell");
			free(input);  // Free dynamically allocated memory
			exit(EXIT_FAILURE);
		} else {
			// Parent process
			int status;
			waitpid(pid, &status, 0); // Wait for the child to finish
		}
	}

	free(input);  // Free dynamically allocated memory
	return 0;
}
