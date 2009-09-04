/* gtkgo 0.0.10 (About.c) - 05/17/99
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

#include "About.h"

#ifndef USE_GNOME
void DestroyAbout (void)
{
  gtk_widget_destroy (about);
  iabout = 0;
}
#endif

void About (void)
{
  if (iyesno == 0)
  {
#ifdef USE_GNOME
    const gchar *author[] = {
      "Norbert de Jonge <hack@altavista.net>", "...more credits in the 'AUTHORS' file.", 0
    };
    sprintf (sgoal,
      "The goal of the gtkgo project is to make a go game for both "
      "Linux and Windows, that has skin support and can load computer scripts "
      "that can be made by users, so that different go-computers can 'attack' "
      "each other or other users.");
    about = gnome_about_new ("gtkgo", "0.0.10 - 05/17/99",
      "Copyright (C) 1998, 1999  Norbert de Jonge", author, sgoal, 0);
    gtk_widget_show (about);
#else
    if (iabout != 1)
    {
      sprintf (sgoal,
        "The goal of the gtkgo project is to make a go game for both "
        "Linux and Windows,\nthat has skin support and can load computer "
        "scripts that can be made by users,\nso that different go-computers "
        "can 'attack' each other or other users.\n");
      sprintf (sme,
        "gtkgo 0.0.10 - 05/17/99\n\nCopyright (C) 1998, 1999  Norbert de Jonge "
        "<hack@altavista.net>\n...more credits in the 'AUTHORS' file.");

      about = gtk_dialog_new ();
      gtk_window_position (GTK_WINDOW (about), GTK_WIN_POS_CENTER);
      gtk_window_set_title (GTK_WINDOW (about), "about");
      gtk_signal_connect (GTK_OBJECT (about), "delete_event",
        GTK_SIGNAL_FUNC (DestroyAbout), NULL);
      gtk_window_set_policy (GTK_WINDOW (about), 0, 0, 1);
      gtk_container_border_width (GTK_CONTAINER (GTK_DIALOG (about)->vbox), 10);
      gtk_widget_realize (about);

      aboutlabel = gtk_label_new (sme);
      gtk_box_pack_start (GTK_BOX (GTK_DIALOG (about)->vbox), aboutlabel, TRUE,
        TRUE, 10);
      gtk_widget_show (aboutlabel);
      aboutlabel2 = gtk_label_new (sgoal);
      gtk_box_pack_start (GTK_BOX (GTK_DIALOG (about)->vbox), aboutlabel2, TRUE,
        TRUE, 10);
      gtk_widget_show (aboutlabel2);

      aboutbutton = gtk_button_new_with_label ("OK");
      gtk_signal_connect (GTK_OBJECT (aboutbutton), "clicked",
        GTK_SIGNAL_FUNC (DestroyAbout), NULL);
      GTK_WIDGET_SET_FLAGS (aboutbutton, GTK_CAN_DEFAULT);
      gtk_window_set_default (GTK_WINDOW (about), aboutbutton);
      gtk_box_pack_start (GTK_BOX (GTK_DIALOG (about)->action_area),
        aboutbutton, TRUE, TRUE, 10);
      gtk_widget_show (aboutbutton);

      gtk_widget_show (about);
      iabout = 1;
    }
#endif
  }
}
