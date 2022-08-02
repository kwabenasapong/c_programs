#ifndef _SHELL_H_
#define _SHELL_H_

void kbsh_loop(void);
char *kbsh_readline(void);
char **kbsh_split_line(char *line);
int kbsh_start_process(char **args);

#endif /* _SHELL_H_ */
