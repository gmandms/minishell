cmake_minimum_required(VERSION 3.16)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell main.c minishell.h read_cmdline.c run_cmd.c create_env.c size_dac.c change_env.c pwd.c
        impl_cmds.c FT_PRINTF/LIBFT/ft_strncmp.c FT_PRINTF/LIBFT/ft_atoi.c source_myexe.c setenv.c unsetenv.c echo.c minishell.h cd.c find_arg.c source_cd.c source_free.c source_runcmd.c source_runcmd2.c source_implcmds.c source_runcmd3.c)

target_link_libraries(minishell ${CMAKE_SOURCE_DIR}/FT_PRINTF/libftprintf.a)