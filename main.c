/* 
 * Copyright (C) 2007 OpenedHand Ltd
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <gtk/gtk.h>
#include <vte/vte.h>

static void
on_window_title_changed (VteTerminal *terminal, GtkWindow *window)
{
  char *title;

  title = g_strdup_printf ("%s - Terminal", terminal->window_title);
  gtk_window_set_title (window, title);
  g_free (title);
}

static void
on_eof (VteTerminal *terminal, gpointer user_data)
{
  gtk_main_quit ();
}

int
main (int argc, char **argv)
{
  GtkWidget *window, *box, *terminal, *scrollbar;
  
  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (window, "destroy", gtk_main_quit, NULL);
  
  box = gtk_hbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (window), box);

  terminal = g_object_connect
    (vte_terminal_new (),
     /* Child dying */
     "signal::child-exited", on_eof, NULL,
     "signal::eof", on_eof, NULL,
     /* Child is trying to control the terminal */
     "signal::window-title-changed", on_window_title_changed, window,
     NULL);
  gtk_box_pack_start (GTK_BOX (box), terminal, TRUE, TRUE, 0);

  scrollbar = gtk_vscrollbar_new (VTE_TERMINAL (terminal)->adjustment);
  gtk_box_pack_start (GTK_BOX (box), scrollbar, FALSE, FALSE, 0);

  vte_terminal_fork_command (VTE_TERMINAL (terminal),
                             NULL, NULL, NULL, NULL, TRUE, TRUE, TRUE);

  gtk_widget_show_all (window);

  gtk_main ();

  return 0;
}
