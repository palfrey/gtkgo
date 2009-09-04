/* gtkgo 0.0.10 (SaveSgf.c) - 05/17/99
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

#include "SaveSgf.h"

void SaveSgf (void)
{
  if (ichangestuff == 0)
  {
    Play ("open.mp3", 0);
  }
  files2 = gtk_file_selection_new ("save sgf");
  gtk_signal_connect (GTK_OBJECT (files2), "delete_event",
    GTK_SIGNAL_FUNC (DestroyFiles2), NULL);
  if ((itype == 1) || (itype == 3))
  {
    gtk_signal_connect (GTK_OBJECT (GTK_FILE_SELECTION
      (files2)->ok_button), "clicked", (GtkSignalFunc) ReallyQuit, files2);
  }
  if (itype == 2)
  {
    gtk_signal_connect (GTK_OBJECT (GTK_FILE_SELECTION
      (files2)->ok_button), "clicked", (GtkSignalFunc) ReallyReStart, files2);
  }
  gtk_signal_connect_object (GTK_OBJECT (GTK_FILE_SELECTION
    (files2)->cancel_button), "clicked", (GtkSignalFunc) DestroyFiles2, NULL);
  gtk_file_selection_set_filename (GTK_FILE_SELECTION (files2),
    "gtkgo.sgf");
  gtk_file_selection_show_fileop_buttons (GTK_FILE_SELECTION (files2));
  gtk_widget_set_usize (GTK_WIDGET (files2), 445, 300);
  gtk_widget_show (files2);
  ifilestuff = 1;
}
