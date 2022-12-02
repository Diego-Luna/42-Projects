################################################################################
#                                     CONFIG                                   #
################################################################################


# Program
NAME = push_swap
NAME_BONUS = checker

CC		=	gcc
CFLAGS	=	-g -Wall -Werror -Wextra -I. -I./$(INCDIR)
RM		=	rm -f
RM_F		=	rm -rf

# Includes are all .h files
INCDIR	=	libs/
# INC		=	$(wildcard $(INCDIR)*.h)
INC		=	libs/push_swap.h

INC_BONUS		=	libs/checker.h

# Sources are all .c files
SRCDIR	=	src/
SRCS =	src/main.c src/ft_sa_sb_ss.c src/ft_pa_pb.c src/ft_rra_rrb_rrr.c \
				src/ft_ra_rb_rr.c src/ft_arrange_2_to_5_format.c src/ft_exit.c \
				src/ft_arrange_big.c src/ft_check_params.c src/ft_tlist_utils.c

SRCDIR_BONUS	=	bonus/
SRCS_BONUS =	bonus/checker.c bonus/ft_check_params_bonus.c bonus/ft_exit_bonus.c \
					bonus/ft_sa_sb_ss_bonus.c bonus/ft_pa_pb_bonus.c bonus/ft_rra_rrb_rrr_bonus.c \
					bonus/ft_ra_rb_rr_bonus.c bonus/ft_tlist_utils_bonus.c bonus/checker_utils.c

# Objects are all .o files
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

OBJDIR_BONUS	=	bin_bonus/
OBJS_BONUS	=	$(patsubst $(SRCDIR_BONUS)%.c,$(OBJDIR_BONUS)%.o,$(SRCS_BONUS))

# libf
LIBFT = libft.a
D_LIBFT = libs/libft/

# ////////////////// TARGETS

# all: $(NAME)
all: do_libft $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(D_LIBFT)$(LIBFT)

# Generates output file
$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $(OBJS_BONUS) $(D_LIBFT)$(LIBFT)

# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compiles sources into objects
$(OBJS_BONUS): $(OBJDIR_BONUS)%.o : $(SRCDIR_BONUS)%.c $(INC_BONUS) | $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	mkdir -p $@

$(OBJDIR_BONUS):
	mkdir -p $@

# Removes objects
clean:
	@$(RM_F) $(OBJDIR)
	@$(RM_F) $(OBJDIR_BONUS)
	@$(MAKE) --no-print-directory -C $(D_LIBFT) clean

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(MAKE) --no-print-directory -C $(D_LIBFT) fclean

# Removes objects and executables and remakes
re: fclean all

bonus: do_libft $(NAME_BONUS)

# libf
do_libft:
	@$(MAKE) -C $(D_LIBFT)
# libf
.PHONY:		all clean fclean re header