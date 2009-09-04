/* gtkgo 0.0.10 (AskSave.c) - 06/04/99
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

#include "AskSave.h"

void AskSave (void)
{
  yesnowindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (yesnowindow), "save sgf?");
  if ((itype != 3) && ((biscomputer != 1) || (wiscomputer != 1)))
  {
    gtk_signal_connect (GTK_OBJECT (yesnowindow), "delete_event",
      GTK_SIGNAL_FUNC (DestroyYesNo), (gpointer) 0);
  }
  else
  {
    gtk_signal_connect (GTK_OBJECT (yesnowindow), "delete_event",
      GTK_SIGNAL_FUNC (DestroyYesNo), (gpointer) 1);
  }
  gtk_window_set_policy (GTK_WINDOW (yesnowindow), 0, 0, 1);
  gtk_container_border_width (GTK_CONTAINER (yesnowindow), 0);
  gtk_widget_realize (yesnowindow);

  yesnobox1 = gtk_vbox_new (FALSE, 0);
  gtk_container_border_width (GTK_CONTAINER (yesnobox1), 0);
  gtk_container_add (GTK_CONTAINER (yesnowindow), yesnobox1);
  gtk_widget_show (yesnobox1);
  yesnobox2 = gtk_hbox_new (FALSE, 0);
  gtk_container_border_width (GTK_CONTAINER (yesnobox2), 0);
  gtk_box_pack_start (GTK_BOX (yesnobox1), yesnobox2, FALSE, FALSE, 0);
  gtk_widget_show (yesnobox2);
  yesnotable1 = gtk_table_new (2, 1, FALSE);
  gtk_box_pack_start (GTK_BOX (yesnobox2), yesnotable1, TRUE, TRUE, 0);
  gtk_widget_show (yesnotable1);

  yesnobutton = gtk_event_box_new ();
  gtk_widget_set_usize (yesnobutton, 100, 30);
  gtk_table_attach (GTK_TABLE (yesnotable1), yesnobutton, 0, 1, 0, 1,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_signal_connect (GTK_OBJECT (yesnobutton), "button_press_event",
    GTK_SIGNAL_FUNC (DestroyYesNo), (gpointer) 1);
  gtk_widget_show (yesnobutton);
  im8 = gdk_imlib_load_image (PKGDATADIR"pix/yes.png");
  w8 = im8->rgb_width;
  h8 = im8->rgb_height;
  gdk_imlib_render (im8, w8, h8);
  aspixmap = gdk_imlib_move_image (im8);
  aspixmapwid = gtk_pixmap_new (aspixmap, NULL);
  gtk_container_add (GTK_CONTAINER (yesnobutton), aspixmapwid);
  gtk_widget_show (aspixmapwid);
  gdk_flush ();

  yesnobutton2 = gtk_event_box_new ();
  gtk_widget_set_usize (yesnobutton2, 100, 30);
  gtk_table_attach (GTK_TABLE (yesnotable1), yesnobutton2, 1, 2, 0, 1,
    GTK_FILL, GTK_FILL, 0, 0);
  if ((itype == 1) || (itype == 3))
  {
    gtk_signal_connect (GTK_OBJECT (yesnobutton2), "button_press_event",
      GTK_SIGNAL_FUNC (DestroyYesNo), (gpointer) 3);
  }
  if (itype == 2)
  {
    gtk_signal_connect (GTK_OBJECT (yesnobutton2), "button_press_event",
      GTK_SIGNAL_FUNC (DestroyYesNo), (gpointer) 2);
  }
  gtk_widget_show (yesnobutton2);
  im8 = gdk_imlib_load_image (PKGDATADIR"pix/no.png");
  w8 = im8->rgb_width;
  h8 = im8->rgb_height;
  gdk_imlib_render (im8, w8, h8);
  aspixmap2 = gdk_imlib_move_image (im8);
  aspixmapwid2 = gtk_pixmap_new (aspixmap2, NULL);
  gtk_container_add (GTK_CONTAINER (yesnobutton2), aspixmapwid2);
  gtk_widget_show (aspixmapwid2);
  gdk_flush ();

  iyesno = 1;
  gtk_widget_show (yesnowindow);
  if (ichangestuff == 0)
  {
    Play ("open.mp3", 0);
  }
}
