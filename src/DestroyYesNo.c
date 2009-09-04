/* gtkgo 0.0.10 (DestroyYesNo.c) - 05/17/99
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

#include "DestroyYesNo.h"

void DestroyYesNo (GtkWidget *ynwidget, GdkEvent *ynevent, gpointer yndata)
{
  if (ifilestuff == 0)
  {
    if ((int) yndata == 0)
    {
      gtk_widget_destroy (yesnowindow);
      iyesno = 0;
      /* If a computer is selected and the user destroys AskSave, */
      /* do a computer move.                                      */
      if ((Modulo (imoves, 2) == 0) && (biscomputer == 1))
      {
        Computer ('b');
        JudgeBoard ('w');
      }
      if ((Modulo (imoves, 2) != 0) && (wiscomputer == 1))
      {
        Computer ('w');
        JudgeBoard ('b');
      }
    }
    if ((int) yndata == 1)
    {
      SaveSgf ();
    }
    if ((int) yndata == 2)
    {
      gtk_widget_destroy (yesnowindow);
      iyesno = 0;
      isave = 0;
      ReallyReStart (NULL, NULL);
    }
    if ((int) yndata == 3)
    {
      gtk_widget_destroy (yesnowindow);
      iyesno = 0;
      isave = 0;
      ReallyQuit (NULL, NULL);
    }
  }
}
