/* gtkgo 0.0.10 (Human.c) - 05/17/99
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

#include "Human.h"

void DestroyHuman (void)
{
  gtk_widget_destroy (humwindow);
  iyesno = 0;
}

void ActivateHuman (void)
{
  if (ichangecolorh == 1)
  {
    sprintf (wplayername, "%s", gtk_entry_get_text (GTK_ENTRY (humentry)));
    wiscomputer = 0;
  }
  else
  {
    sprintf (bplayername, "%s", gtk_entry_get_text (GTK_ENTRY (humentry)));
    biscomputer = 0;
  }
  gtk_widget_destroy (humwindow);
  iyesno = 0;
  StatusBar ();
}

void Human (GtkWidget *humwidget, gpointer humdata)
{
  if ((ifilestuff == 0) && ((biscomputer == 0) || (wiscomputer == 0))
    && (iyesno == 0))
  {
    ichangecolorh = (int) humdata;
    humwindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    if (ichangecolorh == 1)
    {
      gtk_window_set_title (GTK_WINDOW (humwindow), "change white");
    }
    else
    {
      gtk_window_set_title (GTK_WINDOW (humwindow), "change black");
    }
    gtk_signal_connect (GTK_OBJECT (humwindow), "delete_event",
      GTK_SIGNAL_FUNC (DestroyHuman), NULL);
    gtk_window_set_policy (GTK_WINDOW (humwindow), 0, 0, 1);
    gtk_container_border_width (GTK_CONTAINER (humwindow), 0);
    gtk_widget_realize (humwindow);

    humbox1 = gtk_vbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (humbox1), 0);
    gtk_container_add (GTK_CONTAINER (humwindow), humbox1);
    gtk_widget_show (humbox1);
    humbox2 = gtk_hbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (humbox2), 0);
    gtk_box_pack_start (GTK_BOX (humbox1), humbox2, FALSE, FALSE, 0);
    gtk_widget_show (humbox2);
    humtable1 = gtk_table_new (1, 3, FALSE);
    gtk_box_pack_start (GTK_BOX (humbox2), humtable1, TRUE, TRUE, 0);
    gtk_widget_show (humtable1);

    humentry = gtk_entry_new_with_max_length (50);
    gtk_signal_connect (GTK_OBJECT (humentry), "activate",
      GTK_SIGNAL_FUNC (ActivateHuman), NULL);
    if ((ichangecolorh == 1) && (wiscomputer == 0))
    {
      gtk_entry_set_text (GTK_ENTRY (humentry), wplayername);
      gtk_entry_select_region (GTK_ENTRY (humentry),
        0, GTK_ENTRY (humentry)->text_length);
    }
    if ((ichangecolorh == 2) && (biscomputer == 0))
    {
      gtk_entry_set_text (GTK_ENTRY (humentry), bplayername);
      gtk_entry_select_region (GTK_ENTRY (humentry),
        0, GTK_ENTRY (humentry)->text_length);
    }
    gtk_table_attach (GTK_TABLE (humtable1), humentry, 0, 1, 0, 1,
      GTK_EXPAND, GTK_EXPAND, 10, 10);
    gtk_widget_grab_focus (humentry);
    gtk_widget_show (humentry);

    humsep = gtk_hseparator_new ();
    gtk_table_attach (GTK_TABLE (humtable1), humsep, 0, 1, 1, 2,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show (humsep);

#ifdef USE_GNOME
    humbutton = gnome_stock_button (GNOME_STOCK_BUTTON_OK);
#else
    humbutton = gtk_button_new_with_label ("OK");
#endif
    gtk_signal_connect (GTK_OBJECT (humbutton), "clicked",
      GTK_SIGNAL_FUNC (ActivateHuman), NULL);
    GTK_WIDGET_SET_FLAGS (humbutton, GTK_CAN_DEFAULT);
    gtk_window_set_default (GTK_WINDOW (humwindow), humbutton);
    gtk_table_attach (GTK_TABLE (humtable1), humbutton, 0, 1, 2, 3,
      GTK_FILL, GTK_FILL, 2, 2);
    gtk_widget_show (humbutton);

    gtk_widget_show (humwindow);
    iyesno = 1;
  }
}
