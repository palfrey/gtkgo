/* gtkgo 0.0.10 (main.c) - 05/17/99
 * Copyright (C) 1998, 1999  Norbert de Jonge
 * (hack@altavista.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this game; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

/*
 * Do NOT use gtk_widget_set_usize for windows. This gives trouble with some
 * GTK+ Themes, Gnome and the Windows port of GTK+.
 */

/*
 * Hmm... Computer.c already contains more than 1800 lines of coding. Maybe
 * this scripting is not such a good idea after all. But I won't give up
 * that fast.
 */

#include "main.h"

int main (int argc, char *argv[])
{
  if (argc == 2)
  {
    if (strcmp (argv[1], "--version") == 0)
    {
      printf ("0.0.10\n");
      exit (1);
    }
  }

  if ((getenv ("DISPLAY")) == 0) {
    printf ("[Start the X Window System first]\n");
    exit (1);
  }

#ifdef USE_GNOME
  gnome_init ("gtkgo", "0.0.10", argc, argv);
#else
  gtk_init (&argc, &argv);
#endif
  gdk_imlib_init ();
  gtk_widget_push_visual (gdk_imlib_get_visual ());
  gtk_widget_push_colormap (gdk_imlib_get_colormap ());

  srandom ((unsigned)time(&tm));
  fixed_font = gdk_font_load ("-misc-fixed-medium-r-*-*-*-100-*-*-*-*-*-*");
  signal (SIGCHLD, SIG_IGN);

  mpg123pid = 0;
  itooltipsdone = 1;
  ilatestdone = 1;
  isounddone = 1;
  ihandicapdone = 1;
  ixdone = 1;
  iyesno = 0;
  inet = 0;
  igonow = 0;
  idohint = 0;
  wiscomputer = 1;
  biscomputer = 0;
  itooltips = 0;
  isize = 1;
  ihandicap = 0;
  ishowlast = 0;
  isound = 0;
  imoving = 0;
  iselectdead = 0;
  sprintf (bplayername, "%s", "unknown");
  sprintf (wplayername, "%s", "default2");

  sprintf (sthesavef, "%s/.gtkgo", getenv ("HOME"));
  isavedes = open (sthesavef, O_RDONLY, 0600);
  ithing = 0;
  if (isavedes == -1)
  {
#ifdef USE_GNOME
    sprintf (sskin, "%s", "gnome");
#else
    sprintf (sskin, "%s", "default");
#endif
    ioptionsx = 0;
    itimelimit = 30;
  }
  else
  {
    idone2 = 0;
    sprintf (ssaveread, "%s", "");
    do
    {
      do
      {
        iret = read (isavedes, schar2, 1);
        if ((schar2[0] != '\n') && (schar2[0] != '/'))
        {
          sprintf (ssavetemp, "%s%c", ssaveread, schar2[0]);
          sprintf (ssaveread, "%s", ssavetemp);
        }
      } while ((iret != 0) && (schar2[0] != '\n'));
      ithing++;
      switch (ithing)
      {
        case 3: sprintf (sskin, "%s", ssaveread); break;
        case 4: ioptionsx = atoi (ssaveread); break;
        case 5: itimelimit = atoi (ssaveread); idone2 = 1; break;
      }
      sprintf (ssaveread, "%s", "");
    } while ((iret != 0) && (idone2 == 0));
    close (isavedes);
    if (idone2 == 0)
    {
      sprintf (sysexec, "rm -f %s", sthesavef);
      system (sysexec);
      printf ("Please restart gtkgo.\n");
      exit (1);
    }
  }

  MainWindow ();
  ReStart (1);
  if (ithing == 0)
  {
    Message ("Welcome to gtkgo!  \n\nEven though gtkgo is as stable as "
      "possible, it is by NO means perfect.  \nIf you want to know more "
      "about gtkgo, please select 'Help...' from the 'Help'-menu.  \nDon't "
      "expect too much, this is just version 0.0.10...", 3, 1);
  }
  gtk_main ();
  return 0;
}
