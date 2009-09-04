/* gtkgo 0.0.10 (Skin.c) - 05/17/99
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

#include "Skin.h"

void Skin (void)
{
  if ((ifilestuff == 0) && ((biscomputer == 0) || (wiscomputer == 0))
    && (iyesno == 0))
  {
    if ((skindir = opendir (PKGDATADIR"skins/")) == NULL)
    {
      Message ("Error loading skins.", 1, 0);
    }
    else
    {
      skinswindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
      gtk_window_set_title (GTK_WINDOW (skinswindow), "load skin");
      gtk_signal_connect (GTK_OBJECT (skinswindow), "delete_event",
        GTK_SIGNAL_FUNC (DestroyFiles), NULL);
      gtk_window_set_policy (GTK_WINDOW (skinswindow), 0, 0, 1);
      gtk_container_border_width (GTK_CONTAINER (skinswindow), 10);
      gtk_widget_realize (skinswindow);
      skintable = gtk_table_new (100, 3, FALSE);
      gtk_widget_show (skintable);
      gtk_container_add (GTK_CONTAINER (skinswindow), skintable);
      inrskins = 0;
      while ((dir = readdir (skindir)) != NULL)
      {
        if ((strcmp (dir->d_name, ".") != 0) && (strcmp (dir->d_name, "..")
          != 0))
        {
          sprintf (skinnames[inrskins], "%s", dir->d_name);
          inrskins++;
        }
      }
      closedir (skindir);

      for (isskinnames = 0; isskinnames < inrskins; isskinnames++)
      {
        sprintf (skinpix, PKGDATADIR"skins/%s/mmb.png",
          skinnames[isskinnames]);
        skinpixim = gdk_imlib_load_image (skinpix);
        skinpixw = skinpixim->rgb_width;
        skinpixh = skinpixim->rgb_height;
        gdk_imlib_render (skinpixim, skinpixw, skinpixh);
        skinpixmap = gdk_imlib_move_image (skinpixim);
        skinpixmapwid = gtk_pixmap_new (skinpixmap, NULL);
        gtk_table_attach (GTK_TABLE (skintable), skinpixmapwid,
          0, 1, isskinnames, isskinnames + 1, GTK_FILL, GTK_FILL, 0, 0);
        gtk_widget_show (skinpixmapwid);
        gdk_flush ();

        skinbuttons[isskinnames] = gtk_button_new_with_label
          (skinnames[isskinnames]);
        gtk_widget_set_usize (GTK_WIDGET (skinbuttons[isskinnames]), 200, 30);
        gtk_table_attach (GTK_TABLE (skintable), skinbuttons[isskinnames],
          1, 2, isskinnames, isskinnames + 1, GTK_FILL | GTK_EXPAND, GTK_FILL
          | GTK_EXPAND, 4, 2);
        gtk_signal_connect (GTK_OBJECT (skinbuttons[isskinnames]), "clicked",
          GTK_SIGNAL_FUNC (ChangeSkin), (gpointer) skinnames[isskinnames]);
        gtk_widget_show (skinbuttons[isskinnames]);

        sprintf (skinpix, PKGDATADIR"skins/%s/mmw.png",
          skinnames[isskinnames]);
        skinpixim = gdk_imlib_load_image (skinpix);
        skinpixw = skinpixim->rgb_width;
        skinpixh = skinpixim->rgb_height;
        gdk_imlib_render (skinpixim, skinpixw, skinpixh);
        skinpixmap = gdk_imlib_move_image (skinpixim);
        skinpixmapwid = gtk_pixmap_new (skinpixmap, NULL);
        gtk_table_attach (GTK_TABLE (skintable), skinpixmapwid,
          2, 3, isskinnames, isskinnames + 1, GTK_FILL, GTK_FILL, 0, 0);
        gtk_widget_show (skinpixmapwid);
        gdk_flush ();
      }
      gtk_widget_show (skinswindow);
      ifilestuff = 1;
      if (ichangestuff == 0)
      {
        Play ("open.mp3", 0);
      }
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
