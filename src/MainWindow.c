/* gtkgo 0.0.10 (MainWindow.c) - 05/17/99
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

#include "MainWindow.h"

#ifdef USE_GNOME
GnomeUIInfo gamemenu[] = {
  {GNOME_APP_UI_ITEM, N_("Re_start"), 0, ReStart,    0, 0,
    GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_NEW,    'S', GDK_CONTROL_MASK, 0},
  {GNOME_APP_UI_ITEM, N_("_Pass"),    0, Pass,       0, 0,
    GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_STOP,   'P', GDK_CONTROL_MASK, 0},
  GNOMEUIINFO_SEPARATOR,
  {GNOME_APP_UI_ITEM, N_("_Hint"),    0, Hint,       0, 0,
    GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_REDO,   'H', GDK_CONTROL_MASK, 0},
  {GNOME_APP_UI_ITEM, N_("_Undo"),    0, Undo,       0, 0,
    GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_UNDO,   'U', GDK_CONTROL_MASK, 0},
  GNOMEUIINFO_SEPARATOR,
  {GNOME_APP_UI_ITEM, N_("_Quit"),    0, Quit,       0, 0,
    GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_QUIT,   'Q', GDK_CONTROL_MASK, 0},
  GNOMEUIINFO_END
};

GnomeUIInfo settingsmenu[] = {
  {GNOME_APP_UI_ITEM, N_("S_kin..."), 0, Skin,       0, 0,
    GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_OPEN,   'K', GDK_CONTROL_MASK, 0},
  {GNOME_APP_UI_ITEM, N_("_Resize"),  0, ReSize,     0, 0,
    GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_CONVERT, 'R', GDK_CONTROL_MASK, 0},
  GNOMEUIINFO_SEPARATOR,
  {GNOME_APP_UI_ITEM, N_("_Options..."), 0, Options, 0, 0,
    GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_PREF,   'O', GDK_CONTROL_MASK, 0},
  GNOMEUIINFO_END
};

GnomeUIInfo helpmenu[] = {
  {GNOME_APP_UI_ITEM, N_("H_elp..."), 0, Help,       0, 0,
    GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_BOOK_OPEN, 'E',
    GDK_CONTROL_MASK, 0},
  {GNOME_APP_UI_ITEM, N_("_About..."), 0, About,     0, 0,
    GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_ABOUT,  'A', GDK_CONTROL_MASK, 0},
  GNOMEUIINFO_END
};

GnomeUIInfo menu_items2[] = {
  GNOMEUIINFO_SUBTREE (N_("_Game"), gamemenu),
  GNOMEUIINFO_SUBTREE (N_("_Settings"), settingsmenu),
  GNOMEUIINFO_SUBTREE (N_("_Help"), helpmenu),
  GNOMEUIINFO_END
};
#else
static GtkItemFactoryEntry menu_items2[] = {
  {"/_Game",                NULL,         NULL,    0, "<Branch>"},
  {"/Game/Re_start",        "<control>S", ReStart, 0, NULL},
  {"/Game/_Pass",           "<control>P", Pass,    0, NULL},
  {"/Game/sep1",            NULL,         NULL,    0, "<Separator>"},
  {"/Game/_Hint",           "<control>H", Hint,    0, NULL},
  {"/Game/_Undo",           "<control>U", Undo,    0, NULL},
  {"/Game/sep2",            NULL,         NULL,    0, "<Separator>"},
  {"/Game/_Quit",           "<control>Q", Quit,    0, NULL},
  {"/_Settings",            NULL,         NULL,    0, "<Branch>"},
  {"/Settings/S_kin...",    "<control>K", Skin,    0, NULL},
  {"/Settings/_Resize",     "<control>R", ReSize,  0, NULL},
  {"/Settings/sep3",        NULL,         NULL,    0, "<Separator>"},
  {"/Settings/_Options...", "<control>O", Options, 0, NULL},
  {"/_Help",                NULL,         NULL,    0, "<LastBranch>"},
  {"/Help/H_elp...",        "<control>E", Help,    0, NULL},
  {"/Help/_About...",       "<control>A", About,   0, NULL},
};
#endif

#ifndef USE_GNOME
void get_main_menu (GtkWidget *window, GtkWidget **menubar)
{
  int nmenu_items = sizeof (menu_items2) / sizeof (menu_items2[0]);
  GtkItemFactory *item_factory;
  GtkAccelGroup *accel_group;

  accel_group = gtk_accel_group_new ();
  item_factory = gtk_item_factory_new (GTK_TYPE_MENU_BAR, "<main>",
    accel_group);
  gtk_item_factory_create_items (item_factory, nmenu_items, menu_items2, NULL);
  gtk_accel_group_attach (accel_group, GTK_OBJECT (window));
  if (menubar)
  {
    *menubar = gtk_item_factory_get_widget (item_factory, "<main>");
  }
}
#endif

void MainWindow (void)
{
#ifdef USE_GNOME
  window1 = gnome_app_new ("gtkgo", "gtkgo");
#else
  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
#endif
  gtk_window_set_title (GTK_WINDOW (window1), "gtkgo 0.0.10");
  gtk_signal_connect (GTK_OBJECT (window1), "delete_event",
    GTK_SIGNAL_FUNC (Quit), NULL);
  gtk_window_set_policy (GTK_WINDOW (window1), 0, 0, 1);
  gtk_container_border_width (GTK_CONTAINER (window1), 0);
  gtk_widget_realize (window1);

  box1 = gtk_vbox_new (FALSE, 0);
  gtk_container_border_width (GTK_CONTAINER (box1), 0);
#ifdef USE_GNOME
  gnome_app_set_contents (GNOME_APP (window1), box1);
#else
  gtk_container_add (GTK_CONTAINER (window1), box1);
#endif
  gtk_widget_show (box1);
  box2 = gtk_vbox_new (FALSE, 0);
  gtk_container_border_width (GTK_CONTAINER (box2), 0);
  gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
  gtk_widget_show (box2);
  box3 = gtk_hbox_new (FALSE, 0);
  gtk_container_border_width (GTK_CONTAINER (box3), 0);
  gtk_box_pack_start (GTK_BOX (box2), box3, FALSE, FALSE, 0);
  gtk_widget_show (box3);
  box4 = gtk_hbox_new (FALSE, 0);
  gtk_container_border_width (GTK_CONTAINER (box4), 0);
  gtk_box_pack_start (GTK_BOX (box2), box4, FALSE, FALSE, 0);
  gtk_widget_show (box4);

  table1 = gtk_table_new (8, 2, FALSE);
  gtk_widget_show (table1);
  gtk_box_pack_start (GTK_BOX (box3), table1, TRUE, TRUE, 0);
  table2 = gtk_table_new (19, 21, FALSE);
  gtk_widget_show (table2);
  gtk_box_pack_start (GTK_BOX (box4), table2, TRUE, TRUE, 0);

#ifdef USE_GNOME
  gnome_app_create_menus (GNOME_APP (window1), menu_items2);
  gtk_menu_item_right_justify (GTK_MENU_ITEM (menu_items2[2].widget));
#else
  get_main_menu (window1, &menubar);
  gtk_table_attach (GTK_TABLE (table1), menubar, 0, 8, 0, 1,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_widget_show (menubar);
#endif

  buttontop = gtk_button_new ();
  if (isize == 1)
  {
    gtk_widget_set_usize (buttontop, 140, 30);
  }
  if (isize == 2)
  {
    gtk_widget_set_usize (buttontop, 112, 24);
  }
  if (isize == 3)
  {
    gtk_widget_set_usize (buttontop, 70, 15);
  }
  gtk_table_attach (GTK_TABLE (table1), buttontop, 0, 1, 1, 2,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_signal_connect (GTK_OBJECT (buttontop), "clicked",
    GTK_SIGNAL_FUNC (Pass), NULL);
  gtk_widget_show (buttontop);
  toptip = gtk_tooltips_new ();
  gtk_tooltips_set_tip (toptip, buttontop, "pass", "pass");
  gtk_tooltips_set_delay (toptip, 1);
  sprintf (thepixmap, PKGDATADIR"skins/%s/pass.png", sskin);
  im2 = gdk_imlib_load_image (thepixmap);
  if (isize == 1)
  {
    w2 = im2->rgb_width;
    h2 = im2->rgb_height;
  }
  if (isize == 2)
  {
    w2 = im2->rgb_width * 0.8;
    h2 = im2->rgb_height * 0.8;
  }
  if (isize == 3)
  {
    w2 = im2->rgb_width/2;
    h2 = im2->rgb_height/2;
  }
  gdk_imlib_render (im2, w2, h2);
  toppixmap = gdk_imlib_move_image (im2);
  toppixmapwid = gtk_pixmap_new (toppixmap, NULL);
  gtk_container_add (GTK_CONTAINER (buttontop), toppixmapwid);
  gtk_widget_show (toppixmapwid);
  gdk_flush ();
  buttontop2 = gtk_button_new ();
  if (isize == 1)
  {
    gtk_widget_set_usize (buttontop2, 250, 30);
  }
  if (isize == 2)
  {
    gtk_widget_set_usize (buttontop2, 200, 24);
  }
  if (isize == 3)
  {
    gtk_widget_set_usize (buttontop2, 125, 15);
  }
  gtk_table_attach (GTK_TABLE (table1), buttontop2, 1, 2, 1, 2,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_signal_connect (GTK_OBJECT (buttontop2), "clicked",
    GTK_SIGNAL_FUNC (ReStart), 0);
  gtk_widget_show (buttontop2);
  toptip2 = gtk_tooltips_new ();
  gtk_tooltips_set_tip (toptip2, buttontop2, "restart", "restart");
  gtk_tooltips_set_delay (toptip2, 1);
  sprintf (thepixmap, PKGDATADIR"skins/%s/restart.png", sskin);
  im2 = gdk_imlib_load_image (thepixmap);
  if (isize == 1)
  {
    w2 = im2->rgb_width;
    h2 = im2->rgb_height;
  }
  if (isize == 2)
  {
    w2 = im2->rgb_width * 0.8;
    h2 = im2->rgb_height * 0.8;
  }
  if (isize == 3)
  {
    w2 = im2->rgb_width/2;
    h2 = im2->rgb_height/2;
  }
  gdk_imlib_render (im2, w2, h2);
  top2pixmap = gdk_imlib_move_image (im2);
  top2pixmapwid = gtk_pixmap_new (top2pixmap, NULL);
  gtk_container_add (GTK_CONTAINER (buttontop2), top2pixmapwid);
  gtk_widget_show (top2pixmapwid);
  gdk_flush ();
  buttontop3 = gtk_button_new ();
  if (isize == 1)
  {
    gtk_widget_set_usize (buttontop3, 30, 30);
  }
  if (isize == 2)
  {
    gtk_widget_set_usize (buttontop3, 24, 24);
  }
  if (isize == 3)
  {
    gtk_widget_set_usize (buttontop3, 15, 15);
  }
  gtk_table_attach (GTK_TABLE (table1), buttontop3, 2, 3, 1, 2,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_signal_connect (GTK_OBJECT (buttontop3), "clicked",
    GTK_SIGNAL_FUNC (Skin), NULL);
  gtk_widget_show (buttontop3);
  toptip3 = gtk_tooltips_new ();
  gtk_tooltips_set_tip (toptip3, buttontop3, "skin", "skin");
  gtk_tooltips_set_delay (toptip3, 1);
  sprintf (thepixmap, PKGDATADIR"skins/%s/skin.png", sskin);
  im2 = gdk_imlib_load_image (thepixmap);
  if (isize == 1)
  {
    w2 = im2->rgb_width;
    h2 = im2->rgb_height;
  }
  if (isize == 2)
  {
    w2 = im2->rgb_width * 0.8;
    h2 = im2->rgb_height * 0.8;
  }
  if (isize == 3)
  {
    w2 = im2->rgb_width/2;
    h2 = im2->rgb_height/2;
  }
  gdk_imlib_render (im2, w2, h2);
  top3pixmap = gdk_imlib_move_image (im2);
  top3pixmapwid = gtk_pixmap_new (top3pixmap, NULL);
  gtk_container_add (GTK_CONTAINER (buttontop3), top3pixmapwid);
  gtk_widget_show (top3pixmapwid);
  gdk_flush ();
  buttontop4 = gtk_button_new ();
  if (isize == 1)
  {
    gtk_widget_set_usize (buttontop4, 30, 30);
  }
  if (isize == 2)
  {
    gtk_widget_set_usize (buttontop4, 24, 24);
  }
  if (isize == 3)
  {
    gtk_widget_set_usize (buttontop4, 15, 15);
  }
  gtk_table_attach (GTK_TABLE (table1), buttontop4, 3, 4, 1, 2,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_signal_connect (GTK_OBJECT (buttontop4), "clicked",
    GTK_SIGNAL_FUNC (Options), NULL);
  gtk_widget_show (buttontop4);
  toptip4 = gtk_tooltips_new ();
  gtk_tooltips_set_tip (toptip4, buttontop4, "options", "options");
  gtk_tooltips_set_delay (toptip4, 1);
  sprintf (thepixmap, PKGDATADIR"skins/%s/options.png", sskin);
  im2 = gdk_imlib_load_image (thepixmap);
  if (isize == 1)
  {
    w2 = im2->rgb_width;
    h2 = im2->rgb_height;
  }
  if (isize == 2)
  {
    w2 = im2->rgb_width * 0.8;
    h2 = im2->rgb_height * 0.8;
  }
  if (isize == 3)
  {
    w2 = im2->rgb_width/2;
    h2 = im2->rgb_height/2;
  }
  gdk_imlib_render (im2, w2, h2);
  top4pixmap = gdk_imlib_move_image (im2);
  top4pixmapwid = gtk_pixmap_new (top4pixmap, NULL);
  gtk_container_add (GTK_CONTAINER (buttontop4), top4pixmapwid);
  gtk_widget_show (top4pixmapwid);
  gdk_flush ();
  buttontop5 = gtk_button_new ();
  if (isize == 1)
  {
    gtk_widget_set_usize (buttontop5, 30, 30);
  }
  if (isize == 2)
  {
    gtk_widget_set_usize (buttontop5, 24, 24);
  }
  if (isize == 3)
  {
    gtk_widget_set_usize (buttontop5, 15, 15);
  }
  gtk_table_attach (GTK_TABLE (table1), buttontop5, 4, 5, 1, 2,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_signal_connect (GTK_OBJECT (buttontop5), "clicked",
    GTK_SIGNAL_FUNC (Undo), NULL);
  gtk_widget_show (buttontop5);
  toptip5 = gtk_tooltips_new ();
  gtk_tooltips_set_tip (toptip5, buttontop5, "undo", "undo");
  gtk_tooltips_set_delay (toptip5, 1);
  sprintf (thepixmap, PKGDATADIR"skins/%s/undo.png", sskin);
  im2 = gdk_imlib_load_image (thepixmap);
  if (isize == 1)
  {
    w2 = im2->rgb_width;
    h2 = im2->rgb_height;
  }
  if (isize == 2)
  {
    w2 = im2->rgb_width * 0.8;
    h2 = im2->rgb_height * 0.8;
  }
  if (isize == 3)
  {
    w2 = im2->rgb_width/2;
    h2 = im2->rgb_height/2;
  }
  gdk_imlib_render (im2, w2, h2);
  top5pixmap = gdk_imlib_move_image (im2);
  top5pixmapwid = gtk_pixmap_new (top5pixmap, NULL);
  gtk_container_add (GTK_CONTAINER (buttontop5), top5pixmapwid);
  gtk_widget_show (top5pixmapwid);
  gdk_flush ();
  buttontop6 = gtk_button_new ();
  if (isize == 1)
  {
    gtk_widget_set_usize (buttontop6, 30, 30);
  }
  if (isize == 2)
  {
    gtk_widget_set_usize (buttontop6, 24, 24);
  }
  if (isize == 3)
  {
    gtk_widget_set_usize (buttontop6, 15, 15);
  }
  gtk_table_attach (GTK_TABLE (table1), buttontop6, 5, 6, 1, 2,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_signal_connect (GTK_OBJECT (buttontop6), "clicked",
    GTK_SIGNAL_FUNC (Hint), NULL);
  gtk_widget_show (buttontop6);
  toptip6 = gtk_tooltips_new ();
  gtk_tooltips_set_tip (toptip6, buttontop6, "hint", "hint");
  gtk_tooltips_set_delay (toptip6, 1);
  sprintf (thepixmap, PKGDATADIR"skins/%s/hint.png", sskin);
  im2 = gdk_imlib_load_image (thepixmap);
  if (isize == 1)
  {
    w2 = im2->rgb_width;
    h2 = im2->rgb_height;
  }
  if (isize == 2)
  {
    w2 = im2->rgb_width * 0.8;
    h2 = im2->rgb_height * 0.8;
  }
  if (isize == 3)
  {
    w2 = im2->rgb_width/2;
    h2 = im2->rgb_height/2;
  }
  gdk_imlib_render (im2, w2, h2);
  top6pixmap = gdk_imlib_move_image (im2);
  top6pixmapwid = gtk_pixmap_new (top6pixmap, NULL);
  gtk_container_add (GTK_CONTAINER (buttontop6), top6pixmapwid);
  gtk_widget_show (top6pixmapwid);
  gdk_flush ();
  buttontop7 = gtk_button_new ();
  if (isize == 1)
  {
    gtk_widget_set_usize (buttontop7, 30, 30);
  }
  if (isize == 2)
  {
    gtk_widget_set_usize (buttontop7, 24, 24);
  }
  if (isize == 3)
  {
    gtk_widget_set_usize (buttontop7, 15, 15);
  }
  gtk_table_attach (GTK_TABLE (table1), buttontop7, 6, 7, 1, 2,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_signal_connect (GTK_OBJECT (buttontop7), "clicked",
    GTK_SIGNAL_FUNC (ReSize), NULL);
  gtk_widget_show (buttontop7);
  toptip7 = gtk_tooltips_new ();
  gtk_tooltips_set_tip (toptip7, buttontop7, "resize", "resize");
  gtk_tooltips_set_delay (toptip7, 1);
  sprintf (thepixmap, PKGDATADIR"skins/%s/resize.png", sskin);
  im2 = gdk_imlib_load_image (thepixmap);
  if (isize == 1)
  {
    w2 = im2->rgb_width;
    h2 = im2->rgb_height;
  }
  if (isize == 2)
  {
    w2 = im2->rgb_width * 0.8;
    h2 = im2->rgb_height * 0.8;
  }
  if (isize == 3)
  {
    w2 = im2->rgb_width/2;
    h2 = im2->rgb_height/2;
  }
  gdk_imlib_render (im2, w2, h2);
  top7pixmap = gdk_imlib_move_image (im2);
  top7pixmapwid = gtk_pixmap_new (top7pixmap, NULL);
  gtk_container_add (GTK_CONTAINER (buttontop7), top7pixmapwid);
  gtk_widget_show (top7pixmapwid);
  gdk_flush ();
  buttontop8 = gtk_button_new ();
  if (isize == 1)
  {
    gtk_widget_set_usize (buttontop8, 30, 30);
  }
  if (isize == 2)
  {
    gtk_widget_set_usize (buttontop8, 24, 24);
  }
  if (isize == 3)
  {
    gtk_widget_set_usize (buttontop8, 15, 15);
  }
  gtk_table_attach (GTK_TABLE (table1), buttontop8, 7, 8, 1, 2,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_signal_connect (GTK_OBJECT (buttontop8), "clicked",
    GTK_SIGNAL_FUNC (Quit), NULL);
  gtk_widget_show (buttontop8);
  toptip8 = gtk_tooltips_new ();
  gtk_tooltips_set_tip (toptip8, buttontop8, "quit", "quit");
  gtk_tooltips_set_delay (toptip8, 1);
  sprintf (thepixmap, PKGDATADIR"skins/%s/quit.png", sskin);
  im2 = gdk_imlib_load_image (thepixmap);
  if (isize == 1)
  {
    w2 = im2->rgb_width;
    h2 = im2->rgb_height;
  }
  if (isize == 2)
  {
    w2 = im2->rgb_width * 0.8;
    h2 = im2->rgb_height * 0.8;
  }
  if (isize == 3)
  {
    w2 = im2->rgb_width/2;
    h2 = im2->rgb_height/2;
  }
  gdk_imlib_render (im2, w2, h2);
  top8pixmap = gdk_imlib_move_image (im2);
  top8pixmapwid = gtk_pixmap_new (top8pixmap, NULL);
  gtk_container_add (GTK_CONTAINER (buttontop8), top8pixmapwid);
  gtk_widget_show (top8pixmapwid);
  gdk_flush ();

  if (isize == 1)
  {
    statbar = gtk_statusbar_new ();
    gtk_table_attach (GTK_TABLE (table2), statbar, 0, 2, 19, 21,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show (statbar);

    statbar2 = gtk_statusbar_new ();
    gtk_table_attach (GTK_TABLE (table2), statbar2, 2, 19, 19, 20,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show (statbar2);

    statbar3 = gtk_statusbar_new ();
    gtk_table_attach (GTK_TABLE (table2), statbar3, 2, 19, 20, 21,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show (statbar3);

    StatusBar ();
  }
  else
  {
    gtk_widget_hide (statbar);
    gtk_widget_hide (statbar2);
    gtk_widget_hide (statbar3);
  }
}
