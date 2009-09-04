/* gtkgo 0.0.10 (TheComputer.c) - 05/17/99
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

#include "TheComputer.h"

void TheComputer (GtkWidget *tcwidget, gpointer tcdata)
{
  if ((ifilestuff == 0) && ((biscomputer == 0) || (wiscomputer == 0))
    && (iyesno == 0))
  {
    ichangecolor = (int) tcdata;
    if (ichangecolor == 1)
    {
      change = gtk_file_selection_new ("change white");
    }
    else
    {
      change = gtk_file_selection_new ("change black");
    }
    gtk_signal_connect (GTK_OBJECT (change), "delete_event",
      GTK_SIGNAL_FUNC (DestroyChange), NULL);
    gtk_signal_connect (GTK_OBJECT (GTK_FILE_SELECTION
      (change)->ok_button), "clicked", (GtkSignalFunc) EnableComp, change);
    gtk_signal_connect_object (GTK_OBJECT (GTK_FILE_SELECTION
      (change)->cancel_button), "clicked",
      (GtkSignalFunc) DestroyChange, NULL);
    if (ichangecolor == 2)
    {
      if (biscomputer == 1)
      {
        sprintf (defchange, PKGDATADIR"computers/%s.gtkgo", bplayername);
      }
      else
      {
        sprintf (defchange, "%s", PKGDATADIR"computers/default2.gtkgo");
      }
      gtk_file_selection_set_filename (GTK_FILE_SELECTION (change), defchange);
    }
    else
    {
      if (wiscomputer == 1)
      {
        sprintf (defchange, PKGDATADIR"computers/%s.gtkgo", wplayername);
      }
      else
      {
        sprintf (defchange, "%s", PKGDATADIR"computers/default2.gtkgo");
      }
      gtk_file_selection_set_filename (GTK_FILE_SELECTION (change), defchange);
    }
    gtk_file_selection_hide_fileop_buttons (GTK_FILE_SELECTION (change));
    gtk_widget_set_usize (GTK_WIDGET (change), 445, 300);
    gtk_widget_show (change);
    ifilestuff = 1;
  }
}
