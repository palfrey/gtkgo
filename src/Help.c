/* gtkgo 0.0.10 (Help.c) - 05/17/99
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

#include "Help.h"

void DestroyHelp (void)
{
  iyesno = 0;
  gtk_widget_destroy (helpwindow);
}

void ToggleWrapH (GtkWidget *checkbutton, GtkWidget *text)
{
  gtk_text_set_word_wrap (GTK_TEXT (texth), GTK_TOGGLE_BUTTON
    (checkbutton)->active);
}

void Help (void)
{
  if ((ifilestuff == 0) && ((biscomputer == 0) || (wiscomputer == 0))
    && (iyesno == 0))
  {
    helpwindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (helpwindow), "help");
    gtk_signal_connect (GTK_OBJECT (helpwindow), "delete_event",
      GTK_SIGNAL_FUNC (DestroyHelp), NULL);
    gtk_window_set_policy (GTK_WINDOW (helpwindow), 0, 0, 1);
    gtk_container_border_width (GTK_CONTAINER (helpwindow), 0);
    gtk_widget_realize (helpwindow);

    helpbox1 = gtk_vbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (helpbox1), 0);
    gtk_container_add (GTK_CONTAINER (helpwindow), helpbox1);
    gtk_widget_show (helpbox1);
    helpbox2 = gtk_hbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (helpbox2), 0);
    gtk_box_pack_start (GTK_BOX (helpbox1), helpbox2, TRUE, TRUE, 5);
    gtk_widget_show (helpbox2);
    helpbox3 = gtk_vbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (helpbox3), 0);
    gtk_box_pack_start (GTK_BOX (helpbox2), helpbox3, TRUE, TRUE, 0);
    gtk_widget_show (helpbox3);
    helptable1 = gtk_table_new (2, 1, FALSE);
    gtk_widget_show (helptable1);
    gtk_box_pack_start (GTK_BOX (helpbox3), helptable1, TRUE, TRUE, 0);
    helptable2 = gtk_table_new (1, 3, FALSE);
    gtk_widget_show (helptable2);
    gtk_box_pack_start (GTK_BOX (helpbox3), helptable2, TRUE, TRUE, 0);

    texth = gtk_text_new (NULL, NULL);
    gtk_widget_set_usize (texth, 535, 266);
    gtk_text_set_editable (GTK_TEXT (texth), FALSE);
    gtk_table_attach (GTK_TABLE (helptable1), texth, 0, 1, 0, 1,
      GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 5, 0);
    gtk_widget_show (texth);

    vscrollbarh = gtk_vscrollbar_new (GTK_TEXT (texth)->vadj);
    gtk_table_attach (GTK_TABLE (helptable1), vscrollbarh, 1, 2, 0, 1,
      GTK_FILL, GTK_EXPAND  | GTK_FILL, 5, 0);
    gtk_widget_show (vscrollbarh);

    gtk_widget_realize (texth);

    wrapcheckh = gtk_check_button_new_with_label ("wrap");
    gtk_table_attach (GTK_TABLE (helptable2), wrapcheckh, 0, 1, 0, 1,
      GTK_FILL, GTK_FILL, 5, 10);
    gtk_signal_connect (GTK_OBJECT (wrapcheckh), "toggled",
      GTK_SIGNAL_FUNC (ToggleWrapH), texth);
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (wrapcheckh), FALSE);
    gtk_widget_show (wrapcheckh);

    helpsep = gtk_hseparator_new ();
    gtk_table_attach (GTK_TABLE (helptable2), helpsep, 0, 1, 1, 2,
      GTK_EXPAND | GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show (helpsep);

#ifdef USE_GNOME
    helpbutton = gnome_stock_button (GNOME_STOCK_BUTTON_CLOSE);
#else
    helpbutton = gtk_button_new_with_label ("Close");
#endif
    gtk_signal_connect (GTK_OBJECT (helpbutton), "clicked",
      GTK_SIGNAL_FUNC (DestroyHelp), NULL);
    GTK_WIDGET_SET_FLAGS (helpbutton, GTK_CAN_DEFAULT);
    gtk_window_set_default (GTK_WINDOW (helpwindow), helpbutton);
    gtk_table_attach (GTK_TABLE (helptable2), helpbutton, 0, 1, 2, 3,
      GTK_EXPAND | GTK_FILL, GTK_FILL, 2, 2);
    gtk_widget_show (helpbutton);

    gtk_text_freeze (GTK_TEXT (texth));
    ihelpdes = open (PKGDATADIR"help/README", O_RDONLY, 0600);
    if (ihelpdes == -1)
    {
      Message ("Could not open README file.", 3, 0);
    }
    else
    {
      while (1)
      {
        nchars = read (ihelpdes, buffer, 1024);
        gtk_text_insert (GTK_TEXT (texth), fixed_font, NULL, NULL, buffer,
          nchars);
        if (nchars < 1024)
        {
          break;
        }
      }
    }
    close (ihelpdes);
    gtk_text_thaw (GTK_TEXT (texth));

    gtk_widget_show (helpwindow);
    iyesno = 1;
    if (ichangestuff == 0)
    {
      Play ("open.mp3", 0);
    }
  }
  else
  {
    if (ichangestuff == 0)
    {
      Play ("click.mp3", 0);
    }
  }
}
