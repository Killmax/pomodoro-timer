/*
** main.c for pomodoro timer in /home/brugue_m/Perso/projets_divers/pomodoro_c
** 
** Made by Maxime B. (website : maxime-brgt.me)
** 
** Started on Thu Jul  9 17:12:42 2015 Maxime B.
** Last update Mon Jul 13 17:53:22 2015 Maxime B.
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<stdbool.h>
#include	<signal.h>
#include	<stdlib.h>
#include	"pomodoro.h"

void		sig_h(int sig)
{
  (void)sig;
  printf("\033[0m\nGood Bye !\n");
  exit(0);
}
void		end_check(bool *is_break, int *count_p, bool *is_lb)
{
  if ((*is_break))
    *is_break = false;
  else if (!(*is_break) && (*count_p) % NBR_POM_LONG_BREAK == 0)
    {
      printf("\033[1;44mGood job, long break time !\n");
      (*is_break) = true;
      (*is_lb) = true;
      (*count_p)++;
    }
  else
    {
      printf("\033[1;42mBreak time !\n");
      (*is_break) = true;
      (*is_lb) = false;
      (*count_p)++;
    }
}

void		main_loop(int *min, int *sec)
{
  while ((*min) >= 0)
    {
      while ((*min) >= 0 && (*sec) >= 0)
	{
	  printf("Il reste ");
	  if ((*min) < 10)
	    printf("0");
	  printf("%d:", (*min));
	  if ((*sec) < 10)
	    printf("0");
	  printf("%d...", (*sec));
	  fflush(stdout);
	  putchar('\r');
	  sleep(1);
	  (*sec)--;
	}
      *sec = 59;
      (*min)--;
    }
}

int		main(int ac, char **av)
{
  int		min;
  int		sec = 59;
  int		count_p = 1;
  bool		is_break = false;
  bool		is_lb = false;

  (void)ac;
  (void)av;
  while (true)
    {
      signal(SIGINT, sig_h);
      if (!is_break)
	printf("\033[1;41mWorking ! Pomodoro n°%d !\n", count_p);
      if (is_break && is_lb)
	min = LENGTH_LONG_BREAK - 1;
      else if (is_break)
	min = LENGTH_SHORT_BREAK - 1;
      else
	min = LENGTH_POMODORO - 1;
      main_loop(&min, &sec);
      putchar('\n');
      printf("\033[0m");
      fflush(stdout);
      system("beep -l 100 -f 400 -D 200 -n -l 100 -f 400");
      end_check(&is_break, &count_p, &is_lb);
    }
  return (EXIT_SUCCESS);
}
