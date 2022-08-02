#ifndef _SHELL_H_
#define _SHELL_H_

void kbsh_loop(void);
char *kbsh_readline(void);
char **kbsh_split_line(char *line);
int kbsh_start_process(char **args);
int kbsh_cd(char **args);
int kbsh_help(char **args);
int kbsh_exit(char **args);
int kbsh_builtins();

#endif /* _SHELL_H_ */
