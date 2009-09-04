/* gtkgo 0.0.10 (PixmapOnButton.c) - 05/17/99
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

#include "PixmapOnButton.h"

static void menu_popup (GtkWidget *mpwidget, GdkEvent *mpevent)
{
  GtkWidget *menu_item;
  GtkWidget *mpmenu;

  GdkEventButton *mpevent2 = (GdkEventButton *) mpevent;
  mpmenu = gtk_menu_new ();

  menu_item = gtk_menu_item_new_with_label ("Hint");
  gtk_menu_append (GTK_MENU (mpmenu), menu_item);
  gtk_signal_connect_object (GTK_OBJECT (menu_item), "activate",
    GTK_SIGNAL_FUNC (Hint), NULL);
  gtk_widget_show (menu_item);

  menu_item = gtk_menu_item_new_with_label ("Undo");
  gtk_menu_append (GTK_MENU (mpmenu), menu_item);
  gtk_signal_connect_object (GTK_OBJECT (menu_item), "activate",
    GTK_SIGNAL_FUNC (Undo), NULL);
  gtk_widget_show (menu_item);

  menu_item = gtk_menu_item_new_with_label ("Help...");
  gtk_menu_append (GTK_MENU (mpmenu), menu_item);
  gtk_signal_connect_object (GTK_OBJECT (menu_item), "activate",
    GTK_SIGNAL_FUNC (Help), NULL);
  gtk_widget_show (menu_item);

  menu_item = gtk_menu_item_new_with_label ("About...");
  gtk_menu_append (GTK_MENU (mpmenu), menu_item);
  gtk_signal_connect_object (GTK_OBJECT (menu_item), "activate",
    GTK_SIGNAL_FUNC (About), NULL);
  gtk_widget_show (menu_item);

  gtk_menu_popup (GTK_MENU (mpmenu), NULL, NULL, NULL, NULL,
    mpevent2->button, mpevent2->time);
}

static void click_handler (GtkWidget *chwidget, GdkEvent *chevent,
  gpointer ibuttonthingy)
{
  GdkEventButton *chbutton = (GdkEventButton *) chevent;
  switch (chbutton->button)
  {
    case 1: MakeMove (chwidget, chevent, (gpointer) ibuttonthingy); break;
    case 3: menu_popup (chwidget, chevent); break;
  }
}

void PixmapOnButton (int ithebutton)
{
  if ((ishowlast == 0) && (Board[ithebutton][3] == 'l'))
  {
    sprintf (pixmapnameb, PKGDATADIR"skins/%s/%c%c%c.png", sskin,
    Board[ithebutton][0], Board[ithebutton][1], Board[ithebutton][2]);
  }
  else
  {
    sprintf (pixmapnameb, PKGDATADIR"skins/%s/%s.png", sskin,
      Board[ithebutton]);
  }
  button[ithebutton] = gtk_event_box_new ();
  if (isize == 1)
  {
    gtk_widget_set_usize (button[ithebutton], 30, 30);
  }
  if (isize == 2)
  {
    gtk_widget_set_usize (button[ithebutton], 24, 24);
  }
  if (isize == 3)
  {
    gtk_widget_set_usize (button[ithebutton], 15, 15);
  }
  gtk_table_attach (GTK_TABLE (table2), button[ithebutton], x, (x + 1), y,
  (y + 1), GTK_FILL, GTK_FILL, 0, 0);
  gtk_signal_connect (GTK_OBJECT (button[ithebutton]), "button_press_event",
    GTK_SIGNAL_FUNC (click_handler), (gpointer) ithebutton);
  gtk_widget_realize (button[ithebutton]);
  gdk_window_set_cursor (button[ithebutton]->window,
    gdk_cursor_new (GDK_DOT));
  gtk_widget_show (button[ithebutton]);

  im[ithebutton] = gdk_imlib_load_image (pixmapnameb);
  if (isize == 1)
  {
    w = im[ithebutton]->rgb_width;
    h = im[ithebutton]->rgb_height;
  }
  if (isize == 2)
  {
    w = im[ithebutton]->rgb_width * 0.8;
    h = im[ithebutton]->rgb_height * 0.8;
  }
  if (isize == 3)
  {
    w = im[ithebutton]->rgb_width/2;
    h = im[ithebutton]->rgb_height/2;
  }
  gdk_imlib_render (im[ithebutton], w, h);
  pixmap[ithebutton] = gdk_imlib_move_image (im[ithebutton]);
  pixmapwid[ithebutton] = gtk_pixmap_new (pixmap[ithebutton], NULL);
  gtk_container_add (GTK_CONTAINER (button[ithebutton]), pixmapwid[ithebutton]);
  gtk_widget_show (pixmapwid[ithebutton]); 
  gdk_flush ();
  buttontip[ithebutton] = gtk_tooltips_new ();
  switch ((Modulo (x, 19)) + 1)
  {
    case 1: sprintf (coor, "A%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 2: sprintf (coor, "B%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 3: sprintf (coor, "C%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 4: sprintf (coor, "D%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 5: sprintf (coor, "E%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 6: sprintf (coor, "F%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 7: sprintf (coor, "G%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 8: sprintf (coor, "H%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 9: sprintf (coor, "J%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 10: sprintf (coor, "K%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 11: sprintf (coor, "L%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 12: sprintf (coor, "M%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 13: sprintf (coor, "N%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 14: sprintf (coor, "O%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 15: sprintf (coor, "P%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 16: sprintf (coor, "Q%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 17: sprintf (coor, "R%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 18: sprintf (coor, "S%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton)); break;
    case 19: sprintf (coor, "T%i (%i/%s)", 19 - y, ithebutton,
      BoardPlace (1, ithebutton));
  }
  gtk_tooltips_set_tip
    (buttontip[ithebutton], button[ithebutton], coor, coor);
  gtk_tooltips_set_delay (buttontip[ithebutton], 1);

  x++;
  if (x == 19)
  {
    x = 0;
    y++;
  }
}
