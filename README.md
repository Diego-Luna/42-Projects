# 42-Projects


## ft_printf
run : clear && make clean && make all && gcc main.c -Wall -Wextra -Werror libftprintf.a && ./a.out | cat -e


## get_next_line

run :  clear && make clean && make all && gcc -Wall -Wextra -Werror -D BUFFER_SIZE=26 main.c get_next_line.a && ./a.out test/test_0.txt | cat -e

# pipe

valgrind -s --leak-check=full --track-fds=all ./pipex_bonus infile.txt  "ls -l" "wc -l"  diego2.txt