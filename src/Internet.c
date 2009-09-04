/* gtkgo 0.0.10 (Internet.c) - 05/17/99
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

#include "Internet.h"

void DestroyConnect (void)
{
  gtk_widget_destroy (connectwindow);
  iyesno = 0;
}

void Internet (void)
{
  if ((ifilestuff == 0) && ((biscomputer == 0) || (wiscomputer == 0))
    && (iyesno == 0) && (inet == 0))
  {
    connectwindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (connectwindow), "Internet play");
    gtk_signal_connect (GTK_OBJECT (connectwindow), "delete_event",
      GTK_SIGNAL_FUNC (DestroyConnect), NULL);
    gtk_window_set_policy (GTK_WINDOW (connectwindow), 0, 0, 1);
    gtk_container_border_width (GTK_CONTAINER (connectwindow), 0);
    gtk_widget_realize (connectwindow);

    connectbox1 = gtk_vbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (connectbox1), 0);
    gtk_container_add (GTK_CONTAINER (connectwindow), connectbox1);
    gtk_widget_show (connectbox1);
    connectbox2 = gtk_hbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (connectbox2), 0);
    gtk_box_pack_start (GTK_BOX (connectbox1), connectbox2, FALSE, FALSE, 0);
    gtk_widget_show (connectbox2);
    connecttable1 = gtk_table_new (2, 4, FALSE);
    gtk_box_pack_start (GTK_BOX (connectbox2), connecttable1, TRUE, TRUE, 0);
    gtk_widget_show (connecttable1);

    entrylabel1 = gtk_label_new ("host:");
    gtk_label_set (GTK_LABEL (entrylabel1), "host:");
    gtk_label_set_justify (GTK_LABEL (entrylabel1), GTK_JUSTIFY_CENTER);
    gtk_table_attach (GTK_TABLE (connecttable1), entrylabel1, 0, 1, 0, 1,
      GTK_FILL, GTK_FILL, 10, 10);
    gtk_widget_show (entrylabel1);

    connectentry1 = gtk_entry_new_with_max_length (50);
    gtk_entry_set_text (GTK_ENTRY (connectentry1), "nngs.cosmic.org");
    gtk_entry_select_region (GTK_ENTRY (connectentry1), 0,
      GTK_ENTRY (connectentry1)->text_length);
    gtk_table_attach (GTK_TABLE (connecttable1), connectentry1, 1, 2, 0, 1,
      GTK_EXPAND, GTK_EXPAND, 0, 10);
    gtk_widget_grab_focus (connectentry1);
    gtk_widget_show (connectentry1);

    entrylabel2 = gtk_label_new ("port:");
    gtk_label_set (GTK_LABEL (entrylabel2), "port:");
    gtk_label_set_justify (GTK_LABEL (entrylabel2), GTK_JUSTIFY_CENTER);
    gtk_table_attach (GTK_TABLE (connecttable1), entrylabel2, 0, 1, 1, 2,
      GTK_FILL, GTK_FILL, 10, 10);
    gtk_widget_show (entrylabel2);

    connectentry2 = gtk_entry_new_with_max_length (5);
    gtk_entry_set_text (GTK_ENTRY (connectentry2), "9696");
    gtk_table_attach (GTK_TABLE (connecttable1), connectentry2, 1, 2, 1, 2,
      GTK_EXPAND, GTK_EXPAND, 0, 10);
    gtk_widget_show (connectentry2);

    connectsep = gtk_hseparator_new ();
    gtk_table_attach (GTK_TABLE (connecttable1), connectsep, 0, 2, 2, 3,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show (connectsep);

    connectbutton = gtk_button_new_with_label ("Connect");
    gtk_signal_connect (GTK_OBJECT (connectbutton), "clicked",
      GTK_SIGNAL_FUNC (InternetGo), NULL);
    GTK_WIDGET_SET_FLAGS (connectbutton, GTK_CAN_DEFAULT);
    gtk_window_set_default (GTK_WINDOW (connectwindow), connectbutton);
    gtk_table_attach (GTK_TABLE (connecttable1), connectbutton, 0, 2, 3, 4,
      GTK_FILL, GTK_FILL, 2, 2);
    gtk_widget_show (connectbutton);

    gtk_widget_show (connectwindow);
    iyesno = 1;
  }
}
