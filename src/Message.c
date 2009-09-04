/* gtkgo 0.0.10 (Message.c) - 05/17/99
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

#include "Message.h"

void Message (char *mestext, int imesquit, int imestype)
{
  if (((imesquit == 1) || (imesquit == 2) || (imesquit == 3) || (imesquit == 4)) && (iyesno == 0))
  {
    if (ichangestuff == 0)
    {
      Play ("open.mp3", 0);
    }
    if ((imesquit == 3) || (imesquit == 4))
    {
      sprintf (mestemp, "\n%s  \n", mestext);
    }
    else
    if (imesquit == 2)
    {
      sprintf (mestemp, "\n%s  \n", ssavemes);
      gtk_widget_destroy (files2);
    }
    else
    if (isavemes == 1)
    {
      sprintf (mestemp, "\n%s  \n%s  \n", ssavemes, mestext);
      gtk_widget_destroy (files2);
    }
    else
    {
      sprintf (mestemp, "\n%s  \n", mestext);
    }
    messagewindow = gtk_window_new (GTK_WINDOW_DIALOG);
    gtk_window_position (GTK_WINDOW (messagewindow), GTK_WIN_POS_CENTER);
    gtk_window_set_title (GTK_WINDOW (messagewindow), "message");
    gtk_signal_connect (GTK_OBJECT (messagewindow), "delete_event",
      GTK_SIGNAL_FUNC (DestroyMessage), NULL);
    gtk_window_set_policy (GTK_WINDOW (messagewindow), 0, 0, 1);
    gtk_container_border_width (GTK_CONTAINER (messagewindow), 0);
    gtk_widget_realize (messagewindow);

    mesbox1 = gtk_vbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (mesbox1), 0);
    gtk_container_add (GTK_CONTAINER (messagewindow), mesbox1);
    gtk_widget_show (mesbox1);
    mesbox2 = gtk_hbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (mesbox2), 0);
    gtk_box_pack_start (GTK_BOX (mesbox1), mesbox2, FALSE, FALSE, 0);
    gtk_widget_show (mesbox2);
    mestable1 = gtk_table_new (2, 3, FALSE);
    gtk_widget_show (mestable1);
    gtk_box_pack_start (GTK_BOX (mesbox2), mestable1, TRUE, TRUE, 0);

    if (imestype == 0)
    {
      mesimg = gdk_imlib_load_image (PKGDATADIR"pix/error.png");
    }
    else
    {
      mesimg = gdk_imlib_load_image (PKGDATADIR"pix/correct.png");
    }
    mesw = mesimg->rgb_width;
    mesh = mesimg->rgb_height;
    gdk_imlib_render (mesimg, mesw, mesh);
    mespixmap = gdk_imlib_move_image (mesimg);
    mespixmapwid = gtk_pixmap_new (mespixmap, NULL);
    gtk_table_attach (GTK_TABLE (mestable1), mespixmapwid, 0, 1, 0, 1,
      GTK_FILL, GTK_FILL, 5, 5);
    gtk_widget_show (mespixmapwid);
    gdk_flush ();

    meslabel = gtk_label_new (mestemp);
    gtk_label_set (GTK_LABEL (meslabel), mestemp);
    gtk_label_set_justify (GTK_LABEL (meslabel), GTK_JUSTIFY_CENTER);
    gtk_table_attach (GTK_TABLE (mestable1), meslabel, 1, 2, 0, 1,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show (meslabel);

    meshsep = gtk_hseparator_new ();
    gtk_table_attach (GTK_TABLE (mestable1), meshsep, 0, 2, 1, 2,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show (meshsep);

#ifdef USE_GNOME
    mesbutton = gnome_stock_button (GNOME_STOCK_BUTTON_OK);
#else
    mesbutton = gtk_button_new_with_label ("OK");
#endif
    gtk_signal_connect (GTK_OBJECT (mesbutton), "clicked",
      GTK_SIGNAL_FUNC (DestroyMessage), NULL);
    GTK_WIDGET_SET_FLAGS (mesbutton, GTK_CAN_DEFAULT);
    gtk_window_set_default (GTK_WINDOW (messagewindow), mesbutton);
    gtk_table_attach (GTK_TABLE (mestable1), mesbutton, 0, 2, 2, 3,
      GTK_FILL, GTK_FILL, 2, 2);
    gtk_widget_show (mesbutton);

    gtk_widget_show (messagewindow);
    iyesno = 1;
    if ((imesquit != 3) && (imesquit != 4))
    {
      iquit = 1;
    }
  }
  else
  {
    isavemes = 1;
    sprintf (ssavemes, "%s", mestext);
  }
}
